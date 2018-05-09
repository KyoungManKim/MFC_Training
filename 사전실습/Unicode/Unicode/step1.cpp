#undef UNICODE
#undef _UNICODE

#include <iostream>
#include <windows.h>
#include <tchar.h>
using namespace std;

#if 1
// Step 5. WIndows API, MFC �� �����ڵ�
// �ٽ� :	�Լ� ���ڷ� ���ڿ��� ���޵Ǹ�
//			�ش� �Լ��� ��ũ�� �����̴�.
//			��¥ �Լ��� xxA(), xxW() ������ �ִ�. 
int main()
{
	MessageBoxA(0, "AA", "BB", 0);
	MessageBoxW(0, L"AA", L"BB", 0);

	// �Ʒ� 2���� UNICODE  ��ũ�� ���� ���ο� ���� 
	// MessageBoxA or MessageBoxW �� ��
	//MessageBox(0, "AA", "BB", 0);	
	//MessageBox(0, L"AA", L"BB", 0);	

	MessageBox(0, _T("AA"), _T("BB"), 0);

}

#endif // 1

#if 0

#ifdef UNICODE
	#define foo	fooW
#else
	#define foo fooA
#endif
// step 4. DBCS �� Unicode �� ���ÿ� �����ϴ� �Լ� �����
// ��ũ�η� �����ϴ� ����� �ѹ��� �Ѱ��� �ۿ� ������ �� ����.
// �ᱹ �ΰ��� �Լ��� ��������
void fooA(const char*) {}		// Ansi string
void fooW(const wchar_t*) {}	// Wide string

int main()
{
	fooA("AA");
	fooW(L"AA");
	foo(_T("AA"));
}
#endif //1



#if 0
// Step 3.

/*
#define UNICODE

#ifdef UNICODE
	typedef wchar_t TCHAR;
	#define _T(x) L##x		// ## Token paste
	#define _tcslen wcslen
#else
	typedef char TCHAR;
	#define _T(x) x
	#define _tcslen strlen
#endif
*/
int main()
{
	TCHAR s[] = _T("ABCD�����ٶ�");

	printf("sizeof %d\n", sizeof(s));
	printf("strlen %d\n", _tcslen(s));

}
#endif // 1




#if 0
// Step 2.
//			Ÿ��		���ڿ�	�Լ�
//DBCS		char		""		strxxx()
//UNICODE	wchar_t		L""		wcsxxx()

int main()
{
	// char : 1byte
	// wchar_t : 2byte
	wchar_t s[] = L"ABCD�����ٶ�";

	printf("sizeof %d\n", sizeof(s)); // 18
	printf("streln %d\n", strlen((char*)s)); //1 -> strlen �� null ���ڰ� ���ö������� ���̸� ã��, Unicode �� ��� A�� 65 00 ���� ����Ǳ� ������ len 1
	printf("wcslen %d\n", wcslen(s));


}
#endif // 0

#if 0
// Step 1
// MBCS : Multi Byte Character Set
// (DBCS : Double Byte Character Set)
int main()
{
	char s[] = "ABCD�����ٶ�";

	char* p = s;
	while (*p) {
		printf("%s\n", p);
		//p = p + 1;
		p = CharNextA(p);

	}
	printf("%d\n", sizeof(s));	//13
	printf("%d\n", strlen(s));  //12
}

#endif // 0
