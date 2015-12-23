#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include<TCHAR.H>
#include <conio.h>
#include "opencv\cv.h"
#include "opencv\highgui.h"



IplImage* CamShot = 0;
double width = 640;
double height = 480;
int counter = 0;
char filename[512];


void SaveImage()
{
	// ��������� ���� � ����
	sprintf(filename, "M:\Image%d.jpg", counter);
	printf("[����������] ������ ������ -  %s\n", filename);
	cvSaveImage(filename, CamShot);
	counter++;


}


int main()
{

	setlocale(LC_ALL, "Russian");

	//////////////////////
	printf("������� ENTER ��� ������ � ��� ������ ��� ESC ��� ������ �� ���������!\n\n");
	//////////////////////

	CvCapture* Camera = cvCreateCameraCapture(1); // ������ � �������� 1 (��������)

	if (!Camera)
	{
		printf("������ ����������!\n\n");
		return 0;
	}
	printf("������ ��������!\n\n");

	//����� width � height
	cvSetCaptureProperty(Camera, CV_CAP_PROP_FRAME_WIDTH, width);
	cvSetCaptureProperty(Camera, CV_CAP_PROP_FRAME_HEIGHT, height);
	//���� �������� ��� ��������� ������
	//cvNamedWindow("���-������", 1);//1 = ���� ������




	while (true){
		// �������� ����
		CamShot = cvQueryFrame(Camera);

		// ���������� �������� �������� ������ ��� ����
		cvShowImage("����������� � WEB CAM", CamShot);

		char c = cvWaitKey(33);
		if (c == 27) { // ������ ESC
			break;
		}
		else if (c == 13) { // Enter
			SaveImage();
		}
	}
	// ����������� �������
	cvReleaseCapture(&Camera);
	cvDestroyWindow("capture");
	return 0;
}