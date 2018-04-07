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
	void srcSpectrum();
public slots:
	void chooseFilter(int);
	void filtering(int);
private:
	Ui::FreqFilter *ui;
	cv::Mat resource;
	cv::Mat dstImage;
	cv::Mat srcSpectrumImage;
};
