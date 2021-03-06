
// Splitter2View.h: CSplitter2View 클래스의 인터페이스
//

#pragma once
#include "Splitter2Doc.h"

class CSplitter2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CSplitter2View();
	DECLARE_DYNCREATE(CSplitter2View)

// 특성입니다.
public:
	CSplitter2Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CSplitter2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Splitter2View.cpp의 디버그 버전
inline CSplitter2Doc* CSplitter2View::GetDocument() const
   { return reinterpret_cast<CSplitter2Doc*>(m_pDocument); }
#endif

