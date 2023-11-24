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
	cv::utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);  // ͨ��������־��ӡ������ٲ���Ҫ����־���
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
		if (waitKey(5) == 'q') break;  // ����q�˳�
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
