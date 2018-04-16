#pragma once

#include <QWidget>
#include "ui_LinearGrayScale.h"

class LinearGrayScale : public QWidget
{
	Q_OBJECT

public:
	LinearGrayScale(QWidget *parent = Q_NULLPTR);
	~LinearGrayScale();
public slots:
	void send();
signals:
	void contrastAndBright(int,int);
	void closeAndPush();
	void closeNotPush();
private:
	Ui::LinearGrayScale *ui;
	void closeEvent(QCloseEvent *event);
};
