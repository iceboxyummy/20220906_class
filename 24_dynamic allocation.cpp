// 24_dynamic allocation.cpp

/*
	동적 할당(dynamic allocation) : 프로그램 실행도중에 메모리 공간을 할당하는것
	 - 런타임(프로그램이 실행중)일때 크기가 결정된다.
	 - 사용자가 원하는 시점에 메모리를 할당하고 해제할 수 있다.
	 - 메모리를 더이상 사용하지 않을 때 반납(free)하지 않으면 메모리 누수(memory leak)가 일어난다.
	 - 힙영역에 할당된다.

	 선언
	 (자료형 *) malloc (메모리의 사이즈)
	 (자료형* ) calloc (개수, 자료형의 크기)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dynamic_allocation();
void using_dynamic_storage_allocation_like_an_array();
char* scan_name();

int main() {

	// dynamic_allocation();
	//using_dynamic_storage_allocation_like_an_array();

	while (true)
	{
		char* name = scan_name();
		if (name != NULL)
			printf("name : %s\n", name);

		if (name != NULL)
		{
			free(name);
			name = NULL;
		}
	}

	return 0;
}

void dynamic_allocation()
{
	{
		int* ptr = NULL;

		int size = 5;

		// 반환값이 void*이기 문에 캐스팅이 필요
		ptr = (int*)malloc(sizeof(int) * size);

		if (ptr == NULL)
		{
			printf("메모리 할당 실패!\n");

			// 프로그램을 종료시키는 함수, 종료와 함께 받은 인자값을 운영체제에 넘긴다.
			exit(EXIT_FAILURE);
		}

		/*
			메모리 누수(memory leak) : 프로그램이 더이상 필요하지 않은 메모리를 계속 가지고 있는 상태
			 - 메모리를 낭비하게되어 프로그램이 불안정해진다.
			 - 동적할당한 메모리를 해제하기전에 해당 메모리를 가리키는 포인터가 소멸되면 메모리 누수가 발생한다.
			 - 사용 후에는 무조건 해제해준다.
			 - 동적할당시 생성과 삭제코드를 동시에 작성해준다.
		*/

		printf("Before free 0x%p\n", ptr);

		free(ptr); // 동적할당한 메모리 공간을 해제한다.

		printf("After free 0x%p\n", ptr); // 메모리는 해제 되었지만 주소는 남아있다. ->dangling pointer


		/*
			*ptr = 10;  사라진 주소에 접근하려 시도함 -> 문제발생

			허상 포인터 (dangling pointer) : 메모리가 해제된 주소를 가리키는 포인터
			 - 메모리를 해제해도 포인터는 사라진 주소값을 가리키고 있기 문에 발생한다.
			 - 접근시 예측불가능한 문제를 일으킬 수 있다.
			 - 메모리 해제후 NULL로 초기화 해주어야 한다.
		*/

		ptr = NULL; // 해제한 후에는 NULL로 초기화 해준다.

		printf("After free 0x%p\n", ptr);
		if (ptr != NULL)
		{
			free(ptr);
			ptr = NULL;

		}

