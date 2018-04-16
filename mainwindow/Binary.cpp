#include "Binary.h"
#include<QDebug>
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
	QObject::connect(ui->sureBtn, &QPushButton::clicked, this, &QWidget::close);
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
	//获取触发关闭事件的按钮
	QPushButton* btn=qobject_cast<QPushButton *>(sender());
	if (btn != NULL && btn->objectName() == "sureBtn") {
		//如果是确定键，就发送压栈信号与传出数据信号
		emit closeAndPush();
		//该传出数据信号是给视频的
		emit closeAndSend(thres);
	}
	else {
		emit closeNotPush();
	}
}