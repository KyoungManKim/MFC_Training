
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once

// 선의 정보를 담은 구조체
struct LINE
{
	CPoint	ptFrom;
	CPoint	ptTo;

	int		width;
	int		red;
	int		green;
	int		blue;	
};



class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:

	CArray<LINE> m_arr;

	CPoint m_ptFrom;
	
	int m_penWidth	= 5;
	int m_red		= 0;
	int m_green		= 51;
	int m_blue		= 221;

	
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnEditSetting();
};

