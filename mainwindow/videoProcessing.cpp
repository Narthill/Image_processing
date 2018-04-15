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

	ui->videoLabel->setAlignment(Qt::AlignCenter);//������Ƶ����
	ui->videoSlider->setEnabled(false);
	time_clock = new QTimer();
	
	connect(ui->actionopen, &QAction::triggered, this, &videoProcessing::openVideo);
	connect(ui->playBtn, &QPushButton::clicked, this, &videoProcessing::playVideo);
	connect(ui->pauseBtn, &QPushButton::clicked, this, &videoProcessing::pauseVideo);
	connect(time_clock, SIGNAL(timeout()), this, SLOT(playVideo()));

	connect(ui->videoSlider, &QSlider::sliderPressed, this, &videoProcessing::pauseVideo);
	connect(ui->videoSlider, &QSlider::sliderReleased, this, &videoProcessing::sliderReleased);

	//����
	connect(ui->actionGray, &QAction::triggered, this, &videoProcessing::video_Gary);
	connect(ui->actionSobel, &QAction::triggered, this, &videoProcessing::video_SobelSolt);
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
		ui->videoSlider->setEnabled(true);
		ui->menu_video->setEnabled(true);//����Ƶѡ��

		if (capture.isOpened()) { capture.release(); }
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
		secondEachFrame = 1000 / fps;//��ʱ��ʱ��=1000ms/֡��
		time_clock->setInterval(secondEachFrame);//���ö�ʱ��ʱ��

		ui->videoSlider->setRange(0, totalFrameNumber - 1);//��ʼ����Ƶ��
		nowFrameIndex = 0;//��ʼ����ǰ֡��λ��

		for (int i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("���ڼ�����Ƶ"));
			Mat frame;
			capture.read(frame);//��ȡ��һ֡
			videoQueue.push_back(frame);//ԭ��Ƶ��ֵ
			dstVideoQueue.push_back(frame);//������ƵҲҪ��ֵ
			statusBar()->showMessage(tr("���ڼ�����Ƶ......"));
		}
		statusBar()->showMessage(tr("��Ƶ������ϣ�"));
		showFristFrame();
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

//���ڹر��ź�
void videoProcessing::closeEvent(QCloseEvent *event)
{
	emit closeVideo();
}

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

void videoProcessing::video_SobelSolt() {
	time_clock->stop();
	EdgeDetection *EdgeDetectionDialog = new EdgeDetection();
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

	img = Mat2QImage(showFrame);//��ʾ��һ֡
	ui->videoLabel->clear();
	ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
	ui->videoLabel->show();
}

void videoProcessing::video_SobelCore(int w, int b, int s, int kSize) {
	time_clock->stop();
	for (long i = 0; i < totalFrameNumber; i++) {
		statusBar()->showMessage(tr("������ȡ��Ե"));
		ImageProcessing sobel(*(videoQueue.begin() + i));
		*(dstVideoQueue.begin() + i) = sobel.edgeDetection(w,b,s,kSize);
		statusBar()->showMessage(tr("������ȡ��Ե......"));
	}
	statusBar()->showMessage(tr("��ȡ��Ե��ɣ�"));
	showFristFrame();
}