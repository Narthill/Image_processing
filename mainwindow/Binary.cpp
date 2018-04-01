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

	//����Slider��SpinBox
	QObject::connect(ui->BinarySlider, &QSlider::valueChanged, ui->BinarySpinBox, &QSpinBox::setValue);
	void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
	QObject::connect(ui->BinarySpinBox, spinBoxSignal, ui->BinarySlider, &QSlider::setValue);
	
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
	int thres = ui->BinarySlider->value();
	emit BinaryThres(thres);
}