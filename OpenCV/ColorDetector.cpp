#include "ColorDetector.h"

#define RGB 1
//#define CIEL*a*b* 0
//������ɫ������ֵ
void ColorDetector::setColorDistanceThreshold(int distance)
{
	if (distance < 0)
		distance = 0;
	maxDist = distance;
}
#ifdef RGB
//��RGBģʽ��������Ҫ������ɫ
void ColorDetector::setTargetColor(cv::Vec3b color)
{
	target = color;
}
void ColorDetector::setTargetColor(uchar blue, uchar green, uchar red)
{
	target = cv::Vec3b(blue, green, red);
}
#else
//��CIEL*a*b*ģʽ��������Ҫ������ɫ
void ColorDetector::setTargetColor(uchar blue, uchar green, uchar red)
{
	//��ʱ�ĵ�����ͼ��
	cv::Mat tmp(1, 1, CV_8UC3);
	tmp.at<cv::Vec3b>(0, 0) = cv::Vec3b(blue, green, red);
	//��Ŀ����ɫת����Labɫ�ʿռ�
	cv::cvtColor(tmp, tmp, CV_BGR2Lab);
	target = tmp.at<cv::Vec3b>(0, 0);
}
#endif
//������Ŀ����ɫ�Ĳ��
int  ColorDetector::getDistanceToTargetColor(const cv::Vec3b& color) const
{
	return getColorDistance(color, target);
}

//����������ɫ֮��ĳ�������
int ColorDetector::getColorDistance(const cv::Vec3b& color1, const cv::Vec3b& color2) const
{
	return abs(color1[0]-color2[0]) + abs(color1[0]-color2[0]) + abs(color1[0]-color2[0]);
}


#ifdef RGB
//ʹ��RGB�ĳ��������ж���ɫ
cv::Mat ColorDetector::process(const cv::Mat &image)
{
	result.create(image.size(), CV_8U);
	//ȡ�õ�����
	cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
	cv::Mat_<uchar>::iterator itout = result.begin<uchar>();
	//��ÿ��Ԫ��
	for ( ; it != itend; ++it, ++itout) {
		//�Ƚ���Ŀ����ɫ�Ĳ��
		if (getDistanceToTargetColor(*it) <= maxDist) {
			*itout = 255;
		}
		else {
			*itout = 0;
		}
	}
	return result;
}
#else
//���ش�����
cv::Mat ColorDetector::process(const cv::Mat &image)
{
	//��Ҫʱ���·����ֵͼ��
	//������ͼ��ĳߴ���ͬ����ʹ�õ�ͨ��
	result.create(image.rows, image.cols, CV_8U);
	//ת����Labɫ�ʿռ�
	cv::cvtColor(image, converted, CV_BGR2Lab);
	//ȡ��ת��ͼ��ĵ�����
	cv::Mat_<cv::Vec3b>::iterator it = converted.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::iterator itend = converted.end<cv::Vec3b>();
	//ȡ�����ͼ��ĵ�����
	cv::Mat_<uchar>::iterator itout = result.begin<uchar>();

	for ( ; it != itend; ++it, ++itout) {
		//�Ƚ���Ŀ����ɫ�Ĳ��
		if (getDistanceToTargetColor(*it) <= maxDist) {
			*itout = 255;
		}
		else {
			*itout = 0;
		}
	}
	
	return result;
}
#endif
ColorDetector::~ColorDetector(void)
{
}


