#include "videoProcessing.h"
#include "ui_videoProcessing.h"
#include<QDebug>
#include"ImageProcessing.h"
#include"EdgeDetection.h"
#include"SpaceFilter.h"
#include"CutColor.h"
#include"Binary.h"
#include<iostream>
videoProcessing::videoProcessing(QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::videoProcessing;
	ui->setupUi(this);

	qRegisterMetaType<Mat>("Mat");//注册mat类型数据在信号槽中可传递

	ui->actionopen->setShortcuts(QKeySequence::Open);
	ui->actionsave->setShortcuts(QKeySequence::Save);
	ui->actionsaveAs->setShortcuts(QKeySequence::SaveAs);
	connect(ui->actionsave, &QAction::triggered, this, &videoProcessing::save);
	connect(ui->actionsaveAs, &QAction::triggered, this, &videoProcessing::saveAs);

	ui->videoLabel->setAlignment(Qt::AlignCenter);//设置视频居中
	uiItemClose();
	ui->menu_video->setEnabled(false);

	time_clock = new QTimer();

	connect(ui->actionopen, &QAction::triggered, this, &videoProcessing::openVideo);
	connect(ui->playBtn, &QPushButton::clicked, this, &videoProcessing::playVideo);
	connect(ui->pauseBtn, &QPushButton::clicked, this, &videoProcessing::pauseVideo);
	connect(time_clock, SIGNAL(timeout()), this, SLOT(playVideo()));//计时器时间一到就播放下一帧
	connect(time_clock, SIGNAL(timeout()), this, SLOT(videoTime()));

	connect(ui->videoSlider, &QSlider::sliderPressed, this, &videoProcessing::pauseVideo);
	connect(ui->videoSlider, &QSlider::sliderReleased, this, &videoProcessing::sliderReleased);

	//处理
	connect(ui->actionGray, &QAction::triggered, this, &videoProcessing::video_Gary);
	connect(ui->actionBinary, &QAction::triggered, this, &videoProcessing::video_BinarySolt);
	connect(ui->actionSobel, &QAction::triggered, this, &videoProcessing::video_SobelSolt);
	connect(ui->actionCutColor, &QAction::triggered, this, &videoProcessing::video_CutColorSolt);
	connect(ui->actionSpaceFilter, &QAction::triggered, this, &videoProcessing::video_SpaceFilterSolt);
	connect(ui->actionHistogram, &QAction::triggered, this, &videoProcessing::video_Histogram);
	
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
		if (capture.isOpened()) { capture.release(); }
		//载入视频
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
		//定时器时间=1000ms/帧率
		secondEachFrame = 1000 / fps;
		//设置定时器时间
		time_clock->setInterval(secondEachFrame);
		//初始化视频条
		ui->videoSlider->setRange(0, totalFrameNumber - 1);
		//初始化当前帧的位置
		nowFrameIndex = 0;
		//清空容器
		videoQueue.clear();
		dstVideoQueue.clear();
		//将视频装入容器
		for (int i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("正在加载视频"));
			Mat frame;
			capture.read(frame);//获取第一帧
			videoQueue.push_back(frame);//原视频赋值
			dstVideoQueue.push_back(frame);//生成视频也要赋值
			statusBar()->showMessage(tr("正在加载视频......"));
		}
		statusBar()->showMessage(tr("视频加载完毕！"));
		//展示第一帧
		showFristFrame();
		uiItemOpen();
		ui->menu_video->setEnabled(true);//打开视频选项
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
//剩余时间
void videoProcessing::videoTime() {
	int totalTime = secondEachFrame*(totalFrameNumber-nowFrameIndex);
	int s = totalTime / 1000;
	int m = s / 60;
	int rs =s % 60;
	
	QString time = QString::number(m, 10)+" m:"+QString::number(rs, 10)+" s";
	ui->timeLabel->setAlignment(Qt::AlignCenter);
	ui->timeLabel->setText(time);
}
//窗口关闭信号
void videoProcessing::closeEvent(QCloseEvent *event)
{
	emit closeVideo();
}
//管理控件的可选与不可选
void videoProcessing::uiItemClose() {
	ui->actionsave->setEnabled(false);
	ui->actionsaveAs->setEnabled(false);
	ui->pauseBtn->setEnabled(false);
	ui->playBtn->setEnabled(false);
	ui->videoSlider->setEnabled(false);
}
void videoProcessing::uiItemOpen() {
	ui->actionsave->setEnabled(true);
	ui->actionsaveAs->setEnabled(true);
	ui->pauseBtn->setEnabled(true);
	ui->playBtn->setEnabled(true);
	ui->videoSlider->setEnabled(true);
}
//灰度化
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
//边缘检测
void videoProcessing::video_SobelSolt() {
	time_clock->stop();

	EdgeDetection *EdgeDetectionDialog = new EdgeDetection();
	//模态对话框
	EdgeDetectionDialog->setWindowModality(Qt::ApplicationModal);
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

	img = Mat2QImage(showFrame);
	ui->videoLabel->clear();
	ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
	ui->videoLabel->show();
}
void videoProcessing::video_SobelCore(int w, int b, int s, int kSize) {
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("正在提取边缘"));
		ImageProcessing sobel(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = sobel.edgeDetection(w,b,s,kSize);
		statusBar()->showMessage(tr("正在提取边缘......"));
	}
	statusBar()->showMessage(tr("提取边缘完成！"));
	showFristFrame();
}
//颜色空间缩减
void videoProcessing::video_CutColorSolt() {
	time_clock->stop();
	CutColor *CutColorDialog = new CutColor();
	//模态对话框
	CutColorDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	CutColorDialog->setAttribute(Qt::WA_DeleteOnClose);
	CutColorDialog->setWindowTitle(tr("颜色空间缩减"));
	//BinaryDialog的阈值发送给二值的core
	QObject::connect(CutColorDialog, SIGNAL(CutColorRank(int)), this, SLOT(video_CutColorShow(int)));
	QObject::connect(CutColorDialog, SIGNAL(closeAndSend(int)), this, SLOT(video_CutColorCore(int)));//收到关闭信号则图像压栈
	CutColorDialog->show();
}
void videoProcessing::video_CutColorShow(int n) {
	Mat showFrame;
	ImageProcessing cutColor(*(videoQueue.begin() + nowFrameIndex));
	showFrame = cutColor.cutColor(n);

	img = Mat2QImage(showFrame);
	ui->videoLabel->clear();
	ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
	ui->videoLabel->show();
}
void videoProcessing::video_CutColorCore(int n) {
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("正在颜色空间缩减"));
		ImageProcessing cutColor(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = cutColor.cutColor(n);
		statusBar()->showMessage(tr("正在颜色空间缩减......"));
	}
	statusBar()->showMessage(tr("颜色空间缩减完成！"));
	showFristFrame();
}
//空间滤波
void videoProcessing::video_SpaceFilterSolt() {
	time_clock->stop();

	SpaceFilter *SpaceFilterDialog = new SpaceFilter(*(videoQueue.begin() + nowFrameIndex));
	//模态对话框
	SpaceFilterDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	SpaceFilterDialog->setAttribute(Qt::WA_DeleteOnClose);
	SpaceFilterDialog->setWindowTitle(tr("空间滤波"));
	QObject::connect(SpaceFilterDialog, SIGNAL(sendDstImage(Mat)), this, SLOT(video_SpaceFilterShow(Mat)));

	QObject::connect(SpaceFilterDialog, SIGNAL(closeAndSendBlur(int,int)), this, SLOT(video_SpaceFilterBlur(int,int)));
	QObject::connect(SpaceFilterDialog, SIGNAL(closeAndSendGauss(int, int, int, int)), this, SLOT(video_SpaceFilterGauss(int, int, int, int)));
	QObject::connect(SpaceFilterDialog, SIGNAL(closeAndSendMedian(int)), this, SLOT(video_SpaceFilterMedian(int)));
	QObject::connect(SpaceFilterDialog, SIGNAL(closeAndSendLaplace(int)), this, SLOT(video_SpaceFilterLaplace(int)));
	SpaceFilterDialog->show();
}
void videoProcessing::video_SpaceFilterShow(Mat showFrame) {
	img = Mat2QImage(showFrame);
	ui->videoLabel->clear();
	ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
	ui->videoLabel->show();
}
void videoProcessing::video_SpaceFilterBlur(int width, int height) {
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("正在进行均值滤波"));
		ImageProcessing FilterBlur(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = FilterBlur.blurFilter(width, height);
		statusBar()->showMessage(tr("正在进行均值滤波......"));
	}
	statusBar()->showMessage(tr("均值滤波完成！"));
	showFristFrame();
}
void videoProcessing::video_SpaceFilterGauss(int width, int height, int sigmaX, int sigmaY) {

	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("正在进行高斯滤波"));
		ImageProcessing FilterBlur(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = FilterBlur.gaussianBlurFilter(width, height, sigmaX, sigmaY);
		statusBar()->showMessage(tr("正在进行高斯滤波......"));
	}
	statusBar()->showMessage(tr("高斯滤波完成！"));
	showFristFrame();
}
void videoProcessing::video_SpaceFilterMedian(int ksize) {
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("正在进行中值滤波"));
		ImageProcessing FilterBlur(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = FilterBlur.medianBlurFilter(ksize);
		statusBar()->showMessage(tr("正在进行中值滤波......"));
	}
	statusBar()->showMessage(tr("中值滤波完成！"));
	showFristFrame();
}
void videoProcessing::video_SpaceFilterLaplace(int ksize) {
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("正在进行拉普拉斯滤波"));
		ImageProcessing FilterBlur(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = FilterBlur.fil2DLaplace(ksize);
		statusBar()->showMessage(tr("正在进行拉普拉斯滤波......"));
	}
	statusBar()->showMessage(tr("拉普拉斯滤波完成！"));
	showFristFrame();
}
//二值化
void videoProcessing::video_BinarySolt() {
	time_clock->stop();
	Binary *BinaryDialog = new Binary();
	//模态对话框
	BinaryDialog->setWindowModality(Qt::ApplicationModal);
	//对话框关闭时销毁
	BinaryDialog->setAttribute(Qt::WA_DeleteOnClose);
	BinaryDialog->setWindowTitle(tr("二值化"));
	//BinaryDialog的阈值发送给二值的core
	QObject::connect(BinaryDialog, SIGNAL(BinaryThres(int)), this, SLOT(video_BinaryShow(int)));
	QObject::connect(BinaryDialog, SIGNAL(closeAndSend(int)), this, SLOT(video_BinaryCore(int)));
	BinaryDialog->show();
}
void videoProcessing::video_BinaryShow(int n) {
	Mat showFrame;
	ImageProcessing Binary(*(videoQueue.begin() + nowFrameIndex));
	showFrame = Binary.rgb2black(n);

	img = Mat2QImage(showFrame);
	ui->videoLabel->clear();
	ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
	ui->videoLabel->show();
}
void videoProcessing::video_BinaryCore(int n) {
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("正在二值化"));
		ImageProcessing Binary(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = Binary.rgb2black(n);
		statusBar()->showMessage(tr("正在二值化......"));
	}
	statusBar()->showMessage(tr("二值化完成！"));
	showFristFrame();
}
//直方图均衡化
void videoProcessing::video_Histogram() {
	time_clock->stop();
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("正在均衡化直方图"));
		ImageProcessing Histogram(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = Histogram.picSrcChannelsSave();
		statusBar()->showMessage(tr("正在均衡化直方图......"));
	}
	statusBar()->showMessage(tr("均衡化直方图完成！"));
	showFristFrame();
}