#include <iostream>
// iostream有的编译器也包含string

//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/imgproc/types_c.h>

// .hpp = .h + .cpp 实现和申明在同一个文件中，常用来发布开源库

//using namespace cv;
//using namespace std;

#include<vector>


// 万能模板？？？
//#include <stdio.h>
//#include <tchar.h>
//
//#include <fstream>
//
//#define CV_VERSION_ID CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)
//
//#ifdef _DEBUG
//#define cvLIB(name) "opencv_" name CV_VERSION_ID "d"
//#else
//#define cvLIB(name) "opencv_" name CV_VERSION_ID
//#endif
//
//#pragma comment( lib, cvLIB("core") )
//#pragma comment( lib, cvLIB("imgproc") )
//#pragma comment( lib, cvLIB("highgui") )
//#pragma comment( lib, cvLIB("flann") )
//#pragma comment( lib, cvLIB("features2d") )
//#pragma comment( lib, cvLIB("calib3d") )
//#pragma comment( lib, cvLIB("gpu") )
//#pragma comment( lib, cvLIB("legacy") )
//#pragma comment( lib, cvLIB("ml") )
//#pragma comment( lib, cvLIB("objdetect") )
//#pragma comment( lib, cvLIB("ts") )
//#pragma comment( lib, cvLIB("video") )
//#pragma comment( lib, cvLIB("contrib") )
//#pragma comment( lib, cvLIB("nonfree") )

#pragma once
class test30_OpenCv
{
public:
	void classMain();

	void operationImgOfOpenCV();

	int shwoImage();
	int openCamera();
	void openVideo();
	std::string findHumanFace();
	//void DetectFace(cv::Mat img, cv::Mat imgGray, cv::CascadeClassifier faceCascade,
	//	cv::CascadeClassifier eyes_Cascade);

	//int findMultFace();
	//void detectAndDraw(cv::Mat& img, cv::CascadeClassifier& cascade, 
	//	cv::CascadeClassifier& nestedCascade, double scale, bool tryflip);
	int rgbOrGbr();

	std::string paramAndNameSpace(std::string str);
};
