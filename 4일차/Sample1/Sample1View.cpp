
// Sample1View.cpp: CSample1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Sample1.h"
#endif

#include "Sample1Doc.h"
#include "Sample1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample1View

IMPLEMENT_DYNCREATE(CSample1View, CHtmlView)

BEGIN_MESSAGE_MAP(CSample1View, CHtmlView)
	ON_COMMAND(IDM_GO_BACK, &CSample1View::OnGoBack)
	ON_COMMAND(IDM_GO_FORWARD, &CSample1View::OnGoForward)
	ON_COMMAND(IDM_GO_HOME, &CSample1View::OnGoHome)
	ON_COMMAND(IDM_GO_REFRESH, &CSample1View::OnGoRefresh)
	ON_COMMAND(IDM_GO_SEARCH, &CSample1View::OnGoSearch)
	ON_COMMAND(IDM_GO_STOP, &CSample1View::OnGoStop)
END_MESSAGE_MAP()

// CSample1View 생성/소멸

CSample1View::CSample1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSample1View::~CSample1View()
{
}

BOOL CSample1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CHtmlView::PreCreateWindow(cs);
}

void CSample1View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	//Navigate2(_T("https://www.naver.com/"),0,0);
	Navigate2(_T("D:\\PSG11.pdf"), 0, 0);

}


// CSample1View 진단

#ifdef _DEBUG
void CSample1View::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CSample1View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CSample1Doc* CSample1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample1Doc)));
	return (CSample1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample1View 메시지 처리기


void CSample1View::OnGoBack()
{
	GoBack();
}


void CSample1View::OnGoForward()
{
	GoForward();
}


void CSample1View::OnGoHome()
{
	GoHome();
}


void CSample1View::OnGoRefresh()
{
	Refresh();
}


void CSample1View::OnGoSearch()
{
	GoSearch();
}


void CSample1View::OnGoStop()
{
	Stop();
}

// HTMLView 가 특정 사이트로 이동하려고 할때 아래 가상함수 호출
void CSample1View::OnBeforeNavigate2(LPCTSTR lpszURL, DWORD nFlags, LPCTSTR lpszTargetFrameName, CByteArray& baPostedData, LPCTSTR lpszHeaders, BOOL* pbCancel)
{
	//AfxMessageBox(lpszURL);

	CString url(lpszURL);
	
	if (url == _T("https://www.naver.com/")) {
		AfxMessageBox(_T("구글로"));
		Navigate2(_T("https://www.google.co.kr/"));
		*pbCancel = TRUE;
		return;
	}

	CHtmlView::OnBeforeNavigate2(lpszURL, nFlags, lpszTargetFrameName, baPostedData, lpszHeaders, pbCancel);
}
