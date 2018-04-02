#include "EdgeDetection.h"

EdgeDetection::EdgeDetection(QWidget *parent)
	: QWidget(parent)
{
	ui =new Ui::EdgeDetection;
	ui->setupUi(this);
	ui->bigSlider->setRange(0, 255);
	ui->bigSpinBox->setRange(0, 255);
	ui->smallSlider->setRange(0, 255);
	ui->smallSpinBox->setRange(0, 255);
}

EdgeDetection::~EdgeDetection()
{
	delete ui;
}
void EdgeDetection::send() {

}