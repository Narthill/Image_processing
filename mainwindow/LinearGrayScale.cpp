#include "LinearGrayScale.h"

LinearGrayScale::LinearGrayScale(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::LinearGrayScale;
	ui->setupUi(this);
	ui->contrastSlider->setRange(1, 255);
	ui->contrastSpinBox->setRange(1, 255);

	ui->brightSlider->setRange(1, 255);
	ui->brightSpinBox->setRange(1, 255);

	//����Slider��SpinBox
	QObject::connect(ui->contrastSlider, SIGNAL(valueChanged(int)), ui->contrastSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->contrastSpinBox, SIGNAL(valueChanged(int)), ui->contrastSlider, SLOT(setValue(int)));

	QObject::connect(ui->brightSlider, SIGNAL(valueChanged(int)), ui->brightSpinBox, SLOT(setValue(int)));
	QObject::connect(ui->brightSpinBox, SIGNAL(valueChanged(int)), ui->brightSlider, SLOT(setValue(int)));

	//Slider�������������ź�
	QObject::connect(ui->contrastSlider, SIGNAL(valueChanged(int)), this, SLOT(send()));
	QObject::connect(ui->brightSlider, SIGNAL(valueChanged(int)), this, SLOT(send()));

	//�ر��ź�
	QObject::connect(ui->sureBtn, &QPushButton::clicked, this, &QWidget::close);
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);

}

LinearGrayScale::~LinearGrayScale()
{
	delete ui;
}

void LinearGrayScale::send() {
	int contrast = ui->contrastSlider->value();
	int bright = ui->brightSlider->value();

	emit contrastAndBright(contrast, bright);
}

//�ر��¼�
void LinearGrayScale::closeEvent(QCloseEvent *event)
{
	QPushButton* btn = qobject_cast<QPushButton *>(sender());
	if (btn != NULL && btn->objectName() == "sureBtn") {
		emit closeAndPush();
	}
	else {
		emit closeNotPush();
	}
}