#pragma once
#include <Windows.h>

class DlgBoxTemPlate
{
public:
	DlgBoxTemPlate();
	virtual ~DlgBoxTemPlate();

	void CreateDlg(HINSTANCE hInstance, LPCSTR dlgResName, HWND parent);
	LRESULT CALLBACK WindowProc(HWND   hwnd, UINT   uMsg, WPARAM wParam, LPARAM lParam);

};

