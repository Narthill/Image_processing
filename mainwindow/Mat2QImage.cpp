#include"Mat2QImage.h"

QImage Mat2QImage(const cv::Mat& InputMat)

{

	cv::Mat TmpMat;


	// convert the color space to RGB  

	if (InputMat.channels() == 1)

	{
		cv::cvtColor(InputMat, TmpMat, CV_GRAY2RGB);
	}
	else
	{
		cv::cvtColor(InputMat, TmpMat, CV_BGR2RGB);
	}

	// construct the QImage using the data of the mat, while do not copy the data  

	QImage Result = QImage((const uchar*)(TmpMat.data), TmpMat.cols, TmpMat.rows, TmpMat.step,
		QImage::Format_RGB888);
	//这是因为QImage图的数据是以字节为单位保存的，每一行的字节数必须是4的整数倍。
	//然而在实际运行过程中image的每行字节可能会有所不同，容易导致图像转换出错或图像效果与原图像不同。
	//这时可以添加&mat.step参数解决。
	// deep copy the data from mat to QImage  

	Result.bits();


	return Result;
}
