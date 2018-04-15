#include "Binary.h"
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
	emit closeAndPush();
	emit closeAndSend(thres);
}