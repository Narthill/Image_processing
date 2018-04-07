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
	QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(chooseFilter(int)));

	//互连Slider和SpinBox
	QObject::connect(ui->rSlider, SIGNAL(valueChanged(int)), ui->rSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->rSpinBox, SIGNAL(valueChanged(int)), ui->rSlider, SLOT(setValue(int)));
	QObject::connect(ui->btwSlider, SIGNAL(valueChanged(int)), ui->btwSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->btwSpinBox, SIGNAL(valueChanged(int)), ui->btwSlider, SLOT(setValue(int)));

	//
	QObject::connect(ui->rSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering(int)));
	QObject::connect(ui->btwSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering(int)));
	//关闭信号
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

void FreqFilter::srcSpectrum() {
	ImageProcessing img(resource);
	srcSpectrumImage = img.ShowSpectrum(img.dftTransformation());
	ui->srcLabel->clear();
	int width = ui->srcLabel->width();
	int height = ui->srcLabel->height();
	QPixmap pixmap = QPixmap::fromImage(Mat2QImage(srcSpectrumImage));
	QPixmap fitpixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);//按比例缩小
	ui->srcLabel->setPixmap(fitpixmap);
}

void FreqFilter::chooseFilter(int a) {
	ui->rSlider->setValue(0);
	if (a == 2) {
		ui->btwSlider->setValue(0);
		ui->btwGroupBox->show();
	}
	else{
		ui->btwGroupBox->hide();
	}
}

void FreqFilter::filtering(int d0) {


}