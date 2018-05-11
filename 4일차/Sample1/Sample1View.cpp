
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

	Navigate2(_T("http://naver.com/"),0,0);
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
