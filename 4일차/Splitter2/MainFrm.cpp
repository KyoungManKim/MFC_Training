
// MainFrm.cpp: CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "Splitter2.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
END_MESSAGE_MAP()

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// 동적 스플리터
	// 스플리터만 만들면 스플리터위의 View는 자동 생성.
	// m_wndSplitter.Create(this, 2, 2, CSize(1, 1), pContext);

	// 정적 스플리터
	m_wndSplitter.CreateStatic(this, 2, 1);

	// 정적 스플리터위에 올라갈 뷰는 사용자가 직접 클래스 이름을 전달해야 함.
	//m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(클래스이름));
	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CSplitter2View),CSize(100,200), pContext);
	m_wndSplitter.CreateView(1, 0, RUNTIME_CLASS(CDownView),CSize(100,100), pContext);

	return TRUE;	
}
