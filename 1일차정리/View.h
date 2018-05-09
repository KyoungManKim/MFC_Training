#pragma once
// View.h
#include <afxwin.h>

class CChildView : public CWnd
{
public:
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnRButtonDown(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()
};
