#pragma once


// CColorEdit

class CColorEdit : public CEdit
{
	DECLARE_DYNAMIC(CColorEdit)

public:
	CColorEdit();
	virtual ~CColorEdit();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};


