// 03_type cast.cpp

/*
 프로그래밍을 하다보면 자료형이 다른 변수끼리 대입을 하거나 연산을 하게된다.
 이, 두 자료형의 형태를 일치시켜야 하는데 이 형변환이 일어난다.

  * 형변환 : 자료형을 다른 자료형으로 변환하는것
   - 서로 다른 자료형의 대입, 연산시 사용한다. 지정하지 않은 경우 암시적으로 변환된다
  
  * 종류 
   - 암시적 형변환 : 따로 지정하지 않은경우 컴파일러에의해 자동으로 변환됨
   - 명시적 형변환 : 사용자가 명시적으로 지정한 자료형으로 바꿔주는것
*/
#include <stdio.h>

int main()
{

	//암시적 형변환 작은자료형 -->> 큰자료형

	short s = 10;
	int i1 = s; // (int)s

	float f1 = 100; // 정수의 기본형은 int형이므로 자동 형변환이 일어난다.
	//float f1 = (float)100

	//큰 자료형에서 작은 자료형으로 들어갈 경우 자이터 손실이 발생할 수있다.

	int i2 = 127;
	char c1 = i2; // char 범위 -128 ~ 127
	printf("%d\n", c1);

	float f2 = 1.25f;
	int i3 = f2; // 실수형 데이터가 정수형 데이터로 변환될 경우 소수점이 버려진다.
	printf("%d\n", i3);

/* 
	연산시에는 큰 자료형으로 바뀌어야 데이터 손실을 줄일 수 있으므로 자료형의 우선순위에 따라 변환된다.
	Ranking of types operations 자료형의 순위
	   - long double > double > float
	   - unsigned long long == long long
	   - unsigned long == long
	   - unsigned int == int
	   - unsigned short int == short int
	   - unsigned char == char
	   - _Bool
*/
	f2 = 10 + 1.25; // f2 = (float)((double)10 + 1.25); 연산시 가장큰 자료형으로 변환된다.
	
	//명시적 형변환

	/*
	int a = 10, b = 4;
	float div = a / b;
	printf("%f\n", div); // 2.0출력
	*/

	int a = 10, b = 4;
	float div = (float)a / b; //명시적 형변환으로 결과값을 float이 되도록 변경
	printf("%f\n", div); // 2.5출력

	int i4 = 10u; // 범위 표현값이 달라서 문제가 생길 수 있다.

	return 0;
}
