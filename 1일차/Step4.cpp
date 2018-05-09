// Step4.cpp - View ������ �߰�
#include <afxwin.h>

// Frame ������ ���ʿ� ���¹�, ���ٵ��� ������ ������ �ڽ� ������ (View ��� �θ�) �� ���δ�.

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
//v.Create() �Ǵ� v.CreateEx() �Ҷ� ������ ����


class CMainFrame : public CFrameWnd
{
public:
	CChildView m_wndView;	// �ڽ� ������ (view) �� ����� ����
	CMainFrame()
	{
		
	}
	// Frame �����찡 ������ �� WN_CREATE �޼��� �߻� , �Ʒ� �Լ� ȣ��
	int OnCreate(LPCREATESTRUCT lpc)
	{
		if (CFrameWnd::OnCreate(lpc) == -1) 
			return -1;

		m_wndView.CreateEx(0, 0, 0,
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			CRect(100, 100, 200, 200),
			this,
			AFX_IDW_PANE_FIRST);	// ID���� AFX_IDW_PANE_FIRST �� ����ϸ� View �� ����, ���¹ٸ� ������ Frame ��ü�� ����
	}

	DECLARE_MESSAGE_MAP()
};
//(Ŭ���� �̸�, ��� Ŭ���� �̸�)
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance()
	{
		CMainFrame* pFrame = new CMainFrame;	// �����츦 ����� �ڵ尡 �ƴ�,
		pFrame->Create(0, _T("Hello!"));	// �� ���� ������ ����
											// WM_CREATE �޼��� �߻�
		pFrame->ShowWindow(SW_SHOW);

		m_pMainWnd = pFrame;


		return TRUE;
	}
};
CMyApp theApp;