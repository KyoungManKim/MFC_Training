// Step4.cpp - View 개념의 추가
#include <afxwin.h>

// Frame 윈도우 안쪽에 상태바, 툴바등을 제외한 영역에 자식 윈도우 (View 라고 부름) 을 붙인다.

class CChildView : public CWnd
{
public:
	void OnLButtonDown(UINT nFlags, CPoint pt)
	{
		AfxMessageBox(_T("View Lbutton"));
	}

	DECLARE_MESSAGE_MAP()

};
BEGIN_MESSAGE_MAP(CChildView,CWnd)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
//CChildView v;
//v.Create() 또는 v.CreateEx() 할때 윈도우 생성


class CMainFrame : public CFrameWnd
{
public:
	CChildView m_wndView;	// 자식 윈도우 (view) 를 멤버로 선언
	CMainFrame()
	{
		
	}
	// Frame 윈도우가 생성될 때 WN_CREATE 메세지 발생 , 아래 함수 호출
	int OnCreate(LPCREATESTRUCT lpc)
	{
		if (CFrameWnd::OnCreate(lpc) == -1) 
			return -1;

		m_wndView.CreateEx(0, 0, 0,
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			CRect(100, 100, 200, 200),
			this,
			AFX_IDW_PANE_FIRST);	// ID값을 AFX_IDW_PANE_FIRST 로 사용하면 View 가 툴바, 상태바를 제외한 Frame 전체를 덮음
	}

	DECLARE_MESSAGE_MAP()
};
//(클래스 이름, 기반 클래스 이름)
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance()
	{
		CMainFrame* pFrame = new CMainFrame;	// 윈도우를 만드는 코드가 아님,
		pFrame->Create(0, _T("Hello!"));	// 이 순간 윈도우 생성
											// WM_CREATE 메세지 발생
		pFrame->ShowWindow(SW_SHOW);

		m_pMainWnd = pFrame;


		return TRUE;
	}
};
CMyApp theApp;