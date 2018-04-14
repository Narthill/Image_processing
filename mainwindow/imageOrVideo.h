#pragma once

#include <QMainWindow>
namespace Ui { class imageOrVideo; };

class imageOrVideo : public QMainWindow
{
	Q_OBJECT

public:
	imageOrVideo(QWidget *parent = Q_NULLPTR);
	~imageOrVideo();

private:
	Ui::imageOrVideo *ui;
};
