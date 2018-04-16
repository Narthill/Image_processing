#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Mat2QImage.h"
#include<QMessageBox>
#include"Binary.h"
#include"LinearGrayScale.h"
#include"PieceWiselinearGrayScale.h"
#include "CutColor.h"
#include"LoglinearGrayScale.h"
#include"ImageProcessing.h"
#include"PowerLawGrayScale.h"
#include"EdgeDetection.h"
#include"Histogram.h"
#include"FreqFilter.h"
#include"SpaceFilter.h"
#include"DctTransformation.h"
#include"videoProcessing.h"
#include<iostream>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
	ui = new Ui::MainWindow;

	qRegisterMetaType<Mat>("Mat");//注册mat类型数据在信号槽中可传递

	ui->setupUi(this);
	ui->menu_image->setEnabled(false);
	ui->revokeBtn->setEnabled(false);
	save_off();
	
	ui->actionopen->setShortcuts(QKeySequence::Open);
	ui->actionsave->setShortcuts(QKeySequence::Save);
	ui->actionsaveas->setShortcuts(QKeySequence::SaveAs);

	//信号槽连接
	connect(ui->actionopen, &QAction::triggered, this, &MainWindow::open);
	connect(ui->actionsave, &QAction::triggered, this, &MainWindow::save);
	connect(ui->actionsaveas, &QAction::triggered, this, &MainWindow::saveAs);
	//connect(ui->clearFormer, &QPushButton::clicked, this, &MainWindow::clearFormer);
	connect(ui->clearResult, &QPushButton::clicked, this, &MainWindow::clearResult);
	connect(ui->revokeBtn, &QPushButton::clicked, this, &MainWindow::revoke);//撤销

	connect(ui->action_Gray, &QAction::triggered, this, &MainWindow::gray);//灰度化
	connect(ui->action_LinearGray, &QAction::triggered, this, &MainWindow::linearGraySolt);//线性灰度变换
	connect(ui->action_PieceWiselinearGray, &QAction::triggered, this, &MainWindow::pieceWiselinearGraySolt);//分段线性灰度变换
	connect(ui->action_LoglinearGray, &QAction::triggered, this, &MainWindow::loglinearGrayScaleSolt);//对数变换
	connect(ui->action_PowerLawlinearGray, &QAction::triggered, this, &MainWindow::powerLawGrayScaleSolt);//幂率变换

	connect(ui->action_CutColor, &QAction::triggered, this, &MainWindow::cutColorSolt);//颜色空间缩减
	connect(ui->action_Hist, &QAction::triggered, this, &MainWindow::HistogramSolt);//直方图

	connect(ui->action_Binary, &QAction::triggered, this, &MainWindow::binarySolt);//二值化
	connect(ui->action_Sobel, &QAction::triggered, this, &MainWindow::EdgeDetectionSolt);//边缘检测
	connect(ui->action_FreqFilter, &QAction::triggered, this, &MainWindow::freqFilterSolt);//频域滤波
	connect(ui->action_SpaceFilter, &QAction::triggered, this, &MainWindow::spaceFilterSolt);//空间滤波

	connect(ui->action_Dct, &QAction::triggered, this, &MainWindow::dctSolt);//dct
}

MainWindow::~MainWindow()
{
	delete ui;
}

//打开图像
void MainWindow::open()
{
	//调用窗口打开文件
	filename = QFileDialog::getOpenFileName(this,
		tr("打开图片"),
		".",
		tr("Image file(*.png *.jpg *.bmp)"));
	
	if (!filename.isEmpty()) {
		srcImage.release();
		//文件路径不为空,用一个opencv Mat全局变量接收图像
		srcImage = imread(filename.toLocal8Bit().data());


		if (imageQueue.size() != 0) {
			imageQueue.clear();
		}//清空

		imageQueue.push_back(srcImage);//压入原图
		nowImage = imageQueue.back();//nowImage指向栈顶
		dstImage = NULL;
		resultScene.clear();//清空原图面板

		int size = imageQueue.size();
		QString stackStatus = "处理容器中的图片数量:" + QString::number(size, 10);//栈中状态
		statusBar()->showMessage(stackStatus);

		//QImage加载成功则展示
		if (srcQimage.load(filename)) {
			ui->menu_image->setEnabled(true);
			QGraphicsScene *fScene =&resultScene;
			fScene->addPixmap(QPixmap::fromImage(srcQimage));
			ui->resultView->setScene(fScene);
			ui->resultView->show();
		}
		else {
			QMessageBox::information(this,
				tr("操作失败"),
				tr("图片打开失败!"));
			return;
		}
	}
	//打开或者关闭撤销按钮
	if (imageQueue.size() > 1) {
		ui->revokeBtn->setEnabled(true);
	}
	else {
		ui->revokeBtn->setEnabled(false);
	}
}

