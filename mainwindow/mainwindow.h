#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include<QGraphicsScene>
#include<opencv2/opencv.hpp>  
using namespace cv;

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void open();
	void save();
	void saveAs();

	//处理槽	

	void turn();
	void sobel();
	void gray();
	void binarySolt();
	void binaryCore(int thres);
	//灰度变换
	void linearGraySolt();
	void linearGrayCore(int contrastValue, int brightValue);
	void pieceWiselinearGraySolt();
	void pieceWiselinearGrayCore(int X1, int Y1, int X2, int Y2);
	void loglinearGrayScaleSolt();
	void loglinearGrayScaleCore(int c);
	void powerLawGrayScaleSolt();
	void powerLawGrayScaleCore(double index);

	//颜色空间缩减
	void cutColorSolt();
	void cutColorCore(int n);

	void freqFilter();
	void spaceFilter();

public:
	void save_on();
	void save_off();
	void display();
	void clearFormer();
	void clearResult();

private:
	Ui::MainWindow *ui;
	QString filename;
	Mat srcImage;	//原mat
	Mat dstImage;	//原mat
	QImage srcQimage;//原图的QImage
	QImage dstQimage;//生成图的QImage
	QGraphicsScene formerScene;
	QGraphicsScene resultScene;
	
};

#endif // MAINWINDOW_H