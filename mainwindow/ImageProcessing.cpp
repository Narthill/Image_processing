#include<iostream>
#include<opencv2/opencv.hpp>  
#include"opencv2/stitching/stitcher.hpp"
#include"ImageProcessing.h"

using namespace std;
using namespace cv;



//构造函数colorHandle
ImageProcessing::ImageProcessing(Mat &Img) {
	srcImg = Img;
}



/* 颜色空间缩减-灰度化-二值化 */
//cutColor函数用于缩减颜色空间  --right--
Mat ImageProcessing::cutColor(int n)
{
	int channels = srcImg.channels();
	int nRows = srcImg.rows;
	int nCols = srcImg.cols* channels;
	if (srcImg.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}
	Mat dstImg= srcImg.clone();
	int i, j;
	for (i = 0; i<nRows; ++i) {
		for (j = 0; j<nCols; ++j) {
			int value = srcImg.ptr(i)[j];
			dstImg.ptr(i)[j] = n * (value / n);
		}
	}
	//得到颜色空间缩减后的图像
	return dstImg;
}
//rgb2gray函数用于将rgb图像转换为灰度图像  --right--
Mat ImageProcessing::rgb2gray()
{
	if (srcImg.channels() == 3) {
		cv::cvtColor(srcImg, srcImg, CV_RGB2GRAY);
	}
	//得到灰度化之后的图
	cv::cvtColor(srcImg, srcImg, CV_GRAY2RGB);

	return srcImg;
}
//rgb2black函数用于将rgb图像转换黑白图像  --right--
Mat ImageProcessing::rgb2black(int num)
{
	int threNum = num;
	cv::cvtColor(srcImg, srcImg, CV_RGB2GRAY);
	threshold(srcImg, srcImg, threNum, 255, THRESH_BINARY);
	//得到二值化之后的图像
	cv::cvtColor(srcImg, srcImg, CV_GRAY2RGB);
	return srcImg;
}
/* 颜色空间缩减-灰度化-二值化 */



/* 线性-非线性灰度变换 */
//linearGrayScaleTransformation函数用于进行线性灰度变换，使用时需要传入两个参数用于调整contrastValue(对比度)/brightValue(亮度)  --no-- srcImg改为dstImg
Mat ImageProcessing::linearGrayScaleTransformation(int contrastValue, int brightValue) {
	//创建窗口
	//Mat srcImgClone = srcImg.clone();
	//srcImgClone = Mat::zeros(srcImg.size(), srcImg.type());
	// 三个for循环，执行运算 g_dstImage(i,j) = a*g_srcImage(i,j) + b 
	//实现彩色图像的线性灰度变换

	//if (contrastValue == 0) {
	//	contrastValue = 1;
	//}
	//if (brightValue == 0) {
	//	brightValue = 1;
	//}

	Mat dstImg = srcImg.clone();

	for (int x = 0; x < srcImg.rows; x++)
	{
		for (int y = 0; y < srcImg.cols; y++)
		{
			for (int c = 0; c < 3; c++)
			{
				dstImg.at<Vec3b>(x, y)[c] = saturate_cast<uchar>((contrastValue*0.01)*(srcImg.at<Vec3b>(x, y)[c]) + brightValue);
			}
		}
	}
	return dstImg;
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
	Mat dstImg = srcImg.clone();
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
		p = dstImg.ptr<uchar>(i);
		for (j = 0; j<nCols; j++) {
			p[j] = table[p[j]];
		}
	}
	return dstImg;
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
	Mat dstImg = srcImg.clone();
	double g = 0;
	for (int x = 0; x < nRows; x++) {
		for (int y = 0; y < nCols; y++) {
			g = srcImg.ptr(x)[y];
			g = c*log((double)(1 + g));
			dstImg.ptr(x)[y] = g;
		}
	}

	return dstImg;
}
//powerLawlinearGrayScaleTransformation函数用于进行非线性-幂律灰度变换，使用时需要传入常数k  --right--
Mat ImageProcessing::powerLawlinearGrayScaleTransformation(double index) {
	int channels = srcImg.channels();
	int nRows = srcImg.rows;
	int nCols = srcImg.cols* channels;
	if (srcImg.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}
	Mat dstImg = srcImg.clone();
	uchar* p;
	double g = 0;
	for (int x = 0; x < nRows; x++) {
		for (int y = 0; y < nCols; y++) {
			g = srcImg.ptr(x)[y];
			g = saturate_cast<uchar>(pow((double)g/255., index)*255.0f);
			dstImg.ptr(x)[y] = g;
		}
	}
	return dstImg;
}
/* 线性-非线性灰度变换 */



