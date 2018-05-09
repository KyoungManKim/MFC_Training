// Frame.cpp
#include "Frame.h"

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

int CMainFrame::OnCreate(LPCREATESTRUCT lpc)
{
	if (CFrameWnd::OnCreate(lpc) == -1)
		return -1;

	// View ������ ����
	m_wndView.CreateEx(0, 0, 0, WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(0, 0, 0, 0),  // ũ��� �ڵ� �����ǹǷ�
							// ��ǥ�� �ǹ̰� �����ϴ�.
		this,
		AFX_IDW_PANE_FIRST);

	return 0;
}

// LBUTTONDOWN �޼��� ó���� ������. - View
