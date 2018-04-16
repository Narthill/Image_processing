#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMetaType>  
#include<QGraphicsScene>
#include<opencv2/opencv.hpp>  
#pragma execution_character_set("utf-8")

using namespace cv;
//Q_DECLARE_METATYPE(cv::Mat);//ע���
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
	void revoke();//����
	void pushImg();//ѹջ
	void notPushImg();//��ѹջչʾջ��
	bool matIsEqual(const cv::Mat mat1, const cv::Mat mat2);//�ж���ͼ�Ƿ����
	//�����	
	void turn();
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

	//ֱ��ͼ�����⻯
	void HistogramSolt();
	void HistogramCore(Mat);
	
	//Ƶ���˲�
	void freqFilterSolt();
	void freqFilterCore(Mat dst);
	//�ռ��˲�
	void spaceFilterSolt();
	void spaceFilterCore(Mat dst);
	//dct
	void dctSolt();
	void dctCore(Mat dst);
	//��Ե���
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
	Mat srcImage;	//ԭmat
	Mat nowImage;	//ԭmat
	Mat dstImage;	//����mat
	QImage srcQimage;//ԭͼ��QImage
	QImage dstQimage;//����ͼ��QImage
	QGraphicsScene resultScene;
	vector<Mat> imageQueue;

	//�ر��¼�
	void closeEvent(QCloseEvent * event);
	
};
#endif // MAINWINDOW_H