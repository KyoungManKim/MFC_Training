#undef UNICODE
#undef _UNICODE
#define _AFXDLL
#include <iostream>
#include <afxwin.h>	//MFC �⺻ ���
#include <afxtempl.h> // ���������� VC ���� ���ø� Ŭ������ ����Ϸ��� �ʿ��� ���
using namespace std;

int main()
{
	int x[5]; 
	//CUIntArray ar; // unsigned int �� �����ϴ� �迭
	CArray<int> ar; //MFC 2.0 ���� Template ����

	ar.Add(10);
	ar.Add(20);
	ar.Add(30);

	ar[0] = 100;

	for (int i = 0; i < ar.GetSize(); i++)
	{
		cout << ar[i] << endl;
	}
}

// Step1. CString ����ϱ�.
//int main()
//{
//	CString s = "Hello";
//	cout << s << endl;
//	cout << s.GetLength() << endl;
//}
