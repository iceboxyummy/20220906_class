// 15_2d array.cpp

/*
	2���� �迭 : 1���� �迭�� ���ҷ� ������ �迭
	 - �迭�� ���ҷ� ������ �迭�� ������ �迭�̶�� �ϴµ� 2������ �Ѿ�� ���´� ���� ������� �ʴ´�.
	 - 1���� �迭�� ���� �޸𸮰� ���������� �پ�����

	����

	 �ڷ��� �迭�̸� [��][��];
	 type name [row][column];

	 int arr[3][5];

	 ���������� 3�� 5��
	 ����������
	 ����������

	 - �� : �������� ����
	 - �� : �������� ����
	 - ���� ��ġ : 1�� 2�� -> arr[1][2]
*/

#include <stdio.h>

#define MAP_HIGHT 2
#define MAP_WIDTH 3
#define ROW 5
#define COL 3

 // 1 2 3
 // 4 5 6

int arr1[MAP_HIGHT][MAP_WIDTH] = { 1,2,3,4,5,6 };
int arr2[2][3] = { {1,2,3}, {4,5,6} };
int arr3[2][3] = { 1,2,3 }; // ������ ���Ҵ� 0���� �ʱ�ȭ
int arr4[][3] = { 1,2,3,4 }; // ���� ���� ����
int arr5[][3] = { {1,2}, {3,4,5}, {6} }; // 
//int arr6[2][] = {1,2,3,4,5,6}; // error : ���� ���� �Ұ���

void print_arr();
void print_score();

int main() {

	print_arr();

	int arr7[4][3];

	sizeof(arr7); // �迭 ��ü�� ����Ʈ ũ��
	sizeof(arr7[0][0]); // �迭�� ������ ����Ʈ ũ��
	sizeof(arr7[0]); // �迭�� 1���� ����Ʈ ũ��
	sizeof(arr7) / sizeof(arr7[0]); // �迭�� ������ ���� �� ����
	sizeof(arr7) / sizeof(arr7[0][0]); // �迭�� ������ ������ �� ����
	sizeof(arr7[0]) / sizeof(arr7[0][0]); //�ϳ��� ���� ������ ������ ����(��)

	print_score();

	return 0;
}

void print_arr() {
	// arr1
	printf("*** arr1 ***\n");
	for (int i = 0; i < MAP_HIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// arr2
	printf("*** arr2 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// arr3
	printf("*** arr3 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// arr4
	printf("*** arr4 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr4[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// arr5
	printf("*** arr5 ***\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr5[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

void print_score() {

	/*
	�л��� ������ �迭�� ��� ����ϰ� ����ϴ� �ڵ�
	ROWS : ������ȣ
	COLUMN : ��������( ����, ���� , ����
	*/

	// �� �л��� ������ �����ϴ� ���� score
	int score[ROW][COL] =
	{
		{50,50,00},
		{40,20,30},
		{100,100,100},
		{80,90,85},
		{70,60,95}
	};

	int total_kor, total_eng, total_math; // ���� ����
	total_kor = total_eng = total_math = 0;
	int student[5] = { 0 };

	for (int i = 0; i < ROW; i++)
	{
		total_kor += score[i][0];
		total_eng += score[i][1];
		total_math += score[i][2];
	}

	printf("\n��������\t��������\t��������\n");
	printf("%d\t\t%d\t\t%d\n\n", total_kor, total_eng, total_math);

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			student[i] += score[i][j];
		}
		printf("%d��° �л��� ���� : %d\n", i + 1, student[i]);
	}

}

// ������ �ϼ��ϱ�

	/*
	 4�� 3ȣ���� �ִ� ����Ʈ
      -> �����Ұ� ������ �ǹ̴� �ش� ��,ȣ�� ����ִ� �ο���

     1. �� ��, ȣ�� ��� �ο����� �Է¹���.
     2. �� ������ �� �ο��� ���
     3. �� ������ ȣ�� �ο��� ���
     4. ��� �ο��� ���
	*/

