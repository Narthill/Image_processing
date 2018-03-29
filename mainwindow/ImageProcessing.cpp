#include<iostream>
#include<opencv2/opencv.hpp>  
#include"opencv2/stitching/stitcher.hpp"
#include"ImageProcessing.h"

using namespace std;
using namespace cv;



//���캯��colorHandle
ImageProcessing::ImageProcessing(Mat Img) {
	//this->filename = fname;
	srcImg = Img;
}



/* ��ɫ�ռ�����-�ҶȻ�-��ֵ�� */
//cutColor��������������ɫ�ռ�  --right--
Mat ImageProcessing::cutColor()
{
	int channels = srcImg.channels();
	int nRows = srcImg.rows;
	int nCols = srcImg.cols* channels;
	if (srcImg.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}

	int i, j;
	for (i = 0; i<nRows; ++i) {
		for (j = 0; j<nCols; ++j) {
			int value = srcImg.ptr(i)[j];
			srcImg.ptr(i)[j] = 50 * (value / 50);
		}
	}
	//�õ���ɫ�ռ��������ͼ��
	return srcImg;
}
//rgb2gray�������ڽ�rgbͼ��ת��Ϊ�Ҷ�ͼ��  --right--
Mat ImageProcessing::rgb2gray()
{
	cv::cvtColor(srcImg, srcImg, CV_RGB2GRAY);
	//�õ��ҶȻ�֮���ͼ
	return srcImg;
}
//rgb2black�������ڽ�rgbͼ��ת���ڰ�ͼ��  --right--
Mat ImageProcessing::rgb2black()
{
	cv::cvtColor(srcImg, srcImg, CV_RGB2GRAY);
	threshold(srcImg, srcImg, 100, 255, THRESH_BINARY);
	//�õ���ֵ��֮���ͼ��
	return srcImg;
}
/* ��ɫ�ռ�����-�ҶȻ�-��ֵ�� */



/* ����-�����ԻҶȱ任 */
//linearGrayScaleTransformation�������ڽ������ԻҶȱ任��ʹ��ʱ��Ҫ���������������ڵ���contrastValue(�Աȶ�)/brightValue(����)  --right--
Mat ImageProcessing::linearGrayScaleTransformation(int contrastValue, int brightValue) {
	//��������
	//Mat srcImgClone = srcImg.clone();
	//srcImgClone = Mat::zeros(srcImg.size(), srcImg.type());
	// ����forѭ����ִ������ g_dstImage(i,j) = a*g_srcImage(i,j) + b 
	//ʵ�ֲ�ɫͼ������ԻҶȱ任
	for (int x = 0; x < srcImg.rows; x++)
	{
		for (int y = 0; y < srcImg.cols; y++)
		{
			for (int c = 0; c < 3; c++)
			{
				srcImg.at<Vec3b>(x, y)[c] = saturate_cast<uchar>((contrastValue*0.01)*(srcImg.at<Vec3b>(x, y)[c]) + brightValue);
			}
		}
	}
	return srcImg;
}
//pieceWiselinearGrayScaleTransformation�������ڽ��зֶ����ԻҶȱ任��ʹ��ʱ��Ҫ��������������깲�ĸ��������ڽ��е���  --right--
Mat ImageProcessing::pieceWiselinearGrayScaleTransformation(double X_1, double Y_1, double X_2, double Y_2) {
	int channels = srcImg.channels();
	int nRows = srcImg.rows;
	int nCols = srcImg.cols* channels;
	if (srcImg.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}
	uchar* p;
	int i, j;

	double intercept_1, intercept_2, intercept_3; //б��

	intercept_1 = (Y_1 / X_1);
	intercept_2 = (Y_2 - Y_1) / (X_2 - X_1);
	intercept_3 = (255 - Y_2) / (255 - X_2);

	uchar table[256];
	for (int k = 0; k<X_1; k++) {
		table[k] = intercept_1 * k;
	}
	for (int k = X_1; k<X_2; k++) {
		table[k] = intercept_2 * (k - X_1) + Y_1;
	}
	for (int k = X_2; k<256; k++) {
		table[k] = intercept_3 * (k - X_2) + Y_2;
	}

	for (i = 0; i<nRows; i++) {
		p = srcImg.ptr<uchar>(i);
		for (j = 0; j<nCols; j++) {
			p[j] = table[p[j]];
		}
	}
	return srcImg;
}
//loglinearGrayScaleTransformation�������ڽ��з�����-�����Ҷȱ任��ʹ��ʱ��Ҫ���볣��c  --right--
Mat ImageProcessing::loglinearGrayScaleTransformation(int c) {
	//uchar* p;
	int channels = srcImg.channels();
	int nRows = srcImg.rows;
	int nCols = srcImg.cols* channels;
	if (srcImg.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}

	double g = 0;
	for (int x = 0; x < nRows; x++) {
		for (int y = 0; y < nCols; y++) {
			g = srcImg.ptr(x)[y];
			g = c*log((double)(1 + g));
			srcImg.ptr(x)[y] = g;
		}
	}

	imshow("1",srcImg);

	return srcImg;
}
//powerLawlinearGrayScaleTransformation�������ڽ��з�����-���ɻҶȱ任��ʹ��ʱ��Ҫ���볣��k  --right--
Mat ImageProcessing::powerLawlinearGrayScaleTransformation(int k) {
	int channels = srcImg.channels();
	int nRows = srcImg.rows;
	int nCols = srcImg.cols* channels;
	if (srcImg.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}

	uchar* p;
	double g = 0;
	for (int x = 0; x < nRows; x++) {
		for (int y = 0; y < nCols; y++) {
			g = srcImg.ptr(x)[y];
			g = k*saturate_cast<uchar>(pow((double)g, 1.5));
			srcImg.ptr(x)[y] = g;
		}
	}
	return srcImg;
}
/* ����-�����ԻҶȱ任 */