//保存
void MainWindow::save() {
	if (!matIsEqual(imageQueue.back(), srcImage)) {//如果当前压栈的图和上一张图不相同则可以保存
		string fileSave = filename.toStdString();
		imwrite(fileSave, imageQueue.back());
	}
	else {
		statusBar()->showMessage(tr("未作任何处理，无需保存！"));
	}
}

//另存为
void MainWindow::saveAs() {
	if (!matIsEqual(imageQueue.back(), srcImage)) {//如果当前压栈的图和上一张图不相同则可以保存
		QString otherFilename = QFileDialog::getSaveFileName(this,
			tr("save picture"),
			".",
			tr("JPEG Files(*.jpg);;PNG Files(*.png);;BMP Files(*.bmp)"));
		if (!otherFilename.isEmpty()) {

			string fileSave = otherFilename.toStdString();
			imwrite(fileSave, imageQueue.back());

		}
		else {
			statusBar()->showMessage(tr("请选择路径！"));
			return;
		}
	}
	else {
		statusBar()->showMessage(tr("未作任何处理，无需保存！"));
	}
} 

//保存选项打开
void MainWindow::save_on() {
	if (!dstQimage.isNull()) {
		ui->actionsave->setEnabled(true);
		ui->actionsaveas->setEnabled(true);
	}
	else {
		ui->actionsave->setEnabled(false);
		ui->actionsaveas->setEnabled(false);
	}
}

//保存选项关闭
void MainWindow::save_off() {
	ui->actionsave->setEnabled(false);
	ui->actionsaveas->setEnabled(false);
}

//显示在生成图界面
void MainWindow::display() {
	resultScene.clear();//清空结果面板
	QGraphicsScene *rScene = &resultScene;
	//int with = ui->resultView->width();
	//int height = ui->resultView->height();
	QPixmap pixmap = QPixmap::fromImage(dstQimage);
	//QPixmap fitpixmap = pixmap.scaled(with, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);//按比例缩小
	//QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//填充满
	rScene->addPixmap(pixmap);
	ui->resultView->setScene(rScene);
	ui->resultView->show();
}

//判断图片是否相同
bool  MainWindow::matIsEqual(const cv::Mat mat1, const cv::Mat mat2) {
	if (mat1.empty() && mat2.empty()) {
		return true;
	}
	if (mat1.cols != mat2.cols || mat1.rows != mat2.rows || mat1.dims != mat2.dims ||
		mat1.channels() != mat2.channels()) {
		return false;
	}
	if (mat1.size() != mat2.size() || mat1.channels() != mat2.channels() || mat1.type() != mat2.type()) {
		return false;
	}
	int nrOfElements1 = mat1.total()*mat1.elemSize();
	if (nrOfElements1 != mat2.total()*mat2.elemSize()) return false;
	bool lvRet = memcmp(mat1.data, mat2.data, nrOfElements1) == 0;
	return lvRet;

	//data：Mat对象中的一个指针，指向内存中存放矩阵数据的一块内存(uchar* data)
	//dims：Mat所代表的矩阵的维度，如 3 * 4 的矩阵为 2 维， 3 * 4 * 5 的为3维
	//channels：通道，矩阵中的每一个矩阵元素拥有的值的个数，比如说 3 * 4 矩阵中一共 12 个元素，如果每个元素有三个值，那么就说这个矩阵是 3 通道的，即 channels = 3。常见的是一张彩色图片有红、绿、蓝三个通道。
	//depth：深度，即每一个像素的位数(bits)，在opencv的Mat.depth()中得到的是一个 0 – 6 的数字，分别代表不同的位数：enum{ CV_8U = 0, CV_8S = 1, CV_16U = 2, CV_16S = 3, CV_32S = 4, CV_32F = 5, CV_64F = 6 }; 可见 0和1都代表8位， 2和3都代表16位，4和5代表32位，6代表64位；
	//step：是一个数组，定义了矩阵的布局，具体见下面图片分析，另外注意 step1(step / elemSize1)，M.step[m - 1] 总是等于 elemSize，M.step1(m - 1)总是等于 channels；
	//elemSize : 矩阵中每一个元素的数据大小，如果Mat中的数据的数据类型是 CV_8U 那么 elemSize = 1，CV_8UC3 那么 elemSize = 3，CV_16UC2 那么 elemSize = 4；记住另外有个 elemSize1 表示的是矩阵中数据类型的大小，即 elemSize / channels 的大小
}

