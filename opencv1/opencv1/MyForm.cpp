#include "stdafx.h"
#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	opencv1::MyForm form;   //WinForm - name of your project
	Application::Run(%form);
}

