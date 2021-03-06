
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once


#define	COUNT	5		//가로세로 블럭의 갯수
#define	EMPTY	( COUNT * COUNT ) - 1


class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();
	
	CImage m_img;
	int m_cxImg, m_cyImg;		// 그림의 크기
	int m_cxBlock, m_cyBlock;	// 한 블럭의 크기 (그림크기 / 5)

	// 게임판의 상태를 관리할 2창원 배열 - 핵심 자료 구조
	int m_board[COUNT][COUNT];
// 특성입니다.
public:

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
	afx_msg void OnNew();
};

