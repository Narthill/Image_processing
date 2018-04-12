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
private:
	Ui::SpaceFilter *ui;
	cv::Mat srcImg;
	void closeEvent(QCloseEvent *event);
};
