
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "KeyBoard.h"
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
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
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

/*
'A' 를 누르면
WN_KEYDOWN 발생 -> WM_CHAR 발생 -> WN_KEYUP 발생

'Shift' 를 누르면
WN_KEYDOWN 발생 -> WN_KEYUP 발생
*/

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// 가상 키코드 조사하는 방법
	// 문자키 : 'A' ~ 'Z'
	// 특수키 : VK_SHIFT, VK_LEFT 등 사용

	CRect rc;
	// GetWindowRect(&rc); // View 윈도우 좌표/크기 구하기
	AfxGetMainWnd()->GetWindowRect(&rc); // Frame 의 좌표/크기 구하기
	

	if (nChar == VK_LEFT)
	{
		rc.left -= 10;
		rc.right -= 10;
	}
	else if (nChar == VK_RIGHT)
	{
		rc.left += 10;
		rc.right += 10;
	}
	else if (nChar == VK_UP)
	{
		rc.top -= 10;
		rc.bottom -= 10;
	}
	else if (nChar == VK_DOWN)
	{
		rc.top += 10;
		rc.bottom += 10;
	}
	
	
	// MoveWindow(&rc);	// View 윈도우 Move
	AfxGetMainWnd()->MoveWindow(&rc);	// Frame 윈도우 Move
	

	//CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
#if 0
void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// 1번째 인자 : 가상키코드
	// 2,3 번째 인자 : 중요하지 않음,
	CString s;

	s.Format(_T("%c 키보드 입력"), nChar);
	AfxMessageBox(s);
	//AfxGetMainWnd()->SetWindowText(s);

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
#endif // 0
void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString s;

	s.Format(_T("WM_CHAR: %c 키보드 입력"), nChar);

	//AfxMessageBox(s);
	//AfxGetMainWnd()->SetWindowText(s);

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
	CWnd::OnChar(nChar, nRepCnt, nFlags);
}
