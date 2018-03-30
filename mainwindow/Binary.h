#pragma once

#include <QWidget>
#include "ui_Binary.h"

class Binary : public QWidget
{
	Q_OBJECT

public:
	Binary(QWidget *parent = Q_NULLPTR);
	~Binary();

private:
	Ui::Binary ui;
};
