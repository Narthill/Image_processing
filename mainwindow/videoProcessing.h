#pragma once

#include <QMainWindow>
#include<QtCore\qtimer.h>
#include<QtGui\qpixmap.h>
#include<opencv2/opencv.hpp>
#include <QFileDialog>
#include <QMetaType>  
#include"Mat2QImage.h"
#pragma execution_character_set("utf-8")

using namespace cv;
Q_DECLARE_METATYPE(cv::Mat);//注册宏
namespace Ui { class videoProcessing; };

class videoProcessing : public QMainWindow
{
	Q_OBJECT

public:
	videoProcessing(QWidget *parent = Q_NULLPTR);
	~videoProcessing();

	void uiItemClose();
	void uiItemOpen();
public slots:
	void openVideo();
	void save();
	void saveAs();
	void playVideo();
	void pauseVideo();
	void sliderReleased();
	void videoTime();
	void showFristFrame();
	
	void video_Gary();
	void video_Histogram();

	void video_BinarySolt();
	void video_BinaryShow(int n);
	void video_BinaryCore(int n);

	void video_CutColorSolt();
	void video_CutColorShow(int n);
	void video_CutColorCore(int n);

	void video_SobelSolt();
	void video_SobelShow(int w, int b, int s, int kSize);
	void video_SobelCore(int w, int b, int s, int kSize);

	void video_SpaceFilterSolt();
	void video_SpaceFilterShow(Mat);
	void video_SpaceFilterBlur(int width, int height);
	void video_SpaceFilterGauss(int width, int height, int sigmaX, int sigmaY);
	void video_SpaceFilterMedian(int ksize);
	void video_SpaceFilterLaplace(int ksize);

signals:
	void closeVideo();
private:
	Ui::videoProcessing *ui;
	QTimer *time_clock;
	QString fileName;
	QImage img;
	VideoCapture capture;
	vector<Mat> videoQueue;
	vector<Mat> dstVideoQueue;

	long totalFrameNumber;
	long nowFrameIndex;
	Mat nowframe;

	int fps;//帧率
	int secondEachFrame;//每帧时间 毫秒

	int videoWidth;
	int videoHeight;
	int fourcc;//四字符代码

	//关闭事件
	void closeEvent(QCloseEvent * event);
};
