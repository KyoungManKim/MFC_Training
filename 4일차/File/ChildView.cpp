
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h"
#include "File.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CFile file(_T("a.txt"), CFile::modeReadWrite | CFile::modeCreate);

	//file.Write("hello", 5);

	//Archive : 파일 입출력을 Serialization 기법으로 사용
	CArchive ar(&file, CArchive::store);
	
	int n = 10;
	CPoint pt(1, 1);
	CString s(_T("hello"));

	ar << n << pt << s;
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CFile file(_T("a.txt"), CFile::modeReadWrite);

	CArchive ar(&file, CArchive::load);	// load 용 archive

	int n;
	CPoint pt;
	CString s;

	// 주의 : 넣은 순서대로 꺼내야 함.
	ar >> n >> pt >> s;

	CString s2;
	s2.Format(_T("%d"), n);
	AfxMessageBox(s2);
}
