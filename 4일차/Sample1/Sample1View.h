
// Sample1View.h: CSample1View 클래스의 인터페이스
//

#pragma once


class CSample1View : public CHtmlView
{
protected: // serialization에서만 만들어집니다.
	CSample1View();
	DECLARE_DYNCREATE(CSample1View)

// 특성입니다.
public:
	CSample1Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CSample1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGoBack();
	afx_msg void OnGoForward();
	afx_msg void OnGoHome();
	afx_msg void OnGoRefresh();
	afx_msg void OnGoSearch();
	afx_msg void OnGoStop();
	virtual void OnBeforeNavigate2(LPCTSTR lpszURL, DWORD nFlags, LPCTSTR lpszTargetFrameName, CByteArray& baPostedData, LPCTSTR lpszHeaders, BOOL* pbCancel);
};

#ifndef _DEBUG  // Sample1View.cpp의 디버그 버전
inline CSample1Doc* CSample1View::GetDocument() const
   { return reinterpret_cast<CSample1Doc*>(m_pDocument); }
#endif

