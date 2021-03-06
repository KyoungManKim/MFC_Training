#pragma once
#include "CColorEdit.h"

// CMyDialog 대화 상자

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	
	CColorEdit m_edit;

	int m_penWidth;
	int m_red;
	int m_green;
	int m_blue;

	// 컨트롤의 멤버 함수를 사용하려면
	// 값 타입이 아닌 컨트롤 타입과 연결해야함
	CSpinButtonCtrl m_spinRed;
	CSpinButtonCtrl m_spinGreen;
	CSpinButtonCtrl m_spinBlue;
public:
	CMyDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMyDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
