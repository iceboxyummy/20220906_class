// 06_switch.cpp

#include <stdio.h>
#define Intro 1
#define Game 2
#define Option 3
#define Exit 4

int main() {

	/*
		switch문 : 괄호안의 변수 값에 해당하는 case로 이동해 동작을 수행한다.
		-정수값만 받을 수 있다. 실수는 불가능

		switch(변수 or 정수) {
		case 값1:
			명령1
			break;

		case 값2:
			명령2
			break;

		default:
			예외처리명령
			break;
		}

		defalut : 변수값에 해당하는  case가 없을 경우 처리된다.

		break : 현재 진행하고있는 statement를 종료한다.

		statement(~문) : 프로그래밍에서 실행가능한 최소한의 독립적인 코드 조각, 코드의 문법적 단위

		*/

	int sel_menu = 0;

	printf("메뉴를 선택하세요[1.인트로 2.게임 3.옵션 4.종료]\n");
	printf("selMenu -> ");
	scanf_s("%d", &sel_menu);

	switch (sel_menu) {

	case Intro:
		printf("\n 인트로 로직이 움직입니다.\n");
		break;

	case Game:
		printf("\n 게임 로직이 움직입니다.\n");
		break;

	case Option:
		printf("\n 옵션 로직이 움직입니다.\n");
		break;

	case Exit:
		printf("\n 종료 로직이 움직입니다.\n");
		break;

	default:
		printf("\n 잘못된입력입니다.\n");
		break;
	}

	printf("\n");

	int time = 0;
	int count = 0;

	printf("시간을 입력해주세요 : ");
	scanf_s("%d", &time);

	if (time < 12)
	{
		count = 1;
	}
	else if (time > 12)
	{
		count = 2;
	}
	else
	{
		count = 3;
	}


	switch (count)
	{
	case 1:
		printf("\n오전입니다.");
		break;
	case 2:
		printf("\n오후입니다.");
		break;
	case 3:
		printf("\n점심입니다.");
		break;
	default:
		break;
	}

		return 0;
	
}