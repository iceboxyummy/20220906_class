 // 21_enumerated types.cpp

/*
	열거형(Eenumerated types) : 서로 관련이 있는 정수형 상수에 이름을 부여하는 자료형
	 - 코드의 가독성 향상 및 유지 보수가 용이하다.

	정의
   enum 열거형명
   {
	  원소명 = 값
	  ...
   }

   변수명 = 초깃값; <= 정의와 동시에 선언, 생략가능

   - 열거형 명을 생략할 경우, 정의와 동시에 생성하지
   않으면 해당 열거형 변수 생성 불가

   - 원소에 대해 값을 직접 지정할 경우, 해당 원소 이후의 값이
   지정되지 않은 원소는 이전 원소의 값에서 1 증가한 값을 가지게된다.
    
   - 원소명에 대해 지정된 값은 정수형 상수와 동일하게 취급된다.

   - 원소명은 소속과 관계없이 그 자체로 지역 전체에서 사용이 가능하다.
*/

#include<stdio.h>

void enum_();
void mini_rpg();

int main() {
	enum_();

	return 0;
}

void enum_()
{
    #define RED 0
    #define ORG 1
    #define YEL 2

    int c = 0;

    printf("값 입력 (0 ~ 2)\n");
    scanf_s("%d", &c);

    if (c == RED)
        printf("red\n");

    if (c == ORG)
        printf("orange\n");

    if (c == YEL)
        printf("yellow\n");
    printf("\n");

    {
        enum color
        {
            Red = 0,
            Orange = 1,
            Yellow = 2,
        };

        int c = 0;
        printf("값 입력 ( 0 ~ 2 )\n");
        scanf_s("%d", &c);

        if (c == Red) // 선언한 지역에서 그 자체의 이름으로 선언가능
            printf("Red\n");

        for (c = Red; c <= Yellow; c++)
            printf("%d, ", c);
    }

    { // 지정하지 않은 경우 앞보다 1큰수가 들어간다.
        enum pet { dog, cat = 10, rabbit, hamster };
    }
}

void mini_rpg()
{
}
