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
	//vector<Mat> getAllChannels;
public:
	ImageProcessing(Mat &srcImg);
	
	/* COLOR HANDLE FUNCTION */
	Mat cutColor(int n);
	Mat rgb2gray();
	Mat rgb2black(int num);
	/* COLOR HANDLE FUNCTION */

	/* GRAY SCALE TRANSFORMATION */
	Mat linearGrayScaleTransformation(int contrastValue, int brightValue);//线性
	Mat pieceWiselinearGrayScaleTransformation(double X_1, double Y_1, double X_2, double Y_2);//分段
	Mat loglinearGrayScaleTransformation(int c);//对数
	Mat powerLawlinearGrayScaleTransformation(double index);//幂率
	/* GRAY SCALE TRANSFORMATION */

	/* HISTOGRAM */
	Mat picHistogramRChannelShow();
	Mat picHistogramGChannelShow();
	Mat picHistogramBChannelShow();
	Mat picSrcChannelsSave();
	/* HISTOGRAM */

	/* FILTER */
	Mat blurFilter(int width, int height);
	Mat gaussianBlurFilter(int width, int height, int sigmaX, int sigmaY);
	Mat medianBlurFilter(int kSize);
	Mat fil2DLaplace(int lapSize);
	/* FILTER */

	/* DCT TRANSFORMATION */
	Mat ShowDctSpectrum(Mat input);
	vector<Mat> dctTransformation(double t);
	/* DCT TRANSFORMATION */

	/* DFT TRANSFORMATION */
	Mat dftTransformation();//dft变换
	Mat ShowSpectrum(Mat input);//生成频谱图
	Mat ShowImage(Mat input);//变换后图像生成
	Mat gausKernel(Mat &dftImg, float d0, bool flag);//返回高斯核，flag为高低通
	Mat IdealKernel(Mat &dftImg, float d0, bool flag);//返回理想滤波核
	Mat ButterworthKernel(Mat &dftImg, float d0,int n,bool flag);//返回巴特沃斯核
	Mat dftMultiply(Mat &dftImg, Mat &kernel);//核与dft矩阵相乘
	Mat idftTransformation(Mat &outImage);//逆傅里叶变换
	/* DFT TRANSFORMATION */

	/* PICTURE MONTAGE */
	Mat montage(string picName1, string picName2, string picName3, string picName4);
	/* PICTURE MONTAGE */

	Mat edgeDetection(int w,int b, int s, int kSize);
};
/* ImageProcessing  funtion*/

#endif