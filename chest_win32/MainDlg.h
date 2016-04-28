#pragma once
#include "DlgBoxTemPlate.h"
#include "resource.h"
class MainDlg : public DlgBoxTemPlate
{
public:
	MainDlg(HINSTANCE hInstance, LPCSTR dlgResName, HWND hwndparent);
	~MainDlg();
	LRESULT RealDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void OnCreate();
};