/* 空间滤波相关 */
//blurFilter函数用于进行均值滤波处理  --right--
Mat ImageProcessing::blurFilter(int width, int height) {
	blur(srcImg, filterResImage, Size(width, height), Point(-1, -1), BORDER_DEFAULT);
	return filterResImage;
}
//gaussianBlurFilter函数用于进行高斯滤波处理  --right--
Mat ImageProcessing::gaussianBlurFilter(int width, int height,int sigmaX,int sigmaY) {
	GaussianBlur(srcImg, filterResImage, Size(width, height), sigmaX, sigmaY, BORDER_DEFAULT);
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
/* 空间滤波相关 */



/* DCT变换 */
//dctTransformation函数用于进行dct变换处理  --right--
vector<Mat> ImageProcessing::dctTransformation(double T) {

	//判断长宽的奇偶并填充原图像
	Mat src = srcImg.clone();
	if (src.rows % 2 != 0 || src.cols %2  != 0) {
		copyMakeBorder(src, src, 0, src.rows % 2, 0, src.cols % 2, BORDER_CONSTANT, Scalar::all(0));
	}
	int h = src.rows;
	int w = src.cols;
	//从BGR空间转换到YUV空间     
	//YUV空间图像yuvimg  
	Mat yuvimg(src.size(), CV_8UC3); 
	cvtColor(src, yuvimg, CV_BGR2YUV);
	//输出图像为dst   
	Mat dst(src.size(), CV_8UC3);

	//YUV通道分离    
	vector<Mat> channels(3);
	split(yuvimg, channels);

	//提取YUV颜色空间各通道      
	Mat_<double>Y = channels.at(0);
	Mat_<double>U = channels.at(1);
	Mat_<double>V = channels.at(2);

	//三个通道的频谱    
	Mat DCTY(src.size(), CV_64FC1);
	Mat DCTU(src.size(), CV_64FC1);
	Mat DCTV(src.size(), CV_64FC1);

	//离散余弦变换
	Rect box;//设置一个8*8矩阵，用于分块
	box.height = 8;
	box.width = 8;
	for (int i = 0; i<(w / 8); i++)
	{
		for (int j = 0; j<(h / 8); j++)
		{
			//矩阵头坐标(块起始坐标)
			box.x = 8 * i;//左上角横坐标
			box.y = 8 * j;//左上角纵坐标
						  //设置矩阵大小(块大小)

						  //各通道在分块大小下进行离散余弦变换
			dct(Y(box), DCTY(box));
			dct(U(box), DCTU(box));
			dct(V(box), DCTV(box));
		}
	}

	//显示频谱
	//imshow("Y频谱", DCTY);
	//imshow("U频谱", DCTU);
	//imshow("V频谱", DCTV);

	//遍历各通道频谱，设定阈值用以压缩
	for (int m = 0; m < h; m++)
	{
		double *y = DCTY.ptr<double>(m);
		double *u = DCTU.ptr<double>(m);
		double *v = DCTV.ptr<double>(m);//定义指向各通道指针
		for (int n = 0; n < w; n++)
		{
			if (abs(y[n]) < T) { y[n] = 0; }
			if (abs(u[n]) < T) { u[n] = 0; }
			if (abs(v[n]) < T) { v[n] = 0; }//绝对值小于阈值就赋值为0
		}
	}
	vector<Mat> allimg;//所有传出图片放在这个向量中
	allimg.push_back(ShowDctSpectrum(DCTY.clone()));
	allimg.push_back(ShowDctSpectrum(DCTU.clone()));
	allimg.push_back(ShowDctSpectrum(DCTV.clone()));

	//逆变换
	for (int i = 0; i<(w / 8); i++)
	{
		for (int j = 0; j<(h / 8); j++)
		{
			//矩阵头坐标(块起始坐标)
			box.x = 8 * i;//左上角横坐标
			box.y = 8 * j;//左上角纵坐标
						  //各通道在分块大小下进行逆变换
			idct(DCTY(box), Y(box));
			idct(DCTU(box), U(box));
			idct(DCTV(box), V(box));
		}
	}

	//通道组合
	channels.at(0) = Mat_<uchar>(Y);
	channels.at(1) = Mat_<uchar>(U);
	channels.at(2) = Mat_<uchar>(V);
	merge(channels, yuvimg);//通道组合
	
							//压缩后图像从YUV空间重新转换到BGR空间    
	cvtColor(yuvimg, dst, CV_YUV2BGR);

	allimg.push_back(dst);

	return allimg;
}
Mat ImageProcessing::ShowDctSpectrum(Mat input) {
	for (int i = 0; i<input.rows; i++)//遍历乘以255
	{
		uchar *ptr = input.ptr<uchar>(i);
		for (int j = 0; j < input.cols*8; j++)
			ptr[j] *= 255;
	}
	input.convertTo(input, CV_8UC1);
	return input;
}
/* DCT变换 */



/* 频域滤波相关 */
//dftTransformation函数用于对图像进行离散傅里叶变换处理
Mat ImageProcessing::dftTransformation() {
	Mat img = srcImg;
	cvtColor(img, img, CV_RGB2GRAY);
	//判断并拓展图像
	int h = getOptimalDFTSize(img.rows);//获取原图长
	int w = getOptimalDFTSize(img.cols);//获取原图宽
	Mat img_pad; // 拓展后的图像
	if (w > img.cols || h > img.rows)
		copyMakeBorder(img, img_pad, 0, h - img.rows, 0, w - img.cols, BORDER_CONSTANT, Scalar::all(0));
	else {
		img.copyTo(img_pad);
	}

	//谱的中心化
	img_pad.convertTo(img_pad, CV_32FC1);
	for (int i = 0; i<img_pad.rows; i++)
	{
		float *ptr = img_pad.ptr<float>(i);
		for (int j = 0; j < img_pad.cols; j++)
			ptr[j] *= pow(-1.0, i + j);
	}
	Mat plane[] = { img_pad, Mat::zeros(img_pad.size(), CV_32F) };
	Mat complexImg;
	merge(plane, 2, complexImg);

	dft(complexImg, complexImg);//离散傅里叶变换

	//ShowSpectrum(complexImg, "原图傅里叶频谱");

	return complexImg;
}
//ShowSpectrum函数用于显示dft变换后的频谱图
Mat ImageProcessing::ShowSpectrum(Mat input) {
	Mat plane[2];
	split(input, plane);
	magnitude(plane[0], plane[1], plane[0]);
	plane[0] += Scalar::all(1);
	log(plane[0], plane[0]);
	normalize(plane[0], plane[0], 0, 1, CV_MINMAX);

	for (int i = 0; i<plane[0].rows; i++)//遍历乘以255
	{
		float *ptr = plane[0].ptr<float>(i);
		for (int j = 0; j < plane[0].cols; j++)
			ptr[j] *= 255;
	}
	Mat tmp = plane[0];
	plane[0].convertTo(tmp, CV_8UC1);
	//cvNamedWindow(caption.c_str(), CV_WINDOW_AUTOSIZE);
	//imshow(caption.c_str(), plane[0]);
	return tmp;
}
//ShowImage函数用于将进行高/低通滤波过后的频域图像转换为能够正常显示的图像
Mat ImageProcessing::ShowImage(Mat input) {
	Mat plane[2];
	split(input, plane);
	for (int i = 0; i<plane[0].rows; i++)
	{
		float *ptr = plane[0].ptr<float>(i);
		for (int j = 0; j < plane[0].cols; j++)
			ptr[j] *= pow(-1, i + j);
	}
	normalize(plane[0], plane[0], 0, 1, CV_MINMAX);//归一化

	for (int i = 0; i<plane[0].rows; i++)//遍历乘以255
	{
		float *ptr = plane[0].ptr<float>(i);
		for (int j = 0; j < plane[0].cols; j++)
			ptr[j] *= 255;
	}
	Mat tmp = plane[0];
	plane[0].convertTo(tmp, CV_8UC1);
	
	return tmp;
}
//返回高斯核，flag为高低通标识
Mat ImageProcessing::gausKernel(Mat &dftImg, float d0, bool flag) {
	Mat GaussianHighLowFilter = dftImg.clone();

	Mat GaussianKernel(GaussianHighLowFilter.size(), CV_32FC2);//高斯滤波器模板
	float D0 = 2 * pow(double(d0), 2.0);//d0的平方
	for (int i = 0; i < GaussianHighLowFilter.rows; i++) {
		float*p = GaussianKernel.ptr<float>(i);
		for (int j = 0; j < GaussianHighLowFilter.cols; j++) {
			float d2 = pow(i - GaussianHighLowFilter.rows / 2, 2.0) + pow(j - GaussianHighLowFilter.cols / 2, 2.0);//（u，v）离中心点距离
			if (flag) {//低通
				p[2 * j] = expf(-d2 / D0);
				p[2 * j + 1] = expf(-d2 / D0);
			}
			else {//高通
				p[2 * j] = 1 - expf(-d2 / D0);
				p[2 * j + 1] = 1 - expf(-d2 / D0);
			}
		}
	}

	return GaussianKernel;
}
//返回理想滤波核
Mat ImageProcessing::IdealKernel(Mat &dftImg, float d0, bool flag) {
	Mat IdealHighLowFilter = dftImg.clone();
	Mat IdealKernel(IdealHighLowFilter.size(), CV_32FC2);//理想滤波器模板
	for (int i = 0; i < IdealHighLowFilter.rows; i++) {
		float*p = IdealKernel.ptr<float>(i);
		for (int j = 0; j < IdealHighLowFilter.cols; j++) {
			float d = sqrt(pow(i - IdealHighLowFilter.rows / 2, 2.0) + pow(j - IdealHighLowFilter.cols / 2, 2.0));//（u，v）离中心点距离
			if (flag) {//低通
				if (d <= d0) {
					//小于d0的都为1
					p[2 * j] = 1;
					p[2 * j + 1] = 1;
				}
				else {
					//大于d0的都为0
					p[2 * j] = 0;
					p[2 * j + 1] = 0;
				}

			}
			else {//高通
				if (d <= d0) {
					//小于d0的都为0
					p[2 * j] = 0;
					p[2 * j + 1] = 0;
				}
				else {
					//大于d0的都为1
					p[2 * j] = 1;
					p[2 * j + 1] = 1;
				}
			}
		}
	}

	return IdealKernel;
}
//返回巴特沃斯核
Mat ImageProcessing::ButterworthKernel(Mat &dftImg, float d0,int n, bool flag) {
	Mat ButterworthHighLowFilter = dftImg.clone();
	Mat ButterworthKernel(ButterworthHighLowFilter.size(), CV_32FC2);//巴特沃斯滤波器模板
	for (int i = 0; i < ButterworthHighLowFilter.rows; i++) {
		float*p = ButterworthKernel.ptr<float>(i);
		for (int j = 0; j < ButterworthHighLowFilter.cols; j++) {
			float d = sqrt(pow(i - ButterworthHighLowFilter.rows / 2, 2.0) + pow(j - ButterworthHighLowFilter.cols / 2, 2.0));//（u，v）离中心点距离
			if (flag) {//低通
				p[2 * j] = 1.0 / (1 + pow((d / d0), 2 * n));
				p[2 * j + 1] = 1.0 / (1 + pow((d / d0), 2 * n));
			}
			else {//高通
				p[2 * j] = 1 - (1.0 / (1 + pow((d / d0), 2 * n)));
				p[2 * j + 1] = 1 - (1.0 / (1 + pow((d / d0), 2 * n)));
			}
		}
	}
	return ButterworthKernel;
}
//返回矩阵相乘
Mat ImageProcessing::dftMultiply(Mat &dftImg, Mat &kernel) {
	Mat outImage;
	multiply(dftImg, kernel, outImage);//模板与傅里叶变换后图像矩阵相乘
	return outImage;
}
//用于进行傅里叶逆变换
Mat ImageProcessing::idftTransformation(Mat &outImage) {
	idft(outImage, outImage);//逆变换
	outImage = ShowImage(outImage);//转换为可视图像
	cv::cvtColor(outImage, outImage, CV_GRAY2RGB);
	return outImage;
}




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

	//imshow("r直方图", rChannelsRes);
	//waitKey(2000);

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

	//imshow("g直方图", gChannelsRes);
	//waitKey(2000);

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

	//imshow("b直方图", bChannelsRes);
	//waitKey(2000);

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



/* 边缘检测 */
Mat ImageProcessing::edgeDetection(int w,int b,int s,int kSize) {
	Mat dstImg = srcImg.clone();
	GaussianBlur(srcImg, dstImg, Size(w, w), 0, 0, BORDER_DEFAULT);
	Canny(dstImg, dstImg, b, s, kSize);
	cv::cvtColor(dstImg, dstImg, CV_GRAY2RGB);
	return dstImg;
}
/* 边缘检测 */