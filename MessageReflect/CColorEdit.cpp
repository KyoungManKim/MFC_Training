// CColorEdit.cpp: 구현 파일
//

#include "stdafx.h"
#include "MessageReflect.h"
#include "CColorEdit.h"


// CColorEdit

IMPLEMENT_DYNAMIC(CColorEdit, CEdit)

CColorEdit::CColorEdit()
{

}

CColorEdit::~CColorEdit()
{
}


BEGIN_MESSAGE_MAP(CColorEdit, CEdit)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()



// CColorEdit 메시지 처리기




HBRUSH CColorEdit::CtlColor(CDC* pDC, UINT nCtlColor)
{
	pDC->SetTextColor(RGB(0, 0, 255));

	static CBrush brush(RGB(0, 0, 0));
	
	return brush;
}
