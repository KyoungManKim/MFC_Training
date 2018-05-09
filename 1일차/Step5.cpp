// Step5.cpp - 
#include <afxwin.h>

// ���ҽ��� �߰��ϸ� 
// 1. ������Ʈ�̸�.rc ���� ����
// 2. *.rc ������ ���� Ŭ�� -> ���ҽ� �� ����
// 3. ���ҽ��信�� ��� ���ҽ� ������ �Ŀ� ID �� ����
//    �Ӽ� â ���� ID �� ����
// 4. ���ҽ��信�� ���� ��� ID �� resource.h �� #define ���� �����ȴ�.
// �ᱹ ���ҽ��� �ڵ忡�� ����Ϸ��� �Ʒ� ����� �ʿ��ϴ�.

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
		AfxMessageBox(_T("���� �޴� ����"));
		// WM_CLOSE �޼����� �ڽſ��� ������ ����ȴ�.
		SendMessage(WM_CLOSE);
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	// 1. �Ϲ� ������ �޼��� : ON_WM_�޼����̸�()
	ON_WM_CREATE()
	// 2. �޴� �޼��� : ON_COMMAND( ID, �Լ��̸� )
	//					�Լ� �̸��� ���ϴ´�� ��밡��.
	//					����� void func()
	ON_COMMAND(ID_APP_EXIT, OnExit) 
END_MESSAGE_MAP()

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance()
	{
		CMainFrame* pFrame = new CMainFrame;
		
		// �޴� ���̴� ���
		// 1. Frame ���鶧 6��° ���ڷ� ID ����
		/*
		pFrame->Create(0, _T("Hello!"),WS_OVERLAPPEDWINDOW,
			CRect(100,100,200,200) , 0, 
			MAKEINTRESOURCE(IDR_MAINFRAME));
		*/
		// 2. Create �� Frame �����츦 ������ ���� Load Frame �Լ��� ����� �����츦 �����,
		//    4���� ���ҽ��� �ڵ� �ε�
		//    (�޴�, ������, Accelerator, string table)
		pFrame->LoadFrame(IDR_MAINFRAME);
		pFrame->ShowWindow(SW_SHOW);

		m_pMainWnd = pFrame;


		return TRUE;
	}
};

CMyApp theApp;