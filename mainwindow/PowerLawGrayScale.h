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
signals:
	void PowerLaw(int,double);
private:
	Ui::PowerLawGrayScale *ui;
};
