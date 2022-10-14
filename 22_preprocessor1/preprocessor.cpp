/*
	전처리기 : #으로 시작하는 컴파일 이전에 우전 처리되는 구문

	include : 해당 파일의 내용을 치환해준다.

	< > : 컴파일러가 기본적으로 지정하고 있는 표준 라이브러리 경로에 있는 헤더 파일 참조
	" " : 사용자가 사용중인 소스에 있는 위치를 기준으로 헤더 파일을 찾고, 만약에 없으면 < >와 같이 동작한다.

	  / : 현재 디렉터리의 루트(최상단파일)이동
	 ./ : 현재위치
	../ : 상위 디렉터리로 이동
*/

#include<stdio.h> // 여기에 stdio.h의 내용을 치환해준다.
#include"stdio.h" // 먼저 현재위치에서 파일을 찾고 없다면 < >와 같이 동작한다.

// 둘 다 같은 의미 현재 디렉터리 위치에서 헤더를 찾는다.
#include"test1.h" // 상대경로
#include"./test1.h" 
#include"C:\Users\SGA_C_014\Desktop\yoo\22_preprocessor1\test1.h" // 절대경로
// 상위 디렉터리로 이동하여 다른 폴더에 접근
#include"../22_preprocessor2/test2.h"

// 메크로 상수 : 매크로 상수를 이름으로 다룰 수 있다.
#define NUM 10

/*
	매크로 함수
	 - 단순 치환이기에 인자의 자료형을 신경쓰지 않는다.
	 = 함수 호출에 의한 성능 저하가 일어나지 않아 실행속도가 향상
	 = 단순 치환이므로 디버깅이 되지 않는다.
	 - 매크로 함수의 코드가 길어질수록 괄호가 많아져서 가족성이 떨어진다.
	  ->간단하고 자주 출되는 함수에 사용하는게 유리
*/

// 곱셈함수
#define MUL1(x,y) (x*y) 
#define MUL2(x,y) ((x)*(y)) 

 // # : 인자를 문자열로 바꾸어 준다.
 // 연속된 문자열은 하나로 합쳐진다. 결과 => printf("x : %d\n",x)
#define PRINT(x) printf(#x" : %d\n",x)

 // ## : 하나로 합쳐준다.
#define STRUCTURE(x) typedef struct {int i;} STRUCTURE_##x

#define Test
#define CANCEL

#if defined CANCEL && defined Test // defined : 해당 매크로가 정의 되어있는가?
#undef Test // 매크로 정의를 해제하는 구문
#endif

#ifdef Test // 해당 매크로가 정의되어 있다면 아래 코드를 포함한다.
int i = 10;
#else	// 그 외의 경우 예외 처리
int i = 20;
#endif

#ifndef Test // 해당 매크로가 정의되어 있지않다면 아래 코드를 포함한다.
int j = 10;
#else	// 그 외의 경우 예외 처리
int j = 20;
#endif

// 외부 파일에 존재하는 전역변수를 가져올 extern 키워드 사용
extern int z; // 외부에 존재하는 z라는 변수를 가져다 쓰겠다.
//extern int z = 10; // 해당 위치에 z라는 변수를 만들겠다.
 // 초기화 시켜주면 해당 변수를 실제로 만드는 명령어가 된다.
 //  -> 전역변수를 초기화 할 는 한 곳에서만 초기화를 해야한다.

extern int w = 20;

// 외부파일의 함수를 추가할때는 프로토타입을 적어준다.
// extern void test(); 
void test(); // <- extern 키워드 생략가능 

int main() {

	print_hello();
	test();

	int a = 3;
	int b = 4;

	int c1 = MUL1(a + 1, b + 1); // (x*y) => (a + 1 * b + 1 )
	int c2 = MUL2(a + 1, b + 1); //((x)*(y)) => ((a + 1) * (b + 1))

	printf("MUL1 = %d, MUL2=%d\n", c1, c2);

	int number = 10;
	PRINT(number);

	STRUCTURE(001);
	STRUCTURE(550);
	STRUCTURE(00050);

	STRUCTURE_001 s1;
	STRUCTURE_550 s2;
	STRUCTURE_00050 s3;

	printf("i : %d\n", i);
	printf("j : %d\n", j);
	printf("z : %d\n", z);
	printf("w : %d\n", w);

	return 0;
} 
