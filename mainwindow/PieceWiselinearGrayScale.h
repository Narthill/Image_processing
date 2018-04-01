#pragma once

#include <QWidget>
#include "ui_PieceWiselinearGrayScale.h"

class PieceWiselinearGrayScale : public QWidget
{
	Q_OBJECT

public:
	PieceWiselinearGrayScale(QWidget *parent = Q_NULLPTR);
	~PieceWiselinearGrayScale();
public slots:
	void send();
signals:
	void inflectionPoint(int X1,int Y1,int X2,int Y2);
private:
	Ui::PieceWiselinearGrayScale *ui;
};
