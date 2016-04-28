#include "MainDlg.h"


MainDlg::MainDlg(HINSTANCE hInstance, LPCSTR dlgResName, HWND hwndparent) : DlgBoxTemPlate(hInstance, dlgResName, hwndparent)
{
	OnCreate();
}


MainDlg::~MainDlg()
{
}

void MainDlg::OnCreate()
{
	MessageBox(m_hWnd, "OnCreate called!", "!!!", MB_OK);

}
LRESULT MainDlg::RealDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
			
	}
	return 0;
}