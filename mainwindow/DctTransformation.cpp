#include "DctTransformation.h"
#include "ui_DctTransformation.h"
#include"ImageProcessing.h"
#include"Mat2QImage.h"

DctTransformation::DctTransformation(Mat &src,QWidget *parent)
	: QWidget(parent)
{
	srcImg = src;
	ui = new Ui::DctTransformation();
	ui->setupUi(this);

	ui->dctSlider->setRange(0, 2550);
	ui->dctSpinBox->setRange(0, 255);

	//����Slider��SpinBox
	QObject::connect(ui->dctSlider, SIGNAL(valueChanged(int)), this, SLOT(slotslider_DoubleSpinBox()));
	QObject::connect(ui->dctSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slotDoubleSpinbox_slider()));

	//Slider�������������ź�
	QObject::connect(ui->dctSlider, SIGNAL(valueChanged(int)), this, SLOT(dct()));

	//�ر��ź�
	QObject::connect(ui->sureBtn, &QPushButton::clicked, this, &QWidget::close);
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

DctTransformation::~DctTransformation()
{
	delete ui;
}

void DctTransformation::dct() {
	double t = ui->dctSpinBox->value();

	ImageProcessing img(srcImg);
	vector<Mat> allImg = img.dctTransformation(t);
	Mat dst;

	QImage YQimage,UQimage,VQimage;
	YQimage = Mat2QImage(allImg[0]);
	UQimage = Mat2QImage(allImg[1]);
	VQimage = Mat2QImage(allImg[2]);
	dst=allImg[3];

	int width = ui->yLabel->width();
	int height = ui->yLabel->height();

	
	QPixmap pixmap, fitpixmap;
	ui->yLabel->clear();
	pixmap = QPixmap::fromImage(YQimage);
	fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//��������С
	ui->yLabel->setPixmap(fitpixmap);
	
	ui->uLabel->clear();
	pixmap = QPixmap::fromImage(UQimage);
	fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//��������С
	ui->uLabel->setPixmap(fitpixmap);

	ui->vLabel->clear();
	pixmap = QPixmap::fromImage(VQimage);
	fitpixmap = pixmap.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//��������С
	ui->vLabel->setPixmap(fitpixmap);
	
	emit sendDstImage(dst);
}

void DctTransformation::slotDoubleSpinbox_slider()
{
	ui->dctSlider->setValue((int)(ui->dctSpinBox->value() * 10));
}
void DctTransformation::slotslider_DoubleSpinBox()
{
	ui->dctSpinBox->setValue((double)(ui->dctSlider->value()) / 10);
}

//�ر��¼�
void DctTransformation::closeEvent(QCloseEvent *event)
{
	QPushButton* btn = qobject_cast<QPushButton *>(sender());
	if (btn != NULL && btn->objectName() == "sureBtn") {
		emit closeAndPush();
	}
	else {
		emit closeNotPush();
	}
}