// View.cpp
#include "View.h"

BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	AfxMessageBox(_T("LButtonDown"));
}
void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	AfxMessageBox(_T("RButtonDown"));
}


