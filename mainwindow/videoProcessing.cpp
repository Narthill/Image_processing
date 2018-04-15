#include "videoProcessing.h"
#include "ui_videoProcessing.h"
#include<QDebug>
#include"ImageProcessing.h"
#include"EdgeDetection.h"
videoProcessing::videoProcessing(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui = new Ui::videoProcessing;
	ui->setupUi(this);
	ui->menu_video->setEnabled(false);

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

	//处理
	connect(ui->actionGray, &QAction::triggered, this, &videoProcessing::video_Gary);
	connect(ui->actionSobel, &QAction::triggered, this, &videoProcessing::video_SobelSolt);
}

videoProcessing::~videoProcessing()
{
	delete ui;
}

//保存
void videoProcessing::save() {
	time_clock->stop();
	if (!fileName.isEmpty() && dstVideoQueue.size() != 0) {
		string fileSave = fileName.toStdString();
		VideoWriter out(fileSave, fourcc, fps, Size(videoWidth, videoHeight));
		for (long i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("正在保存视频"));
			Mat next_frame;
			next_frame = *(dstVideoQueue.begin() + i);
			out.write(next_frame);
			statusBar()->showMessage(tr("正在保存视频..."));
		}
		statusBar()->showMessage(tr("保存完毕！"));
	}
	else {
		statusBar()->showMessage(tr("保存失败！"));
	}
}

//另存为
void videoProcessing::saveAs() {
	QString otherFilename = QFileDialog::getSaveFileName(this,
		tr("视频保存"),
		".",
		tr("video Files(*.avi)"));
	if (!otherFilename.isEmpty()&& dstVideoQueue.size()!=0) {
		string fileSave = otherFilename.toStdString();
		VideoWriter out(fileSave, fourcc, fps, Size(videoWidth, videoHeight));
		for (long i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("正在另存视频"));
			Mat next_frame;
			next_frame = *(dstVideoQueue.begin() + i);
			out.write(next_frame);
			statusBar()->showMessage(tr("正在另存视频..."));
		}
		statusBar()->showMessage(tr("另存完毕！"));
	}
	else {
		statusBar()->showMessage(tr("另存失败！"));
	}
}

//打开视频，并载入到容器
void videoProcessing::openVideo() {
	time_clock->stop();
	fileName = QFileDialog::getOpenFileName(this, tr("打开视频文件"),".",tr("video file(*.mp4 *.avi)"));
	string fileOpen = fileName.toStdString();

	if (!fileName.isEmpty()) {
		ui->videoSlider->setEnabled(true);
		ui->menu_video->setEnabled(true);//打开视频选项

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

		ui->videoSlider->setRange(0, totalFrameNumber - 1);//初始化视频条
		nowFrameIndex = 0;//初始化当前帧的位置

		for (int i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("正在加载视频"));
			Mat frame;
			capture.read(frame);//获取第一帧
			videoQueue.push_back(frame);//原视频赋值
			dstVideoQueue.push_back(frame);//生成视频也要赋值
			statusBar()->showMessage(tr("正在加载视频......"));
		}
		statusBar()->showMessage(tr("视频加载完毕！"));
		showFristFrame();
	}
}
//展示第一帧
void videoProcessing::showFristFrame() {
	Mat frameOne = *dstVideoQueue.begin();
	img = Mat2QImage(frameOne);//显示第一帧
	ui->videoLabel->clear();
	ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
	ui->videoLabel->show();
}
//播放视频
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
	nowframe =*(dstVideoQueue.begin()+ nowFrameIndex);
	
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

//暂停
void videoProcessing::pauseVideo() {
	time_clock->stop();//定时器停止
}

//鼠标释放slider
void videoProcessing::sliderReleased() {
	//滚轮释放
	if (ui->videoSlider->value() != totalFrameNumber) {
		time_clock->start();//不到最后一帧就可以将定时器打开
	}
	nowFrameIndex = ui->videoSlider->value();
	nowframe = *(dstVideoQueue.begin() + nowFrameIndex);//将视频定位到当前帧

}

//窗口关闭信号
void videoProcessing::closeEvent(QCloseEvent *event)
{
	emit closeVideo();
}

void videoProcessing::video_Gary() {
	time_clock->stop();
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("正在灰度化"));
		ImageProcessing gray(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i)=gray.rgb2gray() ;
		statusBar()->showMessage(tr("正在灰度化......"));
	}
	statusBar()->showMessage(tr("灰度化完成！"));
	showFristFrame();
}

void videoProcessing::video_SobelSolt() {
	time_clock->stop();
	EdgeDetection *EdgeDetectionDialog = new EdgeDetection();
	//对话框关闭时销毁
	EdgeDetectionDialog->setAttribute(Qt::WA_DeleteOnClose);
	EdgeDetectionDialog->setWindowTitle(tr("边缘检测"));
	//BinaryDialog的阈值发送给二值的core
	QObject::connect(EdgeDetectionDialog, SIGNAL(EdgeNum(int, int, int, int)), this, SLOT(video_SobelShow(int, int, int, int)));
	QObject::connect(EdgeDetectionDialog, SIGNAL(closeAndSend(int, int, int, int)), this, SLOT(video_SobelCore(int, int, int, int)));//收到关闭信号则传递给Core
	EdgeDetectionDialog->show();
}

void videoProcessing::video_SobelShow(int w, int b, int s, int kSize) {
	Mat showFrame;
	ImageProcessing sobel(*(videoQueue.begin() + nowFrameIndex));
	showFrame = sobel.edgeDetection(w, b, s, kSize);

	img = Mat2QImage(showFrame);//显示第一帧
	ui->videoLabel->clear();
	ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
	ui->videoLabel->show();
}

void videoProcessing::video_SobelCore(int w, int b, int s, int kSize) {
	time_clock->stop();
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("正在提取边缘"));
		ImageProcessing sobel(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = sobel.edgeDetection(w,b,s,kSize);
		statusBar()->showMessage(tr("正在提取边缘......"));
	}
	statusBar()->showMessage(tr("提取边缘完成！"));
	showFristFrame();
}