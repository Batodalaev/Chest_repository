#pragma once
#include <Windows.h>

class DlgBoxTemPlate
{
public:
	DlgBoxTemPlate(HINSTANCE hInstance, LPCSTR dlgResName, HWND hwndparent);	
	virtual ~DlgBoxTemPlate();
	void Show(int nCmdShow);
private:
	virtual void OnCreate() = 0;	
	void CreateDlg(HINSTANCE hInstance, LPCSTR dlgResName, HWND parent);
	static LRESULT WINAPI StDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
	virtual LRESULT RealDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	HWND m_hWnd;
};


