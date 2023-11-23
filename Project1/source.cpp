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
//ʹ��extern ��C�� ��"extern C"��һ���������ԣ�
//������C++����������C���Ժ�����
//��Ϊffmpeg����C���Ա�д�ģ����������������ӵ�ʱ����C�����淶�����ӣ�
//ȷ��C++�����FFmpegʹ����ͬ�ĺ�����
//����Ҫԭ����C������C���������ɺ���Ŀ���������������ͬ����
//�������������ڱ��������ʱʹ��C++������ʱ��
//���������رպ����������Σ�
//�Ӷ��������ܹ�ֱ��ʹ��FFmpeg��C������
//*/
//
//int main()
//{
//    std::cout << "Hello World!\n";
//    printf("%s\n", avcodec_configuration());
//}
