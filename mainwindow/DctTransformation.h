#pragma once

#include <QWidget>
#include<opencv2/opencv.hpp>  
using namespace cv;
namespace Ui { class DctTransformation; };

class DctTransformation : public QWidget
{
	Q_OBJECT

public:
	DctTransformation(Mat &src,QWidget *parent = Q_NULLPTR);
	~DctTransformation();
public slots:
	void slotDoubleSpinbox_slider();//doubleSpinbox数据传递到slider
	void slotslider_DoubleSpinBox();//slider数据传递到doubleSpinbox
	void dct();
signals:
	void sendDstImage(Mat);
	void closeAndPush();
	void closeNotPush();
private:
	Ui::DctTransformation *ui;
	Mat srcImg;
	void closeEvent(QCloseEvent *event);
};
