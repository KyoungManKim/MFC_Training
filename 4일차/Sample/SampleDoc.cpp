
// SampleDoc.cpp: CSampleDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Sample.h"
#endif

#include "SampleDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSampleDoc

IMPLEMENT_DYNCREATE(CSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CSampleDoc, CDocument)
END_MESSAGE_MAP()


// CSampleDoc 생성/소멸

CSampleDoc::CSampleDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CSampleDoc::~CSampleDoc()
{
}

// 새로만들기 버튼을 눌렀을때 실행
BOOL CSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_arr.RemoveAll();

	// View를 무효화해서 다시 그리게 하는 작업은 MFC에서 제공
	return TRUE;
}




// CSampleDoc serialization
//저장 메뉴를 누르면
//1. File DialoBox 를 나타내서 파일 이름을 입력 받고
//2. CFile 로 파일을 오픈
//3. CArchive 클래스로 저장용 아카이브를 만들어서
//4. Doc::Serialize함수를 호출하면서 아카이브를 인자로 전달.

void CSampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_arr.GetSize();
		for (int i = 0; i < m_arr.GetSize(); i++)
			ar << m_arr[i];
	}
	else
	{
		int sz = 0;
		ar >> sz;
		for (int i = 0; i < sz; i++)
		{
			CRect rc;
			ar >> rc;
			m_arr.Add(rc);
		}
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CSampleDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CSampleDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSampleDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSampleDoc 진단

#ifdef _DEBUG
void CSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSampleDoc 명령
