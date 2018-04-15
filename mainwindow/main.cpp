#include "imageOrVideo.h"
#include <QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//a.setQuitOnLastWindowClosed(false);
	imageOrVideo w;
	w.setWindowTitle(QObject::tr("图像视频处理"));
	w.show();
	return a.exec();
}