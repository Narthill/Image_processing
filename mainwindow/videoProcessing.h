#pragma once

#include <QMainWindow>
#include<QtCore\qtimer.h>
#include<QtGui\qpixmap.h>
#include<opencv2/opencv.hpp>
#include <QFileDialog>
#include"Mat2QImage.h"

#pragma execution_character_set("utf-8")
using namespace cv;

namespace Ui { class videoProcessing; };

class videoProcessing : public QMainWindow
{
	Q_OBJECT

public:
	videoProcessing(QWidget *parent = Q_NULLPTR);
	~videoProcessing();
public slots:
	void openVideo();
	void save();
	void saveAs();
	void playVideo();
	void pauseVideo();
	void sliderReleased();
	void showFristFrame();
	
	void video_Gary();

	void video_SobelSolt();
	void video_SobelShow(int w, int b, int s, int kSize);
	void video_SobelCore(int w, int b, int s, int kSize);
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

	int fps;//֡��
	int secondEachFrame;//ÿ֡ʱ�� ����

	int videoWidth;
	int videoHeight;
	int fourcc;//���ַ�����

	//�ر��¼�
	void closeEvent(QCloseEvent * event);
};
