
// MainFrm.cpp: CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "RegSample.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 프레임의 클라이언트 영역을 차지하는 뷰를 만듭니다.
	if (!m_wndView.Create(nullptr, nullptr, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, nullptr))
	{
		TRACE0("뷰 창을 만들지 못했습니다.\n");
		return -1;
	}
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
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

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// 뷰 창으로 포커스를 이동합니다.
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// 뷰에서 첫째 크랙이 해당 명령에 나타나도록 합니다.
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// 그렇지 않으면 기본 처리합니다.
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}



void CMainFrame::OnDestroy()
{
	CFrameWnd::OnDestroy();
	
	// 자신의 위치와 크기를 구함
	CRect rc;
	GetWindowRect(&rc);

	// 레지스트리에 위치를 기록
	// 레지스트리함수는 CWinApp 의 멤버 함수이기 때문에 다른 클래스에서 호출하는것이 불가능
	// 해당클래스의 변수인 theApp 으로 호출하거나
	//theApp.WriteProfileInt(_T("위치"), _T("X"), rc.left);
	//theApp.WriteProfileInt(_T("위치"), _T("Y"), rc.top);
	// AfxGetApp() : App 객체의 주소를 얻을때 사용. 즉, 전역변수 theApp 의 주소가 나옴
	// App가 아닌 곳에서 App 의 멤버 함수를 호출하기 위해서 사용
	AfxGetApp()->WriteProfileInt(_T("위치"), _T("X"), rc.left);
	AfxGetApp()->WriteProfileInt(_T("위치"), _T("Y"), rc.top);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
