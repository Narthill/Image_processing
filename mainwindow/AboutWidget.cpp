#include "AboutWidget.h"
#include "ui_AboutWidget.h"

AboutWidget::AboutWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::AboutWidget;
	ui->setupUi(this);

	ui->label->setText("<html>" 
		+ tr("<b>QT�汾:</b>") + "<br>"
		+ tr("QT5.9.4 32bit") + "<br>" 
		+ tr("<b>OPENCV�汾:</b>") + "<br>"
		+ tr("opencv 2.4.10 32bit") + "<br>" 
		+ tr("<b>Դ���ַ:</b>") + "<br>"
		+ tr("https://github.com/maiarChen/Image_processing") + "</html>");

	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

AboutWidget::~AboutWidget()
{
	delete ui;
}
