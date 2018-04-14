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
	//void saveAs();
	void playVideo();
	void pauseVideo();
	void sliderReleased();
signals:
	void closeVideo();
private:
	Ui::videoProcessing *ui;
	QTimer *time_clock;
	QString fileName;
	QImage img;
	VideoCapture capture;

	long totalFrameNumber;
	long nowFrame;

	int fps;//帧率
	int secondEachFrame;//每帧时间 毫秒

	int videoWidth;
	int videoHeight;
	int fourcc;//四字符代码

	//关闭事件
	void closeEvent(QCloseEvent * event);
};
