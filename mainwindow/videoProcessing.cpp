#include "videoProcessing.h"
#include "ui_videoProcessing.h"
#include<QDebug>
videoProcessing::videoProcessing(QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::videoProcessing;
	ui->setupUi(this);
	ui->actionopen->setShortcuts(QKeySequence::Open);
	ui->actionsave->setShortcuts(QKeySequence::Save);
	ui->actionsaveAs->setShortcuts(QKeySequence::SaveAs);
	connect(ui->actionsave, &QAction::triggered, this, &videoProcessing::save);
	connect(ui->actionsaveAs, &QAction::triggered, this, &videoProcessing::saveAs);


	ui->videoLabel->setAlignment(Qt::AlignCenter);//������Ƶ����
	ui->videoSlider->setEnabled(false);
	time_clock = new QTimer();
	
	connect(ui->actionopen, &QAction::triggered, this, &videoProcessing::openVideo);
	connect(ui->playBtn, &QPushButton::clicked, this, &videoProcessing::playVideo);
	connect(ui->pauseBtn, &QPushButton::clicked, this, &videoProcessing::pauseVideo);
	connect(time_clock, SIGNAL(timeout()), this, SLOT(playVideo()));

	connect(ui->videoSlider, &QSlider::sliderPressed, this, &videoProcessing::pauseVideo);
	connect(ui->videoSlider, &QSlider::sliderReleased, this, &videoProcessing::sliderReleased);
}

videoProcessing::~videoProcessing()
{
	delete ui;
}

//����
void videoProcessing::save() {
	time_clock->stop();

	QString otherFilename = QFileDialog::getSaveFileName(this,
		tr("��Ƶ����"),
		".",
		tr("video Files"));
	string fileSave = otherFilename.toStdString();
	VideoWriter out(fileSave,fourcc,fps,Size(videoWidth,videoHeight));
	for (long i = 0; i < totalFrameNumber-1;i++) {
		statusBar()->showMessage(tr("���ڱ�����Ƶ"));
		Mat next_frame;
		capture.read(next_frame);
		out.write( next_frame);
		statusBar()->showMessage(tr("���ڱ�����Ƶ..."));
	}
	statusBar()->showMessage(tr("�������"));
}

//���Ϊ
void videoProcessing::saveAs() {
	QString otherFilename = QFileDialog::getSaveFileName(this,
		tr("��Ƶ����"),
		".",
		tr("video Files"));
	if (!otherFilename.isEmpty()) {
		string fileSave = otherFilename.toStdString();
	}
	else {
		return;
	}
}


void videoProcessing::openVideo() {
	time_clock->stop();
	fileName = QFileDialog::getOpenFileName(this, tr("����Ƶ�ļ�"),".",tr("video file(*.mp4 *.avi)"));

	string fileOpen = fileName.toStdString();
	if (!fileName.isEmpty()) {
		ui->videoSlider->setEnabled(true);

		if (capture.isOpened()) { capture.release(); }
		capture.open(fileOpen);
		//��ʽ
		fourcc=capture.get(CV_CAP_PROP_FOURCC);
		//��
		videoHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
		//��
		videoWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH);
		//֡��
		fps = capture.get(CV_CAP_PROP_FPS);
		secondEachFrame = 1000 / fps;//��ʱ��ʱ��=1000ms/֡��
		time_clock->setInterval(secondEachFrame);//���ö�ʱ��ʱ��

		Mat frameOne;
		capture.read(frameOne);//��ȡ��һ֡

		img = Mat2QImage(frameOne);//��ʾ��һ֡
		ui->videoLabel->clear();
		ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
		ui->videoLabel->show();
	}

	//��ȡ��֡��
	totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);
	ui->videoSlider->setRange(0, totalFrameNumber);
	nowFrame = 0;
	//qDebug() << totalFrameNumber;
}

void videoProcessing::playVideo() {
	
	time_clock->start();
	
	Mat frame;
	capture.read(frame);
	if (!frame.empty())
	{
		img = Mat2QImage(frame);
		ui->videoLabel->clear();
		ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
		ui->videoLabel->show();
		nowFrame = capture.get(CV_CAP_PROP_POS_FRAMES);
		ui->videoSlider->setValue(nowFrame);
		//qDebug() << capture.get(CV_CAP_PROP_POS_FRAMES);

		if (nowFrame == totalFrameNumber) {
			time_clock->stop();
			capture.set(CV_CAP_PROP_POS_FRAMES, 0);
			//qDebug() << "yes.it stop!";
		}
	}
}

void videoProcessing::pauseVideo() {
	time_clock->stop();//��ʱ��ֹͣ
}
void videoProcessing::sliderReleased() {
	if (ui->videoSlider->value() != totalFrameNumber) {
		time_clock->start();//�������һ֡�Ϳ��Խ���ʱ����
	}
	nowFrame = ui->videoSlider->value();//��������ֵ��ֵ����ǰ֡
	capture.set(CV_CAP_PROP_POS_FRAMES, nowFrame);//����Ƶ��λ����ǰ֡
}