//撤销
void MainWindow::revoke(){

	//以下实现撤销
	imageQueue.pop_back();//末尾图出栈
	dstImage =imageQueue.back();//将dstImage指向出栈后栈的末尾
	//qDebug() <<"出栈::"<< imageQueue.size();
	nowImage=dstImage;//为当前图像赋值
	dstQimage = Mat2QImage(dstImage);

	int size = imageQueue.size();
	QString stackStatus = "处理容器中的图片数量:" + QString::number(size, 10);//栈中状态
	statusBar()->showMessage(stackStatus);

	display();

	if (imageQueue.size() > 1) {
		ui->revokeBtn->setEnabled(true);
	}
	else {
		ui->revokeBtn->setEnabled(false);
	}
}

//压栈,nowImage指向栈顶
void MainWindow::pushImg() {
		imageQueue.push_back(dstImage);//最后生成图进栈
		if (imageQueue.size() > 1) {
			ui->revokeBtn->setEnabled(true);
		}
		else {
			ui->revokeBtn->setEnabled(false);
		}
	nowImage = imageQueue.back();//nowImage指向栈顶

	int size = imageQueue.size();
	QString stackStatus = "处理容器中的图片数量:"+QString::number(size, 10);//栈中状态
	statusBar()->showMessage(stackStatus);
}

void MainWindow::notPushImg() {
	dstQimage = Mat2QImage(nowImage);
	resultScene.clear();//清空结果面板
	QGraphicsScene *rScene = &resultScene;
	QPixmap pixmap = QPixmap::fromImage(dstQimage);
	rScene->addPixmap(pixmap);
	ui->resultView->setScene(rScene);
	ui->resultView->show();
}

//清除生成图与栈
void MainWindow::clearResult() {
	imageQueue.clear();//清空栈
	nowImage = NULL;
	dstImage = NULL;
	srcImage = NULL;
	resultScene.clear();//清空原图面板

	int size = imageQueue.size();
	QString stackStatus = "处理容器中的图片数量:" + QString::number(size, 10);//栈中状态
	statusBar()->showMessage(stackStatus);
	ui->menu_image->setEnabled(false);
	ui->revokeBtn->setEnabled(false);
	save_off();
}

//旋转
void MainWindow::turn()
{
	flip(srcImage, dstImage, 1);//翻转

}

//nowImage负责传入栈顶
//灰度化
void MainWindow::gray() {
	ImageProcessing img(nowImage);
	dstImage = img.rgb2gray();

	pushImg();

	//将Mat图像转换为QImage图像，才能显示
	dstQimage = Mat2QImage(dstImage);
	display();
	save_on();
}

//二值化
void MainWindow::binarySolt() {

	Binary *BinaryDialog = new Binary();
	//模态对话框
	BinaryDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	BinaryDialog->setAttribute(Qt::WA_DeleteOnClose);
	BinaryDialog->setWindowTitle(tr("二值化"));
	//BinaryDialog的阈值发送给二值的core
	QObject::connect(BinaryDialog, SIGNAL(BinaryThres(int)), this, SLOT(binaryCore(int)));//参数传递信号
	QObject::connect(BinaryDialog, SIGNAL(closeAndPush()), this, SLOT(pushImg()));//收到关闭窗口的压栈信号则图像压栈
	QObject::connect(BinaryDialog, SIGNAL(closeNotPush()), this, SLOT(notPushImg()));//收到关闭窗口的不压栈信号
	BinaryDialog->show();
}
void MainWindow::binaryCore(int thres) {
	ImageProcessing img(nowImage);
	dstImage = img.rgb2black(thres);
	dstQimage = Mat2QImage(dstImage);
	display();
	save_on();
}

