#pragma once

#include <QWidget>
#include "ui_CutColor.h"

class CutColor : public QWidget
{
	Q_OBJECT

public:
	CutColor(QWidget *parent = Q_NULLPTR);
	~CutColor();
public slots:
	void send();
signals:
	void CutColorRank(int);
	void closeAndPush();
private:
	Ui::CutColor *ui;
	void closeEvent(QCloseEvent *event);
};
