
// MainFrm.cpp: CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "Splitter1.h"

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


// Frame 이 만들어질때 View 를 만들기 위해서 이 함수 호출
// 재정의해서 View 대신 Splitter를 만들어야함
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// 617 page 코드
	// 동적 스플리터 : 2*2 까지만 가능
	// CSize(100,100) 100 픽셀이상인 경우만 표시,
	// 스플리터만 만들면 스플리터 위의 View 는 자동 생성.
	// 단점 : 모든 View 가 같은 종류(같은 클래스)만 사용 가능.

	m_splitter.Create(this, 2,2,CSize(100,100), pContext);
	return TRUE;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}
