#include "CutColor.h"

CutColor::CutColor(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::CutColor;
	ui->setupUi(this);

	ui->nSlider->setRange(1, 255);
	ui->nSpinBox->setRange(1, 255);

	//����Slider��SpinBox
	QObject::connect(ui->nSlider, SIGNAL(valueChanged(int)), ui->nSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->nSpinBox, SIGNAL(valueChanged(int)), ui->nSlider, SLOT(setValue(int)));

	//Slider�������������ź�
	QObject::connect(ui->nSlider, SIGNAL(valueChanged(int)), this, SLOT(send()));

	//�ر��ź�
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

CutColor::~CutColor()
{
	delete ui;
}
void CutColor::send() {
	int n = ui->nSlider->value();
	emit CutColorRank(n);
}

//�ر��¼�
void CutColor::closeEvent(QCloseEvent *event)
{
	emit closeAndPush();
}