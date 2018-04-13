// shiyan2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<highgui.hpp>
#include<imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main()
{

	


	namedWindow("Source", CV_WINDOW_AUTOSIZE );
	namedWindow("Blur", CV_WINDOW_AUTOSIZE);
	namedWindow("BoxFilter", CV_WINDOW_AUTOSIZE);
	namedWindow("MediaBlur", CV_WINDOW_AUTOSIZE);
	namedWindow("GaussianBlur", CV_WINDOW_AUTOSIZE);
	namedWindow("Sobel", CV_WINDOW_AUTOSIZE);
	namedWindow("Laplacian", CV_WINDOW_AUTOSIZE);
	
		Mat src = imread("test.jpg");
		Mat bluri,box,media,gaus,sobel,sobelx,sobely,lap;
		Mat gray(src.size(), CV_8UC1);
		cvtColor(src, gray, CV_BGR2GRAY);
		
		blur(src, bluri, Size(3, 3));//���� ��� ���ڳߴ�

		boxFilter(src,box ,-1, Size(5, 5));//���� ��� ��� ���ڴ�С

		medianBlur(src, media, 5);//���� ��� �����δ��ڱ߳�

		GaussianBlur(src, gaus, Size(3, 3), 0, 0);//���� ��� ���ڴ�С �Զ�����x��׼�� �Զ�����y��׼��

		Sobel(src, sobelx, src.depth(), 1, 0);//��� ��� ��� x����
		Sobel(src, sobely, src.depth(), 0, 1);//��� ��� ��� y����
		convertScaleAbs(sobelx, sobelx);//�����ֵ
		convertScaleAbs(sobely, sobely);
		addWeighted(sobelx, 0.5, sobely, 0.5, 0, sobel);//���

		Laplacian(src, lap, CV_16S, 3, 1, 0, BORDER_DEFAULT);//���� ��� ��� ���ڴ�С �������� �洢ģʽ
		convertScaleAbs(lap, lap);

		imshow("Source", src);
		imshow("Blur", bluri);
		imshow("BoxFilter", box);
		imshow("MediaBlur",media);
		imshow("GaussianBlur", gaus);
		imshow("Sobel", sobel);
		imshow("Laplacian", lap);
		cvWaitKey(0);
	return 0;
}

