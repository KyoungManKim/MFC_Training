#undef UNICODE
#undef _UNICODE

#include <iostream>
#include <windows.h>
#include <tchar.h>
using namespace std;

#if 1
// Step 5. WIndows API, MFC 와 유니코드
// 핵심 :	함수 인자로 문자열이 전달되면
//			해당 함수는 매크로 버전이다.
//			진짜 함수는 xxA(), xxW() 버전이 있다. 
int main()
{
	MessageBoxA(0, "AA", "BB", 0);
	MessageBoxW(0, L"AA", L"BB", 0);

	// 아래 2줄은 UNICODE  매크로 정의 여부에 따라 
	// MessageBoxA or MessageBoxW 가 됨
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
// step 4. DBCS 와 Unicode 를 동시에 지원하는 함수 만들기
// 매크로로 정의하는 방법은 한번에 한가지 밖에 지원할 수 없음.
// 결국 두개의 함수를 만들어야함
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
	TCHAR s[] = _T("ABCD가나다라");

	printf("sizeof %d\n", sizeof(s));
	printf("strlen %d\n", _tcslen(s));

}
#endif // 1




#if 0
// Step 2.
//			타입		문자열	함수
//DBCS		char		""		strxxx()
//UNICODE	wchar_t		L""		wcsxxx()

int main()
{
	// char : 1byte
	// wchar_t : 2byte
	wchar_t s[] = L"ABCD가나다라";

	printf("sizeof %d\n", sizeof(s)); // 18
	printf("streln %d\n", strlen((char*)s)); //1 -> strlen 은 null 문자가 나올때까지의 길이를 찾음, Unicode 의 경우 A가 65 00 으로 저장되기 때문에 len 1
	printf("wcslen %d\n", wcslen(s));


}
#endif // 0

#if 0
// Step 1
// MBCS : Multi Byte Character Set
// (DBCS : Double Byte Character Set)
int main()
{
	char s[] = "ABCD가나다라";

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
