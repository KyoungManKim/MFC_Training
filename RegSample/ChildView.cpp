
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "RegSample.h"
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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	CString s;
	// 마우스 좌표는 함수 2번째 인자
	// 좌표를 문자열로 변경
	s.Format(_T("%d, %d"), point.x, point.y);

	// 캡션바를 변경하는  함수,
	//SetWindowText(s); // View 의 멤버 함수를 호출
						// View 의 캡션바를 변경하는 코드이기 때문에 Frame 의 캡션바를 호출해야함
	// AfxGetMainWnd() : Frame 객체의 포인터를 얻는 함수

	// Frame 의 멤버 함수 사용
	AfxGetMainWnd()->SetWindowText(s);

	CWnd::OnMouseMove(nFlags, point);
}
