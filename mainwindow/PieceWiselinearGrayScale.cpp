#include "PieceWiselinearGrayScale.h"

#pragma execution_character_set("utf-8")
PieceWiselinearGrayScale::PieceWiselinearGrayScale(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::PieceWiselinearGrayScale;
	ui->setupUi(this);
	ui->X1_Slider->setRange(0, 255);
	ui->Y1_Slider->setRange(0, 255);
	ui->X2_Slider->setRange(0, 255);
	ui->Y2_Slider->setRange(0, 255);
	
	ui->X1_SpinBox->setRange(0, 255);
	ui->Y1_SpinBox->setRange(0, 255);
	ui->X2_SpinBox->setRange(0, 255);
	ui->Y2_SpinBox->setRange(0, 255);

	ui->X1_Slider->setValue(0);
	ui->Y1_Slider->setValue(0);
	ui->X2_Slider->setValue(255);
	ui->Y2_Slider->setValue(255);

	ui->X1_SpinBox->setValue(0);
	ui->Y1_SpinBox->setValue(0);
	ui->X2_SpinBox->setValue(255);
	ui->Y2_SpinBox->setValue(255);

	//����Slider��SpinBox
	QObject::connect(ui->X1_Slider, SIGNAL(valueChanged(int)), ui->X1_SpinBox, SLOT(setValue(int)));
	QObject::connect(ui->Y1_Slider, SIGNAL(valueChanged(int)), ui->Y1_SpinBox, SLOT(setValue(int)));
	QObject::connect(ui->X2_Slider, SIGNAL(valueChanged(int)), ui->X2_SpinBox, SLOT(setValue(int)));
	QObject::connect(ui->Y2_Slider, SIGNAL(valueChanged(int)), ui->Y2_SpinBox, SLOT(setValue(int)));

	QObject::connect(ui->X1_SpinBox, SIGNAL(valueChanged(int)), ui->X1_Slider, SLOT(setValue(int)));
	QObject::connect(ui->Y1_SpinBox, SIGNAL(valueChanged(int)), ui->Y1_Slider, SLOT(setValue(int)));
	QObject::connect(ui->X2_SpinBox, SIGNAL(valueChanged(int)), ui->X2_Slider, SLOT(setValue(int)));
	QObject::connect(ui->Y2_SpinBox, SIGNAL(valueChanged(int)), ui->Y2_Slider, SLOT(setValue(int)));

	//Slider�������������ź�
	QObject::connect(ui->X1_Slider, SIGNAL(valueChanged(int)), this, SLOT(sendAndPaint()));
	QObject::connect(ui->Y1_Slider, SIGNAL(valueChanged(int)), this, SLOT(sendAndPaint()));
	QObject::connect(ui->X2_Slider, SIGNAL(valueChanged(int)), this, SLOT(sendAndPaint()));
	QObject::connect(ui->Y2_Slider, SIGNAL(valueChanged(int)), this, SLOT(sendAndPaint()));

	//�ر��ź�
	QObject::connect(ui->sureBtn, &QPushButton::clicked, this, &QWidget::close);
	QObject::connect(ui->closeBtn, &QPushButton::clicked, this, &QWidget::close);

	series = new QLineSeries;//��ͼ����
	// ���� series����Ϊͼ�������Դ,�����ʼ���յ�
	series->append(0, 0);
	series->append(255, 255);

	chart = new QChart;//�����
	
	//����X��Y����ز���
	QValueAxis *axisX = new QValueAxis;
	axisX->setRange(0, 255);
	//axisX->setLabelsVisible(true);
	//�����±�Ϊ10��������
	axisX->setLabelFormat("%u");
	//�����ڲ�����Ϊ����
	axisX->setGridLineVisible(true);
	axisX->setMinorTickCount(2);

	QValueAxis *axisY = new QValueAxis;
	axisY->setRange(0, 255);
	//axisY->setLabelsVisible(true);
	axisY->setLabelFormat("%u");
	axisY->setGridLineVisible(true);
	axisY->setMinorTickCount(2);

	chart->legend()->hide();  // ����ͼ��
	//����x��y
	chart->setAxisX(axisX);  
	chart->setAxisY(axisY);
	//��ͼ
	chart->addSeries(series);
	chart->setTitle("�ֶ����Ա任");  // ����ͼ��ı��� 
	
	//���chart��ChartView
	ui->ChartView_1->setChart(chart);
	//�����
	ui->ChartView_1->setRenderHint(QPainter::Antialiasing);
}

PieceWiselinearGrayScale::~PieceWiselinearGrayScale()
{
	delete chart;
	delete series;
	delete ui;
}

void PieceWiselinearGrayScale::sendAndPaint() {
	int X1 = ui->X1_Slider->value();
	int Y1 = ui->Y1_Slider->value();
	int X2 = ui->X2_Slider->value();
	int Y2 = ui->Y2_Slider->value();

	//��������
	series->clear();
	*series << QPointF(0, 0) << QPointF(X1, Y1) << QPointF(X2, Y2) << QPointF(255, 255);

	chart->addSeries(series);  // �� series �����ͼ����

	emit inflectionPoint(X1,Y1,X2,Y2);
}

//�ر��¼�
void PieceWiselinearGrayScale::closeEvent(QCloseEvent *event)
{
	QPushButton* btn = qobject_cast<QPushButton *>(sender());
	if (btn != NULL && btn->objectName() == "sureBtn") {
		emit closeAndPush();
	}
	else {
		emit closeNotPush();
	}
}