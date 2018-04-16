#include "Histogram.h"
#include "ui_Histogram.h"
#include"ImageProcessing.h"
#include"Mat2Qimage.h"

Histogram::Histogram(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Histogram;
	ui->setupUi(this);
	ui->getEquHisBtn->setEnabled(false);
	ui->Rlabel->setAlignment(Qt::AlignCenter);
	ui->Glabel->setAlignment(Qt::AlignCenter);
	ui->Blabel->setAlignment(Qt::AlignCenter);
	ui->Res_Rlabel->setAlignment(Qt::AlignCenter);
	ui->Res_Glabel->setAlignment(Qt::AlignCenter);
	ui->Res_Blabel->setAlignment(Qt::AlignCenter);

	//直方图生成信号
	QObject::connect(ui->getHistBtn, &QPushButton::clicked, this, &Histogram::doHist);

	//直方图均衡化并发送均衡化处理后图片信号
	QObject::connect(ui->getEquHisBtn, &QPushButton::clicked, this, &Histogram::equaliAndSend);

	//关闭信号
	QObject::connect(ui->sureBtn, &QPushButton::clicked, this, &QWidget::close);
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

Histogram::~Histogram()
{
	delete ui;
}

void Histogram::getSrcImg(cv::Mat res) {
	resource = res;
}

void Histogram::doHist() {
	ImageProcessing img(resource);
	Mat Rimage = img.picHistogramRChannelShow();
	Mat Gimage = img.picHistogramGChannelShow();
	Mat Bimage = img.picHistogramBChannelShow();

	QImage RQimage,GQimage,BQimage;
	RQimage = Mat2QImage(Rimage);
	GQimage = Mat2QImage(Gimage);
	BQimage = Mat2QImage(Bimage);

	ui->Rlabel->clear();
	ui->Rlabel->setPixmap(QPixmap::fromImage(RQimage));
	ui->Glabel->clear();
	ui->Glabel->setPixmap(QPixmap::fromImage(GQimage));
	ui->Blabel->clear();
	ui->Blabel->setPixmap(QPixmap::fromImage(BQimage));
	
	dstImage = img.picSrcChannelsSave();//均衡化

	ui->getEquHisBtn->setEnabled(true);
}
void Histogram::equaliAndSend() {
	ImageProcessing dstimg(dstImage);
	Mat dst_Rimage = dstimg.picHistogramRChannelShow();
	Mat dst_Gimage = dstimg.picHistogramGChannelShow();
	Mat dst_Bimage = dstimg.picHistogramBChannelShow();

	QImage dst_RQimage, dst_GQimage, dst_BQimage;

	dst_RQimage = Mat2QImage(dst_Rimage);
	dst_GQimage = Mat2QImage(dst_Gimage);
	dst_BQimage = Mat2QImage(dst_Bimage);

	ui->Res_Rlabel->clear();
	ui->Res_Rlabel->setPixmap(QPixmap::fromImage(dst_RQimage));
	ui->Res_Glabel->clear();
	ui->Res_Glabel->setPixmap(QPixmap::fromImage(dst_GQimage));
	ui->Res_Blabel->clear();
	ui->Res_Blabel->setPixmap(QPixmap::fromImage(dst_BQimage));

	//qRegisterMetaType< cv::Mat >("cv::Mat");
	emit equaliPic(dstImage);

}

//关闭事件
void Histogram::closeEvent(QCloseEvent *event)
{
	QPushButton* btn = qobject_cast<QPushButton *>(sender());
	if (btn != NULL && btn->objectName() == "sureBtn") {
		emit closeAndPush();
	}
	else {
		emit closeNotPush();
	}
}