//读写像素pexil以及修改像素值(单通道，3通道)
#include<opencv2/opencv.hpp>
#include<iostream>
#include<opencv2\imgproc\types_c.h>
using namespace std;
using namespace cv;

int main()
{
	Mat src,gray_src;
	src = imread("F:/image/1.2.png");
	if (!src.data)
	{
		printf("can not load the picture");
		return - 1;
	}
	namedWindow("input",WINDOW_AUTOSIZE);
	imshow("input",src);

	//单通道修改像素
	cvtColor(src, gray_src, CV_BGR2GRAY);
	/*namedWindow("gray", WINDOW_AUTOSIZE);
	imshow("gray", gray_src);*/
	Mat dst;
	dst.create(src.size(), src.type());
	int count = src.channels();
	int cols = gray_src.cols;
	int rows = gray_src.rows;
	//printf("cols=%d\nrows=%d\n", cols, rows);
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (count == 1)
			{
				int gray = gray_src.at<uchar>(row, col);
				gray_src.at<uchar>(row, col) = 255 - gray;
			}
			else if (count == 3)
			{
				int b = src.at<Vec3b>(row, col)[0];//0表示第一通道
				int g = src.at<Vec3b>(row, col)[1];
				int r = src.at<Vec3b>(row, col)[2];
				dst.at<Vec3b>(row, col)[0]=255-b;
				dst.at<Vec3b>(row, col)[0] = 255 - g;
				dst.at<Vec3b>(row, col)[0] = 255 - r;
			}
			//printf("%d ",gray);
		}
		//printf("\n");
	}
	namedWindow("output", WINDOW_AUTOSIZE);
	imshow("output",dst);
	waitKey();
	return 0;
}