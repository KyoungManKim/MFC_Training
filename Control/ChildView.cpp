
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Control.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView


// CChildView m_wndView;
// m)wndView.Create();		// 윈도우 생성 WN_CREATE 메시지
CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	// 메시지 맵 1. 일반 메시지
	ON_WM_PAINT()
	ON_WM_CREATE()

	//메시지 맵 2. 메뉴
	// ON_COMMAND ( 메뉴 ID, 함수 )
	
	// 메시지맵 3. 컨트롤이 보내는 메세지 처리
	//				함수 모양 : void fx()
	ON_CONTROL( BN_CLICKED, IDC_BUTTON1, OnButton1)

END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

// View 의 초기화 장소
// 생성자	:	아직 View 윈도우가 없는 상태이다.
//				윈도우가 필요없는 초기화 코드만 가능
// OnCreate():	윈도우가 만들어진 후, 윈도우가 필요한 초기화 자식윈도우(컨트롤) 만들기 등.

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_btn1.Create(_T("버튼1"), WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(210, 100, 300, 150), this, IDC_BUTTON1); 
	m_edit.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL, CRect(110, 100, 200, 200), this, IDC_EDIT);
	m_list.Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(310, 100, 400, 200), this, IDC_LIST);
	m_combo.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN, CRect(410, 100, 500, 200), this, IDC_COMBO);

	m_edit.SetMargins(5, 10);
	
	return 0;
}

void CChildView::OnButton1()
{
	CString s;
	m_edit.GetWindowText(s);
	//AfxMessageBox(s);
	m_list.AddString(s);	
	m_edit.SetWindowText(_T(""));
}

// 컨트롤의 핵심
// 1. 컨트롤을 만드는 법
//	(A) View 선언에 멤버 변수 추가	CEdit m_edit;
//	(B) View::OnCreate() 에서 m_edit.Create() 코드 추가.

// 2. 각 컨트롤을 만들때는 다양한 스타일을 지정할 수 있다.

// 3. 각 컨트롤에는 다양한 멤버 함수가 있다.
//	  컨트롤에 어떤 일을 하고 싶으면 해당하는 멤버함수를 찾으면 된다.
