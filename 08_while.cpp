// 08_while.cpp

#include<stdio.h>
#include<conio.h> // 콘솔용 입출력함수 라이브러리, _getch()
#include<stdlib.h> // 난수
#include<time.h> // 시간 관련

int main() {
	/*
		while문 : 조건식이 true일 동안 명령문을 반복한다.
		-무한히 반복하거나 특정 조건이 만족할때까지 반복해야하는 경우 사용한다.

		while(조건식) 
		{
			명령문
		}
		
		1. 조건식을 검사한다.
		2. 참이면 명령문 실행, 거짓이면 while문을 종료한다.
		3. 명령문이 끝나면 다시 1번으로 간다.

		무한루프
		- while문 내부에서 조건식의 결과를 변경하는 명령문이 없을시 발생
		- 무한루프를 의도적으로 일으킨 경우, 반드시 조건식의 결과를 변경하는 명령문을 포함해야한다
	*/

	bool my_heart = true;
	bool the_end_world = false;

	while (the_end_world == false && my_heart == true) // 탈출하지 못하는 무한루프 발생
	{
		printf("I love you\n");

		printf("아직도? [네 : 1 아니오 : 0] : ");
		int answer = -1;
		scanf_s("%d", &answer);

		if (answer == 0)
			my_heart = false;
	
	}
	printf("\n\n");
	while (true)
	{
		char key = '\0';

		printf("이동키 입력 [w : 상 s : 하 a : 좌 d : 우] = > ");
		key = _getch();

		if (key == 'q')
			break; //break로 반복문을 종료시킬 수 있다.

		//scanf_s(" %c". &key, sizeof(char));

		switch (key)
		{
		case 'w': printf("상\n"); break;
		case 's': printf("하\n"); break;
		case 'a': printf("좌\n"); break;
		case 'd': printf("우\n"); break;
		default: printf("잘못 눌렀습니다.\n"); break;
		}
	}
	printf("\n\n");

	/*
		do while
		 - 명령문을 한번 실행 후 조건식을 검사한다.
		 - 무조건 한번은 명령을 실행해야하는 경우에 사용한다.
		 
		 do
		 {
		 명령문
		 } while()
	*/

	const int secret_code = 123123; // 상수변수, 상수 : 수정하지 못하는 변수
	int password = 0;
	int try_count = 0;

	do {

		if (try_count >= 5) {
			printf("5회 실패! 계정이 잠금됩니다.\n");
			break;
		}

		printf("비밀번호 입력(5회 실패시 잠금, 현재 실패횟수 : %d) : ", try_count);
		scanf_s("%d", &password); 

		try_count++;
	} while (secret_code != password);

	srand(time(NULL));
	int key2 = rand() % 100 + 1;
	int answer = 0;

	int low = 1;
	int high = 100;

	printf("****UP&DOWN****\n");
	while(1){

		printf("현재 범위 : %d ~ %d \n", low, high);
		printf("입력 => ");
		scanf_s("%d", &answer);

		if (key2 == answer)
		{
			printf("정답입니다~~\n\n");
			break;
		}
		else if (low < answer && answer < high)
		{
			if (answer < key2)
			{
				printf("UP!\n");
				low = answer + 1;
			}
			else
			{
				printf("DOWN!\n");
				high = answer - 1;
			}
		}
		else
			printf("범위를 벗어난 입력입니다\n");
	}
	return 0;
}