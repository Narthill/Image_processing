#include "PieceWiselinearGrayScale.h"

PieceWiselinearGrayScale::PieceWiselinearGrayScale(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::PieceWiselinearGrayScale;
	ui->setupUi(this);
	ui->X1_Slider->setRange(0, 255);
	ui->X2_Slider->setRange(0, 255);
	ui->Y1_Slider->setRange(0, 255);
	ui->Y2_Slider->setRange(0, 255);
	
	ui->X1_SpinBox->setRange(0, 255);
	ui->Y1_SpinBox->setRange(0, 255);
	ui->X2_SpinBox->setRange(0, 255);
	ui->Y2_SpinBox->setRange(0, 255);

	//互连Slider和SpinBox
	QObject::connect(ui->X1_Slider, SIGNAL(valueChanged(int)), ui->X1_SpinBox, SLOT(setValue(int)));
	QObject::connect(ui->Y1_Slider, SIGNAL(valueChanged(int)), ui->Y1_SpinBox, SLOT(setValue(int)));
	QObject::connect(ui->X2_Slider, SIGNAL(valueChanged(int)), ui->X2_SpinBox, SLOT(setValue(int)));
	QObject::connect(ui->Y2_Slider, SIGNAL(valueChanged(int)), ui->Y2_SpinBox, SLOT(setValue(int)));

	QObject::connect(ui->X1_SpinBox, SIGNAL(valueChanged(int)), ui->X1_Slider, SLOT(setValue(int)));
	QObject::connect(ui->Y1_SpinBox, SIGNAL(valueChanged(int)), ui->Y1_Slider, SLOT(setValue(int)));
	QObject::connect(ui->X2_SpinBox, SIGNAL(valueChanged(int)), ui->X2_Slider, SLOT(setValue(int)));
	QObject::connect(ui->Y2_SpinBox, SIGNAL(valueChanged(int)), ui->Y2_Slider, SLOT(setValue(int)));

	//Slider滚动触发发送信号
	QObject::connect(ui->X1_Slider, SIGNAL(valueChanged(int)), this, SLOT(send()));
	QObject::connect(ui->Y1_Slider, SIGNAL(valueChanged(int)), this, SLOT(send()));
	QObject::connect(ui->X2_Slider, SIGNAL(valueChanged(int)), this, SLOT(send()));
	QObject::connect(ui->Y2_Slider, SIGNAL(valueChanged(int)), this, SLOT(send()));

	//关闭信号
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

PieceWiselinearGrayScale::~PieceWiselinearGrayScale()
{
	delete ui;
}

void PieceWiselinearGrayScale::send() {
	int X1 = ui->X1_Slider->value();
	int Y1 = ui->Y1_Slider->value();
	int X2 = ui->X2_Slider->value();
	int Y2 = ui->Y2_Slider->value();

	emit inflectionPoint(X1,Y1,X2,Y2);
}