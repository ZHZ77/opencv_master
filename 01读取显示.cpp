#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;



int main01()
{
	
	string path = "./data/lenna_img.png";
	Mat img = imread(path, IMREAD_GRAYSCALE);

	namedWindow("img_show", WINDOW_FREERATIO);
	imshow("img_show", img);
	waitKey(0);
	destroyAllWindows();

	system("pause");
	return 0;
}