#include "EdgeDetection.h"

EdgeDetection::EdgeDetection(QWidget *parent)
	: QWidget(parent)
{
	ui =new Ui::EdgeDetection;
	ui->setupUi(this);
	ui->bigSlider->setRange(1, 255);
	ui->bigSpinBox->setRange(1, 255);
	ui->smallSlider->setRange(1, 255);
	ui->smallSpinBox->setRange(1, 255);

	ui->modelSlider->setRange(3, 7);
	ui->modelSpinBox->setRange(3, 7);
	ui->gSlider->setRange(3, 20);
	ui->gSpinBox->setRange(3, 20);

	//互连Slider和SpinBox
	QObject::connect(ui->bigSlider, SIGNAL(valueChanged(int)), ui->bigSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->smallSlider, SIGNAL(valueChanged(int)), ui->smallSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->modelSlider, SIGNAL(valueChanged(int)), ui->modelSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->gSlider, SIGNAL(valueChanged(int)), ui->gSpinBox, SLOT(setValue(int)));

	QObject::connect(ui->bigSpinBox, SIGNAL(valueChanged(int)), ui->bigSlider, SLOT(setValue(int)));
	QObject::connect(ui->smallSpinBox, SIGNAL(valueChanged(int)), ui->smallSlider, SLOT(setValue(int)));
	QObject::connect(ui->modelSpinBox, SIGNAL(valueChanged(int)), ui->modelSlider, SLOT(setValue(int)));
	QObject::connect(ui->gSpinBox, SIGNAL(valueChanged(int)), ui->gSlider, SLOT(setValue(int)));

	//Slider滚动触发发送信号
	QObject::connect(ui->gSlider, SIGNAL(valueChanged(int)), this, SLOT(send()));
	QObject::connect(ui->bigSlider, SIGNAL(valueChanged(int)), this, SLOT(send()));
	QObject::connect(ui->smallSlider, SIGNAL(valueChanged(int)), this, SLOT(send()));
	QObject::connect(ui->modelSlider, SIGNAL(valueChanged(int)), this, SLOT(send()));

	//关闭信号
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);


}

EdgeDetection::~EdgeDetection()
{
	delete ui;
}
void EdgeDetection::send() {
	int w = ui->gSlider->value();
	if (w % 2 == 0) {
		w++;
	}
	int kSize = ui->modelSlider->value();
	if (kSize % 2 == 0) {
		kSize++;
	}
	int b = ui->bigSlider->value();
	int s = ui->smallSlider->value();
	

	emit EdgeNum(w,b,s,kSize);
}