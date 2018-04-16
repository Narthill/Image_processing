#pragma once
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE
#include <QWidget>
#include "ui_PieceWiselinearGrayScale.h"

class PieceWiselinearGrayScale : public QWidget
{
	Q_OBJECT

public:
	PieceWiselinearGrayScale(QWidget *parent = Q_NULLPTR);
	~PieceWiselinearGrayScale();
public slots:
	void sendAndPaint();
signals:
	void inflectionPoint(int X1,int Y1,int X2,int Y2);
	void closeAndPush();
	void closeNotPush();
private:
	Ui::PieceWiselinearGrayScale *ui;
	QLineSeries *series;
	QChart *chart;
	void closeEvent(QCloseEvent *event);
};