//线性灰度变换
void MainWindow::linearGraySolt() {
	LinearGrayScale *LinearGrayScaleDialog = new LinearGrayScale();
	//模态对话框
	LinearGrayScaleDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	LinearGrayScaleDialog->setAttribute(Qt::WA_DeleteOnClose);
	LinearGrayScaleDialog->setWindowTitle(tr("线性灰度变换"));
	QObject::connect(LinearGrayScaleDialog, SIGNAL(contrastAndBright(int,int)), this, SLOT(linearGrayCore(int,int)));//参数传递信号
	QObject::connect(LinearGrayScaleDialog, SIGNAL(closeAndPush()), this, SLOT(pushImg()));//收到关闭窗口的压栈信号则图像压栈
	QObject::connect(LinearGrayScaleDialog, SIGNAL(closeNotPush()), this, SLOT(notPushImg()));//收到关闭窗口的不压栈信号
	LinearGrayScaleDialog->show();
}
void MainWindow::linearGrayCore(int contrastValue, int brightValue) {
	ImageProcessing img(nowImage);
	dstImage = img.linearGrayScaleTransformation(contrastValue, brightValue);
	//将Mat图像转换为QImage图像，才能显示
	dstQimage = Mat2QImage(dstImage);
	display();
	save_on();
}

//分段线性变换
void MainWindow::pieceWiselinearGraySolt() {
	PieceWiselinearGrayScale *PieceWiselinearGrayScaleDialog = new PieceWiselinearGrayScale();
	//模态对话框
	PieceWiselinearGrayScaleDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	PieceWiselinearGrayScaleDialog->setAttribute(Qt::WA_DeleteOnClose);
	PieceWiselinearGrayScaleDialog->setWindowTitle(tr("分段线性变换"));
	QObject::connect(PieceWiselinearGrayScaleDialog, SIGNAL(inflectionPoint(int,int,int,int)), this, SLOT(pieceWiselinearGrayCore(int,int,int,int)));//参数传递信号
	QObject::connect(PieceWiselinearGrayScaleDialog, SIGNAL(closeAndPush()), this, SLOT(pushImg()));//收到关闭窗口的压栈信号则图像压栈
	QObject::connect(PieceWiselinearGrayScaleDialog, SIGNAL(closeNotPush()), this, SLOT(notPushImg()));//收到关闭窗口的不压栈信号
	PieceWiselinearGrayScaleDialog->show();
}
void MainWindow::pieceWiselinearGrayCore(int X1, int Y1, int X2, int Y2) {
	ImageProcessing img(nowImage);
	dstImage = img.pieceWiselinearGrayScaleTransformation(X1,Y1,X2,Y2);
	//将Mat图像转换为QImage图像，才能显示
	dstQimage = Mat2QImage(dstImage);
	display();
	save_on();
}

//对数
void MainWindow::loglinearGrayScaleSolt() {
	LoglinearGrayScale *loglinearGrayScaleDialog = new LoglinearGrayScale();
	//模态对话框
	loglinearGrayScaleDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	loglinearGrayScaleDialog->setAttribute(Qt::WA_DeleteOnClose);
	loglinearGrayScaleDialog->setWindowTitle(tr("对数变换"));
	QObject::connect(loglinearGrayScaleDialog, SIGNAL(Loglinear(int)), this, SLOT(loglinearGrayScaleCore(int)));//参数传递信号
	QObject::connect(loglinearGrayScaleDialog, SIGNAL(closeAndPush()), this, SLOT(pushImg()));//收到关闭窗口的压栈信号则图像压栈
	QObject::connect(loglinearGrayScaleDialog, SIGNAL(closeNotPush()), this, SLOT(notPushImg()));//收到关闭窗口的不压栈信号
	loglinearGrayScaleDialog->show();
}
void MainWindow::loglinearGrayScaleCore(int c) {
	ImageProcessing img(nowImage);
	dstImage = img.loglinearGrayScaleTransformation(c);
	//将Mat图像转换为QImage图像，才能显示
	dstQimage = Mat2QImage(dstImage);
	display();
	save_on();
}

//幂率
void MainWindow::powerLawGrayScaleSolt() {
	PowerLawGrayScale *PowerLawGrayScaleDialog = new PowerLawGrayScale();
	//模态对话框
	PowerLawGrayScaleDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	PowerLawGrayScaleDialog->setAttribute(Qt::WA_DeleteOnClose);
	PowerLawGrayScaleDialog->setWindowTitle(tr("幂率变换"));
	QObject::connect(PowerLawGrayScaleDialog, SIGNAL(PowerLaw(double)), this, SLOT(powerLawGrayScaleCore(double)));//参数传递信号
	QObject::connect(PowerLawGrayScaleDialog, SIGNAL(closeAndPush()), this, SLOT(pushImg()));//收到关闭窗口的压栈信号则图像压栈
	QObject::connect(PowerLawGrayScaleDialog, SIGNAL(closeNotPush()), this, SLOT(notPushImg()));//收到关闭窗口的不压栈信号
	PowerLawGrayScaleDialog->show();
}
void MainWindow::powerLawGrayScaleCore(double index) {
	ImageProcessing img(nowImage);
	dstImage = img.powerLawlinearGrayScaleTransformation(index);
	//将Mat图像转换为QImage图像，才能显示
	dstQimage = Mat2QImage(dstImage);
	display();
	save_on();
}

