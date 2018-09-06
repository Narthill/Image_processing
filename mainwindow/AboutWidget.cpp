#include "AboutWidget.h"
#include "ui_AboutWidget.h"

AboutWidget::AboutWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::AboutWidget;
	ui->setupUi(this);

	ui->label->setText(
		tr("<b>QT�汾:</b>") + "<br>"
		+ tr("QT5.9.4 32bit") + "<br>" 
		+ tr("<b>OPENCV�汾:</b>") + "<br>"
		+ tr("opencv 2.4.10 32bit") + "<br>" 
		+ tr("<b>Դ���ַ:</b>") + "<br>"
		+ tr("<a href=\"https://github.com/Narthill/Image_processing\">https://github.com/Narthill/Image_processing</a>"));
	ui->label->setOpenExternalLinks(true);
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

AboutWidget::~AboutWidget()
{
	delete ui;
}
