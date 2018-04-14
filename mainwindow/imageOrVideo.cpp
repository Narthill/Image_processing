#include "imageOrVideo.h"
#include "ui_imageOrVideo.h"

imageOrVideo::imageOrVideo(QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::imageOrVideo;
	ui->setupUi(this);
}

imageOrVideo::~imageOrVideo()
{
	delete ui;
}
