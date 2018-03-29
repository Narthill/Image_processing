#include<iostream>
#include<opencv2/opencv.hpp>  
#include"opencv2/stitching/stitcher.hpp"
#include"ImageProcessing.h"

using namespace std;
using namespace cv;



//构造函数colorHandle
ImageProcessing::ImageProcessing(Mat Img) {
	//this->filename = fname;
	srcImg = Img;
}



/* 颜色空间缩减-灰度化-二值化 */
//cutColor函数用于缩减颜色空间  --right--
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
	//得到颜色空间缩减后的图像
	return srcImg;
}
//rgb2gray函数用于将rgb图像转换为灰度图像  --right--
Mat ImageProcessing::rgb2gray()
{
	cv::cvtColor(srcImg, srcImg, CV_RGB2GRAY);
	//得到灰度化之后的图
	return srcImg;
}
//rgb2black函数用于将rgb图像转换黑白图像  --right--
Mat ImageProcessing::rgb2black()
{
	cv::cvtColor(srcImg, srcImg, CV_RGB2GRAY);
	threshold(srcImg, srcImg, 100, 255, THRESH_BINARY);
	//得到二值化之后的图像
	return srcImg;
}
/* 颜色空间缩减-灰度化-二值化 */



/* 线性-非线性灰度变换 */
//linearGrayScaleTransformation函数用于进行线性灰度变换，使用时需要传入两个参数用于调整contrastValue(对比度)/brightValue(亮度)  --right--
Mat ImageProcessing::linearGrayScaleTransformation(int contrastValue, int brightValue) {
	//创建窗口
	//Mat srcImgClone = srcImg.clone();
	//srcImgClone = Mat::zeros(srcImg.size(), srcImg.type());
	// 三个for循环，执行运算 g_dstImage(i,j) = a*g_srcImage(i,j) + b 
	//实现彩色图像的线性灰度变换
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
//pieceWiselinearGrayScaleTransformation函数用于进行分段线性灰度变换，使用时需要传入两个点的坐标共四个参数用于进行调整  --right--
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

	double intercept_1, intercept_2, intercept_3; //斜率

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
//loglinearGrayScaleTransformation函数用于进行非线性-对数灰度变换，使用时需要传入常数c  --right--
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
//powerLawlinearGrayScaleTransformation函数用于进行非线性-幂律灰度变换，使用时需要传入常数k  --right--
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
/* 线性-非线性灰度变换 */



/* 滤波器 */
//blurFilter函数用于进行均值滤波处理  --right--
Mat ImageProcessing::blurFilter(int width, int height) {
	blur(srcImg, filterResImage, Size(width, height), Point(-1, -1), BORDER_DEFAULT);
	return filterResImage;
}
//gaussianBlurFilter函数用于进行高斯滤波处理  --right--
Mat ImageProcessing::gaussianBlurFilter(int width, int height) {
	GaussianBlur(srcImg, filterResImage, Size(width, height), 0, 0, BORDER_DEFAULT);
	return filterResImage;
}
//medianBlurFilter函数用于进行中值滤波处理，使用时需传入常数kSize作为滤波模板的尺寸大小，必须是大于1的奇数  --right--
Mat ImageProcessing::medianBlurFilter(int kSize) {
	medianBlur(srcImg, filterResImage, kSize);
	return filterResImage;
}
//fil2DLapLace函数用于进行拉普拉斯滤波处理  --right--
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
/* 滤波器 */



/* DCT变换 */
//dctTransformation函数用于进行dct变换处理  --right--
Mat ImageProcessing::dctTransformation(double t) {

	double T;
	T = t;
	int h = srcImg.rows;
	int w = srcImg.cols;
	if (srcImg.rows % 2 != 0 || srcImg.cols % 2 != 0) {
		copyMakeBorder(srcImg, srcImg, 0, srcImg.rows % 2, 0, srcImg.cols % 2, BORDER_CONSTANT, Scalar::all(0));
	}

	//从BGR空间转换到YUV空间     
	Mat yuvimg(srcImg.size(), CV_8UC3);
	//定义YUV空间图像yuvimg
	cvtColor(srcImg, yuvimg, CV_BGR2YUV); 
	//定义输出图像为dst
	Mat dst(srcImg.size(), CV_8UC3);        				    
	vector<Mat> channels(3);
	//YUV通道分离
	split(yuvimg, channels);
	//提取YUV颜色空间各通道      
	Mat_<double>Y = channels.at(0);
	Mat_<double>U = channels.at(1);
	Mat_<double>V = channels.at(2);
	//DCT系数的三个通道    
	Mat DCTY(srcImg.size(), CV_64FC1);
	Mat DCTU(srcImg.size(), CV_64FC1);
	Mat DCTV(srcImg.size(), CV_64FC1);
	//DCT变换    
	dct(Y, DCTY);
	dct(U, DCTU);
	dct(V, DCTV);
	//三通道，作阈值处理，进行压缩      
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
	//DCT逆变换    
	idct(DCTY, Y);
	idct(DCTU, U);
	idct(DCTV, V);
	channels.at(0) = Mat_<uchar>(Y);
	channels.at(1) = Mat_<uchar>(U);
	channels.at(2) = Mat_<uchar>(V);
	merge(channels, yuvimg);
	//将压缩后图像从YUV空间重新转换到BGR空间    
	cvtColor(yuvimg, dst, CV_YUV2BGR);
	return dst;
}
/* DCT变换 */



/* 图像拼接 */  
//motage函数用于进行图像拼接，使用时需要传入四张图片的文件名  --pause--
Mat ImageProcessing::montage(string picName1, string picName2, string picName3, string picName4) {

	bool try_use_gpu = false;
	vector<Mat> imgs;
	string resultName = "result.jpg";

	Mat img1, img2, img3, img4;
	//push_back是算法里面的一个函数名。在vector类中作用为在vector尾部加入一个数据。
	img1 = imread(picName1, 1);
	imgs.push_back(img1);
	img2 = imread(picName2, 1);
	imgs.push_back(img2);
	img3 = imread(picName3, 1);
	imgs.push_back(img3);
	img4 = imread(picName4, 1);
	imgs.push_back(img4);

	Mat pano;
	//调用createDefault函数生成默认的参数
	Stitcher stitcher = Stitcher::createDefault(try_use_gpu);
	//使用stitcher函数进行拼接
	Stitcher::Status status = stitcher.stitch(imgs, pano);

	if (status != Stitcher::OK)
	{
		cout << "Can't stitch images, error code = " << int(status) << endl;
	}

	//保存结果图像
	imshow("resImg", pano);

	return pano;

	imwrite(resultName, pano);
}
/* 图像拼接 */



/* 直方图显示 */
//picHistogramRChannelShow函数用于建立图像的r通道直方图并进行显示  --right--
Mat ImageProcessing::picHistogramRChannelShow() {
	//Mat srcImg = imread(filename, CV_LOAD_IMAGE_COLOR);
	//src是要分离通道的对象
	vector<Mat> allChannels(srcImg.channels());

	split(srcImg, allChannels);

	//计算直方图calcHist()

	r_Channel = allChannels[2];

	MatND dstHist_0;
	int dims = 1;	//直方图的维数
	float hranges[] = { 0,255 };
	const float* ranges[] = { hranges };	//所需直方图的每一维的范围
	int size = 256;		//在每一维上直方图的个数
	int channels = 0;		//用来计算直方图的channels的数组
	calcHist(&r_Channel, 1, &channels, Mat(), dstHist_0, dims, &size, ranges);

	//绘制直方图minMaxLoc()
	int scale = 1;
	Mat rChannelsRes(size, size* scale, CV_8UC3, Scalar(0));

	//获取最大值和最小值
	double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist_0, &minValue, &maxValue, 0, 0);

	//绘制出直方图
	int hpt = saturate_cast<int>(0.9*size);
	for (int i = 0; i<256; i++) {
		float binValue = dstHist_0.at<float>(i);
		int realValue = saturate_cast<int>(binValue*hpt / maxValue);
		rectangle(rChannelsRes, Point(i*scale, size - 1), Point((i + 1)*scale - 1, size - realValue), Scalar(0, 0, 255));
	}

	rChannelsSave = rChannelsRes;

	imshow("r直方图", rChannelsRes);
	waitKey(2000);

	return rChannelsRes;
}
//picHistogramGChannelShow函数用于建立图像的g通道直方图并进行显示  --right--
Mat ImageProcessing::picHistogramGChannelShow() {
	//Mat srcImg = imread(filename, CV_LOAD_IMAGE_COLOR);
	//src是要分离通道的对象
	vector<Mat> allChannels(srcImg.channels());

	split(srcImg, allChannels);

	//计算直方图calcHist()

	g_Channel = allChannels[1];

	MatND dstHist_0;
	int dims = 1;	//直方图的维数
	float hranges[] = { 0,255 };
	const float* ranges[] = { hranges };	//所需直方图的每一维的范围
	int size = 256;		//在每一维上直方图的个数
	int channels = 0;		//用来计算直方图的channels的数组
	calcHist(&g_Channel, 1, &channels, Mat(), dstHist_0, dims, &size, ranges);

	//绘制直方图minMaxLoc()
	int scale = 1;
	Mat gChannelsRes(size, size* scale, CV_8UC3, Scalar(0));

	//获取最大值和最小值
	double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist_0, &minValue, &maxValue, 0, 0);

	//绘制出直方图
	int hpt = saturate_cast<int>(0.9*size);
	for (int i = 0; i<256; i++) {
		float binValue = dstHist_0.at<float>(i);
		int realValue = saturate_cast<int>(binValue*hpt / maxValue);
		rectangle(gChannelsRes, Point(i*scale, size - 1), Point((i + 1)*scale - 1, size - realValue), Scalar(0, 255, 0));
	}

	gChannelsSave = gChannelsRes;

	imshow("g直方图", gChannelsRes);
	waitKey(2000);

	return gChannelsRes;
}
//picHistogramBChannelShow函数用于建立图像的b通道直方图并进行显示  --right--
Mat ImageProcessing::picHistogramBChannelShow() {
	//Mat srcImg = imread(filename, CV_LOAD_IMAGE_COLOR);
	//src是要分离通道的对象
	vector<Mat> allChannels(srcImg.channels());

	split(srcImg, allChannels);

	//计算直方图calcHist()

	b_Channel = allChannels[0];

	MatND dstHist_0;
	int dims = 1;	//直方图的维数
	float hranges[] = { 0,255 };
	const float* ranges[] = { hranges };	//所需直方图的每一维的范围
	int size = 256;		//在每一维上直方图的个数
	int channels = 0;		//用来计算直方图的channels的数组
	calcHist(&b_Channel, 1, &channels, Mat(), dstHist_0, dims, &size, ranges);

	//绘制直方图minMaxLoc()
	int scale = 1;
	Mat bChannelsRes(size, size* scale, CV_8UC3, Scalar(0));

	//获取最大值和最小值
	double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist_0, &minValue, &maxValue, 0, 0);

	//绘制出直方图
	int hpt = saturate_cast<int>(0.9*size);
	for (int i = 0; i<256; i++) {
		float binValue = dstHist_0.at<float>(i);
		int realValue = saturate_cast<int>(binValue*hpt / maxValue);
		rectangle(bChannelsRes, Point(i*scale, size - 1), Point((i + 1)*scale - 1, size - realValue), Scalar(255, 0, 0));
	}

	bChannelsSave = bChannelsRes;

	imshow("b直方图", bChannelsRes);
	waitKey(2000);

	return bChannelsRes;
}
//picSrcChannelsSave函数存储三个通道的直方图
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
/* 直方图显示 */