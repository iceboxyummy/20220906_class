//02_data type.cpp

/* 

  변수(varibale) 
   - 데이터를 저장하기위해 할당받은 메모리공간
   - 메모리주소를 직접 다루지 않고도 데이터가 저장되어있는 메모리를 수학의 변수처럼 직관적으로 사용할 수 있게 해준다.

  자료형(data type)
   - 변수의 종류
   - 저장되는 값의 종류와 범위에 따라 다르게 표현

  bit와 byte
    bit : 가장 작은 데어터 단위, 0과 1만을 표현할 수 있는 2진수로 표현
	byte : 8bit == 1byte, 데어커 크기의 단위

  자료형의 종류
  
  부호가 있는 정수형
  음수인 경우 맨 앞 비트가 1 양수의 경우 0
  
  부호없는 정수형
  음수가 없는 대신 양수가 2배로 늘어남
  부호있는 정수형 앞에 unsigned 키워드를 붙이면 됨
  크기는 부호있는 정수형과 같다

  키워드 : 프로그래밍 언어에서 이미 문법적으로 사용하고있어 식별자로 사용할수 없는 단어 
  
*/
char c = 'c'; // 1byte, 주로 문자를 저장할때 사용, 범위(-128 ~ 127)
short s = 1; // 2byte, 정수를 저장한다. 범위(-32768 ~ 32767)
int i = 1; // 4byte, 정수를 저장한다. 범위(-21억 ~ 21억)

unsigned char c2= 'c'; // 1byte, 주로 문자를 저장할때 사용, 범위(0 ~ 255)
unsigned short s2 = 1; // 2byte, 정수를 저장한다. 범위(0 ~ 65535)
unsigned int i2 = 1; // 4byte, 정수를 저장한다. 범위(0 ~ 42억)

/*
 
  2의 보수법 : 음수를 표현할 에는 양수의 비트를 뒤집고 +1을 해주어 표현

   ex) -24표현하기
    0001 1000 => 24양수의 비트표현
    1110 0111 => 비트를 뒤집어준다.
    1110 1000 => 뒤집어진 비트에 +1을 해준다.

*/

#include <stdio.h>

int main(void)
{
	// 변수 선언방법 : datatype name;

	int a; //declaration (선언하다)
	a = 10; //initialize (초기화) : 변수를 선언하고 최초로 값을 저장하는 것

	int b = 10; //선언과 동시에 초기화
	b = 20; //대입, 할당

    // = : 대입연산자, 오른쪽 피연산자를 왼쪽의 피연산자에 대입

/* 
   변수의 이름을 지을  주의점

	 int 1a; 맨 앞에 숫자가 있으면 안됨
     int a1;
	 
	 int hello world; 띄어쓰기 안됨
	 int hello_world;

	 int int;  키워드를 사용하면 안됨
	 int int_;

	 int hp;
	 int hp; 같은 이름의 변수를 선언하면 안됨
*/

  //변수 표기법
	//형가리안 표기법 - 가독성이 떨어져서 잘 쓰지 않는다.
	int i_age;
	int intweight;
 //문자형
	char c1 = 'A';
	char c2 = 65;
	
	printf("character : %c\n", c1);
	printf("character : %c\n", c2);
	printf("character size: %d\n", sizeof(char));
	printf("character size: %d\n\n", sizeof(c1));

	//둘다 같은 문자로 출력이 된다.
	//->char는 값을 숫자로 가지고 있지만 ASCI 코드를 사용해 문자로 출력한다.

	//정수형
	
	int num = 0;
	printf("num : %d \n ", num);
	printf("num + 1 : %d \n ", num+1);
	printf("int size : %d \n ", sizeof(int));
	printf("int size : %d \n\n ", sizeof(num));

	printf("num : %d \n ", num);
	num = 10;
	printf("num : %d \n\n ", num);

	//실수형
	float f = 0.123f; //4byte, 뒤에 f를 붙여줘야함.
	double d = 1.1234; //8byte, 실수의 기본 타입이라 붙이지 않는다.

	/*
	고정 소수점 방식  : 소수점의 위치가 고정되너 표시되는 방식 ex) 0.123
	범위가 한정적이어서 좁은 범위밖에 표현을 못함
	*/

	/*
	부동 소수점 방식 : 소수점의 위치가 바뀐다는 뜻 ex) 0.123e0
	실수 자료형을 저장할 사용하는 방식
	적은 비트로 넓은 범위를 표현할 수 있지만 근사값을 표현하는거라 정확성이 떨어짐

	부동 소수점은 부호, 지수, 가수로 이루어져있음
	 지수 : 소수점의 위치, 비트로 표현할  지수에 127을 더한 후 표현
	 가수 : 유효숫자
	 
	 float : 부호(1bit), 지수(8bit) 가수(32bit)
	 double  : 부호(1bit), 지수(11bit) 가수(52bit)
	 */

	 /*
	표현 방식 0.123을 표현한다고 할때
	고정 소수점 == 0.123

	부동소수점  == 1.23e-1
	- e0, e1, e-1은 10의 제곱을 의미, 해당 값만큽 제곱하여 앞의 값과 곱하면 고정 소수점 방식임
     */

	float f1 = 0.123f; 
	double d1 = 0.123;
	printf("고정 소수점  : %f\n", f1);
	printf("부동 소수점  : %e\n", f1); // 지수를 사용하는 형태로 출력가능
	printf("고정 소수점  : %lf\n", d1);
	printf("float size  : %d\n", sizeof(f1));
	printf("double size  : %d\n", sizeof(d1));

	/*
	논리형 
	ture와 false값만 가지는 자료형
	정수로 true는 1, false는 0을 의미한다.
	*/

	bool isDash = true; //1byte
	printf("캐릭터 대쉬 유무 : %d\n", isDash);
	printf("1 : 대쉬상태 ok 2 : 대쉬상태 x\n");

	return 0;
} 
