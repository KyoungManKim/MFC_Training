
// Sample2View.h: CSample2View 클래스의 인터페이스
//

#pragma once


class CSample2View : public CTreeView
{
protected: // serialization에서만 만들어집니다.
	CSample2View();
	DECLARE_DYNCREATE(CSample2View)

// 특성입니다.
public:

	CImageList m_imgList;

	CSample2Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CSample2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // Sample2View.cpp의 디버그 버전
inline CSample2Doc* CSample2View::GetDocument() const
   { return reinterpret_cast<CSample2Doc*>(m_pDocument); }
#endif

