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
	void gray();
	void turn();
	void sobel();
	void save_on();

private:
	Ui::MainWindow *ui;
	/*QImage *img;*/
	QString filename;
	Mat srcImage;	//原mat
	Mat dstImage;	//原mat
	QImage srcQimage;//原图的QImage
	QImage dstQimage;//生成图的QImage
	QGraphicsScene formerScene;
	QGraphicsScene resultScene;
	
};

#endif // MAINWINDOW_H