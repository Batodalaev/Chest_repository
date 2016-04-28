#include "resource.h"
#include "DlgBoxTemPlate.h"
#include <Windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DlgBoxTemPlate* dlg1 = new DlgBoxTemPlate();
	dlg1->WindowProc(NULL, NULL, NULL,NULL);
}

