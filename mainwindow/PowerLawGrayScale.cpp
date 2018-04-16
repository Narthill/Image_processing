#include "PowerLawGrayScale.h"

PowerLawGrayScale::PowerLawGrayScale(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::PowerLawGrayScale;
	ui->setupUi(this);

	ui->indexSlider->setRange(0,50);
	ui->indexSpinBox->setRange(0,5.0);

	//����Slider��SpinBox
	QObject::connect(ui->indexSlider, SIGNAL(valueChanged(int)), this, SLOT(slotslider_DoubleSpinBox()));
	QObject::connect(ui->indexSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slotDoubleSpinbox_slider()));

	//Slider�������������ź�
	QObject::connect(ui->indexSlider, SIGNAL(valueChanged(int)), this, SLOT(send()));

	//�ر��ź�
	QObject::connect(ui->sureBtn, &QPushButton::clicked, this, &QWidget::close);
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

PowerLawGrayScale::~PowerLawGrayScale()
{
	delete ui;
}

void PowerLawGrayScale::send() {
	double index = ui->indexSpinBox->value();
	emit PowerLaw(index);
}

void PowerLawGrayScale::slotDoubleSpinbox_slider()
{
	ui->indexSlider->setValue((int)(ui->indexSpinBox->value() * 10));
}
void PowerLawGrayScale::slotslider_DoubleSpinBox()
{
	ui->indexSpinBox->setValue((double)(ui->indexSlider->value()) / 10);
}

//�ر��¼�
void PowerLawGrayScale::closeEvent(QCloseEvent *event)
{
	QPushButton* btn = qobject_cast<QPushButton *>(sender());
	if (btn != NULL && btn->objectName() == "sureBtn") {
		emit closeAndPush();
	}
	else {
		emit closeNotPush();
	}
}
