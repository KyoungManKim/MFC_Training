// CRightView.cpp: 구현 파일
//

#include "stdafx.h"
#include "Splitter4.h"
#include "CRightView.h"


// CRightView

IMPLEMENT_DYNCREATE(CRightView, CHtmlView)

CRightView::CRightView()
{

}

CRightView::~CRightView()
{
}

void CRightView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRightView, CHtmlView)
END_MESSAGE_MAP()


// CRightView 진단

#ifdef _DEBUG
void CRightView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CRightView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG


// CRightView 메시지 처리기
