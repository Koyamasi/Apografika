#include "StarterPage.h"
using namespace System;
using namespace System::Windows::Forms;


int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Apografika::StarterPage form;
	Application::Run(% form);

}