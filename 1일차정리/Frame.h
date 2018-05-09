#pragma once
// Frame.h
#include <afxwin.h>
#include "View.h"

class CMainFrame : public CFrameWnd
{
public:
	CChildView m_wndView;


	// FRAME윈도우가 만들어 질때 나오는 WM_CREATE 메시지를
	// 처리할 함수
	int OnCreate(LPCREATESTRUCT lpc);

	DECLARE_MESSAGE_MAP()
};
