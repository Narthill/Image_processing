#include "Binary.h"
#include<QDebug>
//�����Ӵ����������ź�
//������������������ʵ�ֲۺ���
//������������ӹconnect���źźͲ�
//���Ӵ����з����źţ�emit��
Binary::Binary(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Binary;
	ui->setupUi(this);
	ui->BinarySlider->setRange(0, 255);
	ui->BinarySpinBox->setRange(0, 255);
	thres = 0;

	//����Slider��SpinBox
	QObject::connect(ui->BinarySlider, SIGNAL(valueChanged(int)), ui->BinarySpinBox, SLOT(setValue(int)));
	QObject::connect(ui->BinarySpinBox, SIGNAL(valueChanged(int)), ui->BinarySlider, SLOT(setValue(int)));
	
	//Slider�������������ź�
	QObject::connect(ui->BinarySlider, SIGNAL(valueChanged(int)), this, SLOT(send()));

	//�ر��ź�
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

//�ر��¼�
void Binary::closeEvent(QCloseEvent *event)
{
	//��ȡ�����ر��¼��İ�ť
	QPushButton* btn=qobject_cast<QPushButton *>(sender());
	if (btn != NULL && btn->objectName() == "sureBtn") {
		//�����ȷ�������ͷ���ѹջ�ź��봫�������ź�
		emit closeAndPush();
		//�ô��������ź��Ǹ���Ƶ��
		emit closeAndSend(thres);
	}
	else {
		emit closeNotPush();
	}
}