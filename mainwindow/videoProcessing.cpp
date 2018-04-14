#include "videoProcessing.h"
#include "ui_videoProcessing.h"
#include<QDebug>
videoProcessing::videoProcessing(QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::videoProcessing;
	ui->setupUi(this);
	ui->videoLabel->setAlignment(Qt::AlignCenter);
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

void videoProcessing::openVideo() {
	time_clock->stop();
	fileName = QFileDialog::getOpenFileName(this, tr("打开视频文件"),".",tr("Image file(*.mp4 *.avi *.rmvb *.wmv)"));

	string fileOpen = fileName.toStdString();
	if (!fileName.isEmpty()) {
		ui->videoSlider->setEnabled(true);

		if (capture.isOpened()) { capture.release(); }
		capture.open(fileOpen);

		Mat frameOne;
		capture.read(frameOne);
		secondEachFrame = 1000/capture.get(CV_CAP_PROP_FPS);//设置帧率
		time_clock->setInterval(secondEachFrame);

		img = Mat2QImage(frameOne);
		ui->videoLabel->clear();
		ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
		ui->videoLabel->show();
	}

	//获取总帧数
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
	time_clock->stop();
}
void videoProcessing::sliderReleased() {
	if (ui->videoSlider->value() != totalFrameNumber) {
		time_clock->start();
	}
	nowFrame = ui->videoSlider->value();
	capture.set(CV_CAP_PROP_POS_FRAMES, nowFrame);
}