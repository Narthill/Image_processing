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
	Mat linearGrayScaleTransformation(int contrastValue, int brightValue);//����
	Mat pieceWiselinearGrayScaleTransformation(double X_1, double Y_1, double X_2, double Y_2);//�ֶ�
	Mat loglinearGrayScaleTransformation(int c);//����
	Mat powerLawlinearGrayScaleTransformation(double index);//����
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
	Mat dftTransformation();//dft�任
	Mat ShowSpectrum(Mat input);//����Ƶ��ͼ
	Mat ShowImage(Mat input);//�任��ͼ������
	Mat gausKernel(Mat &dftImg, float d0, bool flag);//���ظ�˹�ˣ�flagΪ�ߵ�ͨ
	Mat IdealKernel(Mat &dftImg, float d0, bool flag);//���������˲���
	Mat ButterworthKernel(Mat &dftImg, float d0,int n,bool flag);//���ذ�����˹��
	Mat dftMultiply(Mat &dftImg, Mat &kernel);//����dft�������
	Mat idftTransformation(Mat &outImage);//�渵��Ҷ�任
	/* DFT TRANSFORMATION */

	/* PICTURE MONTAGE */
	Mat montage(string picName1, string picName2, string picName3, string picName4);
	/* PICTURE MONTAGE */

	Mat edgeDetection(int w,int b, int s, int kSize);
};
/* ImageProcessing  funtion*/

#endif