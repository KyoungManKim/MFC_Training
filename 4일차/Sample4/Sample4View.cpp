
// Sample4View.cpp: CSample4View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Sample4.h"
#endif

#include "Sample4Doc.h"
#include "Sample4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample4View

IMPLEMENT_DYNCREATE(CSample4View, CFormView)

BEGIN_MESSAGE_MAP(CSample4View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CSample4View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CSample4View 생성/소멸

CSample4View::CSample4View()
	: CFormView(IDD_SAMPLE4_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSample4View::~CSample4View()
{
}

void CSample4View::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_LIST1, m_listbox);

	CFormView::DoDataExchange(pDX);
}

BOOL CSample4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CSample4View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CSample4View 진단

#ifdef _DEBUG
void CSample4View::AssertValid() const
{
	CFormView::AssertValid();
}

void CSample4View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSample4Doc* CSample4View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample4Doc)));
	return (CSample4Doc*)m_pDocument;
}
#endif //_DEBUG


// CSample4View 메시지 처리기


void CSample4View::OnBnClickedButton1()
{
	// Edit1 에서 값 꺼내기
	CString s;
	m_edit1.GetWindowText(s);
	// listbox 에 추가
	if(s != "")
		m_listbox.AddString(s);
	// edit1 에서 값 지우기
	m_edit1.SetWindowText(_T(""));
	
}
