
// Sample2View.cpp: CSample2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Sample2.h"
#endif

#include "Sample2Doc.h"
#include "Sample2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample2View

IMPLEMENT_DYNCREATE(CSample2View, CTreeView)

BEGIN_MESSAGE_MAP(CSample2View, CTreeView)
	ON_NOTIFY_REFLECT(NM_DBLCLK, &CSample2View::OnNMDblclk)
END_MESSAGE_MAP()

// CSample2View 생성/소멸

CSample2View::CSample2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSample2View::~CSample2View()
{
}

BOOL CSample2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CTreeView::PreCreateWindow(cs);
}

void CSample2View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	
	//컨트롤 뷰 안에는 컨트롤이 들어있다.
	// CTreeView 안에는 CTreeCtrl이 있다.

	CTreeCtrl& tree = GetTreeCtrl();

	// 트리 컨트롤의 핵심 : 트리의 노드를 가르키는 HTREEITEM 타입

	// Tree 사용하기 1. 스타일 지정
	tree.ModifyStyle(0, TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT);

	// 2. ImageList 연결
	// 마지막 파라미터는 투명처리될 색상
	m_imgList.Create(IDB_BITMAP1, 16, 0, RGB(255, 255, 255));

	tree.SetImageList(&m_imgList, TVSIL_NORMAL);

	// 3. 항목 추가 하기.
	// 0 - 기본 아이콩
	// 1 - 선택됬을때 아이콘
	HTREEITEM hItem = tree.InsertItem(_T("부모"),0,1,TVI_ROOT);

	HTREEITEM hItem2 = tree.InsertItem(_T("자식1"), 1,2,hItem);
	tree.InsertItem(_T("자식1-1"), 1, 2, hItem2);
	tree.InsertItem(_T("자식1-2"), 1, 2, hItem2);
	tree.InsertItem(_T("자식1-3"), 1, 2, hItem2);
	tree.InsertItem(_T("자식2"), 1, 2, hItem);
	tree.InsertItem(_T("자식3"), 1, 2, hItem);
}


// CSample2View 진단

#ifdef _DEBUG
void CSample2View::AssertValid() const
{
	CTreeView::AssertValid();
}

void CSample2View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CSample2Doc* CSample2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample2Doc)));
	return (CSample2Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample2View 메시지 처리기


void CSample2View::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	CTreeCtrl& tree = GetTreeCtrl();

	CString s;

	HTREEITEM hItem = tree.GetSelectedItem();
	
	// HTREEITEM -> 문자열로
	s = tree.GetItemText(hItem);
	AfxMessageBox(s);

}
