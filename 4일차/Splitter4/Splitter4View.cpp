
// Splitter4View.cpp: CSplitter4View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Splitter4.h"
#endif

#include "Splitter4Doc.h"
#include "Splitter4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSplitter4View

IMPLEMENT_DYNCREATE(CSplitter4View, CListView)

BEGIN_MESSAGE_MAP(CSplitter4View, CListView)
	ON_WM_STYLECHANGED()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSplitter4View 생성/소멸

CSplitter4View::CSplitter4View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSplitter4View::~CSplitter4View()
{
}

BOOL CSplitter4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CListView::PreCreateWindow(cs);
}

void CSplitter4View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: GetListCtrl()을 호출하여 해당 list 컨트롤을 직접 액세스함으로써
	//  ListView를 항목으로 채울 수 있습니다.
}

void CSplitter4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSplitter4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSplitter4View 진단

#ifdef _DEBUG
void CSplitter4View::AssertValid() const
{
	CListView::AssertValid();
}

void CSplitter4View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CSplitter4Doc* CSplitter4View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSplitter4Doc)));
	return (CSplitter4Doc*)m_pDocument;
}
#endif //_DEBUG


// CSplitter4View 메시지 처리기
void CSplitter4View::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: 사용자가 창의 뷰 스타일을 변경했을 때 반응하는 코드를 추가합니다.
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);
}
