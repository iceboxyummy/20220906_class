// 10_function.cpp

/*
	�Լ� : Ư���۾��� �����ϴ� �ڵ��� ����
	 - ����ڴ� �Լ��� �ڵ带 ���� �Լ��� ȣ���ϴ°͸����ε� �Լ��� ����� ����� �� �ִ�.
	 - �����ϰ� ����ϸ� ���α׷��� ���������ϴµ� �����ϴ�.
*/

/*
	�Լ�������

	1.�ڷ��� 2.�Լ��� (3.�ڷ��� ������, ....)
		{

			(ó��)
		
			4.return ��;
		}
	
	1 : ��ȯ�Ǵ� ���� �ڷ���, ��ȯ���� ������ void�� �Է�, ��ȯ���� �ִٸ� return���� ��ȯ�Ѵ�.
	2 : �Լ��� ȣ���� �� ����ϴ� �̸�
	3 : �Ű�������� �θ���, �Լ����� ����� ���� �޴� �κ�, �Ű����������� ��ȯ���� �޶��� ���ִ�.
	4 : ��ȯ���� ��ȯ�ϰ� �Լ��� �����Ų��.
*/

/*
	�Լ��� ����
	-�Ϲ������� �Լ��� ȣ�⺸�� ���ǰ� �տ� �ۼ��Ǿ��־���Ѵ�.
	�Լ��� ȣ���� ���Ǻ��� �ռ����, �ش��Լ��� ���Ͽ� �Լ��� � ������ ���� �����ִ����� 
	� ������ ���� �ʿ���ϴ��� ����� �ʿ䰡 �ִ�.(function prototype)
*/

#include <stdio.h>

int add(int, int); // ������ Ÿ�Կ����� �����̸� ��������
int sub(int, int);
int mul(int, int);
int div(int, int);
int get_int(); // function prototype
void test();

int main() {

	int x1 = 0;
	int y1 = 0;

	/*
	printf("���ڸ� �Է����ּ��� : ");
	scanf_s("%d", &x1);

	printf("���ڸ� �Է����ּ��� : ");
	scanf_s("%d", &y1);
	*/

	x1 = get_int();
	y1 = get_int();

	int result_1 = add(x1, y1);
	int result_2 = sub(x1, y1);
	int result_3 = mul(x1, y1);
	int result_4 = div(x1, y1);

	printf("%d + %d = %d\n", x1, y1, result_1);
	printf("%d - %d = %d\n", x1, y1, result_2);
	printf("%d * %d = %d\n", x1, y1, result_3);
	printf("%d / %d = %d\n", x1, y1, result_4);

	test();

	return 0;
}

int get_int() {

	int num;

	printf("���ڸ� �Է����ּ��� : ");
	scanf_s("%d", &num);

	return num;
}

// ���� x, y�� ���� ���޹޾� ���� ���� �������� �����ִ� �Լ� add

int add(int x, int y) {
	return x + y;
}

// ���� x, y�� ���� ���޹޾� x���� y�� �� �������� �����ִ� �Լ� sub

int sub(int x, int y) {
	return x - y;
}

// ���� x, y�� ���� ���޹޾� ���� ���� �������� �����ִ� �Լ� mul

int mul(int x, int y) {
	return x * y;
}

// ���� x, y�� ���� ���޹޾� x�� y�� ���� ���� �����ִ� �Լ� sub

int div(int x, int y) {
	return x / y;
}

void test()
{
	printf("1111111111\n");
	printf("2222222222\n");

	return; // ��ȯ���� void
	// �Լ��� return�� ������ �Ǹ� ���� ��ȯ�ϰ� ������
}