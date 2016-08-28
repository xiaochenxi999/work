void ImageAdjust(Mat& src, Mat& dst,
         vector<double> low_in,
         vector<double> high_in,
         vector<double> low_out,
         vector<double> high_out,
         vector<double> gamma)
{
  vector<double> low;
  vector<double> high;
  vector<double> bottom;
  vector<double> top;
  vector<double> err_in;
  vector<double> err_out;
  int N = low_in.size();

  for (int i=0; i<N; i++)
  {
    low.push_back(low_in[i]*255);
    high.push_back(high_in[i]*255);
    bottom.push_back(low_out[i]*255);
    top.push_back(high_out[i]*255);
    err_in.push_back(high[i] - low[i]);
    err_out.push_back(top[i] - bottom[i]);
  }

  int x,y;
  vector<double> val;

  // intensity transform
  for( y = 0; y < src.rows; y++)
  {
    for (x = 0; x < src.cols; x++)
    {
      for (int i=0; i<N; i++)
      {
        double val = (src.at<Vec3b>(y, x)[i]);
        val = pow((val-low[i])/err_in[i], gamma[i])*err_out[i]+bottom[i]; // ☆

        if(val > 255) 
          val = 255;
        if(val < 0) 
          val = 0;
        dst.at<Vec3b>(y, x)[i] = val;
      }
    }
  }

}