#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 전역변수 설정
vector<Rect> icons;		// 아이콘
Mat image;				// 그림판 영상
int hue;
Point pt1, pt2;			// 시작 좌표, 종료 좌표

#include "PaintBrush.h"

int main()
{
	image = Mat(500, 800, CV_8UC3, Scalar(255, 255, 255));  // 그림판 초기화
	placement_icons(Size(60, 60));

	// 팔레트 추가
	Rect last_icon = *(icons.end() - 1);					// 아이콘 사각형 마지막 원소의 시작 위치-> [60 x 60 from (60, 300)]
	Point start_palette = Point(0, last_icon.br().y + 5);	// 팔레트 시작 위치 -> (0, 365)

	icons.push_back(Rect(start_palette, Size(100, 100)));					// 팔레트 사각형 추가
	icons.push_back(Rect(start_palette + Point(105, 0), Size(15, 100)));	// 색상 인덱스 사각형

	create_palette(start_palette.y, icons[PALETTE]);		// 팔레트 생성
	create_hueIndex(icons[13]);								// 색상 인덱스 생성

	hello();

	imshow("그림판", image);


	waitKey();
	return 0;
}
