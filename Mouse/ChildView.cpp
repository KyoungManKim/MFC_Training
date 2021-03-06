
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Mouse.h"
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
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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
	CPoint pt = point;

	// Client 좌표를 Screen 좌표로 변환

	ClientToScreen(&pt);

	CString s;
	s.Format(_T("Client : %d,%d \t Screen : %d, %d"), point.x, point.y, pt.x, pt.y);

	// 1번째 인자에는 SHIFT, CONTROL, LBUTTON, RBUTTON, MBUTTON 의 상태가 들어있음.
	// == 로 하면 안되고 비트연산을 해야함
	//if (nFlags & MK_SHIFT)
	if (nFlags & MK_LBUTTON)
		AfxGetMainWnd()->SetWindowText(s);

}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// 마우스 캡쳐 : 마우스가 윈도우를 벗어나도 계속 마우스 메시지를 보내달라는 의미
	// 제한 : 마우스 버튼이 눌린 상태만 유지 된다. 버튼을 놓으면 마우스 캡쳐가 풀리게 된다.
	SetCapture();
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (GetCapture() == this)
	{
		ReleaseCapture();
		// 현재 커서의 위치를 스크린 좌표로 얻는 방법.
		// 1,2 번째 인자인 point 에 있는 좌표를 ClientToScreen() 함수로 변경
		// 2. 아래 함수 사용
		CPoint pt;
		GetCursorPos(&pt);

		CWnd* pWnd = WindowFromPoint(pt);	// 스크린 좌표로 보냄?

		//ShowWindow(SW_HIDE);	//View 가 보이지 않게
		//AfxGetMainWnd()->ShowWindow(SW_HIDE);	//Frame 이 보이지 않게
		//pWnd->ShowWindow(SW_HIDE);	// 해당 스크린 좌표의 Windows 를 보이지 않게
		//pWnd->MoveWindow(0, 0, 300, 300);
		// 원형 영역(Region) 만들기
		HRGN h = CreateEllipticRgn(0, 0, 300, 300);

		pWnd->SetWindowRgn(h, TRUE);
	}
}

// 마우스 메시지 총 정리
// 1. 마우스 메시지 종류

// 2. Client 좌표 vs Screen 좌표

// 3. 마우스 메시지 발생 시, 함수 인자의 의미
//	1번째 : 2개 키보드, 3개 버튼 상태
//	2번째 : 마우스 좌표(Client 좌표계)

// 4. 마우스 캡쳐 개념과 함수 3개
//	  SetCapture, GetCapture, ReleaseCapture

// 5. 특정 윈도우를 제어하려면 윈도우 포인터만 알면된다.
//    AfxGetMainWnd()-> 멤버함수(); // Frame 윈도우 제어

//	  CPoint pt;
//    GetCursorPos(&pt);
//    CWnd* pWnd = WindowFrom Point(pt); // pt 아래 있는 윈도우 포인터 얻기
//    pWnd->멤버 함수 ();