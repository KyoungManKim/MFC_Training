#undef UNICODE
#undef _UNICODE
#define _AFXDLL
#include <iostream>
#include <afxwin.h>	//MFC 기본 헤더
#include <afxtempl.h> // 옛날버전의 VC 에서 템플릿 클래스를 사용하려면 필요한 헤더
using namespace std;

int main()
{
	int x[5]; 
	//CUIntArray ar; // unsigned int 를 보관하는 배열
	CArray<int> ar; //MFC 2.0 부터 Template 지원

	ar.Add(10);
	ar.Add(20);
	ar.Add(30);

	ar[0] = 100;

	for (int i = 0; i < ar.GetSize(); i++)
	{
		cout << ar[i] << endl;
	}
}

// Step1. CString 사용하기.
//int main()
//{
//	CString s = "Hello";
//	cout << s << endl;
//	cout << s.GetLength() << endl;
//}
