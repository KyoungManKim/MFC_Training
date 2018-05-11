
// Sample3View.h: CSample3View 클래스의 인터페이스
//

#pragma once


class CSample3View : public CTreeView
{
protected: // serialization에서만 만들어집니다.
	CSample3View();
	DECLARE_DYNCREATE(CSample3View)

// 특성입니다.
public:
	CSample3Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CSample3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Sample3View.cpp의 디버그 버전
inline CSample3Doc* CSample3View::GetDocument() const
   { return reinterpret_cast<CSample3Doc*>(m_pDocument); }
#endif

