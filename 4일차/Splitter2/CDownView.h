#pragma once


// CDownView 보기

class CDownView : public CEditView
{
	DECLARE_DYNCREATE(CDownView)

protected:
	CDownView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CDownView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


