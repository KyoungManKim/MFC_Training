
// RegSample.cpp: 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "RegSample.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRegSampleApp

BEGIN_MESSAGE_MAP(CRegSampleApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CRegSampleApp::OnAppAbout)
END_MESSAGE_MAP()


// CRegSampleApp 생성

CRegSampleApp::CRegSampleApp()
{
	// TODO: 아래 응용 프로그램 ID 문자열을 고유 ID 문자열로 바꾸십시오(권장).
	// 문자열에 대한 서식: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("RegSample.AppID.NoVersion"));

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}

// 유일한 CRegSampleApp 개체입니다.

CRegSampleApp theApp;


// CRegSampleApp 초기화

BOOL CRegSampleApp::InitInstance()
{
	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// RichEdit 컨트롤을 사용하려면 AfxInitRichEdit2()가 있어야 합니다.
	// AfxInitRichEdit2();

	// HKEY_CURRENT_USER/SOFTWARE/회사이름/프로그램이름(RegSample)/"위치"
	// 아래 함수가 레지스트리에 항목을 만드는 함수
	SetRegistryKey(_T("MOBIS"));

	// 아래 함수 들이 레지스트리에 항목을 만드는 함수
	// WriteProfileInt(_T("위치"), _T("X"), 100);
	// WriteProfileInt(_T("위치"), _T("Y"), 200);
	
	// 레지스트리에 기록된 윈도우 좌표 읽어오기.
	// AfxGetApp 을 사용할 필요가 없다.
	int x = GetProfileInt(_T("위치"), _T("X"), 0);	// 0: 해당 key 값이 존재하지 않으면 Default 0
	int y = GetProfileInt(_T("위치"), _T("X"), 0);

	// WM_DESTORY -> 닫기 눌렀을때 발생하는 이벤트

	// 주 창을 만들기 위해 이 코드에서는 새 프레임 창 개체를
	// 만든 다음 이를 응용 프로그램의 주 창 개체로 설정합니다.
	CFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// 프레임을 만들어 리소스와 함께 로드합니다.
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr,
		nullptr);

	// Frame 윈도우를 이동
	pFrame->MoveWindow(x, y, 500, 500);



	// 창 하나만 초기화되었으므로 이를 표시하고 업데이트합니다.
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int CRegSampleApp::ExitInstance()
{
	//TODO: 추가한 추가 리소스를 처리합니다.
	return CWinApp::ExitInstance();
}

// CRegSampleApp 메시지 처리기


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// 대화 상자를 실행하기 위한 응용 프로그램 명령입니다.
void CRegSampleApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CRegSampleApp 메시지 처리기



