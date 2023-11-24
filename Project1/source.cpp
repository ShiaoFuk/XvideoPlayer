#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/utils/logger.hpp>
#include <iostream>

//#include <opencv2/core/utils/logger.hpp>
//#include <opencv2/calib3d.hpp>
//#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
//void printMs(const char* text = "") {
//	static long long last = 0;
//	long long cur = getTickCount();  // int 64
//	if (last == 0) {
//		last = cur;
//
//		return;
//	}
//	long long ms = 0;
//	ms = (double(cur - last) / getTickFrequency()) * 1000;
//	if (*text != 0) {
//		printf("%s = %dms\n", text, ms);
//	}
//}


int main() {
	cv::utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);  // 通过设置日志打印级别减少不必要的日志输出
	VideoCapture cam(0);
	namedWindow("cam");
	if (!cam.isOpened()) {
		cout << "cam open failed" << endl;
		getchar();
		return -1;
	}
	Mat img;
	int fps = cam.get(CAP_PROP_FPS);
	if (fps <= 0) fps = 25;
	VideoWriter vw;
	vw.open("out.avi",
		VideoWriter::fourcc('X', '2', '6', '4'),
		fps,
		Size(cam.get(CAP_PROP_FRAME_WIDTH),
			cam.get(CAP_PROP_FRAME_HEIGHT))
		);
	if (!vw.isOpened()) {
		perror("video open failed");
		return -1;
	}
	for (;;) {
		cam.read(img);
		if (img.empty()) {
			break;
		}
		imshow("cam", img);
		vw.write(img);
		if (waitKey(5) == 'q') break;  // 按下q退出
	}
	vw.release();
	//imshow()
	waitKey(0);
	return 0;
}


//#include <iostream>
//
//extern "C" {
//#include "libavcodec/avcodec.h"
//#include "libavformat/avformat.h"
//}
///*
//使用extern “C” 。"extern C"是一种语言特性，
//用于在C++代码中引用C语言函数。
//因为ffmpeg是用C语言编写的，告诉链接器在链接的时候用C函数规范来链接，
//确保C++代码和FFmpeg使用相同的函数名
//（主要原因是C＋＋和C程序编译完成后在目标代码中命名规则不同）。
//这样，当我们在编译和链接时使用C++编译器时，
//编译器将关闭函数名称修饰，
//从而让我们能够直接使用FFmpeg的C函数。
//*/
//
//int main()
//{
//    std::cout << "Hello World!\n";
//    printf("%s\n", avcodec_configuration());
//}
