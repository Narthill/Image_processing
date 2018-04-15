#include<iostream>
#include<opencv2/opencv.hpp>  
#include"opencv2/stitching/stitcher.hpp"
#include"ImageProcessing.h"

using namespace std;
using namespace cv;



//���캯��colorHandle
ImageProcessing::ImageProcessing(Mat &Img) {
	srcImg = Img;
}



/* ��ɫ�ռ�����-�ҶȻ�-��ֵ�� */
//cutColor��������������ɫ�ռ�  --right--
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
	//�õ���ɫ�ռ��������ͼ��
	return dstImg;
}
//rgb2gray�������ڽ�rgbͼ��ת��Ϊ�Ҷ�ͼ��  --right--
Mat ImageProcessing::rgb2gray()
{
	if (srcImg.channels() == 3) {
		cv::cvtColor(srcImg, srcImg, CV_RGB2GRAY);
	}
	//�õ��ҶȻ�֮���ͼ
	cv::cvtColor(srcImg, srcImg, CV_GRAY2RGB);

	return srcImg;
}
//rgb2black�������ڽ�rgbͼ��ת���ڰ�ͼ��  --right--
Mat ImageProcessing::rgb2black(int num)
{
	int threNum = num;
	cv::cvtColor(srcImg, srcImg, CV_RGB2GRAY);
	threshold(srcImg, srcImg, threNum, 255, THRESH_BINARY);
	//�õ���ֵ��֮���ͼ��
	cv::cvtColor(srcImg, srcImg, CV_GRAY2RGB);
	return srcImg;
}
/* ��ɫ�ռ�����-�ҶȻ�-��ֵ�� */



/* ����-�����ԻҶȱ任 */
//linearGrayScaleTransformation�������ڽ������ԻҶȱ任��ʹ��ʱ��Ҫ���������������ڵ���contrastValue(�Աȶ�)/brightValue(����)  --no-- srcImg��ΪdstImg
Mat ImageProcessing::linearGrayScaleTransformation(int contrastValue, int brightValue) {
	//��������
	//Mat srcImgClone = srcImg.clone();
	//srcImgClone = Mat::zeros(srcImg.size(), srcImg.type());
	// ����forѭ����ִ������ g_dstImage(i,j) = a*g_srcImage(i,j) + b 
	//ʵ�ֲ�ɫͼ������ԻҶȱ任

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
	Mat dstImg = srcImg.clone();
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
		p = dstImg.ptr<uchar>(i);
		for (j = 0; j<nCols; j++) {
			p[j] = table[p[j]];
		}
	}
	return dstImg;
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
//powerLawlinearGrayScaleTransformation�������ڽ��з�����-���ɻҶȱ任��ʹ��ʱ��Ҫ���볣��k  --right--
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
/* ����-�����ԻҶȱ任 */



