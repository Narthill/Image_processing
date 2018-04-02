#pragma once

#include <QWidget>
#include "ui_EdgeDetection.h"

class EdgeDetection : public QWidget
{
	Q_OBJECT

public:
	EdgeDetection(QWidget *parent = Q_NULLPTR);
	~EdgeDetection();
public slots:
	void send();
signals:
	void EdgeNum(int,int,int);
private:
	Ui::EdgeDetection *ui;
};
