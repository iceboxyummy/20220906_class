// 24_dynamic allocation.cpp

/*
	���� �Ҵ�(dynamic allocation) : ���α׷� ���൵�߿� �޸� ������ �Ҵ��ϴ°�
	 - ��Ÿ��(���α׷��� ������)�϶� ũ�Ⱑ �����ȴ�.
	 - ����ڰ� ���ϴ� ������ �޸𸮸� �Ҵ��ϰ� ������ �� �ִ�.
	 - �޸𸮸� ���̻� ������� ���� �� �ݳ�(free)���� ������ �޸� ����(memory leak)�� �Ͼ��.
	 - �������� �Ҵ�ȴ�.

	 ����
	 (�ڷ��� *) malloc (�޸��� ������)
	 (�ڷ���* ) calloc (����, �ڷ����� ũ��)
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

		// ��ȯ���� void*�̱� ������ ĳ������ �ʿ�
		ptr = (int*)malloc(sizeof(int) * size);

		if (ptr == NULL)
		{
			printf("�޸� �Ҵ� ����!\n");

			// ���α׷��� �����Ű�� �Լ�, ����� �Բ� ���� ���ڰ��� �ü���� �ѱ��.
			exit(EXIT_FAILURE);
		}

		/*
			�޸� ����(memory leak) : ���α׷��� ���̻� �ʿ����� ���� �޸𸮸� ��� ������ �ִ� ����
			 - �޸𸮸� �����ϰԵǾ� ���α׷��� �Ҿ���������.
			 - �����Ҵ��� �޸𸮸� �����ϱ����� �ش� �޸𸮸� ����Ű�� �����Ͱ� �Ҹ�Ǹ� �޸� ������ �߻��Ѵ�.
			 - ��� �Ŀ��� ������ �������ش�.
			 - �����Ҵ�� ������ �����ڵ带 ���ÿ� �ۼ����ش�.
		*/

		printf("Before free 0x%p\n", ptr);

		free(ptr); // �����Ҵ��� �޸� ������ �����Ѵ�.

		printf("After free 0x%p\n", ptr); // �޸𸮴� ���� �Ǿ����� �ּҴ� �����ִ�. ->dangling pointer


		/*
			*ptr = 10;  ����� �ּҿ� �����Ϸ� �õ��� -> �����߻�

			��� ������ (dangling pointer) : �޸𸮰� ������ �ּҸ� ����Ű�� ������
			 - �޸𸮸� �����ص� �����ʹ� ����� �ּҰ��� ����Ű�� �ֱ� ������ �߻��Ѵ�.
			 - ���ٽ� �����Ұ����� ������ ����ų �� �ִ�.
			 - �޸� ������ NULL�� �ʱ�ȭ ���־�� �Ѵ�.
		*/

		ptr = NULL; // ������ �Ŀ��� NULL�� �ʱ�ȭ ���ش�.

		printf("After free 0x%p\n", ptr);
		if (ptr != NULL)
		{
			free(ptr);
			ptr = NULL;

		}

#define SAFE_FREE(ptr) if(ptr!=NULL){free(ptr); ptr = NULL;}

		SAFE_FREE(ptr);
	}

	// malloc�� calloc�� ����
	{
		int size = 0;

		printf("�ʿ��� int�� ���� : ");
		scanf_s("%d", &size);

		int* ma = (int*)malloc(sizeof(int) * size);
		int* ca = (int*)calloc(size, sizeof(int));

		// malloc : ����� �ʱ�ȭ x => �����Ⱚ
		// calloc : ����� 0���� �ʱ�ȭ 
		printf("\n�ʱ�ȭ ��\n\n");

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

		printf("�����Ҵ��� double�� ������ ���� �Է� : ");
		scanf_s("%d", &size);

		double* ptr = (double*)calloc(size, sizeof(double));

		printf("\nptr�� �Ҵ���� �ּ� : 0x%p\n", ptr);
		for (int i = 0; i < size; i++)
		{
			ptr[i] = i;
			printf("ptr[%d] : %lf\n", i, ptr[i]);
		}

		printf("\n���Ҵ��� double�� ������ ���� �Է� : ");
		scanf_s("%d", &size);

		int* test = NULL;
		int num = 5;
		test = (int*)malloc(sizeof(int) * num);

		ptr = (double*)_recalloc((void*)ptr, size, sizeof(double));

		printf("\nptr�� ���Ҵ���� �ּ� : 0x%p\n", ptr);
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
				printf("%lf, ", ptr[i]); // �迭ó�� ��밡��

			for (int i = 0; i < n; i++)
				*(ptr + i) = (double)i; // ũ�Ⱑ �����־� ������� ����

			for (int i = 0; i < n; i++)
				printf("%lf, ", ptr[i]);
			printf("\n");

			free(ptr);
			ptr = NULL;
		}
	}

	{
		/*
			�޸� ����ȭ
			 = RAM�� �޸� ������ ���� �������� �������� ���� �� �޸��� ������ ��������� �Ҵ��� �Ұ������� ����

			 ����ȭ�� ����
			  - ���� ����ȭ : �޸𸮸� �Ҵ��Ҷ� �޸𸮰� �ʿ��� �纸�� �� ũ�� �Ҵ�Ǿ� �޸� ������ ����Ǵ� ����
			  - �ܺ� ����ȭ : �޸� �Ҵ�� ������ �ݺ��ɶ� �Ҵ�� �޸� ���̸��� �Ҵ����� ���� ���� �޸� ������ ����� ����
		*/
	}
}

void using_dynamic_storage_allocation_like_an_array()
{
	// ���� �ϳ�
	{
		int* ptr = NULL;

		ptr = (int*)malloc(sizeof(int) * 1);
		if (!ptr) exit(1);

		*ptr = 1024 * 3;
		printf("%d\n\n", *ptr);

		free(ptr);
		ptr = NULL;
	}

	// 1���� �迭
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

	// 2���� �迭
	{
		int row = 3, col = 2;

		// vla ��� ���� x
		// int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);

		// �������� �־��ְԵǸ� �����Ҵ��� ���� �ǹ̰� ����ȴ�.
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
		  1���� �迭�� 2���� �迭ó�� ����ϱ�

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

		  find index ===> c(��ǥ ��) + col(������ ũ��) * r(��ǥ ��)
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
		����ڷκ��� ������ ũ���� ������ ���ڿ��� �Է����޾� 
		�ش� ���ڿ� ũ�⸸ŭ�� ������ ����� ������ �����ϰ� 
		�� ������ �����͸� ��ȯ�ϴ� �Լ� scan_name
	*/

	char buffer[100] = { 0 };

	printf("�̸��� �Է��� �ּ��� : ");
	scanf_s("%s", buffer, sizeof(buffer));

	int size = strlen(buffer) + sizeof((char)('\0'));

	if (size == sizeof((char)('\0')))
		return NULL;

	char* name = (char*)calloc(size, sizeof(char));

	if (name != NULL)
		strcpy_s(name, size, buffer);


	return buffer;
}