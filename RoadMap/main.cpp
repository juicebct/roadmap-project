#include "mainwindow.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    RoadMap::mainwindow form;
    Application::Run(% form);

    Application::Exit();

    return 0;
}