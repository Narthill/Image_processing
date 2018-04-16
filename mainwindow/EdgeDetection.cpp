#include "EdgeDetection.h"
#include<QDebug>
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
	w = 3;s = 0;b=0;kSize=3;

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
	QObject::connect(ui->sureBtn, &QPushButton::clicked, this, &QWidget::close);
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

EdgeDetection::~EdgeDetection()
{
	delete ui;
}
void EdgeDetection::send() {
	w = ui->gSlider->value();
	if (w % 2 == 0) {
		w++;
	}
	kSize = ui->modelSlider->value();
	if (kSize % 2 == 0) {
		kSize++;
	}
	b = ui->bigSlider->value();
	s = ui->smallSlider->value();
	

	emit EdgeNum(w,b,s,kSize);
}

//关闭事件
void EdgeDetection::closeEvent(QCloseEvent *event)
{
	QPushButton* btn = qobject_cast<QPushButton *>(sender());
	if (btn != NULL && btn->objectName() == "sureBtn") {
		emit closeAndPush();
		emit closeAndSend(w, b, s, kSize);
	}
	else {
		emit closeNotPush();
	}
}