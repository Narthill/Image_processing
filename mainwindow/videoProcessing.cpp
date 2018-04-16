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

	qRegisterMetaType<Mat>("Mat");//ע��mat�����������źŲ��пɴ���

	ui->actionopen->setShortcuts(QKeySequence::Open);
	ui->actionsave->setShortcuts(QKeySequence::Save);
	ui->actionsaveAs->setShortcuts(QKeySequence::SaveAs);
	connect(ui->actionsave, &QAction::triggered, this, &videoProcessing::save);
	connect(ui->actionsaveAs, &QAction::triggered, this, &videoProcessing::saveAs);

	ui->videoLabel->setAlignment(Qt::AlignCenter);//������Ƶ����
	uiItemClose();
	ui->menu_video->setEnabled(false);

	time_clock = new QTimer();

	connect(ui->actionopen, &QAction::triggered, this, &videoProcessing::openVideo);
	connect(ui->playBtn, &QPushButton::clicked, this, &videoProcessing::playVideo);
	connect(ui->pauseBtn, &QPushButton::clicked, this, &videoProcessing::pauseVideo);
	connect(time_clock, SIGNAL(timeout()), this, SLOT(playVideo()));//��ʱ��ʱ��һ���Ͳ�����һ֡
	connect(time_clock, SIGNAL(timeout()), this, SLOT(videoTime()));

	connect(ui->videoSlider, &QSlider::sliderPressed, this, &videoProcessing::pauseVideo);
	connect(ui->videoSlider, &QSlider::sliderReleased, this, &videoProcessing::sliderReleased);

	//����
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

