// Step3.cpp	- event ó���ϱ� �ٽ�
#include <afxwin.h>

//1. CFrameWnd �� �Ļ� Ŭ������ �����
//2. Ŭ���� ���� DECLARE_MESSAGE_MAP() �߰�
//3. Ŭ���� �ܺο� BEGIN_MESSAGE_MAP() ~ END_MESSAGE_MAP()
//4. �ش� �޼����� ��ũ�θ� �ʿ� �߰��ϰ� �ɹ��Լ� �߰�

class CMainFrame : public CFrameWnd
{
public:
	// event �� ���� �Լ� �̸��� ����� �̹� ��ӵǾ� �ֽ��ϴ�.
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

	
	// �� Ŭ�������� �̺�Ʈ�� ó���ϰڴٴ� ����� MFC�� �˸���.
	DECLARE_MESSAGE_MAP()
};
// Ŭ���� �ܺο� �޼��� ���� ����� ó���� �޼����� ���� ��ũ�� �߰�.

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)	//(Ŭ���� �̸�, ��� Ŭ���� �̸�)
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
