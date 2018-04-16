#include "LoglinearGrayScale.h"

LoglinearGrayScale::LoglinearGrayScale(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::LoglinearGrayScale;
	ui->setupUi(this);

	ui->cSlider->setRange(0, 50);
	ui->cSpinBox->setRange(0, 50);

	//互连Slider和SpinBox
	QObject::connect(ui->cSlider, SIGNAL(valueChanged(int)), ui->cSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->cSpinBox, SIGNAL(valueChanged(int)), ui->cSlider, SLOT(setValue(int)));

	//Slider滚动触发发送信号
	QObject::connect(ui->cSlider, SIGNAL(valueChanged(int)), this, SLOT(send()));

	//关闭信号
	QObject::connect(ui->sureBtn, &QPushButton::clicked, this, &QWidget::close);
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

LoglinearGrayScale::~LoglinearGrayScale()
{
	delete ui;
}

void LoglinearGrayScale::send() {
	int c = ui->cSlider->value();
	emit Loglinear(c);
}

//关闭事件
void LoglinearGrayScale::closeEvent(QCloseEvent *event)
{
	QPushButton* btn = qobject_cast<QPushButton *>(sender());
	if (btn != NULL && btn->objectName() == "sureBtn") {
		emit closeAndPush();
	}
	else {
		emit closeNotPush();
	}
}