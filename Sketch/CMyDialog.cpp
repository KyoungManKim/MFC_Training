// CMyDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "Sketch.h"
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

	// 컨트롤을 값 타입이 아닌 컨트롤 타입 변수로 연결
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_SPIN1, m_spinRed);
	DDX_Control(pDX, IDC_SPIN2, m_spinGreen);
	DDX_Control(pDX, IDC_SPIN3, m_spinBlue);

	DDX_Text(pDX, IDC_EDIT1, m_penWidth);
	DDX_Text(pDX, IDC_EDIT2, m_red);
	DDX_Text(pDX, IDC_EDIT3, m_green);
	DDX_Text(pDX, IDC_EDIT4, m_blue);

	// DDV(Dialog Data Validation)
	DDV_MinMaxInt(pDX, m_penWidth, 1, 300);
	DDV_MinMaxInt(pDX, m_red, 0, 255);
	DDV_MinMaxInt(pDX, m_green, 0, 255);
	DDV_MinMaxInt(pDX, m_blue, 0, 255);

	// Edit 를 CString 변수와 연결했을때 최대 문자열 제한
	// DDV_MaxChars(pDX, m_strData, 5);


	
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMyDialog 메시지 처리기


BOOL CMyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	m_spinRed.SetRange32(0, 255);
	m_spinGreen.SetRange32(0, 255);
	m_spinBlue.SetRange32(0, 255);
	
	m_edit.SetTextColor(RGB(60, 180, 100));
	m_edit.SetBkColor(RGB(200,200,255));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


// Dialog 가 필요하면
// 1. 리소스에서 Dialog 디자인
// 2. 클래스 추가 ( CDialogEx 의 파생 클래스 )
// 3. Dialog 위에 있는 컨트롤과 변수 연결 (Wizard 또는 직접 코딩)
//    DoDataExchange() 함수에서 연결
// 4. 메뉴를 만들고 View 에 메뉴 핸들러 추가 후, Dialog 를 나타내는 코드 추가

void CMyDialog::OnBnClickedButton1()
{
	// 컨트롤 내용 (입력값) -> 멤버 변수로 옮긴 후 사용
	UpdateData(TRUE);
	CString s;
	s.Format(_T("%d"), m_penWidth);

	AfxMessageBox(s);

}
