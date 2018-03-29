#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Mat2QImage.h"
#include<QMessageBox>
#include<iostream>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
{
	ui = new Ui::MainWindow;

	setWindowState(Qt::WindowMaximized);//可最大化
	ui->setupUi(this);
	ui->menu_image->setEnabled(false);
	ui->menu_video->setEnabled(false);
	ui->actionsave->setEnabled(false);
	ui->actionsaveas->setEnabled(false);
	ui->actionopen->setShortcuts(QKeySequence::Open);
	ui->actionsave->setShortcuts(QKeySequence::Save);
	ui->actionsaveas->setShortcuts(QKeySequence::SaveAs);
	//信号槽连接
	connect(ui->actionopen, &QAction::triggered, this, &MainWindow::open);
	connect(ui->actionsave, &QAction::triggered, this, &MainWindow::save);
	connect(ui->actionsaveas, &QAction::triggered, this, &MainWindow::saveAs);
	connect(ui->action_Gray, &QAction::triggered, this, &MainWindow::gray);//灰度化
	connect(ui->action_Sobel, &QAction::triggered, this, &MainWindow::sobel);//边缘检测
	connect(ui->action_Filter, &QAction::triggered, this, &MainWindow::filter);//滤波
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
		tr("open picture"),
		".",
		tr("Image file(*.png *.jpg *.bmp)"));
	
	if (!filename.isEmpty()) {
		srcImage.release();
		//文件路径不为空,用一个opencv Mat全局变量接收图像
		srcImage = imread(filename.toLocal8Bit().data());
		formerScene.clear();//清空原图面板

		//QImage加载成功则展示
		if (srcQimage.load(filename)) {
			ui->menu_image->setEnabled(true);
			QGraphicsScene *fScene =&formerScene;
			fScene->addPixmap(QPixmap::fromImage(srcQimage));
			ui->formerView->setScene(fScene);
			ui->formerView->show();
		}
		else {
			QMessageBox::information(this,
				tr("failed"),
				tr("open picture failed!"));
			return;
		}
	}
}

//保存
void MainWindow::save() {
	string fileSave = filename.toStdString();
	imwrite(fileSave, dstImage);
}

//另存为
void MainWindow::saveAs() {
	QString otherFilename = QFileDialog::getSaveFileName(this,
		tr("save picture"),
		".",
		tr("Image file(*.png *.jpg *.bmp)"));
	if (!otherFilename.isEmpty()) {
		string fileSave = otherFilename.toStdString();
		imwrite(fileSave, dstImage);
	}
	else {
		return;
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
	if (dstQimage.isNull()) {
		ui->actionsave->setEnabled(false);
		ui->actionsaveas->setEnabled(false);
	}
	else {
		ui->actionsave->setEnabled(true);
		ui->actionsaveas->setEnabled(true);
	}
}

//清除原图
void MainWindow::clearFormer() {
	
}
//清除生成图
void MainWindow::clearResult() {
	
}
//旋转
void MainWindow::turn()
{
	flip(srcImage, dstImage, 1);//翻转

}

//灰度化
void MainWindow::gray() {
	cvtColor(srcImage, dstImage, CV_RGB2GRAY);
	//将Mat图像转换为QImage图像，才能显示
	dstQimage = Mat2QImage(dstImage);

	resultScene.clear();//清空结果面板
	QGraphicsScene *rScene = &resultScene;
	rScene->addPixmap(QPixmap::fromImage(dstQimage));
	ui->resultView->setScene(rScene);
	ui->resultView->show();

	save_on();
}

//边缘检测
void MainWindow::sobel() {
	Canny(srcImage, dstImage, 128, 128 * 0.4, 3, true);
	dstQimage = Mat2QImage(dstImage);

	resultScene.clear();//清空结果面板
	QGraphicsScene *rScene = &resultScene;
	rScene->addPixmap(QPixmap::fromImage(dstQimage));
	ui->resultView->setScene(rScene);
	ui->resultView->show();
	save_on();
}

//滤波
//void MainWindow::filter() {
//	//模态对话框，主框体仅仅与一个消息框体同存
//	QDialog dialog;
//	dialog.setWindowTitle(tr("Hello, dialog!"));
//	dialog.exec();
//}

void MainWindow::filter() {
	//非模态对话框，主框体可与多消息框体同存
	QDialog *dialog = new QDialog;
	dialog->setAttribute(Qt::WA_DeleteOnClose);//消息窗口关闭时释放
	dialog->setWindowTitle(tr("Hello, dialog!"));
	dialog->show();
}

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