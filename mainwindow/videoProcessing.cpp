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

	//connect(this, SIGNAL(closeVideo()), parentWidget(), SLOT(showMain()));

}

videoProcessing::~videoProcessing()
{
	delete ui;
}

//����
void videoProcessing::save() {
	time_clock->stop();
	if (!fileName.isEmpty()) {
		string fileSave = fileName.toStdString();
		VideoWriter out(fileSave, fourcc, fps, Size(videoWidth, videoHeight));
		for (long i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("���ڱ�����Ƶ"));
			Mat next_frame;
			next_frame = *(videoQueue.begin() + i);
			out.write(next_frame);
			statusBar()->showMessage(tr("���ڱ�����Ƶ..."));
		}
		statusBar()->showMessage(tr("������ϣ�"));
	}
}

//���Ϊ
void videoProcessing::saveAs() {
	QString otherFilename = QFileDialog::getSaveFileName(this,
		tr("��Ƶ����"),
		".",
		tr("video Files(*.avi)"));
	if (!otherFilename.isEmpty()) {
		string fileSave = otherFilename.toStdString();
		VideoWriter out(fileSave, fourcc, fps, Size(videoWidth, videoHeight));
		for (long i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("���ڱ�����Ƶ"));
			Mat next_frame;
			next_frame = *(videoQueue.begin() + i);
			out.write(next_frame);
			statusBar()->showMessage(tr("���ڱ�����Ƶ..."));
		}
		statusBar()->showMessage(tr("������ϣ�"));
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
		//��ȡ��֡��
		totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);
		//֡��
		fps = capture.get(CV_CAP_PROP_FPS);
		secondEachFrame = 1000 / fps;//��ʱ��ʱ��=1000ms/֡��
		time_clock->setInterval(secondEachFrame);//���ö�ʱ��ʱ��

		

		for (int i = 0; i < totalFrameNumber; i++) {
			statusBar()->showMessage(tr("���ڼ�����Ƶ"));
			Mat frame;
			capture.read(frame);//��ȡ��һ֡
			videoQueue.push_back(frame);
			statusBar()->showMessage(tr("���ڼ�����Ƶ......"));
		}
		statusBar()->showMessage(tr("��Ƶ������ϣ�"));

		Mat frameOne = *videoQueue.begin();

		img = Mat2QImage(frameOne);//��ʾ��һ֡
		ui->videoLabel->clear();
		ui->videoLabel->setPixmap((QPixmap::fromImage(img)));
		ui->videoLabel->show();
	}

	
	ui->videoSlider->setRange(0, totalFrameNumber-1);
	nowFrameIndex = 0;
}

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
	time_clock->stop();//��ʱ��ֹͣ
}
void videoProcessing::sliderReleased() {
	//�����ͷ�
	if (ui->videoSlider->value() != totalFrameNumber) {
		time_clock->start();//�������һ֡�Ϳ��Խ���ʱ����
	}
	nowFrameIndex = ui->videoSlider->value();
	nowframe = *(videoQueue.begin() + nowFrameIndex);//����Ƶ��λ����ǰ֡

}

void videoProcessing::closeEvent(QCloseEvent *event)
{
	emit closeVideo();
}