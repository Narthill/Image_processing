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

	//�����	

	void turn();
	void sobel();
	void gray();
	void binarySolt();
	void binaryCore(int thres);
	//�Ҷȱ任
	void linearGraySolt();
	void linearGrayCore(int contrastValue, int brightValue);
	void pieceWiselinearGraySolt();
	void pieceWiselinearGrayCore(int X1, int Y1, int X2, int Y2);
	void loglinearGrayScaleSolt();
	void loglinearGrayScaleCore(int c);
	void powerLawGrayScaleSolt();
	void powerLawGrayScaleCore(double index);

	//��ɫ�ռ�����
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
	Mat srcImage;	//ԭmat
	Mat dstImage;	//ԭmat
	QImage srcQimage;//ԭͼ��QImage
	QImage dstQimage;//����ͼ��QImage
	QGraphicsScene formerScene;
	QGraphicsScene resultScene;
	
};

#endif // MAINWINDOW_H