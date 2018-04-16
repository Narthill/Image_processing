#pragma once

#include <QWidget>
#include<opencv2/opencv.hpp>
namespace Ui { class SpaceFilter; };

class SpaceFilter : public QWidget
{
	Q_OBJECT

public:
	SpaceFilter(cv::Mat &src, QWidget *parent = Q_NULLPTR);
	~SpaceFilter();
public slots:
	void chooseFilter(int);
	void filtering();
signals:
	void sendDstImage(cv::Mat);
	void closeAndPush();
	void closeNotPush();
	void closeAndSendBlur(int width, int height);
	void closeAndSendGauss(int width, int height, int sigmaX, int sigmaY);
	void closeAndSendMedian(int ksize);
	void closeAndSendLaplace(int ksize);

private:
	Ui::SpaceFilter *ui;
	cv::Mat srcImg;
	void closeEvent(QCloseEvent *event);

	int choose;
	int width;
	int height;
	int ksize;
	double sigmaX;
	double sigmaY;
};
