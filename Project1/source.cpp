#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

//#include <opencv2/core/utils/logger.hpp>
//#include <opencv2/calib3d.hpp>
//#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
void printMs(const char* text = "") {
	static long long last = 0;
	long long cur = getTickCount();  // int 64
	if (last == 0) {
		last = cur;

		return;
	}
	long long ms = 0;
	ms = (double(cur - last) / getTickFrequency()) * 1000;
	if (*text != 0) {
		printf("%s = %dms\n", text, ms);
	}
}


int main() {
	VideoCapture video;
	video.open("X:\\opencv\\build\\x64\\vc16\\bin\\video.mp4");
	if (video.isOpened() == false) {
		perror("open video failed!");
		getchar();
		return -1;
	}
	cout << "open video success!" << endl;
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
