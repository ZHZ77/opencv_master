
#include "quickdemo.h"

void QuickDemo::colorSpace_Demo(Mat& image)
{
	Mat gray, hsv;

	cvtColor(image, gray, COLOR_BGR2GRAY);
	cvtColor(image, hsv, COLOR_BGR2HSV);
	imshow("GRAY", gray);
	imshow("HSV", hsv);
	imwrite("./data/gray.png", gray);
	imwrite("./data/hsv.png", hsv);

}

void QuickDemo::creation_demo(Mat& image)
{

	Mat m1, m2;
	m1 = image.clone();
	image.copyTo(m2);

	// �����հ�ͼ��
	Mat m3 = Mat::zeros(Size(8, 8), CV_8UC1);
	std::cout << "width:" << m3.cols << "height:" << m3.rows << "channels:" << m3.channels() << std::endl;
	std::cout << m3 << std::endl;


}


void QuickDemo::pixel_visit_demo(Mat& image)
{
	// ��ɫ
	int w = image.cols;
	int h = image.rows;
	int dims = image.channels();

	//for (int row = 0; row < h; row++)
	//{
	//	for (int col = 0; col < w; col++)
	//	{
	//		if (dims == 1)
	//		{
	//			// �Ҷ�ͼ��
	//			int pv = image.at<uchar>(row, col);
	//			image.at<uchar>(row, col) = 255 - pv;
	//		}
	//		if (dims == 3)
	//		{
	//			// ��ɫͼ��
	//			Vec3b bgr = image.at<Vec3b>(row, col);
	//			image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
	//			image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
	//			image.at<Vec3b>(row, col)[2] = 255 - bgr[2];

	//		}
	//	}
	//}


	for (int row = 0; row < h; row++)
	{
		uchar* current_row = image.ptr<uchar>(row);
		for (int col = 0; col < w; col++)
		{
			if (dims == 1)
			{
				// �Ҷ�ͼ��
				int pv = *current_row;
				*current_row++ = 255 - pv;
			}
			if (dims == 3)
			{
				// ��ɫͼ��
				int pv = *current_row;
				*current_row++ = 255 - pv;
				*current_row++ = 255 - pv;
				*current_row++ = 255 - pv;

			}
		}
	}



	//imshow("���ض�д��ʾ", image);

}


void QuickDemo::operators_demo(Mat& image)
{
	Mat dst;
	dst = image + Scalar(30, 30, 30);
	imshow("�ӷ�����", dst);

}


static void on_track(int b, void* userdata)
{
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	addWeighted(image, 1.0, m, 0, b, dst);
	imshow("������Աȶȵ���", dst);
}

static void on_contrast(int b, void* userdata)
{
	Mat image = *((Mat*)userdata);
	Mat dst = Mat::zeros(image.size(), image.type());
	Mat m = Mat::zeros(image.size(), image.type());
	double contrast = b / 100.0;
	addWeighted(image, contrast, m, 0.0, 0, dst);
	imshow("������Աȶȵ���", dst);
}

void QuickDemo::tracking_bar_demo(Mat& image)
{
	namedWindow("������Աȶȵ���", WINDOW_AUTOSIZE);

	int lightness = 50;
	int max_value = 100;
	int contrast_value = 100;

	
	createTrackbar("Value Bar:", "������Աȶȵ���", &lightness, max_value, on_track,(void*)(&image));
	createTrackbar("Contrast Bar:", "������Աȶȵ���", &contrast_value, 200, on_contrast,(void*)(&image));
	
	
	//on_track(50, &image);



}
