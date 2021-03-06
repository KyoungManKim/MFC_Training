
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Game.h"
#include "ChildView.h"
#include <algorithm>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using std::swap;

// CChildView

CChildView::CChildView()
{
	m_img.Load(_T("movie.jpg"));

	m_cxImg = m_img.GetWidth();
	m_cyImg = m_img.GetHeight();

	m_cxBlock = m_cxImg / COUNT;
	m_cyBlock = m_cyImg / COUNT;

	int k = 0;
	for (int y = 0; y < COUNT; y++)
	{
		for (int x = 0; x < COUNT; x++)
		{
			m_board[y][x] = k++;
		}
	}
	
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDM_NEW, &CChildView::OnNew)
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
	//AfxGetMainWnd()->SetWindowPos(0, 0, 0, m_cxImg, m_cyImg, 0);
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	// m_img.BitBlt(dc, CRect(0, 0, m_cxImg, m_cyImg),CPoint(0, 0));

	// 핵심 3
	//int bx = 1;
	//int by = 2;
	//m_img.BitBlt(dc, CRect(0, 0, m_cxBlock, m_cyBlock), CPoint(bx*m_cxBlock, by*m_cyBlock));

	// 핵심 4
	/*int N = 1;
	int bx = N%COUNT;
	int by = N/COUNT;
	m_img.BitBlt(dc, CRect(0, 0, m_cxBlock, m_cyBlock), CPoint(bx*m_cxBlock, by*m_cyBlock));*/

	// 핵심 5	N 번째 블럭을 View 의 0,0 이 아닌 x,y 번째 화면 블럭에 출력
	/*int x = 1;
	int y = 0;

	int N = 1;
	int bx = N % COUNT;
	int by = N / COUNT;
	m_img.BitBlt(dc, CRect(x * m_cxBlock, y* m_cyBlock, (x+1)*m_cxBlock, (y+1)*m_cyBlock), CPoint(bx*m_cxBlock, by*m_cyBlock));*/

	

	int N = 0;
	for (int y = 0; y < COUNT; y++) {
		for (int x = 0; x < COUNT; x++) {

			if (m_board[y][x] == EMPTY) {
				CBrush brush(RGB(255, 255, 255));
				dc.FillRect(CRect(x*m_cxBlock, y* m_cyBlock, (x + 1)*m_cxBlock - 1, (y + 1)*m_cyBlock - 1), &brush);
				continue;
			}
			int bx = m_board[y][x] % COUNT;
			int by = m_board[y][x] / COUNT;

			m_img.BitBlt(dc, CRect(x * m_cxBlock, y* m_cyBlock, (x + 1)*m_cxBlock-1, (y + 1)*m_cyBlock-1), CPoint(bx*m_cxBlock, by*m_cyBlock));
			
		}
	}
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	int bx = point.x / m_cxBlock;
	int by = point.y / m_cyBlock;

	//	int N = (point.x / m_cxBlock) + (point.y / m_cyBlock)*COUNT;
	CRect rc(bx * m_cxBlock, by *m_cyBlock, (bx + 1)*m_cxBlock, (by + 1)*m_cyBlock);


	//이동가능여부 확인
	//상하좌우에 EMPTY가 있으면 이동가능

	if (by > 0 && (m_board[by - 1][bx] == EMPTY))
	{
		swap(m_board[by][bx], m_board[by - 1][bx]);
		rc.top -= m_cyBlock;
		InvalidateRect(rc);
	}
	else if (by < COUNT - 1 && (m_board[by + 1][bx] == EMPTY))
	{
		swap(m_board[by][bx], m_board[by + 1][bx]);
		rc.bottom += m_cyBlock;
		InvalidateRect(rc);
	}
	else if (bx > 0 && (m_board[by][bx - 1] == EMPTY))
	{
		swap(m_board[by][bx], m_board[by][bx - 1]);
		rc.left -= m_cxBlock;
		InvalidateRect(rc);
	}
	else if (bx < COUNT - 1 && m_board[by][bx + 1] == EMPTY)
	{
		swap(m_board[by][bx], m_board[by][bx + 1]);
		rc.right += m_cxBlock;
		InvalidateRect(rc);
	}
	else
	{
		// 이곳 까지 온 경우는 이동할수 없었던 경우이다.
		MessageBeep(0); // "삑"

		return;   // 메세지 처리 종료
	}
	//------------------
	// 블럭이 이동한 경우. 다 맞추었는지 확인해야 한다.
	int k = 0;
	for (int y = 0; y < COUNT; y++)
	{
		for (int x = 0; x < COUNT; x++)
		{
			if (m_board[y][x] != k++)
				return;
		}
	}
	//------------
	AfxMessageBox(_T("Success !!!"));

}

void CChildView::OnNew()
{
	srand((unsigned)time(NULL));
	int val = rand() % 25;
	

	InvalidateRect(0);

}
