#include "stdafx.h"
#include <iostream>
#include <opencv\highgui.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	IplImage* img = cvLoadImage(argv[1]);
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("Example1");
}