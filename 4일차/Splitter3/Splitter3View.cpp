
// Splitter3View.cpp: CSplitter3View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Splitter3.h"
#endif

#include "Splitter3Doc.h"
#include "Splitter3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSplitter3View

IMPLEMENT_DYNCREATE(CSplitter3View, CTreeView)

BEGIN_MESSAGE_MAP(CSplitter3View, CTreeView)
END_MESSAGE_MAP()

// CSplitter3View 생성/소멸

CSplitter3View::CSplitter3View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSplitter3View::~CSplitter3View()
{
}

BOOL CSplitter3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CTreeView::PreCreateWindow(cs);
}

void CSplitter3View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

}


// CSplitter3View 진단

#ifdef _DEBUG
void CSplitter3View::AssertValid() const
{
	CTreeView::AssertValid();
}

void CSplitter3View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CSplitter3Doc* CSplitter3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSplitter3Doc)));
	return (CSplitter3Doc*)m_pDocument;
}
#endif //_DEBUG


// CSplitter3View 메시지 처리기
