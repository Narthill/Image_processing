#pragma once

#include <QWidget>
#include<opencv2/opencv.hpp>
namespace Ui { class FreqFilter; };

class FreqFilter : public QWidget
{
	Q_OBJECT

public:
	FreqFilter(QWidget *parent = Q_NULLPTR);
	~FreqFilter();
	void getSrcImg(cv::Mat);
	void srcDftSpectrum();
public slots:
	void chooseFilter(int);
	void filtering();
signals:
	void idftImage(cv::Mat);
	void closeAndPush();
	void closeNotPush();
private:
	Ui::FreqFilter *ui;
	cv::Mat resource;
	cv::Mat dstImage;
	cv::Mat srcSpectrum;
	void closeEvent(QCloseEvent *event);
};
