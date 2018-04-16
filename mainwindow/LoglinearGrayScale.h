#pragma once

#include <QWidget>
#include "ui_LoglinearGrayScale.h"

class LoglinearGrayScale : public QWidget
{
	Q_OBJECT

public:
	LoglinearGrayScale(QWidget *parent = Q_NULLPTR);
	~LoglinearGrayScale();
public slots:
	void send();
signals:
	void Loglinear(int);
	void closeAndPush();
	void closeNotPush();
private:
	Ui::LoglinearGrayScale *ui;
	void closeEvent(QCloseEvent *event);
};
