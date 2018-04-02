#pragma once

#include <QWidget>
#include "ui_PowerLawGrayScale.h"

class PowerLawGrayScale : public QWidget
{
	Q_OBJECT

public:
	PowerLawGrayScale(QWidget *parent = Q_NULLPTR);
	~PowerLawGrayScale();
public slots:
	void send();
	void slotDoubleSpinbox_slider();
	void slotslider_DoubleSpinBox();
signals:
	void PowerLaw(double);
private:
	Ui::PowerLawGrayScale *ui;
};
