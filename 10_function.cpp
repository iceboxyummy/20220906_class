// 10_function.cpp

/*
	함수 : 특정작업을 수행하는 코드의 집합
	 - 사용자는 함수의 코드를 몰라도 함수를 호출하는것만으로도 함수의 기능을 사용할 수 있다.
	 - 적절하게 사용하면 프로그램을 유지보수하는데 용이하다.
*/

/*
	함수선언방식

	1.자료형 2.함수명 (3.자료향 변수명, ....)
		{

			(처리)
		
			4.return 값;
		}
	
	1 : 반환되는 값의 자료형, 반환값이 없으면 void를 입력, 반환값이 있다면 return으로 반환한다.
	2 : 함수를 호출할 때 사용하는 이름
	3 : 매개변수라고 부른다, 함수에서 사용할 값을 받는 부분, 매개변수에따라 반환값이 달라질 수있다.
	4 : 반환값을 반환하고 함수를 종료시킨다.
*/

/*
	함수의 선언
	-일반적으로 함수의 호출보다 정의가 앞에 작성되어있어야한다.
	함수의 호출이 정의보다 앞설경우, 해당함수에 대하여 함수가 어떤 유형의 값을 돌려주는지와 
	어떤 유형의 값을 필요로하는지 명시할 필요가 있다.(function prototype)
*/

#include <stdio.h>

int add(int, int); // 프로토 타입에서는 변수이름 생략가능
int sub(int, int);
int mul(int, int);
int div(int, int);
int get_int(); // function prototype
void test();

int main() {

	int x1 = 0;
	int y1 = 0;

	/*
	printf("숫자를 입력해주세요 : ");
	scanf_s("%d", &x1);

	printf("숫자를 입력해주세요 : ");
	scanf_s("%d", &y1);
	*/

	x1 = get_int();
	y1 = get_int();

	int result_1 = add(x1, y1);
	int result_2 = sub(x1, y1);
	int result_3 = mul(x1, y1);
	int result_4 = div(x1, y1);

	printf("%d + %d = %d\n", x1, y1, result_1);
	printf("%d - %d = %d\n", x1, y1, result_2);
	printf("%d * %d = %d\n", x1, y1, result_3);
	printf("%d / %d = %d\n", x1, y1, result_4);

	test();

	return 0;
}

int get_int() {

	int num;

	printf("숫자를 입력해주세요 : ");
	scanf_s("%d", &num);

	return num;
}

// 정수 x, y를 재료로 전달받아 둘을 더한 정수값을 돌려주는 함수 add

int add(int x, int y) {
	return x + y;
}

// 정수 x, y를 재료로 전달받아 x에서 y를 뺀 정수값을 돌려주는 함수 sub

int sub(int x, int y) {
	return x - y;
}

// 정수 x, y를 재료로 전달받아 둘을 곱한 정수값을 돌려주는 함수 mul

int mul(int x, int y) {
	return x * y;
}

// 정수 x, y를 재료로 전달받아 x를 y로 나눈 몫을 돌려주는 함수 sub

int div(int x, int y) {
	return x / y;
}

void test()
{
	printf("1111111111\n");
	printf("2222222222\n");

	return; // 반환값이 void
	// 함수는 return을 만나게 되면 값을 반환하고 종료함
}