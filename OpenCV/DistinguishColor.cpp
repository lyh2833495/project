// DistinguishColor.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <highgui.hpp>
#include <imgproc.hpp>

using namespace cv;
using namespace std;

//int main(int argc, char** argv)
//{
//	/*VideoCapture cap(0); //����һ��VideoCapture��cap������0Ϊ������ͷ ��������Ϊĳ��Ƶ�ļ���·����Ϊ�򿪸���Ƶ      capture the video from web cam
//
//	if (!cap.isOpened())  //�ж��Ƿ�򿪳ɹ�  if not success, exit program
//	{
//		cout << "Cannot open the web cam" << endl;
//		return -1;
//	}*/
//
//	namedWindow("Control", CV_WINDOW_NORMAL); //����һ�����ڣ�������H��S��V�������ڸ�   create a window called "Control"
//	//namedWindow("Select", CV_WINDOW_NORMAL);
//	int iLowH = 100;//��СH��ɫ������ֵ  Ĭ��100
//	int iHighH = 140;//���H��ֵ Ĭ��140   ����S��V����
//
//	int iLowS = 90;//���Ͷ�
//	int iHighS = 255;
//
//	int iLowV = 90;//����
//	int iHighV = 255;
//
//	int i = 0, j = 0;//ѭ������
//	//Create trackbars in "Control" window
//	
//	cvCreateTrackbar("LowH", "Control", &iLowH, 179); //��Control�н�����СHֵ���ڸ�LowH���������� ɫ��ȡֵ��ΧHue (0 - 179)
//	cvCreateTrackbar("HighH", "Control", &iHighH, 179);
//
//	cvCreateTrackbar("LowS", "Control", &iLowS, 255); //���Ͷ�ȡֵ��ΧSaturation (0 - 255)
//	cvCreateTrackbar("HighS", "Control", &iHighS, 255);
//
//	cvCreateTrackbar("LowV", "Control", &iLowV, 255); //����ȡֵ��ΧValue (0 - 255)
//	cvCreateTrackbar("HighV", "Control", &iHighV, 255);
//	
//	while (true)
//	{   Mat imgOriginal= imread("C:\\Users\\LYH\\Pictures\\test.jpg");  //����ע����Ĵ����Ϊ��һ��ͼ
//	resize(imgOriginal, imgOriginal, Size(imgOriginal.cols /4, imgOriginal.rows / 4), 0, 0, INTER_LINEAR);
//
//		/*bool bSuccess = cap.read(imgOriginal); // ������ͷcap��Mat��imgOrigial�� �ȼ���cap >> imgOriginal;                     read a new frame from video
//		if (!bSuccess) //if not success, break loop
//		{
//			cout << "Cannot read a frame from video stream" << endl;
//			break;
//		}*/
//
//		Mat imgHSV;//��������HSVɫ�ʿռ��һ��Mat
//		vector<Mat> hsvSplit;//����H S V����
//		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //ת��RGB��HSV   Convert the captured frame from BGR to HSV
//													  //��Ϊ���Ƕ�ȡ���ǲ�ɫͼ��ֱ��ͼ���⻯��Ҫ��HSV�ռ���
//		split(imgHSV, hsvSplit);//����HSV
//		equalizeHist(hsvSplit[2], hsvSplit[2]);//Vֱ��ͼ���⻯
//		merge(hsvSplit, imgHSV);//HSV�ں�
//		Mat imgThresholded;//ʶ����Mat
//
//		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //ȷ��Ҫʶ���HSV��ֵ ��ֵ��  Threshold the image
//		//����������ѩ����ȣ�
//		Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
//		morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);//������(ȥ��һЩ���) �������Ƕ�ͼ���ȸ�ʴ�����ͣ������ų�С�ŵ�����       
//		morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);//�ղ��� (����һЩ��ͨ��) �������Ƕ�ͼ���������ٸ�ʴ�������ų�С�ͺڶ�
//
//		Mat result(imgOriginal.size(), imgOriginal.type());//��ɫ����ʾ��ʶ��
//		for (i = 0; i < result.cols; i++)
//		{
//			
//			for (j = 0; j < result.rows; j++)
//			{
//				if (imgThresholded.at<uchar>(j, i) == 255)//��ֵͼ��Ϊ��ɫ����ʾΪԭ��ɫ
//				{
//					result.at<cv::Vec3b>(j, i) = imgOriginal.at<cv::Vec3b>(j, i);
//				}
//				//else result.at<cv::Vec3b>(j, i) = (0, 0, 0);//��ֵͼ��Ϊ��ɫ����ʾ��ɫ
//			}
//		}
//
//		cvNamedWindow("result", CV_WINDOW_NORMAL);
//		cvNamedWindow("Thresholded Image", CV_WINDOW_NORMAL);
//		cvNamedWindow("Original", CV_WINDOW_NORMAL);
//		imshow("result", result);
//		imshow("Thresholded Image", imgThresholded); //��ֵʶ���� show the thresholded image
//		imshow("Original", imgOriginal); //ԭͼ show the original image
//		char key = (char)waitKey(3);
//		if (key == 27)
//			break;
//	}
//
//	return 0;
//
//}

