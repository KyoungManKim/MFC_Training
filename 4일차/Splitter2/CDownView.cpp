// CDownView.cpp: 구현 파일
//

#include "stdafx.h"
#include "Splitter2.h"
#include "CDownView.h"


// CDownView

IMPLEMENT_DYNCREATE(CDownView, CEditView)

CDownView::CDownView()
{

}

CDownView::~CDownView()
{
}

BEGIN_MESSAGE_MAP(CDownView, CEditView)
END_MESSAGE_MAP()


// CDownView 진단

#ifdef _DEBUG
void CDownView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CDownView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDownView 메시지 처리기
