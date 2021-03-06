// CMyDiag.cpp: 구현 파일
//

#include "stdafx.h"
#include "Dialog2.h"
#include "CMyDiag.h"
#include "afxdialogex.h"


// CMyDiag 대화 상자

IMPLEMENT_DYNAMIC(CMyDiag, CDialogEx)

CMyDiag::CMyDiag(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDiag::~CMyDiag()
{
}

void CMyDiag::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	// 컨트롤 변수를 연결
	// 1. 컨트롤 형식 변수
	// DDX_Control(pDX, IDC_EDIT1, m_edit1

	// 2. 값 방식 변수
	DDX_Text(pDX, IDC_EDIT1, m_data);
	DDX_Text(pDX, IDC_EDIT2, m_x);
	DDX_Text(pDX, IDC_EDIT3, m_y);

}


BEGIN_MESSAGE_MAP(CMyDiag, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDiag::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CMyDiag::OnBnClickedOk)
END_MESSAGE_MAP()


// CMyDiag 메시지 처리기


void CMyDiag::OnBnClickedButton1()
{
	AfxMessageBox(_T("Button1"));
}


BOOL CMyDiag::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 멤버 변수의 값 => 컨트롤로 옮긴다.
	UpdateData(FALSE); // 위 코드에서 발생

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CMyDiag::OnBnClickedOk()
{
	// Dialog 를 닫을때
	// 컨트롤에 입력한 값 -> 멤버면수로 꺼내온다.
	//UpdateData(TRUE);	// 이 코드가 아래 함수 호출 안에서 발생
	
	CDialogEx::OnOK();
}
