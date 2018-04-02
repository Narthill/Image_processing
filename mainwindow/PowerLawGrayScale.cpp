#include "PowerLawGrayScale.h"

PowerLawGrayScale::PowerLawGrayScale(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::PowerLawGrayScale;
	ui->setupUi(this);

	ui->kSlider->setRange(1, 10);
	ui->kSpinBox->setRange(1, 10);

	ui->indexSlider->setRange((double)1.00, (double)5.00);
	ui->indexSpinBox->setRange((double)1.00, (double)5.00);

	//互连Slider和SpinBox
	QObject::connect(ui->kSlider, SIGNAL(valueChanged(int)), ui->kSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->kSpinBox, SIGNAL(valueChanged(int)), ui->kSlider, SLOT(setValue(int)));

	QObject::connect(ui->indexSlider, SIGNAL(valueChanged(double)), ui->indexSpinBox, SLOT(setValue(double)));
	QObject::connect(ui->indexSpinBox, SIGNAL(valueChanged(double)), ui->indexSlider, SLOT(setValue(double)));

	//Slider滚动触发发送信号
	QObject::connect(ui->kSlider, SIGNAL(valueChanged(int)), this, SLOT(send()));
	QObject::connect(ui->indexSlider, SIGNAL(valueChanged(double)), this, SLOT(send()));

	//关闭信号
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

PowerLawGrayScale::~PowerLawGrayScale()
{
	delete ui;
}
void PowerLawGrayScale::send() {
	int k = ui->kSlider->value();
	double index = ui->indexSlider->value();
	emit PowerLaw(k,index);
}