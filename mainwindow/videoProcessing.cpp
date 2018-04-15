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

	//connect(this, SIGNAL(closeVideo()), parentWidget(), SLOT(showMain()));

}

videoProcessing::~videoProcessing()
{
	delete ui;
}

//保存
void videoProcessing::save() {
	time_clock->stop();
	if (!fileName.isEmpty()) {
		string fileSave = fileName.toStdString();
		VideoWriter out(fileSave, fourcc, fps, Size(videoWidth, videoHeight));
		for (long i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("正在保存视频"));
			Mat next_frame;
			next_frame = *(videoQueue.begin() + i);
			out.write(next_frame);
			statusBar()->showMessage(tr("正在保存视频..."));
		}
		statusBar()->showMessage(tr("保存完毕！"));
	}
}

//另存为
void videoProcessing::saveAs() {
	QString otherFilename = QFileDialog::getSaveFileName(this,
		tr("视频保存"),
		".",
		tr("video Files(*.avi)"));
	if (!otherFilename.isEmpty()) {
		string fileSave = otherFilename.toStdString();
		VideoWriter out(fileSave, fourcc, fps, Size(videoWidth, videoHeight));
		for (long i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("正在保存视频"));
			Mat next_frame;
			next_frame = *(videoQueue.begin() + i);
			out.write(next_frame);
			statusBar()->showMessage(tr("正在保存视频..."));
		}
		statusBar()->showMessage(tr("保存完毕！"));
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
		//获取总帧数
		totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);
		//帧率
		fps = capture.get(CV_CAP_PROP_FPS);
		secondEachFrame = 1000 / fps;//定时器时间=1000ms/帧率
		time_clock->setInterval(secondEachFrame);//设置定时器时间

		

		for (int i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("正在加载视频"));
			Mat frame;
			capture.read(frame);//获取第一帧
			videoQueue.push_back(frame);
			statusBar()->showMessage(tr("正在加载视频......"));
		}
		statusBar()->showMessage(tr("视频加载完毕！"));

		Mat frameOne = *videoQueue.begin();

		img = Mat2QImage(frameOne);//显示第一帧
		ui->videoLabel->clear();
		ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
		ui->videoLabel->show();
	}

	
	ui->videoSlider->setRange(0, totalFrameNumber-1);
	nowFrameIndex = 0;
}

void videoProcessing::playVideo() {
	//播放
	time_clock->start();
	if (nowFrameIndex == totalFrameNumber) {
		time_clock->stop();
		nowFrameIndex = 0;
		//qDebug() << "yes.it stop!";
		return;
	}
	//capture.read(frame);
	nowframe =*(videoQueue.begin()+ nowFrameIndex);
	
	if (!nowframe.empty())
	{
		img = Mat2QImage(nowframe);
		ui->videoLabel->clear();
		ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
		ui->videoLabel->show();

		ui->videoSlider->setValue(nowFrameIndex);

		nowFrameIndex++;
	}
	
}

void videoProcessing::pauseVideo() {
	time_clock->stop();//定时器停止
}
void videoProcessing::sliderReleased() {
	//滚轮释放
	if (ui->videoSlider->value() != totalFrameNumber) {
		time_clock->start();//不到最后一帧就可以将定时器打开
	}
	nowFrameIndex = ui->videoSlider->value();
	nowframe = *(videoQueue.begin() + nowFrameIndex);//将视频定位到当前帧

}

void videoProcessing::closeEvent(QCloseEvent *event)
{
	emit closeVideo();
}