/* �ռ��˲���� */
//blurFilter�������ڽ��о�ֵ�˲�����  --right--
Mat ImageProcessing::blurFilter(int width, int height) {
	blur(srcImg, filterResImage, Size(width, height), Point(-1, -1), BORDER_DEFAULT);
	return filterResImage;
}
//gaussianBlurFilter�������ڽ��и�˹�˲�����  --right--
Mat ImageProcessing::gaussianBlurFilter(int width, int height,int sigmaX,int sigmaY) {
	GaussianBlur(srcImg, filterResImage, Size(width, height), sigmaX, sigmaY, BORDER_DEFAULT);
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
/* �ռ��˲���� */



/* DCT�任 */
//dctTransformation�������ڽ���dct�任����  --right--
vector<Mat> ImageProcessing::dctTransformation(double T) {

	//�жϳ������ż�����ԭͼ��
	Mat src = srcImg.clone();
	if (src.rows % 2 != 0 || src.cols %2  != 0) {
		copyMakeBorder(src, src, 0, src.rows % 2, 0, src.cols % 2, BORDER_CONSTANT, Scalar::all(0));
	}
	int h = src.rows;
	int w = src.cols;
	//��BGR�ռ�ת����YUV�ռ�     
	//YUV�ռ�ͼ��yuvimg  
	Mat yuvimg(src.size(), CV_8UC3); 
	cvtColor(src, yuvimg, CV_BGR2YUV);
	//���ͼ��Ϊdst   
	Mat dst(src.size(), CV_8UC3);

	//YUVͨ������    
	vector<Mat> channels(3);
	split(yuvimg, channels);

	//��ȡYUV��ɫ�ռ��ͨ��      
	Mat_<double>Y = channels.at(0);
	Mat_<double>U = channels.at(1);
	Mat_<double>V = channels.at(2);

	//����ͨ����Ƶ��    
	Mat DCTY(src.size(), CV_64FC1);
	Mat DCTU(src.size(), CV_64FC1);
	Mat DCTV(src.size(), CV_64FC1);

	//��ɢ���ұ任
	Rect box;//����һ��8*8�������ڷֿ�
	box.height = 8;
	box.width = 8;
	for (int i = 0; i<(w / 8); i++)
	{
		for (int j = 0; j<(h / 8); j++)
		{
			//����ͷ����(����ʼ����)
			box.x = 8 * i;//���ϽǺ�����
			box.y = 8 * j;//���Ͻ�������
						  //���þ����С(���С)

						  //��ͨ���ڷֿ��С�½�����ɢ���ұ任
			dct(Y(box), DCTY(box));
			dct(U(box), DCTU(box));
			dct(V(box), DCTV(box));
		}
	}

	//��ʾƵ��
	//imshow("YƵ��", DCTY);
	//imshow("UƵ��", DCTU);
	//imshow("VƵ��", DCTV);

	//������ͨ��Ƶ�ף��趨��ֵ����ѹ��
	for (int m = 0; m < h; m++)
	{
		double *y = DCTY.ptr<double>(m);
		double *u = DCTU.ptr<double>(m);
		double *v = DCTV.ptr<double>(m);//����ָ���ͨ��ָ��
		for (int n = 0; n < w; n++)
		{
			if (abs(y[n]) < T) { y[n] = 0; }
			if (abs(u[n]) < T) { u[n] = 0; }
			if (abs(v[n]) < T) { v[n] = 0; }//����ֵС����ֵ�͸�ֵΪ0
		}
	}
	vector<Mat> allimg;//���д���ͼƬ�������������
	allimg.push_back(ShowDctSpectrum(DCTY.clone()));
	allimg.push_back(ShowDctSpectrum(DCTU.clone()));
	allimg.push_back(ShowDctSpectrum(DCTV.clone()));

	//��任
	for (int i = 0; i<(w / 8); i++)
	{
		for (int j = 0; j<(h / 8); j++)
		{
			//����ͷ����(����ʼ����)
			box.x = 8 * i;//���ϽǺ�����
			box.y = 8 * j;//���Ͻ�������
						  //��ͨ���ڷֿ��С�½�����任
			idct(DCTY(box), Y(box));
			idct(DCTU(box), U(box));
			idct(DCTV(box), V(box));
		}
	}

	//ͨ�����
	channels.at(0) = Mat_<uchar>(Y);
	channels.at(1) = Mat_<uchar>(U);
	channels.at(2) = Mat_<uchar>(V);
	merge(channels, yuvimg);//ͨ�����
	
							//ѹ����ͼ���YUV�ռ�����ת����BGR�ռ�    
	cvtColor(yuvimg, dst, CV_YUV2BGR);

	allimg.push_back(dst);

	return allimg;
}
Mat ImageProcessing::ShowDctSpectrum(Mat input) {
	for (int i = 0; i<input.rows; i++)//��������255
	{
		uchar *ptr = input.ptr<uchar>(i);
		for (int j = 0; j < input.cols*8; j++)
			ptr[j] *= 255;
	}
	input.convertTo(input, CV_8UC1);
	return input;
}
/* DCT�任 */



/* Ƶ���˲���� */
//dftTransformation�������ڶ�ͼ�������ɢ����Ҷ�任����
Mat ImageProcessing::dftTransformation() {
	Mat img = srcImg;
	cvtColor(img, img, CV_RGB2GRAY);
	//�жϲ���չͼ��
	int h = getOptimalDFTSize(img.rows);//��ȡԭͼ��
	int w = getOptimalDFTSize(img.cols);//��ȡԭͼ��
	Mat img_pad; // ��չ���ͼ��
	if (w > img.cols || h > img.rows)
		copyMakeBorder(img, img_pad, 0, h - img.rows, 0, w - img.cols, BORDER_CONSTANT, Scalar::all(0));
	else {
		img.copyTo(img_pad);
	}

	//�׵����Ļ�
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

	dft(complexImg, complexImg);//��ɢ����Ҷ�任

	//ShowSpectrum(complexImg, "ԭͼ����ҶƵ��");

	return complexImg;
}
//ShowSpectrum����������ʾdft�任���Ƶ��ͼ
Mat ImageProcessing::ShowSpectrum(Mat input) {
	Mat plane[2];
	split(input, plane);
	magnitude(plane[0], plane[1], plane[0]);
	plane[0] += Scalar::all(1);
	log(plane[0], plane[0]);
	normalize(plane[0], plane[0], 0, 1, CV_MINMAX);

	for (int i = 0; i<plane[0].rows; i++)//��������255
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
//ShowImage�������ڽ����и�/��ͨ�˲������Ƶ��ͼ��ת��Ϊ�ܹ�������ʾ��ͼ��
Mat ImageProcessing::ShowImage(Mat input) {
	Mat plane[2];
	split(input, plane);
	for (int i = 0; i<plane[0].rows; i++)
	{
		float *ptr = plane[0].ptr<float>(i);
		for (int j = 0; j < plane[0].cols; j++)
			ptr[j] *= pow(-1, i + j);
	}
	normalize(plane[0], plane[0], 0, 1, CV_MINMAX);//��һ��

	for (int i = 0; i<plane[0].rows; i++)//��������255
	{
		float *ptr = plane[0].ptr<float>(i);
		for (int j = 0; j < plane[0].cols; j++)
			ptr[j] *= 255;
	}
	Mat tmp = plane[0];
	plane[0].convertTo(tmp, CV_8UC1);
	
	return tmp;
}
//���ظ�˹�ˣ�flagΪ�ߵ�ͨ��ʶ
Mat ImageProcessing::gausKernel(Mat &dftImg, float d0, bool flag) {
	Mat GaussianHighLowFilter = dftImg.clone();

	Mat GaussianKernel(GaussianHighLowFilter.size(), CV_32FC2);//��˹�˲���ģ��
	float D0 = 2 * pow(double(d0), 2.0);//d0��ƽ��
	for (int i = 0; i < GaussianHighLowFilter.rows; i++) {
		float*p = GaussianKernel.ptr<float>(i);
		for (int j = 0; j < GaussianHighLowFilter.cols; j++) {
			float d2 = pow(i - GaussianHighLowFilter.rows / 2, 2.0) + pow(j - GaussianHighLowFilter.cols / 2, 2.0);//��u��v�������ĵ����
			if (flag) {//��ͨ
				p[2 * j] = expf(-d2 / D0);
				p[2 * j + 1] = expf(-d2 / D0);
			}
			else {//��ͨ
				p[2 * j] = 1 - expf(-d2 / D0);
				p[2 * j + 1] = 1 - expf(-d2 / D0);
			}
		}
	}

	return GaussianKernel;
}
//���������˲���
Mat ImageProcessing::IdealKernel(Mat &dftImg, float d0, bool flag) {
	Mat IdealHighLowFilter = dftImg.clone();
	Mat IdealKernel(IdealHighLowFilter.size(), CV_32FC2);//�����˲���ģ��
	for (int i = 0; i < IdealHighLowFilter.rows; i++) {
		float*p = IdealKernel.ptr<float>(i);
		for (int j = 0; j < IdealHighLowFilter.cols; j++) {
			float d = sqrt(pow(i - IdealHighLowFilter.rows / 2, 2.0) + pow(j - IdealHighLowFilter.cols / 2, 2.0));//��u��v�������ĵ����
			if (flag) {//��ͨ
				if (d <= d0) {
					//С��d0�Ķ�Ϊ1
					p[2 * j] = 1;
					p[2 * j + 1] = 1;
				}
				else {
					//����d0�Ķ�Ϊ0
					p[2 * j] = 0;
					p[2 * j + 1] = 0;
				}

			}
			else {//��ͨ
				if (d <= d0) {
					//С��d0�Ķ�Ϊ0
					p[2 * j] = 0;
					p[2 * j + 1] = 0;
				}
				else {
					//����d0�Ķ�Ϊ1
					p[2 * j] = 1;
					p[2 * j + 1] = 1;
				}
			}
		}
	}

	return IdealKernel;
}
//���ذ�����˹��
Mat ImageProcessing::ButterworthKernel(Mat &dftImg, float d0,int n, bool flag) {
	Mat ButterworthHighLowFilter = dftImg.clone();
	Mat ButterworthKernel(ButterworthHighLowFilter.size(), CV_32FC2);//������˹�˲���ģ��
	for (int i = 0; i < ButterworthHighLowFilter.rows; i++) {
		float*p = ButterworthKernel.ptr<float>(i);
		for (int j = 0; j < ButterworthHighLowFilter.cols; j++) {
			float d = sqrt(pow(i - ButterworthHighLowFilter.rows / 2, 2.0) + pow(j - ButterworthHighLowFilter.cols / 2, 2.0));//��u��v�������ĵ����
			if (flag) {//��ͨ
				p[2 * j] = 1.0 / (1 + pow((d / d0), 2 * n));
				p[2 * j + 1] = 1.0 / (1 + pow((d / d0), 2 * n));
			}
			else {//��ͨ
				p[2 * j] = 1 - (1.0 / (1 + pow((d / d0), 2 * n)));
				p[2 * j + 1] = 1 - (1.0 / (1 + pow((d / d0), 2 * n)));
			}
		}
	}
	return ButterworthKernel;
}
//���ؾ������
Mat ImageProcessing::dftMultiply(Mat &dftImg, Mat &kernel) {
	Mat outImage;
	multiply(dftImg, kernel, outImage);//ģ���븵��Ҷ�任��ͼ��������
	return outImage;
}
//���ڽ��и���Ҷ��任
Mat ImageProcessing::idftTransformation(Mat &outImage) {
	idft(outImage, outImage);//��任
	outImage = ShowImage(outImage);//ת��Ϊ����ͼ��
	cv::cvtColor(outImage, outImage, CV_GRAY2RGB);
	return outImage;
}




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

	//imshow("rֱ��ͼ", rChannelsRes);
	//waitKey(2000);

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

	//imshow("gֱ��ͼ", gChannelsRes);
	//waitKey(2000);

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

	//imshow("bֱ��ͼ", bChannelsRes);
	//waitKey(2000);

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



/* ��Ե��� */
Mat ImageProcessing::edgeDetection(int w,int b,int s,int kSize) {
	Mat dstImg = srcImg.clone();
	GaussianBlur(srcImg, dstImg, Size(w, w), 0, 0, BORDER_DEFAULT);
	Canny(dstImg, dstImg, b, s, kSize);
	cv::cvtColor(dstImg, dstImg, CV_GRAY2RGB);
	return dstImg;
}
/* ��Ե��� */