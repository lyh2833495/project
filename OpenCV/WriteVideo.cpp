#include "stdafx.h"

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>

#include <string>
#include <iostream>
#include "D://OpenCV/cvui-2.0.0/cvui.h"
#include <Windows.h>
using namespace cv;
using namespace std;

int main()
{
	//void stretch(Mat src, int nMin, int nMax);
	//VideoCapture cap("E:\\Project\\OpenCV\\TEST\\x64\\Debug\\4.mp4");
	VideoCapture cap(1);
	Mat img;
	Mat gray;
	while (1) {
		cap >> img;
		if (img.empty()) {
			cout << "no" << endl;
			break;
		}
		else {
			
			cvtColor(img, gray, COLOR_RGB2GRAY);
			imshow("src", img);
			cvWaitKey(1);
			//stretch(img, 0, 255);
			//imshoTHRESH_BINARYw("555", img);
			//equalizeHist(img, img);
			//imshow("3", img);
			threshold(gray, gray, 0, 255, CV_THRESH_OTSU);
			//adaptiveThreshold(img, img, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY,27, 8);
						imshow("1", gray);
			cvWaitKey(1);
		}

	}

}


/*
int main() {
	//VideoCapture cap("test.mp4");
	VideoCapture cap(0);
	//Mat img=imread("lena.jpg") ;
	Mat img;
	Mat frame = cv::Mat(1080, 1920, CV_8UC3);
	frame = Scalar(100, 100, 100);
	cv::namedWindow("123");
	cvui::init("123");
	while(1)
	{
		cap >> img;
		resize(img, img, cv::Size(640, 480), (0, 0), (0, 0), 1);
	cvui::image(frame, 50, 50, img);
	cvui::button(frame, 700, 50, 90, 80, "Start");
	if (cvui::button(frame, 700, 400, 90, 80, "End")) {
		cout << "2222" << endl;
		break;
	}
	cvui::update();
	imshow("123", frame);
	cvWaitKey(1);
	
	}
	cout << "End";
	return 0;
}


*/

/*
int main(void)
{
	cv::Mat frame = cv::Mat(200, 500, CV_8UC3);
	int count = 0;

	// ��ʼ������  
	cv::namedWindow("123");
	cvui::init("123");
	while (cv::waitKey(30) != 27) {
		// ֱ�������ɫ  
		frame = cv::Scalar(49, 52, 49);

		// ��λ��110��80��ʾ��ť  
		if (cvui::button(frame, 110, 80, "Hello, world!")) {
			// ����  
			count++;
			cout << "123";
			return 0;
		}
		// ��λ�ã�250��90����ʾ���ֺŴ�СΪ0.4��ɫΪ��ɫ  
		cvui::printf(frame, 250, 90, 0.4, 0xff0000, "Button click count: %d", count);
		//ˢ��  
		cvui::update();
		// ��ʾ  
		cv::imshow("123", frame);
	}
	return 0;
}*/