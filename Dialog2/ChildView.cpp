
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Dialog2.h"
#include "ChildView.h"
#include "CMyDiag.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	dc.TextOut(m_x, m_y, m_data);
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMyDiag dlg;

	dlg.m_data = m_data;
	dlg.m_x = m_x;
	dlg.m_y = m_y;

	// DoModal() 을 호출하면 Dialog 가 나타나고
	// OnInitDialog() 가 호출됩니다.
	if (dlg.DoModal() == IDOK)
	{
		// OK 버튼을 누를때 : UpdateData(TRUE) 가 되기 때문에
		// Control -> Dlg 멤버 변수에 옮겨 짐
		// Dlg 멤버 => View 멤버로 옮겨 담음.

		m_data = dlg.m_data;
		m_x = dlg.m_x;
		m_y = dlg.m_y;

		//View 전체를 다시 그리기 -- 무효화 발생
		InvalidateRect(0);
	}

}
