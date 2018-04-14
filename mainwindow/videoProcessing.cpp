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


	ui->videoLabel->setAlignment(Qt::AlignCenter);//设置视频居中
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

//保存
void videoProcessing::save() {
	time_clock->stop();

	QString otherFilename = QFileDialog::getSaveFileName(this,
		tr("视频保存"),
		".",
		tr("video Files"));
	string fileSave = otherFilename.toStdString();
	VideoWriter out(fileSave,fourcc,fps,Size(videoWidth,videoHeight));
	for (long i = 0; i < totalFrameNumber-1;i++) {
		statusBar()->showMessage(tr("正在保存视频"));
		Mat next_frame;
		capture.read(next_frame);
		out.write( next_frame);
		statusBar()->showMessage(tr("正在保存视频..."));
	}
	statusBar()->showMessage(tr("保存完毕"));
}

//另存为
void videoProcessing::saveAs() {
	QString otherFilename = QFileDialog::getSaveFileName(this,
		tr("视频保存"),
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
	fileName = QFileDialog::getOpenFileName(this, tr("打开视频文件"),".",tr("video file(*.mp4 *.avi)"));

	string fileOpen = fileName.toStdString();
	if (!fileName.isEmpty()) {
		ui->videoSlider->setEnabled(true);

		if (capture.isOpened()) { capture.release(); }
		capture.open(fileOpen);
		//格式
		fourcc=capture.get(CV_CAP_PROP_FOURCC);
		//高
		videoHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
		//宽
		videoWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH);
		//帧率
		fps = capture.get(CV_CAP_PROP_FPS);
		secondEachFrame = 1000 / fps;//定时器时间=1000ms/帧率
		time_clock->setInterval(secondEachFrame);//设置定时器时间

		Mat frameOne;
		capture.read(frameOne);//获取第一帧

		img = Mat2QImage(frameOne);//显示第一帧
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
	time_clock->stop();//定时器停止
}
void videoProcessing::sliderReleased() {
	if (ui->videoSlider->value() != totalFrameNumber) {
		time_clock->start();//不到最后一帧就可以将定时器打开
	}
	nowFrame = ui->videoSlider->value();//滑动条的值赋值给当前帧
	capture.set(CV_CAP_PROP_POS_FRAMES, nowFrame);//将视频定位到当前帧
}