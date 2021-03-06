#pragma once


// CMyDiag 대화 상자

class CMyDiag : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDiag)

public:
	CMyDiag(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMyDiag();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

public:
	// Dialog 위의 컨트롤과 값 방식으로 연결할 변수.
	CString	m_data;
	int		m_x;
	int		m_y;

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
