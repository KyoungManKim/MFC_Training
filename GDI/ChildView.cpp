
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "GDI.h"
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
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
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
	// CClinetDC: 그림을 그리는 함수만 제공
	// CPaintDC : 그림을 그리는 함수 제공 + 무효화 영역을 유효화로 변경하는 작업 + 기타 작업

	// 결론 : OnPaint() 에서는 CPaintDC 사용
	//		  다른 함수에서는 CClientDC 사용
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// 배열에 보관된 좌표를 사용해서 모든 그림을 다시 그린다.
	// CClientDC dc(this);
	// ValidateRect(0); // 0: 전체 영역을 유효화
	
	for (int i = 0; i < m_array.GetSize(); i++)
	{
		CPoint pt = m_array[i];
		dc.Rectangle(pt.x, pt.y, pt.x + 50, pt.y + 50);
	}

	
}

void CChildView::OnMButtonDown(UINT nFlags, CPoint point)
{

}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this); //그림을 그리기 위한 함수를 가진 클래스

	dc.Rectangle(point.x, point.y, point.x + 50, point.y + 50);
	m_array.Add(point);

}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	//CClientDC dc(this); //그림을 그리기 위한 함수를 가진 클래스
	//dc.Rectangle(point.x, point.y, point.x + 10, point.y + 10);
}

// 교재 191 page
// GDI(Graphic Device Interface) : 그림을 그리기 위한 함수(구초제) 모음, 1000개 이상의 함수 제공.
// MFC 에서는 DC 클래스의 멤버로 제공된다.

// 1. 무효화 영역 : 다시 그려야 하는 영역
// 2. 무효화 영역 발생 시 : OS는 무효화 영역을 배경색으로 지우고 WM_PAING 메시지 발생

