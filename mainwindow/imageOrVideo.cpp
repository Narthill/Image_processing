#include "imageOrVideo.h"
#include "ui_imageOrVideo.h"

imageOrVideo::imageOrVideo(QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::imageOrVideo;
	ui->setupUi(this);
	//this->setModal(true);
	connect(ui->imageBtn, &QPushButton::clicked, this, &imageOrVideo::imageProcess);
	connect(ui->videoBtn, &QPushButton::clicked, this, &imageOrVideo::videoProcess);

}

imageOrVideo::~imageOrVideo()
{
	delete ui;
}

void imageOrVideo::imageProcess(){

	QEventLoop a;//开启事件循环
	image = new MainWindow();
	image->setAttribute(Qt::WA_DeleteOnClose);
	image->setWindowTitle(tr("图像处理"));
	QObject::connect(image, SIGNAL(closeImage()), this, SLOT(showMain()));
	image->show();
	this->hide();

	a.exec();
	
}
void imageOrVideo::videoProcess(){

	QEventLoop a;//开启事件循环

	video = new videoProcessing();
	video->setAttribute(Qt::WA_DeleteOnClose);
	video->setWindowTitle(tr("视频处理"));
	QObject::connect(video, SIGNAL(closeVideo()), this, SLOT(showMain()));
	video->show();
	this->hide();

	a.exec();
}
void imageOrVideo::showMain() {
	this->show();
}