// Step1. cpp
// 가장 간단한 MFC GUI 프로그램
// #define _AFXDLL - console 에서 MFC 사용
// Windosw 데스크탑 마법사 - WIndowx 응용프로그램 선택 후
// 프로젝트 -> 속성 메뉴에서, MFC 사용항목을 공유DLL 에서 MFC 사용으로 선택

// Afx 로 시작하는 함수들 : 멤버함수가 아닌 일반 함수.
//							어떤 클래스 안에서도 사용 가능
						
// CWinAPP 에서 구현되어 있는 InitInstance 를 반드시 이용해야함
// 일반적인 Workflow:
// 1. CWinAPP 을 상속받아 InitInstance 를 재정의
// 2. 상속한 Class 를 전역변수로 선언

//핵심
//1. main 함수 (WinMain)는 MFC 내부에 있다.
//2. 사용자는 MFC를 사용하기 위해 규칙을 지켜야 한다.
//	(1) CWinApp 에서 파생된 클래스 생성
//	(2) InitInstance() 가상함수를 재정의
//	(3) 사용자가 만든 클래스의 객체를 전역적으로 한개 만들어야 한다.
//	(4) 필요하면 ExitInstance() 를 재정의 해서 종료직전에 수행할 작업을 작성

#include <afxwin.h>


class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance()
	{
		AfxMessageBox(_T("Hello, MFC"));
		return FALSE;
	}
	virtual BOOL ExitInstance()
	{
		AfxMessageBox(_T("Bye, MFC"));
		return FALSE;
	}
};

CMyApp theApp;


