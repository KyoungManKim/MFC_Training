
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Sketch.h"
#include "ChildView.h"
#include "CMyDialog.h"

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
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDM_EDIT_SETTING, &CChildView::OnEditSetting)
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
	
	for (int i = 0; i < m_arr.GetSize(); i++)
	{
		LINE line = m_arr[i];
		CPen pen(PS_SOLID, line.width, RGB(line.red, line.green, line.blue));

		CPen* oldPen = dc.SelectObject(&pen);

		dc.MoveTo(line.ptFrom);	// 선의 시작점
		dc.LineTo(line.ptTo);		// 선의 끝점;

		dc.SelectObject(oldPen);
	}
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_ptFrom = point;
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{

	if (nFlags & MK_LBUTTON)	// 마우스 왼쪽 버튼을 누르고 이동할때
	{
		CClientDC dc(this);
		CPen pen(PS_SOLID, m_penWidth, RGB(m_red, m_green, m_blue));
		
		CPen* oldPen = dc.SelectObject(&pen);
		
		dc.MoveTo(m_ptFrom);	// 선의 시작점
		dc.LineTo(point);		// 선의 끝점;
		
		dc.SelectObject(oldPen);

		// --------------------------------------------------------
		// 선의 정보를 배열에 저장
		LINE line;
		line.ptFrom = m_ptFrom;
		line.ptTo = point;
		line.width = m_penWidth;
		line.red = m_red;
		line.green = m_green;
		line.blue = m_blue;

		m_arr.Add(line);
		// --------------------------------------------------------

		// 현재점을 다시 시작점으로,
		m_ptFrom = point;
	}

}


void CChildView::OnEditSetting()
{
	CMyDialog dlg;
	
	dlg.m_penWidth = m_penWidth;
	dlg.m_red	= m_red;
	dlg.m_green	= m_green;
	dlg.m_blue	= m_blue;

	if (dlg.DoModal() == IDOK)
	{
		m_penWidth	= dlg.m_penWidth;
		m_red		= dlg.m_red;
		m_green		= dlg.m_green;
		m_blue		= dlg.m_blue;
	}

}
