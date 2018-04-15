#include "imageOrVideo.h"
#include "ui_imageOrVideo.h"


imageOrVideo::imageOrVideo(QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::imageOrVideo;
	ui->setupUi(this);
	connect(ui->imageBtn, &QPushButton::clicked, this, &imageOrVideo::imageProcess);
	connect(ui->videoBtn, &QPushButton::clicked, this, &imageOrVideo::videoProcess);
	connect(ui->actionAbout, &QAction::triggered, this, &imageOrVideo::about);
}

imageOrVideo::~imageOrVideo()
{
	delete ui;
}

void imageOrVideo::about() {
	AboutWidget* ab = new AboutWidget();
	ab->setAttribute(Qt::WA_DeleteOnClose);
	ab->setWindowTitle(tr("����"));
	ab->show();
}

void imageOrVideo::imageProcess(){

	QEventLoop a;//�����¼�ѭ��
	image = new MainWindow();
	image->setAttribute(Qt::WA_DeleteOnClose);
	image->setWindowTitle(tr("ͼ����"));
	QObject::connect(image, SIGNAL(closeImage()), this, SLOT(showMain()));
	image->show();
	this->hide();

	a.exec();
	
}
void imageOrVideo::videoProcess(){

	QEventLoop a;//�����¼�ѭ��

	video = new videoProcessing();
	video->setAttribute(Qt::WA_DeleteOnClose);
	video->setWindowTitle(tr("��Ƶ����"));
	QObject::connect(video, SIGNAL(closeVideo()), this, SLOT(showMain()));
	video->show();
	this->hide();

	a.exec();
}
void imageOrVideo::showMain() {
	this->show();
}