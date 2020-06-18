#include "test30_OpenCv.h"
#include <iostream>
// iostream有的编译器也包含string

#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>

#include<vector>


// opencv实现数字图像处理
// opencv提供的基础操作 - 图像的输入，输出，自动内存管理
// 










// 人脸检测相关
// #include <opencv/cv.h>
// #include <opencv/highgui.h>

// 原先使用的命名空间
//using namespace cv;
//using namespace std;

void test30_OpenCv::classMain()
{
	std::cout << "test30_OpenCv" << "\n";

	int stature = 0;
	std::string result = "初始化";

	this->operationImgOfOpenCV();

	//stature = this->shwoImage();
	//stature = this->openCamera();
	//this->openVideo();
	//stature = this->rgbOrGbr();
	//stature = this->findMultFace();
	std::cout << "执行结果" << stature << "\n";

	//result = this->findHumanFace();

	std::cout << "执行结果：" << result << "\n";

	//std::string str = "参数和命名空间测试";
	//std::cout << this->paramAndNameSpace(str) << "\n";



}

// opencv基础数字图像处理
void test30_OpenCv::operationImgOfOpenCV()
{
	//不做任何转化进行读取
	cv::Mat matUnchanged = cv::imread(".\\image\\lena.jpg", cv::IMREAD_UNCHANGED);
	cv::imshow("UNCHANGED", matUnchanged);

	//彩色模式进行读取	
	cv::Mat matColor = cv::imread(".\\image\\lenna.jpeg", cv::IMREAD_COLOR);
	cv::imshow("COLOR", matColor);

	//灰度模式进行读取
	cv::Mat matGrayScale = cv::imread(".\\image\\lenna.jpeg", cv::IMREAD_GRAYSCALE);
	cv::imshow("GRAYSCALE", matGrayScale);

	// 获取图像属性
	//cv::Mat matUnchanged = cv::imread("./lena.jpg", cv::IMREAD_UNCHANGED);
	//宽度
	std::cout << "宽度：" << matUnchanged.cols << std::endl;
	//高度
	std::cout << "高度：" << matUnchanged.rows << std::endl;
	//数据缓存区指针 - 无符号数
	unsigned char* pData = matUnchanged.data;
	std::cout << "数据地址：" << &pData << std::endl;
	//通道数 - 
	std::cout << "通道数：" << matUnchanged.channels() << std::endl;
	//深度 - 像素字节数 / 8 * 通道数
	//elemSize函数返回的是一个像素占用的字节数
	std::cout << "深度：" << matUnchanged.elemSize() / matUnchanged.channels() * 8 << std::endl;
	cv::imshow("UNCHANGED", matUnchanged);
	cv::waitKey(0);

	// 图像遍历 - win中为BGR遍历，openCV的at成员函数提供图像数据的访问接口
	for (size_t r = 0; r < matUnchanged.rows; r++)//行
		for (size_t c = 0; c < matUnchanged.cols; c++)//列
		{
			cv::Vec3b& bgr = matUnchanged.at<cv::Vec3b>(r, c);
			bgr[2] = 0;
		}

	// 图像遍历 - 使用指针
	for (size_t r = 0; r < matUnchanged.rows; r++)//行
	{
		//step返回图像一行的字节数
		unsigned char* pRow = matUnchanged.data + r * matUnchanged.step[0];//计算图像行首指针
		for (size_t c = 0; c < matUnchanged.cols; c++)//列
		{
			pRow[3 * c + 2] = 0;
		}
	}


	// 图像遍历 - 行首指针存储法
	//存储图像行首指针
	std::vector<unsigned char*> rowPtr(matUnchanged.rows);
	for (size_t r = 0; r < matUnchanged.rows; r++)
		rowPtr[r] = matUnchanged.data + r * matUnchanged.step[0];

	//遍历图像
	for (size_t r = 0; r < matUnchanged.rows; r++)//行
		for (size_t c = 0; c < matUnchanged.cols; c++)//列
		{
			rowPtr[r][c * 3 + 2] = 0;
		}



	// 参考
	// https://blog.csdn.net/huqiang_823/article/details/80698670


}


