#include "Binary.h"
//①在子窗口中声明信号
//②在主窗口中声明并实现槽函数
//③在主窗口中庸connect绑定信号和槽
//④子窗口中发送信号（emit）
Binary::Binary(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Binary;
	ui->setupUi(this);
	ui->BinarySlider->setRange(0, 255);
	ui->BinarySpinBox->setRange(0, 255);
	thres = 0;

	//互连Slider和SpinBox
	QObject::connect(ui->BinarySlider, SIGNAL(valueChanged(int)), ui->BinarySpinBox, SLOT(setValue(int)));
	QObject::connect(ui->BinarySpinBox, SIGNAL(valueChanged(int)), ui->BinarySlider, SLOT(setValue(int)));
	
	//Slider滚动触发发送信号
	QObject::connect(ui->BinarySlider, SIGNAL(valueChanged(int)), this, SLOT(send()));

	//关闭信号
	QObject::connect(ui->closeBtn,&QPushButton::clicked, this,&QWidget::close );
}

Binary::~Binary()
{
	delete ui;
}

void Binary::send() {
	thres = ui->BinarySlider->value();
	emit BinaryThres(thres);
}

//关闭事件
void Binary::closeEvent(QCloseEvent *event)
{
	emit closeAndPush();
	emit closeAndSend(thres);
}