
// Sample4.h: Sample4 응용 프로그램의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// CSample4App:
// 이 클래스의 구현에 대해서는 Sample4.cpp을(를) 참조하세요.
//

class CSample4App : public CWinApp
{
public:
	CSample4App();


// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSample4App theApp;
