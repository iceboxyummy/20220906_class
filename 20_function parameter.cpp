// 20_function parameter

/*
   �Ű�����(parameter)
   - �Լ��� ȣ���� �� �޴� ���� ����ų �� ����ϴ� ����
   - �Լ��� ���Ǻο� ���� ������ �ǹ�
   - ���������� �����Ǳ� ������ �Լ��� ���ۿ� �����ǰ� �Լ��� ����Ǹ� �������.

   ����(argument)
   - �Լ��� ȣ���� �� ���޵Ǵ� ���� ��
   - �Լ��� ȣ���� �� ����� ���� ��.
*/

#include<stdio.h>

/*
   Call by value
   - �Լ� ȣ��� ���� ������ ���� �����Ͽ� �����Ѵ�.
   - ���� �����Ͽ� �������� ������ ������ ������ �ȴ�.
   - ���� �����Ͽ� �ѱ�� ������ �޸� ��뷮�� �þ��.
*/

void swap(int x, int y) // �Ű� ����
{
    int tmep = x;
    x = y;
    y = tmep;

    return;
}

/*
   Call by address
   Call by pointer
   Call by reference
   - �Լ��� ȣ��� ���� ������ ������ �ּҸ� �޾� �����Ѵ�.
   - ������ �����ϱ� ������ ������ ��� ������ ������ �޴´�.
   - �������� �ʰ� ������ �޾� �ӵ��� ������.
*/

void swap_pointer(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int i = 5;
    int j = 10;

    printf("i : %d\n", i);
    printf("j : %d\n\n", j);

    swap(i, j); // ���� : �Լ��� ȣ���� �� ����� ���� ��

    printf("i : %d\n", i);
    printf("j : %d\n\n", j);

   swap_pointer(&i, &j);

    printf("i : %d\n", i);
    printf("j : %d\n\n", j);

    return 0;
}