//颜色空间缩减
void MainWindow::cutColorSolt() {
	CutColor *CutColorDialog = new CutColor();
	//模态对话框
	CutColorDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	CutColorDialog->setAttribute(Qt::WA_DeleteOnClose);
	CutColorDialog->setWindowTitle(tr("颜色空间缩减"));
	//BinaryDialog的阈值发送给二值的core
	QObject::connect(CutColorDialog, SIGNAL(CutColorRank(int)), this, SLOT(cutColorCore(int)));//参数传递信号
	QObject::connect(CutColorDialog, SIGNAL(closeAndPush()), this, SLOT(pushImg()));//收到关闭窗口的压栈信号则图像压栈
	QObject::connect(CutColorDialog, SIGNAL(closeNotPush()), this, SLOT(notPushImg()));//收到关闭窗口的不压栈信号
	CutColorDialog->show();
}
void MainWindow::cutColorCore(int n) {
	ImageProcessing img(nowImage);
	dstImage = img.cutColor(n);
	dstQimage = Mat2QImage(dstImage);
	display();
	save_on();
}

//直方图及均衡化
void MainWindow::HistogramSolt() {
	Histogram *hist = new Histogram();
	hist->getSrcImg(nowImage);
	//模态对话框
	hist->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	hist->setAttribute(Qt::WA_DeleteOnClose);
	hist->setWindowTitle(tr("直方图均衡化"));
	QObject::connect(hist, SIGNAL(equaliPic(Mat)), this, SLOT(HistogramCore(Mat)));//参数传递信号
	QObject::connect(hist, SIGNAL(closeAndPush()), this, SLOT(pushImg()));//收到关闭窗口的压栈信号则图像压栈
	QObject::connect(hist, SIGNAL(closeNotPush()), this, SLOT(notPushImg()));//收到关闭窗口的不压栈信号
	hist->show();
}
void MainWindow::HistogramCore(Mat dst) {
	dstImage = dst;
	dstQimage = Mat2QImage(dst);
	display();
	save_on();
}

//边缘检测
void MainWindow::EdgeDetectionSolt() {
	EdgeDetection *EdgeDetectionDialog = new EdgeDetection();
	//模态对话框
	EdgeDetectionDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	EdgeDetectionDialog->setAttribute(Qt::WA_DeleteOnClose);
	EdgeDetectionDialog->setWindowTitle(tr("边缘检测"));
	//BinaryDialog的阈值发送给二值的core
	QObject::connect(EdgeDetectionDialog, SIGNAL(EdgeNum(int, int, int, int)), this, SLOT(EdgeDetectionCore(int,int,int,int)));//参数传递信号
	QObject::connect(EdgeDetectionDialog, SIGNAL(closeAndPush()), this, SLOT(pushImg()));//收到关闭窗口的压栈信号则图像压栈
	QObject::connect(EdgeDetectionDialog, SIGNAL(closeNotPush()), this, SLOT(notPushImg()));//收到关闭窗口的不压栈信号
	EdgeDetectionDialog->show();
}
void MainWindow::EdgeDetectionCore(int w,int b,int s,int kSize) {
	ImageProcessing img(nowImage);
	dstImage = img.edgeDetection(w,b,s,kSize);
	dstQimage = Mat2QImage(dstImage);
	display();
	save_on();
}

//频域滤波
void MainWindow::freqFilterSolt() {
	FreqFilter *FreqFilterDialog = new FreqFilter();
	//模态对话框
	FreqFilterDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	FreqFilterDialog->getSrcImg(nowImage);
	FreqFilterDialog->srcDftSpectrum();
	FreqFilterDialog->setAttribute(Qt::WA_DeleteOnClose);
	FreqFilterDialog->setWindowTitle(tr("频域滤波"));
	QObject::connect(FreqFilterDialog, SIGNAL(idftImage(Mat)), this, SLOT(freqFilterCore(Mat)));//参数传递信号
	QObject::connect(FreqFilterDialog, SIGNAL(closeAndPush()), this, SLOT(pushImg()));//收到关闭窗口的压栈信号则图像压栈
	QObject::connect(FreqFilterDialog, SIGNAL(closeNotPush()), this, SLOT(notPushImg()));//收到关闭窗口的不压栈信号
	FreqFilterDialog->show();
}
void MainWindow::freqFilterCore(Mat dst) {
	dstImage = dst;
	dstQimage = Mat2QImage(dst);
	display();
	save_on();
}

