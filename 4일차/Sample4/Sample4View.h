
// Sample4View.h: CSample4View 클래스의 인터페이스
//

#pragma once


class CSample4View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CSample4View();
	DECLARE_DYNCREATE(CSample4View)


public:
	CEdit m_edit1;
	CEdit m_edit2;
	CListBox m_listbox;

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_SAMPLE4_FORM };
#endif

// 특성입니다.
public:
	CSample4Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CSample4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // Sample4View.cpp의 디버그 버전
inline CSample4Doc* CSample4View::GetDocument() const
   { return reinterpret_cast<CSample4Doc*>(m_pDocument); }
#endif

