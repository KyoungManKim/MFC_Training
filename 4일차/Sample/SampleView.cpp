
// SampleView.cpp: CSampleView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Sample.h"
#endif

#include "SampleDoc.h"
#include "SampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSampleView

IMPLEMENT_DYNCREATE(CSampleView, CView)

BEGIN_MESSAGE_MAP(CSampleView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CSampleView 생성/소멸

CSampleView::CSampleView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSampleView::~CSampleView()
{
}

BOOL CSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSampleView 그리기
// Doc/View 모델을 사용하면 OnPaint 는 MFC가 제공
// OnPaint 안에서 OnDraw() 호출
void CSampleView::OnDraw(CDC* pDC)
{
	CSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i< pDoc->m_arr.GetSize(); i++)
	{
		CRect rc = pDoc->m_arr[i];
		pDC->Rectangle(rc);
	}


}


// CSampleView 진단

#ifdef _DEBUG
void CSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSampleDoc* CSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSampleDoc)));
	return (CSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CSampleView 메시지 처리기


void CSampleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);

	CRect rc(point.x, point.y, point.x + 100, point.y + 100);

	dc.Rectangle(rc);

	//View 에서 Document 포인터를 알고 싶을때
	CSampleDoc* pDoc = GetDocument();

	pDoc->m_arr.Add(rc);

	// 새로운 데이터가 생성되었음을 MFC 에게 알림
	pDoc->SetModifiedFlag(TRUE);
}


void CSampleView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CSampleDoc* pDoc = GetDocument();

	for (int i = 0; i < pDoc->m_arr.GetSize(); i++) {
		CRect rc = pDoc->m_arr[i];

		if (point.x > rc.left && point.x < rc.right	&& point.y >rc.top && point.y < rc.bottom)
			pDoc->m_arr.RemoveAt(i);
		InvalidateRect(0);
	}
	
}
