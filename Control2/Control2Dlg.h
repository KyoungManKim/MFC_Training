
// Control2Dlg.h: 헤더 파일
//

#pragma once


// CControl2Dlg 대화 상자
class CControl2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CControl2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CListCtrl m_list;
	CImageList m_img;
	CImageList m_imgSmall;

	CListBox	m_listbox;
	CComboBox	m_combobox;


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTROL2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	void RefreshList();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLbnDblclkList2();
};