// 显示图片
int test30_OpenCv::shwoImage()
{
	cv::Mat imageJpg = cv::imread(".\\image\\01.jpg"); // .当前文件夹下的路径，不是.. 他表示父文件夹下的路径
	cv::Mat imagePng = cv::imread(".\\image\\02.png");
	cv::Mat imageJpeg = cv::imread(".\\image\\03.jpeg");
	bool a = false;
	a = imageJpg.empty(); // 图片的data，zise,dims为空时，则表示图片为空，不能显示
	if (imageJpg.empty()) {

		printf("could not load image...\n");

		return -1;

	}

	cv::namedWindow("test_opencv_setup-jpg", 10); // 新建窗口,并设置显示类型，其类型是一个枚举。若为WINDOW_AUTOSIZE则自适应图像大小。
	cv::imshow("test_opencv_setup-jpg", imageJpg); // 装入图片

	if (imagePng.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	cv::namedWindow("test_opencv_setup-png", 0);
	cv::imshow("test_opencv_setup-png", imagePng);

	if (imageJpeg.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	cv::namedWindow("test_opencv_setup-jpeg", 0);
	cv::imshow("test_opencv_setup-jpeg", imageJpeg);

	// 等待时间
	cv::waitKey(0);
	return 0;


}

// 打开摄像头
int test30_OpenCv::openCamera()
{

	cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	cap.open(0);
	// VideoCapture cap(0);这句话可以替代上面两个语句，效果是一致的。
	if (!cap.isOpened())
	{
		std::cout << "不能打开摄像头。。。" << "\n";
		return -1;
	}

	cv::Mat frame;
	while (1)
	{
		cap >> frame;
		if (frame.empty())
		{
			break;
		}
		cv::imshow("Example", frame);
		if (cv::waitKey(33) >= 0) break;
	}
	std::getchar();
	return 0;
}

// 读取视频为图像
void test30_OpenCv::openVideo()
{

	cv::VideoCapture cap;
	cap.open(".\\image\\video\\faceVideo.mp4"); //打开视频,以上两句等价于VideoCapture cap("E://2.avi");

	 //cap.open("http://www.laganiere.name/bike.avi");//也可以直接从网页中获取图片，前提是网页有视频，以及网速够快
	if (!cap.isOpened()) return; //如果视频不能正常打开则返回
	cv::Mat frame;
	while (1)
	{
		cap >> frame;//等价于cap.read(frame);
		if (frame.empty()) break; //如果某帧为空则退出循环
		cv::imshow("video", frame);
		cv::waitKey(50);//每帧延时20毫秒
	}
	cap.release();//释放资源
}


// 人脸检测
// 来源
// https://zhuanlan.zhihu.com/p/31852169
// 检测思路：
// 先把图片转为灰度，接着将图片直方均匀化，在上面处理后的图片矩阵中检测脸的区域，然后把脸这一块圈出来去检测眼睛。
//std::string test30_OpenCv::findHumanFace()
//{
//	// opencv库中的类
//	cv::CascadeClassifier faceCascade; // 人脸分类器
//	cv::CascadeClassifier eyes_Cascade;
//
//	cv::VideoCapture cap;
//	if (!cap.open(".\\image\\video\\faceVideo.mp4")) { // 检测视频中的人脸
//		std::cout << "摄像头打开失败!!" << "\n";
//		return "摄像头打开失败";
//	}
//	if (!faceCascade.load(".\\model\\haarcascade_frontalface_alt2.xml")) { // 加载人脸分类器
//		std::cout << "人脸检测级联分类器没找到！！" << "\n";
//		return "加载人脸分类器失败";
//	}
//	if (!eyes_Cascade.load(".\\model\\haarcascade_eye_tree_eyeglasses.xml")) { // 加载人眼分类器
//		std::cout << "眼睛检测级联分类器没找到！！" << "\n";
//		return "加载人眼分类器失败";
//	}
//	cv::Mat img, imgGray;
//	int fps = 60; // 帧数
//	while (true) {
//		cap >> img;
//		if (img.empty()) break;
//		else
//		{
//			cv::cvtColor(img, imgGray, CV_BGR2GRAY);
//			cv::equalizeHist(imgGray, imgGray);//直方图均匀化 - 直方图均衡化
//			this->DetectFace(img, imgGray, faceCascade, eyes_Cascade);
//			cv::waitKey(1000 / fps); // 等待若干毫秒后关闭窗口，若为0或()，则一直等待
//		}
//	}
//	cap.release(); // 释放资源
//	return "成功";
//}
//
//void test30_OpenCv::DetectFace(cv::Mat img, cv::Mat imgGray, cv::CascadeClassifier faceCascade, cv::CascadeClassifier eyes_Cascade)
//{
//
//	// opencv库中的类
//	//CascadeClassifier faceCascade;
//	//CascadeClassifier eyes_Cascade;
//
//	cv::namedWindow("src", cv::WINDOW_AUTOSIZE); // 原始图窗口
//	cv::namedWindow("gray_face", cv::WINDOW_AUTOSIZE); // 灰度图窗口
//	cv::namedWindow("binary_face", cv::WINDOW_AUTOSIZE); // 二值图窗口
//	std::vector<cv::Rect> faces, eyes; // 在using namespace std中，也可通过 #include<vector>引入
//
//	faceCascade.detectMultiScale(imgGray, faces, 1.2, 5, 0, cv::Size(30, 30)); // 检测的参数，表示框的范围
//
//	for (auto b : faces) { // auto的变量类型是由编译器推导的出的
//		// x,y是人脸左下角的坐标
//		std::cout << "输出一张人脸位置：(x,y):" << "(" << b.x << "," << b.y << ") , (宽度,高度):(" << b.width << "," << b.height << ")" << "\n";
//	}
//
//	// 在每一帧上把检测到的人脸标记出来
//	if (faces.size() > 0) {
//		for (size_t i = 0; i < faces.size(); i++) { // size_t 是size type，保存的是表示大小类型的整数，类似int，long
//			cv::putText(img, "big face !!!", cvPoint(faces[i].x, faces[i].y - 10), cv::FONT_HERSHEY_PLAIN, 2.0, cv::Scalar(0, 0, 255));
//
//			// 绘制矩形
//			// Point是点的模板类，Scalar是颜色的模板类，是一个向量
//			cv::rectangle(img, cv::Point(faces[i].x, faces[i].y), cv::Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), cv::Scalar(0, 0, 255), 1, 8);
//			std::cout << faces[i] << "\n";
//
//			// 将人脸从灰度图中抠出来
//			cv::Mat face_ = imgGray(faces[i]);
//			cv::Mat result;
//			cv::imshow("gray_face", face_); // 显示灰度图
//			eyes_Cascade.detectMultiScale(face_, eyes, 1.2, 2, 0, cv::Size(30, 30));
//
//			cv::threshold(face_, result, 170, 255, CV_THRESH_BINARY); // 把face_进行二值化后输出到resule中
//			cv::imshow("binary_face", result);
//			for (size_t j = 0; j < eyes.size(); j++) {
//
//				// 级联分类器
//				cv::Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
//				int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
//				cv::circle(img, eye_center, radius, cv::Scalar(65, 105, 255), 4, 8, 0);
//			}
//		}
//	}
//	cv::imshow("src", img); // 输出原图
//}



// 另一种方式
// https://blog.csdn.net/li_wen01/article/details/78369751


//int test30_OpenCv::findMultFace()
//{
//	// 宏定义可放在方法体内，但会减小作用域
//#define CASCADENAME			".\\model\\haarcascade_frontalface_alt2.xml"
//#define NESTEDCASCADENAME	".\\model\\haarcascade_eye_tree_eyeglasses.xml"
//#define FACEPHOTO_FACENAME  ".\\image\\face\\fa01.jpeg" // 这张图没用到
//#define DETECT_IMAGE		".\\image\\face\\fa02.jpeg"
//
//	cv::Mat frame, image;
//	bool tryflip = true;
//	cv::CascadeClassifier cascade, nestedCascade;
//	double scale = 1.3;
//
//	/* 加载分类器 */
//	if (!nestedCascade.load(NESTEDCASCADENAME))
//	{
//		std::cerr << "WARNING: Could not load classifier cascade for nested objects" << std::endl;
//	}
//	if (!cascade.load(CASCADENAME))
//	{
//		std::cerr << "ERROR: Could not load classifier cascade" << std::endl;
//		return -1;
//	}
//
//	/* 加载图片 */
//	image = cv::imread(DETECT_IMAGE, 1);
//	if (image.empty())
//	{
//		std::cout << "Couldn't read iamge" << DETECT_IMAGE << std::endl;
//
//	}
//
//	std::cout << "Detecting face(s) in " << DETECT_IMAGE << std::endl;
//
//	/* 检测人脸及眼睛并画出检测到的区域 */
//	if (!image.empty())
//	{
//		// 入参：图片，人脸，人眼识别引擎，图片缩小比例，
//		this->detectAndDraw(image, cascade, nestedCascade, scale, tryflip);
//		cv::waitKey(0);
//	}
//	return 0;
//}


// 检测和标记
//void test30_OpenCv::detectAndDraw(cv::Mat& img, cv::CascadeClassifier& cascade,
//	cv::CascadeClassifier& nestedCascade, double scale, bool tryflip)
//{
//	double t = 0;
//	std::vector<cv::Rect> faces, faces2;
//	/* 定义七种颜色用于人脸标记 */
//	const static cv::Scalar colors[] =
//	{
//		cv::Scalar(255,0,0),
//		cv::Scalar(255,128,0),
//		cv::Scalar(255,255,0),
//		cv::Scalar(0,255,0),
//		cv::Scalar(0,128,255),
//		cv::Scalar(0,255,255),
//		cv::Scalar(0,0,255),
//		cv::Scalar(255,0,255)
//	};
//
//	cv::Mat gray, smallImg;
//
//	/* 因为用的是类haar特征，所以都是基于灰度图像的，这里要转换成灰度图像 */
//	cvtColor(img, gray, cv::COLOR_BGR2GRAY);
//
//	/* 将图片缩小，加快检测速度 */
//	double fx = 1 / scale;
//	/* 将尺寸缩小到1/scale, 用线性插值 */
//	cv::resize(gray, smallImg, cv::Size(), fx, fx, cv::INTER_LINEAR);
//	/* 直方图均衡化 */
//	cv::equalizeHist(smallImg, smallImg);
//
//	/* 用来计算算法执行时间 */
//	t = (double)cv::getTickCount(); // 得到时钟计数时间
//
//	/*detectMultiScale - 人脸检测函数，可检测出图片中所有人脸，并用vector保存各个人脸的位置，大小(用矩形表示)
//		smallImg：输入的原图
//		faces	：表示检测到的人脸目标序列
//		1.1		：每次图像尺寸减小的比例为1.1
//		3		：每一个目标至少要被检测到3次才算是真的目标
//		CV_HAAR_SCALE_IMAGE：表示不是缩放分类器来检测，而是缩放图像
//		Size(30, 30) 目标的最大最小尺寸
//	*/
//	cascade.detectMultiScale(smallImg, faces, 1.1, 3, cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
//	if (tryflip)
//	{
//		flip(smallImg, smallImg, 1);
//		cascade.detectMultiScale(smallImg, faces2, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
//		for (std::vector<cv::Rect>::const_iterator r = faces2.begin(); r != faces2.end(); ++r)
//		{
//			faces.push_back(cv::Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
//		}
//	}
//
//	/* 相减为算法执行的时间 */
//	t = (double)cv::getTickCount() - t;
//	printf("detection time = %g ms\n", t * 1000 / cv::getTickFrequency());
//
//	for (size_t i = 0; i < faces.size(); i++)
//	{
//		cv::Rect r = faces[i];
//		cv::Mat smallImgROI;
//		std::vector<cv::Rect> nestedObjects;
//		cv::Point center;
//		cv::Scalar color = colors[i % 8];
//		int radius;
//
//		/* 人脸长宽比例，在0.75-1.3 间画圆，其他范围画矩形 */
//		double aspect_ratio = (double)r.width / r.height;
//		if (0.75 < aspect_ratio && aspect_ratio < 1.3)
//		{
//			/*还原原来尺寸 计算圆心和圆半径 */
//			center.x = cvRound((r.x + r.width * 0.5) * scale);
//			center.y = cvRound((r.y + r.height * 0.5) * scale);
//			radius = cvRound((r.width + r.height) * 0.25 * scale);
//			/* 画出人脸检测区域 画圆 */
//			cv::circle(img, center, radius, color, 3, 8, 0);
//		}
//		else
//		{
//			/* 画出检测区域，画矩形 */
//			cv::rectangle(img, cvPoint(cvRound(r.x * scale), cvRound(r.y * scale)),
//				cvPoint(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)), color, 3, 8, 0);
//		}
//
//		/* 检测到人眼，在人脸上画出人眼 */
//		if (nestedCascade.empty())
//		{
//			continue;
//		}
//
//		smallImgROI = smallImg(r);
//
//		/* 人眼检测 */
//		nestedCascade.detectMultiScale(smallImgROI, nestedObjects, 1.1, 2, cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
//		for (size_t j = 0; j < nestedObjects.size(); j++)
//		{
//			cv::Rect nr = nestedObjects[j];
//			/*还原原来尺寸 计算圆心和圆半径 */
//			center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
//			center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
//			radius = cvRound((nr.width + nr.height) * 0.25 * scale);
//			/* 画出人眼检测区域 画圆*/
//			cv::circle(img, center, radius, color, 3, 8, 0);
//		}
//	}
//	/* 显示图像 img */
//	cv::imshow("result", img);
//}


// 有趣的例子
// https://blog.csdn.net/weixin_42142612/article/details/80804039
// 像素可视化插件
// https://blog.csdn.net/u011574296/article/details/73286820
int test30_OpenCv::rgbOrGbr()
{
	cv::Mat src = cv::imread(".\\image\\face\\fa01.jpeg", 1);
	if (src.empty() || src.channels() != 3)
	{
		std::cout << "Source image load error!" << std::endl;
		return -1;
	}

	//采用CV_BGR2GRAY,转换公式Gray = 0.1140*B + 0.5870*G + 0.2989*R
	cv::Mat bgr2grayImg;
	cvtColor(src, bgr2grayImg, CV_BGR2GRAY);

	//采用CV_RGB2GRAY,转换公式Gray = 0.1140*R + 0.5870*G + 0.2989*B
	cv::Mat rgb2grayImg;
	cvtColor(src, rgb2grayImg, CV_RGB2GRAY);

	//采用CV_GRAY2BGR,转换公式B = G = R = Gray
	cv::Mat gray2bgrImg;
	cvtColor(bgr2grayImg, gray2bgrImg, CV_GRAY2BGR);

	//采用CV_GRAY2RGB,转换公式R = G = B = Gray
	cv::Mat gray2rgbImg;
	cvtColor(rgb2grayImg, gray2rgbImg, CV_GRAY2RGB);

	cv::waitKey(0);
	return 0;
}

// 活体检测


// 参数与命名空间
std::string test30_OpenCv::paramAndNameSpace(std::string str)
{
	std::cout << str + "----------" << "\n";
	return str;
}
