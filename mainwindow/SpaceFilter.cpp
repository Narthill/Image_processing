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
	ui->groupBox_sigmaX->hide();
	ui->groupBox_sigmaY->hide();

	ui->kheightSlider->setRange(1,99);
	ui->kwidthSlider->setRange(1, 99);
	ui->ksizeSlider->setRange(1, 99);

	ui->kheightSpinBox->setRange(1, 99);
	ui->kwidthSpinBox->setRange(1, 99);
	ui->ksizeSpinBox->setRange(1, 99);

	/* test */
	ui->sigmaXSlider->setRange(1, 10);
	ui->sigmaYSlider->setRange(1, 10);
	ui->sigmaXspinBox->setRange(1,10);
	ui->sigmaYspinBox->setRange(1,10);
	/* test */
	choose = 0; width = 1; height = 1;ksize=1;sigmaX=1;sigmaY=1;

	QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(chooseFilter(int)));

	QObject::connect(ui->kheightSlider, SIGNAL(valueChanged(int)), ui->kheightSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->kwidthSlider, SIGNAL(valueChanged(int)), ui->kwidthSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->ksizeSlider, SIGNAL(valueChanged(int)), ui->ksizeSpinBox, SLOT(setValue(int)));

	/* test */
	QObject::connect(ui->sigmaXSlider, SIGNAL(valueChanged(int)), ui->sigmaXspinBox, SLOT(setValue(int)));
	QObject::connect(ui->sigmaYSlider, SIGNAL(valueChanged(int)), ui->sigmaYspinBox, SLOT(setValue(int)));
	/* test */

	QObject::connect(ui->kheightSpinBox, SIGNAL(valueChanged(int)), ui->kheightSlider, SLOT(setValue(int)));
	QObject::connect(ui->kwidthSpinBox, SIGNAL(valueChanged(int)), ui->kwidthSlider, SLOT(setValue(int)));
	QObject::connect(ui->ksizeSpinBox, SIGNAL(valueChanged(int)), ui->ksizeSlider, SLOT(setValue(int)));

	/* test */
	QObject::connect(ui->sigmaXspinBox, SIGNAL(valueChanged(int)),ui->sigmaXSlider,SLOT(filtering()));
	QObject::connect(ui->sigmaYspinBox, SIGNAL(valueChanged(int)),ui->sigmaYSlider, SLOT(filtering()));
	/* test */

	//处理信号
	QObject::connect(ui->kheightSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering()));
	QObject::connect(ui->kwidthSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering()));
	QObject::connect(ui->ksizeSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering()));
	QObject::connect(ui->sigmaXSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering()));
	QObject::connect(ui->sigmaYSlider, SIGNAL(valueChanged(int)), this, SLOT(filtering()));
	//关闭信号
	QObject::connect(ui->sureBtn, &QPushButton::clicked, this, &QWidget::close);
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

	if (a==1) {
		ui->groupBox_sigmaX->show();
		ui->groupBox_sigmaY->show();
	}
	else {
		ui->groupBox_sigmaX->hide();
		ui->groupBox_sigmaY->hide();
	}
}
void SpaceFilter::filtering() {
	ImageProcessing img(srcImg);
	choose = ui->comboBox->currentIndex();
	width = ui->kwidthSlider->value();
	height = ui->kheightSlider->value();
	ksize = ui->ksizeSlider->value();

	/* test */
	sigmaX = ui->sigmaXSlider->value();
	sigmaY = ui->sigmaYSlider->value();
	/* test */

	Mat dstImg;
	if (choose == 0) {
		//均值滤波
		dstImg = img.blurFilter(width, height);
	}
	else if (choose == 1) {
		//高斯条件，不能为偶
		if (width % 2 == 0) {
			width++;
			ui->kwidthSlider->setValue(width);
		}
		if (height % 2 == 0) {
			height++;
			ui->kheightSlider->setValue(height);
		}
		

		dstImg = img.gaussianBlurFilter(width, height,sigmaX,sigmaY);
	}
	else if (choose == 2) {
		//中值条件，不能为偶
		if (ksize % 2 == 0) {
			ksize++;
		}
		ui->ksizeSlider->setValue(ksize);
		dstImg = img.medianBlurFilter(ksize);
	}
	else if (choose == 3) {
		//拉普拉斯
		dstImg = img.fil2DLaplace(ksize);
	}
	else {
	}

	emit sendDstImage(dstImg);
}

//关闭事件
void SpaceFilter::closeEvent(QCloseEvent *event)
{
	QPushButton* btn = qobject_cast<QPushButton *>(sender());
	if (btn != NULL && btn->objectName() == "sureBtn") {
		emit closeAndPush();
		if (choose == 0) {
			emit closeAndSendBlur(width, height);
		}
		else if (choose == 1) {
			emit closeAndSendGauss(width, height, sigmaX, sigmaY);
		}
		else if (choose == 2) {
			emit closeAndSendMedian(ksize);
		}
		else if (choose == 3) {
			emit closeAndSendLaplace(ksize);
		}
	}
	else {
		emit closeNotPush();
	}
}