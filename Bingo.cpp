// Bingo.cpp

/*
	빙고판
	빙고판 크기
	승리조건(빙고횟수)

	* 빙고판세팅
	 - 1 ~ 25 순서대로 값을 2차원 배얼에 넣어준다.
	 - 임의의 인덱스 값을 2개 받아서 서로 스왑해준다.

	* 빙고 번호 입력
	 - 번호를 입력 받는다.
	 - 빙고판에서 받은 번호를 찾아 체크해준다.

	* 빙고 갯수 체크
	* 승리 조건 체크
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>

#define BINGO_SIZE 5
#define COMPLETE 5
#define CHECK_NUMBER 0

int sel_number = 0; // 선택한 숫자
int bingo_count = 0; // 빙고 갯수
int prev_bingo_count = 0; // 이전 빙고 횟수

void swap(int board[BINGO_SIZE][BINGO_SIZE]); // 빙고판 숫자섞기
void print_board(int board[BINGO_SIZE][BINGO_SIZE]); // 빙고판 출력
int get_num(); // 숫자선택
void check_num(int board[BINGO_SIZE][BINGO_SIZE]); // 선택한 숫자 확인
int check_bingo(int board[BINGO_SIZE][BINGO_SIZE]); // 빙고 갯수 확인
int check_win(int bingo_count, int prev_bingo_count); // 승리조건 체크

int main() {
	// 게임세팅
	int board[BINGO_SIZE][BINGO_SIZE] = {}; // 빙고 보드판

	swap(board);

	// 게임 진행
		while (bingo_count<COMPLETE)
		{
			print_board(board); 
			do {
				get_num();
			} while (sel_number < 1 or sel_number >pow(BINGO_SIZE, 2));
			system("cls");
			check_num(board);
			check_bingo(board);
			check_win(bingo_count, prev_bingo_count);
		} 
		printf("승리!\n");

	return 0;
}

void print_board(int  board[BINGO_SIZE][BINGO_SIZE])
{
	for (int y = 0; y < BINGO_SIZE; y++)
	{
		for (int x = 0; x < BINGO_SIZE; x++)
		{
			if (board[y][x] == CHECK_NUMBER)
				printf("%c\t", 35);
			else
				printf("%d\t", board[y][x]);
		}
		printf("\n");
	}
}

void swap(int board[BINGO_SIZE][BINGO_SIZE])
{
	srand(time(NULL));
	int num = 0;

	for (int y = 0; y < BINGO_SIZE; y++)
		for (int x = 0; x < BINGO_SIZE; x++)
			board[y][x] = ++num;

	for (int i = 0; i < 100; i++)
	{
		int a = rand() % BINGO_SIZE;
		int b = rand() % BINGO_SIZE;
		int c = rand() % BINGO_SIZE;
		int d = rand() % BINGO_SIZE;

		int temp = board[a][b];
		board[a][b] = board[c][d];
		board[c][d] = temp;
	}
}

int get_num() {
	printf("입력 : ");
	scanf_s("%d", &sel_number);

	return sel_number;
}

void check_num(int board[BINGO_SIZE][BINGO_SIZE])
{
	for (int y = 0; y < BINGO_SIZE; y++)
	{
		for (int x = 0; x < BINGO_SIZE; x++)
		{
			if (board[y][x] == sel_number)
				board[y][x] = CHECK_NUMBER;
		}
	}
}

int check_bingo(int board[BINGO_SIZE][BINGO_SIZE])
{
	bingo_count = 0;

	for (int y = 0; y < BINGO_SIZE; y++) // 가로줄 체크
	{
		bool check = true;
		for (int x = 1; x < BINGO_SIZE; x++)
			check = check && board[y][0] == board[y][x];

		if (check == true) bingo_count++;
	}

	for (int x = 0; x < BINGO_SIZE; x++) // 세로줄 체크
	{
		bool check = true;
		for (int y = 0; y < BINGO_SIZE; y++)
			check = check && board[0][x] == board[y][x];

		if (check == true) bingo_count++;
	}

	{	// \ 대각선 체크
		bool check = true;
		for (int index = 1; index < BINGO_SIZE; index++)
			check = check && board[0][0] == board[index][index];

		if (check == true) bingo_count++;
	}

	{	// / 대각선 체크
		bool check = true;
		int y = BINGO_SIZE - 1;
		int x = 0;

		for (int index = 0; index < BINGO_SIZE; index++)
			check = check && board[y--][x++] == CHECK_NUMBER;

		if (check == true) bingo_count++;
	}
	return bingo_count;
}

int check_win(int bingo_count, int prev_bingo_count) {
	if (prev_bingo_count < bingo_count)
	{
		printf("%d줄 빙고!\n", bingo_count);
		prev_bingo_count = bingo_count;
	}
	return prev_bingo_count;
}
