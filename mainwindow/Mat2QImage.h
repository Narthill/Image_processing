#ifndef MAT2QIMAGE_H
#define MAT2QIMAGE_H
#include <QMainWindow>
#include<opencv2/opencv.hpp>  
using namespace cv;
QImage Mat2QImage(const cv::Mat& InputMat);
#endif