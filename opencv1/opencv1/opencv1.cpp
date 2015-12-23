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
	// сохраняем кадр в файл
	sprintf(filename, "M:\Image%d.jpg", counter);
	printf("[информация] Сделан снимок -  %s\n", filename);
	cvSaveImage(filename, CamShot);
	counter++;


}


int main()
{

	setlocale(LC_ALL, "Russian");

	//////////////////////
	printf("Нажмите ENTER для снимка с веб камеры или ESC для выхода из программы!\n\n");
	//////////////////////

	CvCapture* Camera = cvCreateCameraCapture(1); // камера с индексом 1 (включена)

	if (!Camera)
	{
		printf("Камера недоступна!\n\n");
		return 0;
	}
	printf("Камера доступна!\n\n");

	//Задаём width и height
	cvSetCaptureProperty(Camera, CV_CAP_PROP_FRAME_WIDTH, width);
	cvSetCaptureProperty(Camera, CV_CAP_PROP_FRAME_HEIGHT, height);
	//Окно создаётся для обработки клавиш
	//cvNamedWindow("Веб-камера", 1);//1 = авто размер




	while (true){
		// получаем кадр
		CamShot = cvQueryFrame(Camera);

		// показываем картинку создавая каждый раз окно
		cvShowImage("Изображение с WEB CAM", CamShot);

		char c = cvWaitKey(33);
		if (c == 27) { // нажата ESC
			break;
		}
		else if (c == 13) { // Enter
			SaveImage();
		}
	}
	// освобождаем ресурсы
	cvReleaseCapture(&Camera);
	cvDestroyWindow("capture");
	return 0;
}