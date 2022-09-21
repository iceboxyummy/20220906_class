// 15_2d array.cpp

/*
	2차원 배열 : 1차원 배열을 원소로 가지는 배열
	 - 배열을 원소로 가지는 배열을 다차원 배열이라고 하는데 2차원을 넘어서는 형태는 거의 사용하지 않는다.
	 - 1차원 배열과 같이 메모리가 연속적으로 붙어있음

	선언

	 자료형 배열이름 [행][열];
	 type name [row][column];

	 int arr[3][5];

	 ㅁㅁㅁㅁㅁ 3행 5열
	 ㅁㅁㅇㅁㅁ
	 ㅁㅁㅁㅁㅁ

	 - 행 : 가로줄의 갯수
	 - 열 : 세로줄의 갯수
	 - ㅇ의 위치 : 1행 2열 -> arr[1][2]
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
int arr3[2][3] = { 1,2,3 }; // 나머지 원소는 0으로 초기화
int arr4[][3] = { 1,2,3,4 }; // 행은 생략 가능
int arr5[][3] = { {1,2}, {3,4,5}, {6} }; // 
//int arr6[2][] = {1,2,3,4,5,6}; // error : 열은 생략 불가능

void print_arr();
void print_score();

int main() {

	print_arr();

	int arr7[4][3];

	sizeof(arr7); // 배열 전체의 바이트 크기
	sizeof(arr7[0][0]); // 배열이 가지는 바이트 크기
	sizeof(arr7[0]); // 배열의 1행의 바이트 크기
	sizeof(arr7) / sizeof(arr7[0]); // 배열이 가지는 행의 총 갯수
	sizeof(arr7) / sizeof(arr7[0][0]); // 배열이 가지는 원소의 총 갯수
	sizeof(arr7[0]) / sizeof(arr7[0][0]); //하나의 행이 가지는 원소의 개수(열)

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
	학생의 성적을 배열로 담아 계산하고 출력하는 코드
	ROWS : 힉생번호
	COLUMN : 과목점수( 국어, 영어 , 수학
	*/

	// 각 학생의 점수를 저장하는 변수 score
	int score[ROW][COL] =
	{
		{50,50,00},
		{40,20,30},
		{100,100,100},
		{80,90,85},
		{70,60,95}
	};

	int total_kor, total_eng, total_math; // 과목별 총점
	total_kor = total_eng = total_math = 0;
	int student[5] = { 0 };

	for (int i = 0; i < ROW; i++)
	{
		total_kor += score[i][0];
		total_eng += score[i][1];
		total_math += score[i][2];
	}

	printf("\n국어총점\t영어총점\t수학총점\n");
	printf("%d\t\t%d\t\t%d\n\n", total_kor, total_eng, total_math);

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			student[i] += score[i][j];
		}
		printf("%d번째 학생의 총점 : %d\n", i + 1, student[i]);
	}

}

// 과제로 완성하기

	/*
	 4층 3호까지 있는 아파트
      -> 각원소가 가지는 의미는 해당 층,호에 살고있는 인원수

     1. 각 층, 호에 사는 인원수를 입력받음.
     2. 각 층마다 총 인원수 출력
     3. 각 층마다 호의 인원수 출력
     4. 모든 인원수 출력
	*/

