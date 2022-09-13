// 05_if.cpp

#include <stdio.h>

int main() {
/*
	if문
	=조건식의 참, 거짓에 따라 다른 계산이나 상황을 수행하게 해준다
	-else 키워드로 예외처리를 할 수 있다.

	if(조건식)
		명령
	=> 조건식 혹은 값이 참이면 명령을 수행하고 아닌경우 무시한다.
*/

	int number = 0;

	printf("정수를 입력해 주세요 : ");
	scanf_s("%d", &number);
	
	/*
	if (number % 2 == 0)
		printf("짝수입니다.\n");

	if(number % 2 != 0)
		printf("홀수입니다.\n");
	*/

	/*
		if(조건식)
			명령1
		else
			명령2
		=> 조건식이 거짓은 경우 else 명령2 실행
	*/

	if (number % 2 == 0)
		printf("짝수입니다.\n");

	else
		printf("홀수입니다.\n");

	// if = else 를 여러개 사용가능

	char key;

	printf("어디로 가야하오 ? : ");
	scanf_s(" %c", &key, sizeof(key));

	if (key == 'w')
		printf("위로 가겠소\n");
	else if (key == 's')
		printf("아래로 가겠소\n");
	else if (key == 'a')
		printf("왼쪽으로 가겠소\n");
	else if (key == 'd')
		printf("오른쪽으로 가겠소\n");
	else
		printf("잘못된 키를 입력하였습니다.\n");

	/*
	중첩 if문 : if문 안에 if믄 사용가능
	*/

	int number2 = 0;

	printf("숫자를 입력해 주세요 : ");
	scanf_s(" %d", &number);
	
	if (number2 < 10)
	{
		printf("10미만입니다.\n");

		if (number2 < 5)
			printf("5미만입니다.\n");
		else
			printf("5이상입니다.\n");
	}

	else
		printf("10이상입니다.\n");

	return 0;

}