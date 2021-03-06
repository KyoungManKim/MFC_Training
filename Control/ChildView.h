
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once

#define IDC_BUTTON1	1
#define IDC_BUTTON2	2
#define IDC_EDIT	3
#define IDC_COMBO	4
#define IDC_LIST	5

// 핵심, 컨트롤을 만드는 방법
// CButton btn;  // 객체를 생성후에
// btn.Create(); // Create() 멤버함수를 호출한다.
class CChildView : public CWnd
{
// 생성입니다.
public:
	CButton		m_btn1;
	CButton		m_btn2;
	CEdit		m_edit;
	CListBox	m_list;
	CComboBox	m_combo;

	CChildView();

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void CChildView::OnButton1();
};

