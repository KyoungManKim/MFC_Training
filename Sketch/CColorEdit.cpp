// CColorEdit.cpp: 구현 파일
//

#include "stdafx.h"
#include "CColorEdit.h"


// CColorEdit

IMPLEMENT_DYNAMIC(CColorEdit, CEdit)

CColorEdit::CColorEdit()
{
	m_brush.CreateSolidBrush(m_bkColor);
}

CColorEdit::~CColorEdit()
{
}


BEGIN_MESSAGE_MAP(CColorEdit, CEdit)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



// CColorEdit 메시지 처리기

void CColorEdit::SetTextColor(COLORREF color)
{
	m_txtColor = color;
	InvalidateRect(0);
}
void CColorEdit::SetBkColor(COLORREF color)
{
	m_bkColor = color;

	// 기존 브러시를 제거하고 새로운 브러시로
	m_brush.DeleteObject();
	m_brush.CreateSolidBrush(m_bkColor);

	InvalidateRect(0);
}


HBRUSH CColorEdit::CtlColor(CDC* pDC, UINT nCtlColor)
{
	pDC->SetTextColor(m_txtColor);
	pDC->SetBkColor(m_bkColor);
	return m_brush;
}
