#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;



[STAThread]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew AssaultCube::Main());

	return 0;
}
