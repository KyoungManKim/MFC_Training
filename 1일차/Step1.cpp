// Step1. cpp
// ���� ������ MFC GUI ���α׷�
// #define _AFXDLL - console ���� MFC ���
// Windosw ����ũž ������ - WIndowx �������α׷� ���� ��
// ������Ʈ -> �Ӽ� �޴�����, MFC ����׸��� ����DLL ���� MFC ������� ����

// Afx �� �����ϴ� �Լ��� : ����Լ��� �ƴ� �Ϲ� �Լ�.
//							� Ŭ���� �ȿ����� ��� ����
						
// CWinAPP ���� �����Ǿ� �ִ� InitInstance �� �ݵ�� �̿��ؾ���
// �Ϲ����� Workflow:
// 1. CWinAPP �� ��ӹ޾� InitInstance �� ������
// 2. ����� Class �� ���������� ����

//�ٽ�
//1. main �Լ� (WinMain)�� MFC ���ο� �ִ�.
//2. ����ڴ� MFC�� ����ϱ� ���� ��Ģ�� ���Ѿ� �Ѵ�.
//	(1) CWinApp ���� �Ļ��� Ŭ���� ����
//	(2) InitInstance() �����Լ��� ������
//	(3) ����ڰ� ���� Ŭ������ ��ü�� ���������� �Ѱ� ������ �Ѵ�.
//	(4) �ʿ��ϸ� ExitInstance() �� ������ �ؼ� ���������� ������ �۾��� �ۼ�

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


