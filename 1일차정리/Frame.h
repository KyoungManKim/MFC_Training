#pragma once
// Frame.h
#include <afxwin.h>
#include "View.h"

class CMainFrame : public CFrameWnd
{
public:
	CChildView m_wndView;


	// FRAME�����찡 ����� ���� ������ WM_CREATE �޽�����
	// ó���� �Լ�
	int OnCreate(LPCREATESTRUCT lpc);

	DECLARE_MESSAGE_MAP()
};
