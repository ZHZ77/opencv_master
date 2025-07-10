#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;
/*
	imread(string params)
	imshow(win_name, img)
	waitKey(0)
	destroyAllWindows()
*/

void ImageThreshold(string str)
{
	Mat image = imread(str, IMREAD_GRAYSCALE);
	if (image.empty())
	{
		cout << "¶ÁÈ¡Í¼ÏñÊ§°Ü£¡" << endl;
	}
	//namedWindow("ÊäÈë´°¿Ú", WINDOW_FREERATIO);
	imshow("ÊäÈë´°¿Ú", image);
	waitKey(0);
	destroyAllWindows();
	
}

int main01()
{
	string str = "../data/lenna_img.png";
	ImageThreshold(str);
	return 0;
}
