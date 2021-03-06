
// Control2Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Control2.h"
#include "Control2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CControl2Dlg 대화 상자



CControl2Dlg::CControl2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONTROL2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CControl2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST1, m_list);

	DDX_Control(pDX, IDC_LIST2, m_listbox);
	DDX_Control(pDX, IDC_COMBO1, m_combobox);

}

BEGIN_MESSAGE_MAP(CControl2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CControl2Dlg::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CControl2Dlg::OnNMDblclkList1)
	ON_LBN_DBLCLK(IDC_LIST2, &CControl2Dlg::OnLbnDblclkList2)
END_MESSAGE_MAP()


// CControl2Dlg 메시지 처리기

BOOL CControl2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	// List 컨트롤 사용 방법
	// 1. List 의 보기 스타일 (아이콘, 작은 아이콘, 자세히, 간단히) 지정
	m_list.ModifyStyle(LVS_TYPEMASK,	// 기존스타일 제거
					LVS_REPORT);			// 이 스타일로 지정.

	// 2. List 컨트롤 확장스타일
	// LVS_		: List View Style (List를 List View 라고도 함.
	// LVS_EX_	: List View Extended Style
	m_list.SetExtendedStyle( LVS_EX_FULLROWSELECT );
	
	// 3. List 에 ImageList 연결
	m_img.Create(IDB_BITMAP2, 48, 0, RGB(255, 255, 255));
	m_imgSmall.Create(IDB_BITMAP1, 16, 0, RGB(255, 255, 255));

	m_list.SetImageList(&m_img, LVSIL_NORMAL);		// 큰 아이콘
	m_list.SetImageList(&m_imgSmall, LVSIL_SMALL);	//작은 아이콘, 자세히, 간단히

	// 4. 컬럼 헤더 추가
	m_list.InsertColumn(0, _T("이름"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(1, _T("크기"), LVCFMT_RIGHT, 150);
	m_list.InsertColumn(2, _T("날짜"), LVCFMT_LEFT, 150);
	
	// 5. 항목 추가하기
	//m_list.InsertItem(0, _T("readme.txt"), 0);
	//m_list.SetItemText(0, 1, _T("10 kb"));
	//m_list.SetItemText(0, 2, _T("2018-05-10"));

	//m_list.InsertItem(1, _T("a.txt"), 1);
	//m_list.SetItemText(1, 1, _T("11 kb"));
	//m_list.SetItemText(1, 2, _T("2018-05-10"));

	//m_list.InsertItem(2, _T("b.txt"), 2);
	//m_list.SetItemText(2, 1, _T("1 mb"));
	//m_list.SetItemText(2, 2, _T("2018-05-10"));

	// 디렉토리 추가
	RefreshList();



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CControl2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CControl2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CControl2Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CControl2Dlg::RefreshList()
{
	SetCurrentDirectory(_T("C:\\Windows"));	// 열거할 디렉토리

	CFileFind ff;	// 파일을 열거할 때 사용하는 클래스

	BOOL b = ff.FindFile(_T("*.*"));
	b = ff.FindNextFile();
	int imgno = 0;
	while (b)
	{
		if (ff.IsDirectory())
			imgno = 1;
		else
			imgno = 0;
		m_list.InsertItem(0, ff.GetFileName(), imgno);
		
		if (ff.IsDirectory() == FALSE)
		{
			int size = ff.GetLength();
			CString s;
			s.Format(_T("%d KB"), (size / 1024) + 1);
			m_list.SetItemText(0, 1, s);
		}

		b = ff.FindNextFile();
	}
}


void CControl2Dlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
	//AfxMessageBox(_T("DBLCLK"));
	
	// list 는 여러개 항목 선택 가능
	POSITION pos = m_list.GetFirstSelectedItemPosition();

	while (pos)
	{
		// 선택된 항목의 index 를 꺼내고, 다음 항목으로 이동.
		int item = m_list.GetNextSelectedItem(pos);
		
		// item 의 index로 부터 항목의 문자열을 구함
		CString s;
		s = m_list.GetItemText(item, 0);

		m_listbox.AddString(s);
		
	}
	
}


void CControl2Dlg::OnLbnDblclkList2()
{
	CString s;
	int item= m_listbox.GetCurSel();
		
	m_listbox.GetText(item, s);
	m_listbox.DeleteString(item);
	
	m_combobox.AddString(s);
}
