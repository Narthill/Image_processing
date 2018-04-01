#include"Mat2QImage.h"
#include<qDebug>
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
//QImage Mat2QImage(const cv::Mat& mat)
//{
//	// 8-bits unsigned, NO. OF CHANNELS = 1  
//	if (mat.type() == CV_8UC1)
//	{
//		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
//		// Set the color table (used to translate colour indexes to qRgb values)  
//		image.setColorCount(256);
//		for (int i = 0; i < 256; i++)
//		{
//			image.setColor(i, qRgb(i, i, i));
//		}
//		// Copy input Mat  
//		uchar *pSrc = mat.data;
//		for (int row = 0; row < mat.rows; row++)
//		{
//			uchar *pDest = image.scanLine(row);
//			memcpy(pDest, pSrc, mat.cols);
//			pSrc += mat.step;
//		}
//		return image;
//	}
//	// 8-bits unsigned, NO. OF CHANNELS = 3  
//	else if (mat.type() == CV_8UC3)
//	{
//		// Copy input Mat  
//		const uchar *pSrc = (const uchar*)mat.data;
//		// Create QImage with same dimensions as input Mat  
//		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
//		return image.rgbSwapped();
//	}
//	else if (mat.type() == CV_8UC4)
//	{
//		qDebug() << "CV_8UC4";
//		// Copy input Mat  
//		const uchar *pSrc = (const uchar*)mat.data;
//		// Create QImage with same dimensions as input Mat  
//		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
//		return image.copy();
//	}
//	else
//	{
//		qDebug() << "ERROR: Mat could not be converted to QImage.";
//		return QImage();
//	}
//}
