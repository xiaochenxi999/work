#include <iosteam.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;

void homomofilter()
{
	//get image soucre
	Mat imgSrc=imread("E:\\lean.jpg");
	
	//change to HSI
	Mat imgHsi;
	cvtColor(imgSrc,imgHsi,CV_RGB2HLS);
	vector<Mat> channels;
	split(imgHsi,channels);
	Mat imgHsiL=channels.at(1);

	//normalize imgHsiL to 0-1
	Mat imgGsrc=Mat::zeros(imgHsiL.size(),CV_32FC1);
	imgHsiL.convertTo(imgGsrc,CV_32FC1);

	//log Make a In.f(x,y)
	Mat imgLog;
	imgLog=imgGsrc+0.0001;
	log(imgLog,imgLog);

	//smooth filter with imgLog
	Mat imgFilter=Mat::zeros(imgHsiL.size(),CV_32FC1);
	boxFilter(imgLog,imgFilter,-1,Size(21,21));

	//get high part at image
	Mat imgHp==Mat::zeros(imgHsiL.size(),CV_32FC1);
	if(choe==1)
	{
		imgHp=imgLog-imgFilter;
	}
	else 
	{
		imgHp=imgGsrc-imgFilter;
	}
	
	//exp make a e^
	exp(imghp,imgHp);
	imgHp.convertTo(imgDst,cv_8UC1);


	imgageAdjust(imgDst,imgDst,0,1,0,1,2.1);

	return;
}