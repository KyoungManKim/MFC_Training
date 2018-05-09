// Step2.cpp
// Step2. �ٽ� ����
//1.CMyApp::InitInstance ���� ������ �����
//	 CFrameWnd �� ����ؼ� ���� 3���� �ڵ�
//2. ������� ������ ��ü�� �ּҴ� �ݵ�� m_pMainWnd �� �����ؾ� �Ѵ�.
//3. return TRUE �� �ؼ� ���α׷��� ������� �ʰ� �޼��� ������ �����ϰ� �Ѵ�.
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
		pFrame->Create(0, _T("Hello!"));	// ������ ����
		pFrame->ShowWindow(SW_SHOW);		// ������ �����ֱ�

		m_pMainWnd = pFrame;				// CWinApp ���κ��� ��ӹ���, �ڵ����� Delete ���� ����

		return TRUE;	// FALSE: main ���� ���ư��� ������� ����
						// TRUE : GUI Event�� ó���ϱ� ���� �޼��� ���� ����
	}
};

CMyApp theApp;



#if 0

// MFC ���� �����ϴ� ������ Ŭ����
// 1. CWnd : ��� �������� ������ Ư¡�� ����
class Cwnd
{
public:
	void CreateEx() {} //������ ����
};
// 2. CFrameWnd : ����Ư¡ + �� ������� ���Ǳ� ���� Ư¡�� �߰�
class CFrameWnd : public CWnd
{
public:
	// �޴����� ��� 
	void Create() { CWnd::CreateEx(); }
};
// 3. Dialog Ŭ������ ����
class CDialog : public CWnd {};
class CButton : public CWnd {};


#endif // 0

