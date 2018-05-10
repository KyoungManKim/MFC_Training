#pragma once


// CMyDialog 대화 상자

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)

public:

	CEdit m_edit1;
	CEdit m_edit2;
	
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
	afx_msg void OnBnClickedButton1();
};
