 // Bingo.cpp

/*
	������
	������ ũ��
	�¸�����(����Ƚ��)

	* �����Ǽ���
	 - 1 ~ 25 ������� ���� 2���� ��� �־��ش�.
	 - ������ �ε��� ���� 2�� �޾Ƽ� ���� �������ش�.

	* ���� ��ȣ �Է�
	 - ��ȣ�� �Է� �޴´�.
	 - �����ǿ��� ���� ��ȣ�� ã�� üũ���ش�.

	* ���� ���� üũ
	* �¸� ���� üũ
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>

#define BINGO_SIZE 5
#define COMPLETE 5
#define CHECK_NUMBER 0

void print_board(int board[BINGO_SIZE][BINGO_SIZE]);

int main() {
	// ���Ӽ���
	int board[BINGO_SIZE][BINGO_SIZE] = {}; // ���� ������
	int sel_number = 0; // ������ ��ȣ
	int bingo_count = 0; // ���� ����
	int prev_bingo_count = 0; // ���� ���� Ƚ��

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

	print_board(board);

	while(1)
		while (true)
		{
			bingo_count = 0;

			// �����Է�
			do {
				printf("�Է� : ");
				scanf_s("%d", &sel_number);
			} while (sel_number < 1 or sel_number >pow(BINGO_SIZE, 2));

			system("cls");

			// �Է� ���� ���� �����ǿ��� üũ
			for (int y = 0; y < BINGO_SIZE; y++)
			{
				for (int x = 0; x < BINGO_SIZE; x++)
				{
					if (board[y][x] == sel_number)
						board[y][x] = CHECK_NUMBER;
				}
			}
			print_board(board);

			// ���� ���� üũ

			for (int y = 0; y < BINGO_SIZE; y++) // ������ üũ
			{
				bool check = true;
				for (int x = 1; x < BINGO_SIZE; x++)
					check = check && board[y][0] == board[y][x];
				
				if (check == true) bingo_count++;
			}

			for (int x = 0; x < BINGO_SIZE; x++) // ������ üũ
			{
				bool check = true;
				for (int y = 1; y < BINGO_SIZE; y++)
					check = check && board[0][x] == board[y][x];

				if (check == true) bingo_count++;
			}

			{	// \ �밢�� üũ
				bool check = true;

				for (int index = 1; index < BINGO_SIZE;index++)
					check = check && board[0][0] == board[index][index];

				if (check == true) bingo_count++;
			}

			{	// / �밢�� üũ
				bool check = true;
				int y = BINGO_SIZE - 1;
				int x = 0;

				for (int index = 0; index < BINGO_SIZE; index++)
					check = check && board[y--][x++]== CHECK_NUMBER ;

				if (check == true) bingo_count++;
			}
			// �¸�����üũ
			if (prev_bingo_count < bingo_count)
			{
				printf("%d�� ����!\n", bingo_count);
				prev_bingo_count = bingo_count;

				if (bingo_count >= COMPLETE)
				{
					printf("�¸�!\n");
					break;
				}
			}
		} // while(1) ����
	return 0;
}

void print_board(int  board[BINGO_SIZE][BINGO_SIZE])
{
	for (int y = 0; y < BINGO_SIZE; y++)
	{
		for (int x = 0; x < BINGO_SIZE; x++)
		{
			if (board[y][x] == CHECK_NUMBER)
				printf("%c\t",35);
			else
				printf("%d\t", board[y][x]);
		}
		printf("\n");
	}
}