//空间滤波
void MainWindow::spaceFilterSolt() {
	SpaceFilter *SpaceFilterDialog = new SpaceFilter(nowImage);
	//模态对话框
	SpaceFilterDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	SpaceFilterDialog->setAttribute(Qt::WA_DeleteOnClose);
	SpaceFilterDialog->setWindowTitle(tr("空间滤波"));
	QObject::connect(SpaceFilterDialog, SIGNAL(sendDstImage(Mat)), this, SLOT(spaceFilterCore(Mat)));//参数传递信号
	QObject::connect(SpaceFilterDialog, SIGNAL(closeAndPush()), this, SLOT(pushImg()));//收到关闭窗口的压栈信号则图像压栈
	QObject::connect(SpaceFilterDialog, SIGNAL(closeNotPush()), this, SLOT(notPushImg()));//收到关闭窗口的不压栈信号
	SpaceFilterDialog->show();
}
void MainWindow::spaceFilterCore(Mat dst) {
	dstImage = dst;
	dstQimage = Mat2QImage(dst);
	display();
	save_on();
}

//dct
void  MainWindow::dctSolt() {
	DctTransformation *Dcter = new DctTransformation(nowImage);
	//模态对话框
	Dcter->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	Dcter->setAttribute(Qt::WA_DeleteOnClose);
	Dcter->setWindowTitle(tr("离散余弦变换"));
	QObject::connect(Dcter, SIGNAL(sendDstImage(Mat)), this, SLOT(dctCore(Mat)));//参数传递信号
	QObject::connect(Dcter, SIGNAL(closeAndPush()), this, SLOT(pushImg()));//收到关闭窗口的压栈信号则图像压栈
	QObject::connect(Dcter, SIGNAL(closeNotPush()), this, SLOT(notPushImg()));//收到关闭窗口的不压栈信号
	Dcter->show();
}
void  MainWindow::dctCore(Mat dst) {
	dstImage = dst;
	dstQimage = Mat2QImage(dst);
	display();
	save_on();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	emit closeImage();
}

//视频
//void MainWindow::videoProcess() {
//	videoProcessing *video = new videoProcessing();
//	video->setAttribute(Qt::WA_DeleteOnClose);
//	video->setWindowTitle(tr("视频处理"));
//	video->show();
//}

//滤波
//void MainWindow::filter() {
//	//模态对话框，主框体仅仅与一个消息框体同存
//	QDialog dialog;
//	dialog.setWindowTitle(tr("Hello, dialog!"));
//	dialog.exec();
//}

//void MainWindow::filter() {
//	//非模态对话框，主框体可与多消息框体同存
//	Binary *dialog = new Binary;
//	//dialog->setAttribute(Qt::WA_DeleteOnClose);//消息窗口关闭时释放
//	dialog->setWindowTitle(tr("Hello, dialog!"));
//	dialog->show();
//}

/*所谓的模态Dialog就是将当前线程放入阻塞队列，
所谓的非模态Dialog就是再创建一个线程专门用来显示对话框，
可以这么理解，事实上，模态、非模态是针对事件循环的。不过事件循环其实也是在一个新的线程里面的
*/
//void MainWindow::on_openBtn_clicked()
//{
//	QString fileName = QFileDialog::getOpenFileName(
//		this, "打开图片",
//		".",
//		"图片 (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;所有文件(*.*)");
//	if (fileName != "")
//	{
//		if (img->load(fileName))
//		{
//			QGraphicsScene *scene = new QGraphicsScene;
//			scene->addPixmap(QPixmap::fromImage(*img));
//			ui->formerView->setScene(scene);
//			ui->formerView->resize(img->width() + 10, img->height() + 10);
//			ui->formerView->show();
//		}
//		else
//		{
//			QMessageBox::information(this,
//				tr("打开图像失败"),
//				tr("打开图像失败!"));
//			delete img; return;
//		}
//	}
//}