/* �˲��� */
//blurFilter�������ڽ��о�ֵ�˲�����  --right--
Mat ImageProcessing::blurFilter(int width, int height) {
	blur(srcImg, filterResImage, Size(width, height), Point(-1, -1), BORDER_DEFAULT);
	return filterResImage;
}
//gaussianBlurFilter�������ڽ��и�˹�˲�����  --right--
Mat ImageProcessing::gaussianBlurFilter(int width, int height) {
	GaussianBlur(srcImg, filterResImage, Size(width, height), 0, 0, BORDER_DEFAULT);
	return filterResImage;
}
//medianBlurFilter�������ڽ�����ֵ�˲�����ʹ��ʱ�贫�볣��kSize��Ϊ�˲�ģ��ĳߴ��С�������Ǵ���1������  --right--
Mat ImageProcessing::medianBlurFilter(int kSize) {
	medianBlur(srcImg, filterResImage, kSize);
	return filterResImage;
}
//fil2DLapLace�������ڽ���������˹�˲�����  --right--
Mat ImageProcessing::fil2DLaplace(int lapSize) {
	int laplace_Size = lapSize;
	if (laplace_Size % 2 == 0) {
		laplace_Size = laplace_Size + 1;
	}

	Mat kernel(laplace_Size, laplace_Size, CV_32FC1);
	for (int m = 0; m < laplace_Size*laplace_Size; m++) {
		if (m == ((laplace_Size*laplace_Size) / 2 + 1)) {
			kernel.at<float>(m) = -(laplace_Size*laplace_Size);
		}
		else {
			kernel.at<float>(m) = 1;
		}
	}
	filter2D(srcImg, filterResImage, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
	return filterResImage;
}
/* �˲��� */



/* DCT�任 */
//dctTransformation�������ڽ���dct�任����  --right--
Mat ImageProcessing::dctTransformation(double t) {

	double T;
	T = t;
	int h = srcImg.rows;
	int w = srcImg.cols;
	if (srcImg.rows % 2 != 0 || srcImg.cols % 2 != 0) {
		copyMakeBorder(srcImg, srcImg, 0, srcImg.rows % 2, 0, srcImg.cols % 2, BORDER_CONSTANT, Scalar::all(0));
	}

	//��BGR�ռ�ת����YUV�ռ�     
	Mat yuvimg(srcImg.size(), CV_8UC3);
	//����YUV�ռ�ͼ��yuvimg
	cvtColor(srcImg, yuvimg, CV_BGR2YUV); 
	//�������ͼ��Ϊdst
	Mat dst(srcImg.size(), CV_8UC3);        				    
	vector<Mat> channels(3);
	//YUVͨ������
	split(yuvimg, channels);
	//��ȡYUV��ɫ�ռ��ͨ��      
	Mat_<double>Y = channels.at(0);
	Mat_<double>U = channels.at(1);
	Mat_<double>V = channels.at(2);
	//DCTϵ��������ͨ��    
	Mat DCTY(srcImg.size(), CV_64FC1);
	Mat DCTU(srcImg.size(), CV_64FC1);
	Mat DCTV(srcImg.size(), CV_64FC1);
	//DCT�任    
	dct(Y, DCTY);
	dct(U, DCTU);
	dct(V, DCTV);
	//��ͨ��������ֵ��������ѹ��      
	for (int i = 0; i < h; i++)
	{
		double *y = DCTY.ptr<double>(i);
		double *u = DCTU.ptr<double>(i);
		double *v = DCTV.ptr<double>(i);
		for (int j = 0; j < w; j++)
		{
			if (abs(y[j]) < T) { y[j] = 0; }
			if (abs(u[j]) < T) { u[j] = 0; }
			if (abs(v[j]) < T) { v[j] = 0; }

		}
	}
	//DCT��任    
	idct(DCTY, Y);
	idct(DCTU, U);
	idct(DCTV, V);
	channels.at(0) = Mat_<uchar>(Y);
	channels.at(1) = Mat_<uchar>(U);
	channels.at(2) = Mat_<uchar>(V);
	merge(channels, yuvimg);
	//��ѹ����ͼ���YUV�ռ�����ת����BGR�ռ�    
	cvtColor(yuvimg, dst, CV_YUV2BGR);
	return dst;
}
/* DCT�任 */



/* ͼ��ƴ�� */  
//motage�������ڽ���ͼ��ƴ�ӣ�ʹ��ʱ��Ҫ��������ͼƬ���ļ���  --pause--
Mat ImageProcessing::montage(string picName1, string picName2, string picName3, string picName4) {

	bool try_use_gpu = false;
	vector<Mat> imgs;
	string resultName = "result.jpg";

	Mat img1, img2, img3, img4;
	//push_back���㷨�����һ������������vector��������Ϊ��vectorβ������һ�����ݡ�
	img1 = imread(picName1, 1);
	imgs.push_back(img1);
	img2 = imread(picName2, 1);
	imgs.push_back(img2);
	img3 = imread(picName3, 1);
	imgs.push_back(img3);
	img4 = imread(picName4, 1);
	imgs.push_back(img4);

	Mat pano;
	//����createDefault��������Ĭ�ϵĲ���
	Stitcher stitcher = Stitcher::createDefault(try_use_gpu);
	//ʹ��stitcher��������ƴ��
	Stitcher::Status status = stitcher.stitch(imgs, pano);

	if (status != Stitcher::OK)
	{
		cout << "Can't stitch images, error code = " << int(status) << endl;
	}

	//������ͼ��
	imshow("resImg", pano);

	return pano;

	imwrite(resultName, pano);
}
/* ͼ��ƴ�� */



/* ֱ��ͼ��ʾ */
//picHistogramRChannelShow�������ڽ���ͼ���rͨ��ֱ��ͼ��������ʾ  --right--
Mat ImageProcessing::picHistogramRChannelShow() {
	//Mat srcImg = imread(filename, CV_LOAD_IMAGE_COLOR);
	//src��Ҫ����ͨ���Ķ���
	vector<Mat> allChannels(srcImg.channels());

	split(srcImg, allChannels);

	//����ֱ��ͼcalcHist()

	r_Channel = allChannels[2];

	MatND dstHist_0;
	int dims = 1;	//ֱ��ͼ��ά��
	float hranges[] = { 0,255 };
	const float* ranges[] = { hranges };	//����ֱ��ͼ��ÿһά�ķ�Χ
	int size = 256;		//��ÿһά��ֱ��ͼ�ĸ���
	int channels = 0;		//��������ֱ��ͼ��channels������
	calcHist(&r_Channel, 1, &channels, Mat(), dstHist_0, dims, &size, ranges);

	//����ֱ��ͼminMaxLoc()
	int scale = 1;
	Mat rChannelsRes(size, size* scale, CV_8UC3, Scalar(0));

	//��ȡ���ֵ����Сֵ
	double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist_0, &minValue, &maxValue, 0, 0);

	//���Ƴ�ֱ��ͼ
	int hpt = saturate_cast<int>(0.9*size);
	for (int i = 0; i<256; i++) {
		float binValue = dstHist_0.at<float>(i);
		int realValue = saturate_cast<int>(binValue*hpt / maxValue);
		rectangle(rChannelsRes, Point(i*scale, size - 1), Point((i + 1)*scale - 1, size - realValue), Scalar(0, 0, 255));
	}

	rChannelsSave = rChannelsRes;

	imshow("rֱ��ͼ", rChannelsRes);
	waitKey(2000);

	return rChannelsRes;
}
//picHistogramGChannelShow�������ڽ���ͼ���gͨ��ֱ��ͼ��������ʾ  --right--
Mat ImageProcessing::picHistogramGChannelShow() {
	//Mat srcImg = imread(filename, CV_LOAD_IMAGE_COLOR);
	//src��Ҫ����ͨ���Ķ���
	vector<Mat> allChannels(srcImg.channels());

	split(srcImg, allChannels);

	//����ֱ��ͼcalcHist()

	g_Channel = allChannels[1];

	MatND dstHist_0;
	int dims = 1;	//ֱ��ͼ��ά��
	float hranges[] = { 0,255 };
	const float* ranges[] = { hranges };	//����ֱ��ͼ��ÿһά�ķ�Χ
	int size = 256;		//��ÿһά��ֱ��ͼ�ĸ���
	int channels = 0;		//��������ֱ��ͼ��channels������
	calcHist(&g_Channel, 1, &channels, Mat(), dstHist_0, dims, &size, ranges);

	//����ֱ��ͼminMaxLoc()
	int scale = 1;
	Mat gChannelsRes(size, size* scale, CV_8UC3, Scalar(0));

	//��ȡ���ֵ����Сֵ
	double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist_0, &minValue, &maxValue, 0, 0);

	//���Ƴ�ֱ��ͼ
	int hpt = saturate_cast<int>(0.9*size);
	for (int i = 0; i<256; i++) {
		float binValue = dstHist_0.at<float>(i);
		int realValue = saturate_cast<int>(binValue*hpt / maxValue);
		rectangle(gChannelsRes, Point(i*scale, size - 1), Point((i + 1)*scale - 1, size - realValue), Scalar(0, 255, 0));
	}

	gChannelsSave = gChannelsRes;

	imshow("gֱ��ͼ", gChannelsRes);
	waitKey(2000);

	return gChannelsRes;
}
//picHistogramBChannelShow�������ڽ���ͼ���bͨ��ֱ��ͼ��������ʾ  --right--
Mat ImageProcessing::picHistogramBChannelShow() {
	//Mat srcImg = imread(filename, CV_LOAD_IMAGE_COLOR);
	//src��Ҫ����ͨ���Ķ���
	vector<Mat> allChannels(srcImg.channels());

	split(srcImg, allChannels);

	//����ֱ��ͼcalcHist()

	b_Channel = allChannels[0];

	MatND dstHist_0;
	int dims = 1;	//ֱ��ͼ��ά��
	float hranges[] = { 0,255 };
	const float* ranges[] = { hranges };	//����ֱ��ͼ��ÿһά�ķ�Χ
	int size = 256;		//��ÿһά��ֱ��ͼ�ĸ���
	int channels = 0;		//��������ֱ��ͼ��channels������
	calcHist(&b_Channel, 1, &channels, Mat(), dstHist_0, dims, &size, ranges);

	//����ֱ��ͼminMaxLoc()
	int scale = 1;
	Mat bChannelsRes(size, size* scale, CV_8UC3, Scalar(0));

	//��ȡ���ֵ����Сֵ
	double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist_0, &minValue, &maxValue, 0, 0);

	//���Ƴ�ֱ��ͼ
	int hpt = saturate_cast<int>(0.9*size);
	for (int i = 0; i<256; i++) {
		float binValue = dstHist_0.at<float>(i);
		int realValue = saturate_cast<int>(binValue*hpt / maxValue);
		rectangle(bChannelsRes, Point(i*scale, size - 1), Point((i + 1)*scale - 1, size - realValue), Scalar(255, 0, 0));
	}

	bChannelsSave = bChannelsRes;

	imshow("bֱ��ͼ", bChannelsRes);
	waitKey(2000);

	return bChannelsRes;
}
//picSrcChannelsSave�����洢����ͨ����ֱ��ͼ
Mat ImageProcessing::picSrcChannelsSave() {

	vector<Mat> getAllChannels(srcImg.channels());

	split(srcImg, getAllChannels);

	r_Channel = getAllChannels[0];
	g_Channel = getAllChannels[1];
	b_Channel = getAllChannels[2];

	equalizeHist(r_Channel, r_Channel);
	equalizeHist(g_Channel, g_Channel);
	equalizeHist(b_Channel, b_Channel);

	Mat channelsMerge;
	merge(getAllChannels, channelsMerge);

	return channelsMerge;
}
/* ֱ��ͼ��ʾ */