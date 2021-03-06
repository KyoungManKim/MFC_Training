// CMyDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "Dialog.h"
#include "CMyDialog.h"
#include "afxdialogex.h"


// CMyDialog 대화 상자

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	// IDC_EDIT1 의 리소스를 m_edit1 변수와 연결
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);

	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMyDialog 메시지 처리기


void CMyDialog::OnBnClickedButton1()
{
	CString s1,s2;
	
	// 컨트롤에서 값 꺼내기
	// 1. 컨트롤의 ID 값으로 부터, 컨트롤을 가리키는 객체를 얻어냅니다.
	//CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	//edit->GetWindowText(s);

	// 2. 컨트롤에서 바로 값을 꺼낼수 있다.
	//GetDlgItemText(IDC_EDIT1, s);
	
	// 3. DDX(DIalog Data Exchange) 로 연결한 컨트롤 변수 사용
	m_edit1.GetWindowText(s1);
	m_edit2.GetWindowText(s2);
	AfxMessageBox(s1+"\n"+s2);
}
