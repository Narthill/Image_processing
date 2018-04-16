#pragma once

#include <QWidget>

#include<opencv2/opencv.hpp>
namespace Ui { class Histogram; };

class Histogram : public QWidget
{
	Q_OBJECT

public:
	Histogram(QWidget *parent = Q_NULLPTR);
	void getSrcImg(cv::Mat);
	~Histogram();
public slots:
	void equaliAndSend();
	void doHist();
signals:
	void equaliPic(cv::Mat);
	void closeAndPush();
	void closeNotPush();
private:
	Ui::Histogram *ui;
	cv::Mat resource;
	cv::Mat dstImage;
	void closeEvent(QCloseEvent *event);
};