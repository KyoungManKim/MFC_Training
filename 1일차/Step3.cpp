// Step3.cpp	- event 처리하기 핵심
#include <afxwin.h>

//1. CFrameWnd 의 파생 클래스를 만들고
//2. 클래스 선언에 DECLARE_MESSAGE_MAP() 추가
//3. 클래스 외부에 BEGIN_MESSAGE_MAP() ~ END_MESSAGE_MAP()
//4. 해당 메세지의 매크로를 맵에 추가하고 맴버함수 추가

class CMainFrame : public CFrameWnd
{
public:
	// event 에 따른 함수 이름과 모양이 이미 약속되어 있습니다.
	void OnLButtonDown(UINT nFlags, CPoint pt)
	{
		AfxMessageBox(_T("LButton"));
	}
	void OnRButtonDown(UINT nFlags, CPoint pt)
	{
		AfxMessageBox(_T("RButton"));
	}
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		AfxMessageBox(_T("KeyButton"));
	}

	
	// 이 클래스에서 이벤트를 처리하겠다는 사실을 MFC에 알린다.
	DECLARE_MESSAGE_MAP()
};
// 클래스 외부에 메세지 맵을 만들고 처리할 메세지에 대한 매크로 추가.

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)	//(클래스 이름, 기반 클래스 이름)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance()
	{
		CMainFrame* pFrame = new CMainFrame;
		pFrame->Create(0, _T("Hello!"));
		pFrame->ShowWindow(SW_SHOW);

		m_pMainWnd = pFrame;

		
		return TRUE;
	}
};
CMyApp theApp;
