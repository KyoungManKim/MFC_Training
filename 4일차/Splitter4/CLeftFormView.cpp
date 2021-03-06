// CLeftFormView.cpp: 구현 파일
//

#include "stdafx.h"
#include "Splitter4.h"
#include "CLeftFormView.h"
#include "Splitter4Doc.h"
#include "Splitter4View.h"

// CLeftFormView

IMPLEMENT_DYNCREATE(CLeftFormView, CFormView)
// FormView 의 패생클래스의 생성자에서는
// 반드시 리소스ID 를 기반 클래스인 FormView 에 보내야 합니다.
CLeftFormView::CLeftFormView()
	: CFormView(IDD_FORMVIEW)
{

}

CLeftFormView::~CLeftFormView()
{
}

BEGIN_MESSAGE_MAP(CLeftFormView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CLeftFormView::OnBnClickedButton1)
//	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CLeftFormView 진단

#ifdef _DEBUG
void CLeftFormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftFormView 메시지 처리기


void CLeftFormView::OnBnClickedButton1()
{
	CString s;
	m_edit.GetWindowText(s);

	//Navigate2(s, 0, 0);
	// htmlview 포인트->Navigate2
	CSplitterWnd* pSplitter = (CSplitterWnd*)GetParent();
	
	// 스플리터는 모든 뷰를 알고 있다.
	CHtmlView* pView = (CHtmlView*)pSplitter->GetPane(0, 1);
	pView->Navigate2(s, 0, 0);
}


void CLeftFormView::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	CFormView::DoDataExchange(pDX);
}


//void CLeftFormView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	if (nChar == VK_SHIFT)
//		AfxMessageBox(_T("Enter"));
//
//	CFormView::OnKeyDown(nChar, nRepCnt, nFlags);
//}
