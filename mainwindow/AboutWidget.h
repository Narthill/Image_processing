#pragma once

#include <QWidget>
#pragma execution_character_set("utf-8")
namespace Ui { class AboutWidget; };

class AboutWidget : public QWidget
{
	Q_OBJECT

public:
	AboutWidget(QWidget *parent = Q_NULLPTR);
	~AboutWidget();

private:
	Ui::AboutWidget *ui;
};
