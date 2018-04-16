#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMetaType>  
#include<QGraphicsScene>
#include<opencv2/opencv.hpp>  
#pragma execution_character_set("utf-8")

using namespace cv;
//Q_DECLARE_METATYPE(cv::Mat);//注册宏
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
	void revoke();//撤销
	void pushImg();//压栈
	void notPushImg();//不压栈展示栈顶
	bool matIsEqual(const cv::Mat mat1, const cv::Mat mat2);//判断两图是否相等
	//处理槽	
	void turn();
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

	//直方图及均衡化
	void HistogramSolt();
	void HistogramCore(Mat);
	
	//频域滤波
	void freqFilterSolt();
	void freqFilterCore(Mat dst);
	//空间滤波
	void spaceFilterSolt();
	void spaceFilterCore(Mat dst);
	//dct
	void dctSolt();
	void dctCore(Mat dst);
	//边缘检测
	void EdgeDetectionSolt();
	void EdgeDetectionCore(int w, int b, int s, int kSize);

 signals:
	void closeImage();
public:
	void save_on();
	void save_off();
	void display();
	
	void clearResult();

private:
	Ui::MainWindow *ui;
	QString filename;
	Mat srcImage;	//原mat
	Mat nowImage;	//原mat
	Mat dstImage;	//生成mat
	QImage srcQimage;//原图的QImage
	QImage dstQimage;//生成图的QImage
	QGraphicsScene resultScene;
	vector<Mat> imageQueue;

	//关闭事件
	void closeEvent(QCloseEvent * event);
	
};
#endif // MAINWINDOW_H