int main(int argc, char** argv)
{
	VideoCapture cap(0); //����һ��VideoCapture��cap������0Ϊ������ͷ ��������Ϊĳ��Ƶ�ļ���·����Ϊ�򿪸���Ƶ      capture the video from web cam
	//cap.set(CAP_PROP_FRAME_WIDTH, 1920);
	//cap.set(CAP_PROP_FRAME_HEIGHT, 1080);
	if (!cap.isOpened())  //�ж��Ƿ�򿪳ɹ�  if not success, exit program
	{
	cout << "Cannot open the web cam" << endl;
	return -1;
	}
	
	namedWindow("Select", CV_WINDOW_NORMAL); //����һ�����ڣ�������H��S��V�������ڸ�   create a window called "Control"
	resizeWindow("Select", 640, 480);
											 //namedWindow("Select", CV_WINDOW_NORMAL);
	int black = 0,gray=0,white = 0,red=0,orange=0,yellow=0,green=0,qing=0,blue=0,purple=0;

	cvCreateTrackbar("��", "Select", &black, 1); 
	cvCreateTrackbar("��", "Select", &gray, 1);
	cvCreateTrackbar("��", "Select", &white, 1);
	cvCreateTrackbar("��", "Select", &red, 1);
	cvCreateTrackbar("��", "Select", &orange, 1);
	cvCreateTrackbar("��", "Select", &yellow, 1);
	cvCreateTrackbar("��", "Select", &green, 1);
	cvCreateTrackbar("��", "Select", &qing, 1);
	cvCreateTrackbar("��", "Select", &blue, 1);
	cvCreateTrackbar("��", "Select", &purple, 1);

	while (true)
	{
		int i = 0, j = 0;
		Mat imgOriginal;// = imread("C:\\Users\\LYH\\Pictures\\test.jpg");  //����ע����Ĵ����Ϊ��һ��ͼ
		//resize(imgOriginal, imgOriginal, Size(imgOriginal.cols / 4, imgOriginal.rows / 4), 0, 0, INTER_LINEAR);

		bool bSuccess = cap.read(imgOriginal); // ������ͷcap��Mat��imgOrigial�� �ȼ���cap >> imgOriginal;                     read a new frame from video
		if (!bSuccess) //if not success, break loop
		{
		cout << "Cannot read a frame from video stream" << endl;
		break;
		}

		Mat imgHSV;//��������HSVɫ�ʿռ��һ��Mat
		vector<Mat> hsvSplit;//����H S V����
		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //ת��RGB��HSV   Convert the captured frame from BGR to HSV
													  //��Ϊ���Ƕ�ȡ���ǲ�ɫͼ��ֱ��ͼ���⻯��Ҫ��HSV�ռ���
		split(imgHSV, hsvSplit);//����HSV
		equalizeHist(hsvSplit[2], hsvSplit[2]);//Vֱ��ͼ���⻯
		merge(hsvSplit, imgHSV);//HSV�ں�
		
		Mat imgThresholded(imgOriginal.size(),CV_8U,Scalar(0));//ʶ����Mat
		Mat mask;
		
		if (black == 1) {
			inRange(imgHSV, Scalar(0, 0, 0), Scalar(180, 255, 46), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (gray == 1) {
			inRange(imgHSV, Scalar(0, 0, 46), Scalar(180, 43, 220), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (white== 1) {
			inRange(imgHSV, Scalar(0, 0, 221), Scalar(180, 30, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (red == 1) {
			inRange(imgHSV, Scalar(0, 43, 46), Scalar(10, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
			inRange(imgHSV, Scalar(156, 43, 46), Scalar(180, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (orange== 1) {
			inRange(imgHSV, Scalar(11, 43, 46), Scalar(25, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (yellow == 1) {
			inRange(imgHSV, Scalar(26, 43, 46), Scalar(34, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (green== 1) {
			inRange(imgHSV, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (qing == 1) {
			inRange(imgHSV, Scalar(78, 43, 46), Scalar(99, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (blue== 1) {
			inRange(imgHSV, Scalar(100, 43, 46), Scalar(124, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (purple == 1) {
			inRange(imgHSV, Scalar(125, 43, 46), Scalar(155, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		
        //����������ѩ����ȣ�
		Mat element = getStructuringElement(MORPH_RECT, Size(1, 1));
		morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);//������(ȥ��һЩ���) �������Ƕ�ͼ���ȸ�ʴ�����ͣ������ų�С�ŵ�����       
		morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);//�ղ��� (����һЩ��ͨ��) �������Ƕ�ͼ���������ٸ�ʴ�������ų�С�ͺڶ�
		
		Mat result(imgOriginal.size(), imgOriginal.type());//��ɫ����ʾ��ʶ��
		for (i = 0; i < result.rows; i++)
		{
			uchar* data1 = imgOriginal.ptr<uchar>(i);
			uchar* data2 = result.ptr<uchar>(i);
			for (j = 0; j < result.cols; j++)
			{
				if (imgThresholded.at<uchar>(i, j) == 255)//��ֵͼ��Ϊ��ɫ����ʾΪԭ��ɫ
				{
					data2[3*j] = data1[3*j];
					data2[3*j+1] = data1[3*j+1];
					data2[3*j+2] = data1[3*j+2];
					//result.at<cv::Vec3b>(i, j) = imgOriginal.at<cv::Vec3b>(i, j);
				}
				else if (imgThresholded.at<uchar>(i, j) == 0) {
					data2[3 * j] = 0;
					data2[3 * j+1] = 0;
					data2[3 * j+2] = 0;
					//result.at<cv::Vec3b>(i, j) = (0, 0, 0);//��ֵͼ��Ϊ��ɫ����ʾ��ɫ
				}
					
			}
		}
		
		cvNamedWindow("Result", CV_WINDOW_NORMAL);
		cvNamedWindow("Thresholded", CV_WINDOW_NORMAL);
		cvNamedWindow("Original", CV_WINDOW_NORMAL);
		cvResizeWindow("Result", 640, 480);
		cvResizeWindow("Thresholded", 640, 480);
		cvResizeWindow("Original", 640, 480);
		imshow("Result", result);
		imshow("Thresholded", imgThresholded); //��ֵʶ���� show the thresholded image
		imshow("Original", imgOriginal); //ԭͼ show the original image
		char key = (char)waitKey(1);
		if (key == 27)
			break;
	}

	return 0;

	}