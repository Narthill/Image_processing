#ifndef ImageProcessing_H
#define ImageProcessing_H

#include<opencv2/opencv.hpp>
using namespace cv;

/* ImageProcessing  funtion*/
class ImageProcessing {
private:
	String filename;
	Mat srcImg;
	Mat	filterResImage;
	int channels;
	int nRows;
	int nCols;
	Mat r_Channel;
	Mat g_Channel;
	Mat b_Channel;
	Mat rChannelsRes;
	Mat gChannelsRes;
	Mat bChannelsRes;
	Mat rChannelsSave;
	Mat gChannelsSave;
	Mat bChannelsSave;
public:
	ImageProcessing(Mat srcImg);
	
	/* COLOR HANDLE FUNCTION */
	Mat cutColor();
	Mat rgb2gray();
	Mat rgb2black(int num);
	/* COLOR HANDLE FUNCTION */

	/* GRAY SCALE TRANSFORMATION */
	Mat linearGrayScaleTransformation(int contrastValue, int brightValue);//线性
	Mat pieceWiselinearGrayScaleTransformation(double X_1, double Y_1, double X_2, double Y_2);//分段
	Mat loglinearGrayScaleTransformation(int c);//对数
	Mat powerLawlinearGrayScaleTransformation(int k);//幂率
	/* GRAY SCALE TRANSFORMATION */

	/* HISTOGRAM */
	Mat picHistogramRChannelShow();
	Mat picHistogramGChannelShow();
	Mat picHistogramBChannelShow();
	Mat picSrcChannelsSave();
	/* HISTOGRAM */

	/* FILTER */
	Mat blurFilter(int width, int height);
	Mat gaussianBlurFilter(int width, int height);
	Mat medianBlurFilter(int kSize);
	Mat fil2DLaplace(int lapSize);
	/* FILTER */

	/* DCT TRANSFORMATION */
	Mat dctTransformation(double t);
	/* DCT TRANSFORMATION */

	/* PICTURE MONTAGE */
	Mat montage(string picName1, string picName2, string picName3, string picName4);
	/* PICTURE MONTAGE */

};
/* ImageProcessing  funtion*/

#endif