//����
void videoProcessing::save() {
	time_clock->stop();
	if (!fileName.isEmpty() && dstVideoQueue.size() != 0) {
		string fileSave = fileName.toStdString();
		VideoWriter out(fileSave, fourcc, fps, Size(videoWidth, videoHeight));
		for (long i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("���ڱ�����Ƶ"));
			Mat next_frame;
			next_frame = *(dstVideoQueue.begin() + i);
			out.write(next_frame);
			statusBar()->showMessage(tr("���ڱ�����Ƶ..."));
		}
		statusBar()->showMessage(tr("������ϣ�"));
	}
	else {
		statusBar()->showMessage(tr("����ʧ�ܣ�"));
	}
}
//���Ϊ
void videoProcessing::saveAs() {
	QString otherFilename = QFileDialog::getSaveFileName(this,
		tr("��Ƶ����"),
		".",
		tr("video Files(*.avi)"));
	if (!otherFilename.isEmpty()&& dstVideoQueue.size()!=0) {
		string fileSave = otherFilename.toStdString();
		VideoWriter out(fileSave, fourcc, fps, Size(videoWidth, videoHeight));
		for (long i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("���������Ƶ"));
			Mat next_frame;
			next_frame = *(dstVideoQueue.begin() + i);
			out.write(next_frame);
			statusBar()->showMessage(tr("���������Ƶ..."));
		}
		statusBar()->showMessage(tr("�����ϣ�"));
	}
	else {
		statusBar()->showMessage(tr("���ʧ�ܣ�"));
	}
}
//����Ƶ�������뵽����
void videoProcessing::openVideo() {
	time_clock->stop();
	
	fileName = QFileDialog::getOpenFileName(this, tr("����Ƶ�ļ�"),".",tr("video file(*.mp4 *.avi)"));
	string fileOpen = fileName.toStdString();

	if (!fileName.isEmpty()) {
		if (capture.isOpened()) { capture.release(); }
		//������Ƶ
		capture.open(fileOpen);
		//��ʽ
		fourcc=capture.get(CV_CAP_PROP_FOURCC);
		//��
		videoHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
		//��
		videoWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH);
		//��ȡ��֡��
		totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);
		//֡��
		fps = capture.get(CV_CAP_PROP_FPS);
		//��ʱ��ʱ��=1000ms/֡��
		secondEachFrame = 1000 / fps;
		//���ö�ʱ��ʱ��
		time_clock->setInterval(secondEachFrame);
		//��ʼ����Ƶ��
		ui->videoSlider->setRange(0, totalFrameNumber - 1);
		//��ʼ����ǰ֡��λ��
		nowFrameIndex = 0;
		//�������
		videoQueue.clear();
		dstVideoQueue.clear();
		//����Ƶװ������
		for (int i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("���ڼ�����Ƶ"));
			Mat frame;
			capture.read(frame);//��ȡ��һ֡
			videoQueue.push_back(frame);//ԭ��Ƶ��ֵ
			dstVideoQueue.push_back(frame);//������ƵҲҪ��ֵ
			statusBar()->showMessage(tr("���ڼ�����Ƶ......"));
		}
		statusBar()->showMessage(tr("��Ƶ������ϣ�"));
		//չʾ��һ֡
		showFristFrame();
		uiItemOpen();
		ui->menu_video->setEnabled(true);//����Ƶѡ��
	}
}
//չʾ��һ֡
void videoProcessing::showFristFrame() {
	Mat frameOne = *dstVideoQueue.begin();
	img = Mat2QImage(frameOne);//��ʾ��һ֡
	ui->videoLabel->clear();
	ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
	ui->videoLabel->show();
}
//������Ƶ
void videoProcessing::playVideo() {
	//����
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
//��ͣ
void videoProcessing::pauseVideo() {
	time_clock->stop();//��ʱ��ֹͣ
}
//����ͷ�slider
void videoProcessing::sliderReleased() {
	//�����ͷ�
	if (ui->videoSlider->value() != totalFrameNumber) {
		time_clock->start();//�������һ֡�Ϳ��Խ���ʱ����
	}
	nowFrameIndex = ui->videoSlider->value();
	nowframe = *(dstVideoQueue.begin() + nowFrameIndex);//����Ƶ��λ����ǰ֡

}
//ʣ��ʱ��
void videoProcessing::videoTime() {
	int totalTime = secondEachFrame*(totalFrameNumber-nowFrameIndex);
	int s = totalTime / 1000;
	int m = s / 60;
	int rs =s % 60;
	
	QString time = QString::number(m, 10)+" m:"+QString::number(rs, 10)+" s";
	ui->timeLabel->setAlignment(Qt::AlignCenter);
	ui->timeLabel->setText(time);
}
//���ڹر��ź�
void videoProcessing::closeEvent(QCloseEvent *event)
{
	emit closeVideo();
}
//����ؼ��Ŀ�ѡ�벻��ѡ
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
//�ҶȻ�
void videoProcessing::video_Gary() {
	time_clock->stop();
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("���ڻҶȻ�"));
		ImageProcessing gray(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i)=gray.rgb2gray() ;
		statusBar()->showMessage(tr("���ڻҶȻ�......"));
	}
	statusBar()->showMessage(tr("�ҶȻ���ɣ�"));
	showFristFrame();
}
//��Ե���
void videoProcessing::video_SobelSolt() {
	time_clock->stop();

	EdgeDetection *EdgeDetectionDialog = new EdgeDetection();
	//ģ̬�Ի���
	EdgeDetectionDialog->setWindowModality(Qt::ApplicationModal);
	//�Ի���ر�ʱ����
	EdgeDetectionDialog->setAttribute(Qt::WA_DeleteOnClose);
	EdgeDetectionDialog->setWindowTitle(tr("��Ե���"));
	//BinaryDialog����ֵ���͸���ֵ��core
	QObject::connect(EdgeDetectionDialog, SIGNAL(EdgeNum(int, int, int, int)), this, SLOT(video_SobelShow(int, int, int, int)));
	QObject::connect(EdgeDetectionDialog, SIGNAL(closeAndSend(int, int, int, int)), this, SLOT(video_SobelCore(int, int, int, int)));//�յ��ر��ź��򴫵ݸ�Core
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
		statusBar()->showMessage(tr("������ȡ��Ե"));
		ImageProcessing sobel(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = sobel.edgeDetection(w,b,s,kSize);
		statusBar()->showMessage(tr("������ȡ��Ե......"));
	}
	statusBar()->showMessage(tr("��ȡ��Ե��ɣ�"));
	showFristFrame();
}
//��ɫ�ռ�����
void videoProcessing::video_CutColorSolt() {
	time_clock->stop();
	CutColor *CutColorDialog = new CutColor();
	//ģ̬�Ի���
	CutColorDialog->setWindowModality(Qt::ApplicationModal);
	//�Ի���ر�ʱ����
	CutColorDialog->setAttribute(Qt::WA_DeleteOnClose);
	CutColorDialog->setWindowTitle(tr("��ɫ�ռ�����"));
	//BinaryDialog����ֵ���͸���ֵ��core
	QObject::connect(CutColorDialog, SIGNAL(CutColorRank(int)), this, SLOT(video_CutColorShow(int)));
	QObject::connect(CutColorDialog, SIGNAL(closeAndSend(int)), this, SLOT(video_CutColorCore(int)));//�յ��ر��ź���ͼ��ѹջ
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
		statusBar()->showMessage(tr("������ɫ�ռ�����"));
		ImageProcessing cutColor(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = cutColor.cutColor(n);
		statusBar()->showMessage(tr("������ɫ�ռ�����......"));
	}
	statusBar()->showMessage(tr("��ɫ�ռ�������ɣ�"));
	showFristFrame();
}
//�ռ��˲�
void videoProcessing::video_SpaceFilterSolt() {
	time_clock->stop();

	SpaceFilter *SpaceFilterDialog = new SpaceFilter(*(videoQueue.begin() + nowFrameIndex));
	//ģ̬�Ի���
	SpaceFilterDialog->setWindowModality(Qt::ApplicationModal);
	//�Ի���ر�ʱ����
	SpaceFilterDialog->setAttribute(Qt::WA_DeleteOnClose);
	SpaceFilterDialog->setWindowTitle(tr("�ռ��˲�"));
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
		statusBar()->showMessage(tr("���ڽ��о�ֵ�˲�"));
		ImageProcessing FilterBlur(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = FilterBlur.blurFilter(width, height);
		statusBar()->showMessage(tr("���ڽ��о�ֵ�˲�......"));
	}
	statusBar()->showMessage(tr("��ֵ�˲���ɣ�"));
	showFristFrame();
}
void videoProcessing::video_SpaceFilterGauss(int width, int height, int sigmaX, int sigmaY) {

	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("���ڽ��и�˹�˲�"));
		ImageProcessing FilterBlur(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = FilterBlur.gaussianBlurFilter(width, height, sigmaX, sigmaY);
		statusBar()->showMessage(tr("���ڽ��и�˹�˲�......"));
	}
	statusBar()->showMessage(tr("��˹�˲���ɣ�"));
	showFristFrame();
}
void videoProcessing::video_SpaceFilterMedian(int ksize) {
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("���ڽ�����ֵ�˲�"));
		ImageProcessing FilterBlur(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = FilterBlur.medianBlurFilter(ksize);
		statusBar()->showMessage(tr("���ڽ�����ֵ�˲�......"));
	}
	statusBar()->showMessage(tr("��ֵ�˲���ɣ�"));
	showFristFrame();
}
void videoProcessing::video_SpaceFilterLaplace(int ksize) {
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("���ڽ���������˹�˲�"));
		ImageProcessing FilterBlur(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = FilterBlur.fil2DLaplace(ksize);
		statusBar()->showMessage(tr("���ڽ���������˹�˲�......"));
	}
	statusBar()->showMessage(tr("������˹�˲���ɣ�"));
	showFristFrame();
}
//��ֵ��
void videoProcessing::video_BinarySolt() {
	time_clock->stop();
	Binary *BinaryDialog = new Binary();
	//ģ̬�Ի���
	BinaryDialog->setWindowModality(Qt::ApplicationModal);
	//�Ի���ر�ʱ����
	BinaryDialog->setAttribute(Qt::WA_DeleteOnClose);
	BinaryDialog->setWindowTitle(tr("��ֵ��"));
	//BinaryDialog����ֵ���͸���ֵ��core
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
		statusBar()->showMessage(tr("���ڶ�ֵ��"));
		ImageProcessing Binary(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = Binary.rgb2black(n);
		statusBar()->showMessage(tr("���ڶ�ֵ��......"));
	}
	statusBar()->showMessage(tr("��ֵ����ɣ�"));
	showFristFrame();
}
//ֱ��ͼ���⻯
void videoProcessing::video_Histogram() {
	time_clock->stop();
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("���ھ��⻯ֱ��ͼ"));
		ImageProcessing Histogram(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = Histogram.picSrcChannelsSave();
		statusBar()->showMessage(tr("���ھ��⻯ֱ��ͼ......"));
	}
	statusBar()->showMessage(tr("���⻯ֱ��ͼ��ɣ�"));
	showFristFrame();
}