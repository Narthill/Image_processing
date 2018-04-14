#include "imageOrVideo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//a.setQuitOnLastWindowClosed(false);
	imageOrVideo w=new imageOrVideo();
	
	w.show();
	return a.exec();
}