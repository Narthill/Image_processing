#include "FreqFilter.h"
#include "ui_FreqFilter.h"
#include<QMessageBox>
#include"imageProcessing.h"
#include"Mat2QImage.h"
#include <qdebug.h>
FreqFilter::FreqFilter(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::FreqFilter();
	ui->setupUi(this);
	ui->btwGroupBox->hide();

	ui->highOrlow->setId(ui->lowRbtn, true);
	ui->highOrlow->setId(ui->highRbtn, false);
	ui->lowRbtn->setChecked(true);

	QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(chooseFilter(int)));

	//互连Slider和SpinBox
	QObject::connect(ui->rSlider, SIGNAL(valueChanged(int)), ui->rSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->rSpinBox, SIGNAL(valueChanged(int)), ui->rSlider, SLOT(setValue(int)));
	QObject::connect(ui->btwSlider, SIGNAL(valueChanged(int)), ui->btwSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->btwSpinBox, SIGNAL(valueChanged(int)), ui->btwSlider, SLOT(setValue(int)));

	//处理信号
	QObject::connect(ui->rSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering()));
	QObject::connect(ui->btwSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering()));

	QObject::connect(ui->highRbtn, SIGNAL(toggled(bool)), this, SLOT(filtering()));
	QObject::connect(ui->lowRbtn, SIGNAL(toggled(bool)), this, SLOT(filtering()));
	//关闭信号
	QObject::connect(ui->sureBtn, &QPushButton::clicked, this, &QWidget::close);
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

FreqFilter::~FreqFilter()
{
	//delete resource;
	//delete dstImage;
	//delete srcSpectrumImage;
	delete ui;
}

void FreqFilter::getSrcImg(cv::Mat res) {
	resource = res;
}

void FreqFilter::srcDftSpectrum() {
	ImageProcessing img(resource);
	Mat dftImg = img.dftTransformation();
	srcSpectrum = img.ShowSpectrum(dftImg);

	ui->srcLabel->clear();
	int width = ui->srcLabel->width();
	int height = ui->srcLabel->height();
	QPixmap pixmap = QPixmap::fromImage(Mat2QImage(srcSpectrum));
	QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//按比例缩小
	ui->srcLabel->setPixmap(fitpixmap);
}

void FreqFilter::chooseFilter(int a) {
	ui->rSlider->setValue(0);
	ui->btwSlider->setValue(0);
	if (a == 2) {
		ui->btwGroupBox->show();
	}
	else{
		ui->btwGroupBox->hide();
	}
}

void FreqFilter::filtering() {
	ImageProcessing img(resource);
	Mat dftImg = img.dftTransformation();
	int choose = ui->comboBox->currentIndex();
	int R = ui->rSlider->value();
	bool flag = ui->highOrlow->checkedId();;
	int N = ui->btwSlider->value();
	Mat kernel;
	Mat kernelSpectrum;
	

	if (choose == 0) {
		kernel = img.gausKernel(dftImg,R, flag);
		kernelSpectrum = img.ShowSpectrum(kernel);
	}
	else if (choose == 1) {
		 kernel = img.IdealKernel(dftImg, R, flag);
		 kernelSpectrum = img.ShowSpectrum(kernel);
	}
	else if (choose == 2) {
		 kernel = img.ButterworthKernel(dftImg, R,N,flag);
		 kernelSpectrum = img.ShowSpectrum(kernel);
	}
	else {
		
	}

	Mat idftImg;
	Mat idftSpectrum;
	if (kernel.data!=NULL) {
		ui->filterLabel->clear();
		int width = ui->filterLabel->width();
		int height = ui->filterLabel->height();
		QPixmap pixmap = QPixmap::fromImage(Mat2QImage(kernelSpectrum));
		QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		ui->filterLabel->setPixmap(fitpixmap);

		idftImg = img.dftMultiply(dftImg, kernel);
		idftSpectrum = img.ShowSpectrum(idftImg);
	}

	if (idftImg.data != NULL) {
		ui->dstLabel->clear();
		int width = ui->dstLabel->width();
		int height = ui->dstLabel->height();
		QPixmap pixmap = QPixmap::fromImage(Mat2QImage(idftSpectrum));
		QPixmap fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
		ui->dstLabel->setPixmap(fitpixmap);
	}
	Mat dstImg;
	dstImg = img.idftTransformation(idftImg);

	emit idftImage(dstImg);
}

//关闭事件
void FreqFilter::closeEvent(QCloseEvent *event)
{
	QPushButton* btn = qobject_cast<QPushButton *>(sender());
	if (btn != NULL && btn->objectName() == "sureBtn") {
		emit closeAndPush();
	}
	else {
		emit closeNotPush();
	}
}