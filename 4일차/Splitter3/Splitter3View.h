
// Splitter3View.h: CSplitter3View 클래스의 인터페이스
//

#pragma once
#include "Splitter3Doc.h"

class CSplitter3View : public CTreeView
{
protected: // serialization에서만 만들어집니다.
	CSplitter3View();
	DECLARE_DYNCREATE(CSplitter3View)

// 특성입니다.
public:
	CSplitter3Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CSplitter3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Splitter3View.cpp의 디버그 버전
inline CSplitter3Doc* CSplitter3View::GetDocument() const
   { return reinterpret_cast<CSplitter3Doc*>(m_pDocument); }
#endif

