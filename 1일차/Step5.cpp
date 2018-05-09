// Step5.cpp - 
#include <afxwin.h>

// 리소스를 추가하면 
// 1. 프로젝트이름.rc 파일 생성
// 2. *.rc 파일을 더블 클릭 -> 리소스 뷰 생성
// 3. 리소스뷰에서 모든 리소스 디자인 후에 ID 값 변경
//    속성 창 열고 ID 값 변경
// 4. 리소스뷰에서 만든 모든 ID 는 resource.h 에 #define 으로 생성된다.
// 결국 리소스를 코드에서 사용하려면 아래 헤더가 필요하다.

#include "resource.h"
class CChildView : public CWnd
{
public:
	void OnLButtonDown(UINT nFlags, CPoint pt)
	{
		AfxMessageBox(_T("View Lbutton"));
	}

	DECLARE_MESSAGE_MAP()

};
BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

class CMainFrame : public CFrameWnd
{
public:
	CChildView m_wndView;	
	CMainFrame()
	{

	}

	int OnCreate(LPCREATESTRUCT lpc)
	{
		if (CFrameWnd::OnCreate(lpc) == -1)
			return -1;

		m_wndView.CreateEx(0, 0, 0,
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			CRect(100, 100, 200, 200),
			this,
			AFX_IDW_PANE_FIRST);
		return 0;
	}
	void OnExit()
	{
		AfxMessageBox(_T("종료 메뉴 선택"));
		// WM_CLOSE 메세지를 자신에게 보내면 종료된다.
		SendMessage(WM_CLOSE);
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	// 1. 일반 윈도우 메세지 : ON_WM_메세지이름()
	ON_WM_CREATE()
	// 2. 메뉴 메세지 : ON_COMMAND( ID, 함수이름 )
	//					함수 이름은 원하는대로 사용가능.
	//					모양은 void func()
	ON_COMMAND(ID_APP_EXIT, OnExit) 
END_MESSAGE_MAP()

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance()
	{
		CMainFrame* pFrame = new CMainFrame;
		
		// 메뉴 붙이는 방법
		// 1. Frame 만들때 6번째 인자로 ID 전달
		/*
		pFrame->Create(0, _T("Hello!"),WS_OVERLAPPEDWINDOW,
			CRect(100,100,200,200) , 0, 
			MAKEINTRESOURCE(IDR_MAINFRAME));
		*/
		// 2. Create 로 Frame 윈도우를 만들지 말고 Load Frame 함수를 사용해 윈도우를 만들고,
		//    4개의 리소스를 자동 로드
		//    (메뉴, 아이콘, Accelerator, string table)
		pFrame->LoadFrame(IDR_MAINFRAME);
		pFrame->ShowWindow(SW_SHOW);

		m_pMainWnd = pFrame;


		return TRUE;
	}
};

CMyApp theApp;