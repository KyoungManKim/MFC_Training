
// Control1Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Control1.h"
#include "Control1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CControl1Dlg 대화 상자



CControl1Dlg::CControl1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONTROL1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CControl1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);

}

BEGIN_MESSAGE_MAP(CControl1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER1, &CControl1Dlg::OnTRBNThumbPosChangingSlider1)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, &CControl1Dlg::OnNMReleasedcaptureSlider1)
END_MESSAGE_MAP()


// CControl1Dlg 메시지 처리기

BOOL CControl1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	m_progress.SetRange(0, 100);
	m_slider.SetRange(0, 100);
	
	m_progress.SetPos(50);
	m_progress.SetPos(50);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CControl1Dlg::OnPaint()
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
HCURSOR CControl1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CControl1Dlg::OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 이 기능을 사용하려면 Windows Vista 이상이 있어야 합니다.
	// _WIN32_WINNT 기호는 0x0600보다 크거나 같아야 합니다.
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

}


void CControl1Dlg::OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;


	// 현재위치를 얻어온다.
	int nPos = m_slider.GetPos();

	m_progress.SetPos(nPos);
}
