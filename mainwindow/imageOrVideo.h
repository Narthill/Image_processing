#pragma once
#include"videoProcessing.h"
#include"mainwindow.h"
#include <QMainWindow>
namespace Ui { class imageOrVideo; };

class imageOrVideo : public QMainWindow
{
	Q_OBJECT

public:
	imageOrVideo(QWidget *parent = Q_NULLPTR);
	~imageOrVideo();
public slots:
	void imageProcess();
	void videoProcess();
	void showMain();
private:
	videoProcessing *video;
	MainWindow *image;
	Ui::imageOrVideo *ui;
};
