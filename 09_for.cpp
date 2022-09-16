// 09_for.cpp

#include<stdio.h>
	/*
		for문 : 명령문을 정해진 횟수만큼 실행하고 싶을 때 사용하며 while문보다 가독성이 좋다.
		 - 초기식 조건식 증감식을 포함하고 있으며 사용자의 목적에 따라 생략할 수 있다.
		
		for(초기식 ; 조건식 ; 증감식)
		{
			명령문
		}
		
		실행순서
			1. 초기식 수행 : 반복문 시작전 사용할 값을 초기화 해준다.
			2. 조건식 검사 : 거짓일경우 반복문 종료
			3. 명령문 실행
			4. 증감식 수행 : 증감식 수행후 다시 2로 이동
	*/
int main() {
	/*
	for (int i = 0; i < 5; i++) 
	{	
		printf("for문 명령어 %d번 반복중\n", i + 1);
	}
	*/

	/*
	 for문과 while문의 차이

	 작성 형식의 차이가 있어 주로 사용처가 다를 뿐
	 for문을 while문 처럼 while문을 for문처럼 사용할 수 있다.
    */

	//while문을 for문처럼

	/*
	int i = 0;

	while (1)
	{
		 printf("while문 %번 반복중\n", i + 1); << 명령문
		 i++; << 증감식

		 if (i > 4) << 조건식
			break;
	}
	*/


    // for문을 while문처럼

    /*
	 for (;;)
	  {
		 printf("무한루프\n");
	  }
    */

	/*
	for (char c = 'A'; c <= 'Z'; c++)
	{
		printf("%c ", c);
	}
	printf("\n\n");

	for (char c = 'Z'; c >= 'A'; c--)
		printf("%c ", c);
	*/

	/*
	int total = 0;
	int num = 0;

	printf("0부터 num까지의 덧셈을 구합니다. num은? : ");
	scanf_s("%d", &num);

	for (int i = 0; i <= num; i++)
	{
		total = total + i;
	}
	printf("0부터 %d 까지의 덧셈 = %d\n", num, total);
	*/

	/*
	int total = 0;
	int num = 0;

	printf("1부터 num까지의 홀수의 합을 구합니다. num은? : ");
	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++)
		if (i % 2 == 1)
			total  += i;

	printf("0부터 %d 까지의 홀수의 합 = %d\n", num, total);
	*/

	//중첩 for문

	// *****
	// *****
	// *****
	// *****
	// *****

	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	// *
	// **
	// ***
	// ****
	// *****
	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}