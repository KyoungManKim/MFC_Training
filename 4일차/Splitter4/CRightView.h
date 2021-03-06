#pragma once

#ifdef _WIN32_WCE
#error "Windows CE에서는 CHtmlView가 지원되지 않습니다."
#endif 
#include "Splitter4Doc.h"
#include "Splitter4View.h"
// CRightView html 보기

class CRightView : public CHtmlView
{
	DECLARE_DYNCREATE(CRightView)

protected:
	CRightView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CRightView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};


