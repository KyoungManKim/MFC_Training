// Step2.cpp
// Step2. 핵심 정리
//1.CMyApp::InitInstance 에서 윈도우 만들기
//	 CFrameWnd 를 사용해서 만든 3줄의 코드
//2. 만들어진 윈도우 객체의 주소는 반드시 m_pMainWnd 에 보관해야 한다.
//3. return TRUE 를 해서 프로그램이 종료되지 않고 메세지 루프를 수행하게 한다.
#include <afxwin.h>


class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance()
	{
		/*
		CFrameWnd w;
		w.Create(0, _T("Hello"));
		w.ShowWindow(SW_SHOW);

		AfxMessageBox(_T("..."));
		*/
		CFrameWnd* pFrame = new CFrameWnd;
		pFrame->Create(0, _T("Hello!"));	// 윈도우 생성
		pFrame->ShowWindow(SW_SHOW);		// 윈도우 보여주기

		m_pMainWnd = pFrame;				// CWinApp 으로부터 상속받음, 자동으로 Delete 까지 수행

		return TRUE;	// FALSE: main 으로 돌아가서 종료과정 진행
						// TRUE : GUI Event를 처리하기 위한 메세지 루프 수행
	}
};

CMyApp theApp;



#if 0

// MFC 에서 제공하는 윈도우 클래스
// 1. CWnd : 모든 윈도우의 공통의 특징을 제공
class Cwnd
{
public:
	void CreateEx() {} //윈도우 생성
};
// 2. CFrameWnd : 공통특징 + 주 윈도우로 사용되기 위한 특징을 추가
class CFrameWnd : public CWnd
{
public:
	// 메뉴관리 기능 
	void Create() { CWnd::CreateEx(); }
};
// 3. Dialog 클래스도 제공
class CDialog : public CWnd {};
class CButton : public CWnd {};


#endif // 0