#define SAFE_FREE(ptr) if(ptr!=NULL){free(ptr); ptr = NULL;}

		SAFE_FREE(ptr);
	}

	// malloc과 calloc의 차이
	{
		int size = 0;

		printf("필요한 int의 개수 : ");
		scanf_s("%d", &size);

		int* ma = (int*)malloc(sizeof(int) * size);
		int* ca = (int*)calloc(size, sizeof(int));

		// malloc : 선언시 초기화 x => 쓰레기값
		// calloc : 선언시 0으로 초기화 
		printf("\n초기화 전\n\n");

		for (int i = 0; i < size; i++)
		{
			printf("ma[%d] : %d\n", i, ma[i]);
			printf("ca[%d] : %d\n", i, ca[i]);
		}

		SAFE_FREE(ma);
		SAFE_FREE(ca);
	}

	// realloc
	{
		int size = 0;

		printf("동적할당할 double형 변수의 개수 입력 : ");
		scanf_s("%d", &size);

		double* ptr = (double*)calloc(size, sizeof(double));

		printf("\nptr이 할당받은 주소 : 0x%p\n", ptr);
		for (int i = 0; i < size; i++)
		{
			ptr[i] = i;
			printf("ptr[%d] : %lf\n", i, ptr[i]);
		}

		printf("\n재할당할 double형 변수의 개수 입력 : ");
		scanf_s("%d", &size);

		int* test = NULL;
		int num = 5;
		test = (int*)malloc(sizeof(int) * num);

		ptr = (double*)_recalloc((void*)ptr, size, sizeof(double));

		printf("\nptr이 재할당받은 주소 : 0x%p\n", ptr);
		for (int i = 0; i < size; i++)
		{
			printf("ptr[%d] : %lf\n", i, ptr[i]);
		}
		printf("\n");

		SAFE_FREE(test);
		SAFE_FREE(ptr);
	}

	{
		int n = 5;
		double* ptr = (double*)malloc(n * sizeof(double));

		if (ptr != NULL)
		{
			for (int i = 0; i < n; i++)
				printf("%lf, ", ptr[i]); // 배열처럼 사용가능

			for (int i = 0; i < n; i++)
				*(ptr + i) = (double)i; // 크기가 잡혀있어 산술연산 가능

			for (int i = 0; i < n; i++)
				printf("%lf, ", ptr[i]);
			printf("\n");

			free(ptr);
			ptr = NULL;
		}
	}

	{
		/*
			메모리 단편화
			 = RAM의 메모리 공간이 작은 조각으로 나뉘어져 남은 총 메모리의 공간은 충분하지만 할당이 불가능해진 상테

			 단편화의 종류
			  - 내부 단편화 : 메모리를 할당할때 메모리가 필요한 양보다 더 크게 할당되어 메모리 공간이 낭비되는 현상
			  - 외부 단편화 : 메모리 할당과 해제가 반복될때 할당된 메모리 사이마다 할당하지 못한 작은 메모리 공간이 생기는 현상
		*/
	}
}

void using_dynamic_storage_allocation_like_an_array()
{
	// 변수 하나
	{
		int* ptr = NULL;

		ptr = (int*)malloc(sizeof(int) * 1);
		if (!ptr) exit(1);

		*ptr = 1024 * 3;
		printf("%d\n\n", *ptr);

		free(ptr);
		ptr = NULL;
	}

	// 1차원 배열
	{
		int n = 3;
		int* ptr = (int*)malloc(sizeof(int) * n);
		if (!ptr) exit(1);

		ptr[0] = 123;
		*(ptr + 1) = 456;
		*(ptr + 2) = 789;

		free(ptr);
		ptr = NULL;
	}

	// 2차원 배열
	{
		int row = 3, col = 2;

		// vla 기능 지원 x
		// int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);

		// 고정값을 넣어주게되면 동적할당을 쓰는 의미가 퇴색된다.
		int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);

		if (!ptr2d) exit(1);

		for (int r = 0; r < row; r++)
			for (int c = 0; c < col; c++)
				ptr2d[r][c] = c + col * r;

		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
				printf("%d ", ptr2d[r][c]);
			printf("\n");
		}
		printf("\n");

		free(ptr2d);
		ptr2d = NULL;
	}

	{
		/*
		  **************************************************
		  1차원 배열을 2차원 배열처럼 사용하기

		  row = 3, col = 2;

		  -----------------------------------------------
		  2D(r, c)
		  -----------------------------------------------
		  (0, 0), (0, 1)
		  (1, 0), (1, 1)
		  (2, 0), (2, 1)

		  -----------------------------------------------
		  1D(r, c)
		  -----------------------------------------------
		  (0, 0), (0, 1), (1, 0), (1, 1), (2, 0), (2, 1)
			0       1       2       3        4       5

		  find index ===> c(목표 열) + col(한줄의 크기) * r(목표 행)
		  **************************************************
	   */

		int row = 3, col = 2;

		int* ptr = (int*)malloc(row * col * sizeof(int));
		if (!ptr) exit(1);

		for (int r = 0; r < row; r++)
			for (int c = 0; c < col; c++)
				ptr[c + col * r] = c + col * r;

		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
				printf("%d ", *(ptr + c + col * r));
			printf("\n");
		}

		free(ptr);
		ptr = NULL;
	}
}

char* scan_name()
{
	/*
		사용자로부터 적절한 크기의 공간에 문자열을 입력을받아 
		해당 문자열 크기만큼의 공간을 만들어 내용을 복사하고 
		그 공간의 포인터를 반환하는 함수 scan_name
	*/

	char buffer[100] = { 0 };

	printf("이름을 입력해 주세요 : ");
	scanf_s("%s", buffer, sizeof(buffer));

	int size = strlen(buffer) + sizeof((char)('\0'));

	if (size == sizeof((char)('\0')))
		return NULL;

	char* name = (char*)calloc(size, sizeof(char));

	if (name != NULL)
		strcpy_s(name, size, buffer);


	return buffer; 
}
