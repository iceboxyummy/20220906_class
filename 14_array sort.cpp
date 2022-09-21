//14_array sort.cpp

#include <stdio.h>

void print_arr(int arr[], int arr_size);
void bubble_sort(int arr[], int arr_size);
/* 
	�������� : ���������� �� ���Ҹ� ���ϸ� �����ϴ� �˰���

	 *�������� ��������
	 <1ȸ��>
	 [3 5] 4 1 2
	 3 [5 4] 1 2
	 3 4 [5 1] 2
	 3 4 1 [5 2]
	 3 4 1 2 5
	 �ݺ�
*/

void selection_sort(int arr[], int arr_size);
/*
	�������� : ȸ������ �ڸ��� ������ �ְ� �ش� �ڸ��� �� ���Ҹ� ã�� �־��ִ� �˰���
	
	3 5 4 1 2 <- ���� ���� 1�� �ε����� ��ȯ
	1 5 4 3 2
	1 2 4 3 5
	1 2 3 4 5
*/

int main() {
	int arr[5] = { 3,5,4,1,2 };

	print_arr(arr, sizeof(arr[0]));
	//bubble_sort(arr, sizeof(arr[0]));
	selection_sort(arr, sizeof(arr[0]));
	print_arr(arr, sizeof(arr[0]));

	return 0;
}
void print_arr(int arr[], int arr_size) {

}

void bubble_sort(int arr[], int arr_size) {
	int temp = 0;
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selection_sort(int arr[], int arr_size) {
	int minIndex = 0; // ������ �ڸ�(i)�� �� ������ �ε���
	int temp = 0;
	for (int i = 0; i < arr_size; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < arr_size; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;

		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;	
	}
}