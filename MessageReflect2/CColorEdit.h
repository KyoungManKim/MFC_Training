#pragma once


// CColorEdit

class CColorEdit : public CEdit
{
	DECLARE_DYNAMIC(CColorEdit)

public:
	CColorEdit();
	virtual ~CColorEdit();
	
	//------------------------------------------------
	COLORREF m_txtColor	= RGB(0, 0, 0);
	COLORREF m_bkColor	= RGB(255, 255, 255);
	CBrush	 m_brush;

	void SetTextColor(COLORREF color);
	void SetBkColor(COLORREF color);
	//------------------------------------------------

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};


