
// Splitter1View.cpp: CSplitter1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Splitter1.h"
#endif

#include "Splitter1Doc.h"
#include "Splitter1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSplitter1View

IMPLEMENT_DYNCREATE(CSplitter1View, CView)

BEGIN_MESSAGE_MAP(CSplitter1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSplitter1View 생성/소멸

CSplitter1View::CSplitter1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSplitter1View::~CSplitter1View()
{
}

BOOL CSplitter1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSplitter1View 그리기

void CSplitter1View::OnDraw(CDC* /*pDC*/)
{
	CSplitter1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSplitter1View 인쇄

BOOL CSplitter1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSplitter1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSplitter1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSplitter1View 진단

#ifdef _DEBUG
void CSplitter1View::AssertValid() const
{
	CView::AssertValid();
}

void CSplitter1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSplitter1Doc* CSplitter1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSplitter1Doc)));
	return (CSplitter1Doc*)m_pDocument;
}
#endif //_DEBUG


// CSplitter1View 메시지 처리기


void CSplitter1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	dc.Ellipse(point.x, point.y, point.x + 100, point.y + 100);

	CView::OnLButtonDown(nFlags, point);
}
