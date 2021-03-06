
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "GDI2.h"
#include "ChildView.h"

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
	// 아래 dc 로는 무효화 영역만 그림 그릴 수 있다.
	// 무효화영역이 없다면 그림을 그릴 수 없음.
	// 절대 OnPaint() 함수를 직접 호출하지 말것.
	CPaintDC dc(this); 
	
	dc.TextOut(50, 50, m_str);
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// 마우스 좌표의 정보를 가지고 멤버 변수 m_str 을 변경
	m_str.Format(_T("x : %d , y : %d"), point.x, point.y);

	// 다시 그리게 하려면!?
	// 방법 1. CClientDC 를 가지고 직접 다시 그린다. - Ok
	// 방법 2. OnPaing()함수 호출 - No
	//		   OnPaint(); // 실패
	// 방법 3. 다시 그리고 싶은 영역만큼 무효화 한다.
	CRect rc(50, 50, 300, 200);

	InvalidateRect(&rc);
}

// 핵심 1
// (1) 항상 보여주고 싶은 출력물이 있다면 View::OnPaint 에서 출력
// (2) 출력물은 변경하고 싶은 경우 - InvalidateRect 함수로 무효화 영역을 만든다.

// 핵심 2
// (1) 사용자 입력(LBUTTONDOWN) 에서 그림을 그렸다면
// (2) OnPaint() 에서 다시 그리기 위해서 좌표를 보관해야 한다.