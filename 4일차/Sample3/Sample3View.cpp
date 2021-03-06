
// Sample3View.cpp: CSample3View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Sample3.h"
#endif

#include "Sample3Doc.h"
#include "Sample3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample3View

IMPLEMENT_DYNCREATE(CSample3View, CListView)

BEGIN_MESSAGE_MAP(CSample3View, CListView)
END_MESSAGE_MAP()

// CSample3View 생성/소멸

CSample3View::CSample3View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSample3View::~CSample3View()
{
}

BOOL CSample3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CListView::PreCreateWindow(cs);
}

void CSample3View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// CListView 에는 CListCtrl 이 들어있습니다.
	// TreeView 에서 TreeCtrl 꺼내기 : GetTreeCtrl
	// ListView 에서 ListCtrl 꺼내기 : GetListCtrl
	CListCtrl& list = GetListCtrl();
	list.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);

	list.InsertColumn(0, _T("파일"), LVCFMT_LEFT, 150);
	list.InsertColumn(0, _T("크기"), LVCFMT_LEFT, 150);
	list.InsertItem(0, _T("Readme.txt"));
	list.InsertItem(1, _T("a.txt"));
}


// CSample3View 진단

#ifdef _DEBUG
void CSample3View::AssertValid() const
{
	CListView::AssertValid();
}

void CSample3View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CSample3Doc* CSample3View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample3Doc)));
	return (CSample3Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample3View 메시지 처리기
