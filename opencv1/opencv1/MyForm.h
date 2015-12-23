#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vcclr.h>



#include "opencv\cv.h"
#include "opencv\highgui.h"




IplImage* CamShot = 0;
double width = 640;
double height = 480;
int counter = 0;



namespace opencv1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;


	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button3;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 498);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 54);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Камера";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(108, 498);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(90, 54);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Сохранить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::saveFileDialog1_FileOk);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Multiselect = true;
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(819, 480);
			this->panel1->TabIndex = 3;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(837, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 61);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Галерея";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuBar;
			this->ClientSize = System::Drawing::Size(970, 567);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Камера";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
				
			
			SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

			saveFileDialog1->InitialDirectory = "c:\\";
			saveFileDialog1->Filter = "Bitmap files (*.bmp)|*.bmp|JPEG files (*.jpg)|*.jpg";
			saveFileDialog1->FilterIndex = 2;
			saveFileDialog1->RestoreDirectory = true;

			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if (saveFileDialog1->FileName)
				{
					IntPtr file_name_interop = Marshal::StringToHGlobalAnsi(saveFileDialog1->FileName);
					const char* file_name = static_cast<const char*>(file_name_interop.ToPointer());
					printf("[информация] Сделан снимок -  %s\n", file_name);
					cvSaveImage(file_name, CamShot);
					//ofstream fout("myphoto.txt", ios::app);
					
					Marshal::FreeHGlobal(file_name_interop);
				}
			}
		
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 {

					 setlocale(LC_ALL, "Russian");

					 CvCapture* Camera = cvCreateCameraCapture(1); // камера с индексом 1 (включена)

					 if (!Camera)
					 {
						 printf("Камера недоступна!\n\n");
						 
					 }
					 printf("Камера доступна!\n\n");

					 //Задаём width и height
					 cvSetCaptureProperty(Camera, CV_CAP_PROP_FRAME_WIDTH, width);
					 cvSetCaptureProperty(Camera, CV_CAP_PROP_FRAME_HEIGHT, height);
					
					 while (1)
					 {
						 // получаем кадр
						 CamShot = cvQueryFrame(Camera);

						 // показываем картинку создавая каждый раз окно
						 cvShowImage("Изображение с WEB CAM", CamShot);

						 char c = cvWaitKey(1);
						 if (c == 27) // ждем ESC
						 {
							 break;
						 }
					 }
				

					 // освобождаем ресурсы
					 cvReleaseCapture(&Camera);
					 //cvDestroyWindow("capture");
					 cvDestroyAllWindows();
				 }
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 /*switch (comboBox1->SelectedIndex)
			 {
			 case 0: pictureBox1->Image = Image::FromFile("M:\\Image1.jpg");	break;
			 case 1: pictureBox1->Image = Image::FromFile("M:\\Image2.jpg");	break;
			 case 2: pictureBox1->Image = Image::FromFile("M:\\Image3.jpg");	break;
			 case 3: pictureBox1->Image = Image::FromFile("M:\\Image4.jpg");	break;
			 case 4: pictureBox1->Image = Image::FromFile("M:\\Image5.jpg");	break;
			 }*/
			
}
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}

private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 int height1 = 328, width1 = 193;
				 int x = 12, y = 12, diff = 10;
				 for each(String^ file_name in openFileDialog1->FileNames)
				 {
					 Image^ img = Image::FromFile(file_name);
					 PictureBox^ pb = gcnew PictureBox;
					 pb->Size = System::Drawing::Size::Size(height1, width1);
					 pb->SizeMode = PictureBoxSizeMode::StretchImage;
					 pb->Image = img;
					 if (x > 2 * diff + 2 * width1)
					 {
						 x = 12;
						 y += height1 + diff;
					 }
					 else
					 {
						 x += width1 + diff;
					 }
					 pb->Location = Point::Point(x, y);
					 x += diff;

					 panel1->Controls->Add(pb);
				 }
			 }
}
};
}
