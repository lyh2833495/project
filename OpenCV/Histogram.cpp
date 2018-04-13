// Histogram.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <highgui.hpp>
#include <imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;
class Histogram1D {
private:
	int histSize[1];//ֱ��ͼ������bin������ eg:�Ҷ�ͼ��256��bin
	float hranges[2];//ֵ��Χ
	const float* ranges[1];//ֵ��Χ��ָ��
	int channels[1];//Ҫ����ͨ������
public:
	Histogram1D()
	{
		histSize[0]=256;//256������bin
		hranges[0] = 0.0;//ֵ��0��ʼ��������
		hranges[1] = 256.0;//��255����
		ranges[0] = hranges;//ָ��ָ��ֵ��Χ����ͷ
		channels[0]=0;//����0ͨ��
	}
    
	Mat getHistogram(const Mat &image)
	{
	Mat hist;
	cv::calcHist(&image, 
		1,//һ��ͼ���ֱ��ͼ
		channels,//ʹ�õ�ͨ��
		Mat(),//����������
		hist,//���ֱ��ͼ
		1,//һά
		histSize,//�������� 
		ranges//����ֵ�ķ�Χ
	);
	return hist;
	}

	Mat getHistogramImage(const Mat &image, int zoom = 1) {
		Mat hist = getHistogram(image);
		return getImageOfHistogram(hist, zoom);
	}

	static Mat getImageOfHistogram(const Mat &hist, int zoom) {
		double maxval = 0;
		double minval = 0;
		minMaxLoc(hist, &minval, &maxval, 0, 0);
		int histSize = hist.rows;
		Mat histImg(histSize*zoom, histSize*zoom, CV_8U, Scalar(255));
		int hpt = static_cast<int>(0.9*histSize);
		for (int h = 0; h < histSize; h++) {
			float binval = hist.at<float>(h);
			if (binval > 0) {
				int intensity = static_cast<int>(binval*hpt / maxval);
				line(histImg,
					Point(h*zoom, histSize*zoom),
					Point(h*zoom,(histSize-intensity)*zoom),
					Scalar(0),
					zoom);
					
			}
		}
		return histImg;
	}
};



int main()
{
	Mat image = imread("ll.jpg");
	Histogram1D h;
	Mat histo = h.getHistogram(image);
	int num = 0;
	for (int i = 0; i < 256; i++)
	{
		num = num + histo.at<float>(i);
		cout << "���ػҶ�ֵΪ " << i << " ������=" << histo.at<float>(i) << endl;
	}
	cout <<endl<< "��������=" << num<<endl;
	cout << "�ֱ���=" << image.cols << "*" << image.rows << "=" << image.cols*image.rows<<endl;
	
	Mat dst(Size(h.getHistogramImage(image).cols*4, h.getHistogramImage(image).rows*4), h.getHistogramImage(image).type());
	resize(h.getHistogramImage(image),
		dst,
		dst.size()
	);
	imshow("123", dst);
	char c = cvWaitKey(0);
	return 0;
}

