#include "SpaceFilter.h"
#include "ui_SpaceFilter.h"
#include"ImageProcessing.h"

SpaceFilter::SpaceFilter(Mat &src,QWidget *parent)
	: QWidget(parent)
{
	srcImg = src;
	ui = new Ui::SpaceFilter();
	ui->setupUi(this);
	ui->groupBox_ksize->hide();

	ui->kheightSlider->setRange(1,99);
	ui->kwidthSlider->setRange(1, 99);
	ui->ksizeSlider->setRange(1, 99);

	ui->kheightSpinBox->setRange(1, 99);
	ui->kwidthSpinBox->setRange(1, 99);
	ui->ksizeSpinBox->setRange(1, 99);

	QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(chooseFilter(int)));

	QObject::connect(ui->kheightSlider, SIGNAL(valueChanged(int)), ui->kheightSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->kwidthSlider, SIGNAL(valueChanged(int)), ui->kwidthSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->ksizeSlider, SIGNAL(valueChanged(int)), ui->ksizeSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->kheightSpinBox, SIGNAL(valueChanged(int)), ui->kheightSlider, SLOT(setValue(int)));
	QObject::connect(ui->kwidthSpinBox, SIGNAL(valueChanged(int)), ui->kwidthSlider, SLOT(setValue(int)));
	QObject::connect(ui->ksizeSpinBox, SIGNAL(valueChanged(int)), ui->ksizeSlider, SLOT(setValue(int)));

	//处理信号
	QObject::connect(ui->kheightSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering()));
	QObject::connect(ui->kwidthSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering()));
	QObject::connect(ui->ksizeSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering()));

	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

SpaceFilter::~SpaceFilter()
{
	delete ui;
}

void SpaceFilter::chooseFilter(int a) {
	ui->kheightSlider->setValue(1);
	ui->kwidthSlider->setValue(1);
	ui->ksizeSlider->setValue(1);
	if (a == 0||a==1) {
		
		ui->groupBox_kheight->show();
		ui->groupBox_kwidth->show();
		ui->groupBox_ksize->hide();
	}
	else {
		ui->groupBox_kheight->hide();
		ui->groupBox_kwidth->hide();
		ui->groupBox_ksize->show();
	}
}
void SpaceFilter::filtering() {
	ImageProcessing img(srcImg);
	int choose = ui->comboBox->currentIndex();
	int width = ui->kwidthSlider->value();
	int height = ui->kwidthSlider->value();
	int ksize = ui->ksizeSlider->value();
	Mat dstImg;
	if (choose == 0) {
		dstImg = img.blurFilter(width, height);
	}
	else if (choose == 1) {
		//高斯
		if (width % 2 == 0) {
			width++;
		}
		if (height % 2 == 0) {
			height++;
		}
		ui->kheightSlider->setValue(height);
		ui->kwidthSlider->setValue(width);

		dstImg = img.gaussianBlurFilter(width, height);
	}
	else if (choose == 2) {
		if (ksize % 2 == 0) {
			ksize++;
		}
		ui->ksizeSlider->setValue(ksize);
		dstImg = img.medianBlurFilter(ksize);
	}
	else if (choose == 3) {
		dstImg = img.fil2DLaplace(ksize);
	}
	else {
	}

	emit sendDstImage(dstImg);
}
