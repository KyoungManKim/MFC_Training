#pragma once


// CLeftFormView 보기

class CLeftFormView : public CFormView
{
	DECLARE_DYNCREATE(CLeftFormView)

protected:
	CLeftFormView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CLeftFormView();

public:
	enum { IDD = IDD_FORMVIEW };

	CEdit m_edit;

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual void DoDataExchange(CDataExchange* pDX);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};


