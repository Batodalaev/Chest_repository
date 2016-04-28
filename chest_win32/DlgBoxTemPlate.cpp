#include "DlgBoxTemPlate.h"



DlgBoxTemPlate::DlgBoxTemPlate(HINSTANCE hInstance, LPCSTR dlgResName, HWND hwndparent)
{
	CreateDlg(hInstance, dlgResName, hwndparent);
}


DlgBoxTemPlate::~DlgBoxTemPlate()
{
}

void DlgBoxTemPlate::CreateDlg(HINSTANCE hInstance, LPCSTR dlgResName, HWND parent)
{
	m_hWnd = CreateDialog(hInstance, dlgResName, parent,(DLGPROC)StDlgProc);
	SetWindowLongPtr(m_hWnd, GWLP_USERDATA, (LONG_PTR)this);
}

LRESULT CALLBACK  DlgBoxTemPlate::StDlgProc(HWND   hwnd, UINT   uMsg, WPARAM wParam, LPARAM lParam)
{
	DlgBoxTemPlate* pDlgTemplate = NULL;

	pDlgTemplate = (DlgBoxTemPlate*) GetWindowLongPtr(hwnd, GWLP_USERDATA);

	if (pDlgTemplate != NULL)
	{
		return pDlgTemplate->RealDlgProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}


LRESULT DlgBoxTemPlate::RealDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_INITDIALOG:
		break;
		case WM_CLOSE:
			EndDialog(hwnd, wParam);
			PostQuitMessage(0);
		break;
	}
	return 0;
}

void DlgBoxTemPlate::Show(int nCmdShow)
{
	ShowWindow(m_hWnd, nCmdShow);
}