
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "GDI3.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_img.Load(_T("movie.jpg"));
	m_cx = m_img.GetWidth();
	m_cy = m_img.GetHeight();
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
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

#if 0
void CChildView::OnPaint()
{
	CPaintDC dc(this);  // 기본적으로 검정펜, 흰색 브러시를 가지고 있다.

	CPen pen(PS_DOT, 1, RGB(56, 92, 186));
	CBrush brush(HS_CROSS, RGB(45, 186, 210));

	CPen*	oldpen = dc.SelectObject(&pen);
	CBrush*	oldbrush = dc.SelectObject(&brush);
	dc.Rectangle(100, 100, 200, 200);

	// GDI Object 를 변경한 경우, 그림을 다 그린후에 다시 원래의 GDI Object를 넣어야함
	dc.SelectObject(oldpen);
	dc.SelectObject(oldbrush);
	dc.Rectangle(300, 300, 200, 200);
}
#endif // 0
#if 0
void CChildView::OnPaint()
{
	CPaintDC dc(this);

	CImage img;
	img.Load(_T("movie.jpg"));

	int cx = img.GetWidth();
	int cy = img.GetHeight();

	CRect rc(0, 0, cx, cy);
	CPoint pt(0, 0);

	// 일반적인 그리기 : dc.그리는 함수();
	// 그림 출력 : img.BitBlt(dc 전달)
	img.BitBlt(dc, rc, pt);

	//img.BitBlt(dc, CRect(0, 0, 100, 100), CPoint(0, 0));
}
#endif // 0
void CChildView::OnPaint()
{
	CPaintDC dc(this);
	
	m_img.BitBlt(dc, CRect(100, 100, m_cx, m_cy), CPoint(0, 0));
	//img.BitBlt(dc, CRect(0, 0, 100, 100), CPoint(0, 0));
}

// 199 Page
// GDI Object : DC 안에 들어있는 그릴때 사용하는 도구
//				펜, 브러쉬, 폰트, 팔레트, 리전(Region)