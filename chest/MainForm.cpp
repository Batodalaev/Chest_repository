#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;



[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	chest::MainForm form;
	Application::Run(%form);
}