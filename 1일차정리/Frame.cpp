// Frame.cpp
#include "Frame.h"

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

int CMainFrame::OnCreate(LPCREATESTRUCT lpc)
{
	if (CFrameWnd::OnCreate(lpc) == -1)
		return -1;

	// View 윈도우 생성
	m_wndView.CreateEx(0, 0, 0, WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(0, 0, 0, 0),  // 크기는 자동 조절되므로
							// 좌표는 의미가 없습니다.
		this,
		AFX_IDW_PANE_FIRST);

	return 0;
}

// LBUTTONDOWN 메세지 처리해 보세요. - View
