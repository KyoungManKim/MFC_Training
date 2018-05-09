// App.cpp
#include "App.h"
#include "Frame.h"
#include "resource.h"

BOOL CMyApp::InitInstance()
{
	CMainFrame* pFrame = new CMainFrame;

	//pFrame->Create(0, _T("hello"));
	pFrame->LoadFrame(IDR_MAINFRAME);
	pFrame->ShowWindow(SW_SHOW);

	m_pMainWnd = pFrame;
	//AfxMessageBox(_T("Hello"));

	return TRUE;
}

CMyApp theApp;