// 文件名：02色彩空间转换
// 创建时间：2025/7/10 18:02:01

#include <iostream>
#include <opencv2/opencv.hpp>
#include "quickdemo.h"

using namespace std;

/*
	
*/

int main()
{
	Mat img = imread("./data/len.jpg");
	if (!img.empty())
	{
		imshow("原图", img);
	}
	QuickDemo qd;
	//qd.colorSpace_Demo(img);
	//qd.creation_demo(img);
	//qd.pixel_visit_demo(img);
	//qd.operators_demo(img);
	qd.tracking_bar_demo(img);




	waitKey(0);
	destroyAllWindows();

	system("pause");
	return 0;
}
