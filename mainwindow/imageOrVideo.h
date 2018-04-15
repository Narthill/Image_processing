#pragma once
#include"videoProcessing.h"
#include"mainwindow.h"
#include "AboutWidget.h"
#include <QMainWindow>
#pragma execution_character_set("utf-8")
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
	void about();
private:
	videoProcessing *video;
	MainWindow *image;
	Ui::imageOrVideo *ui;
};
