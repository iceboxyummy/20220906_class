// 05_if.cpp

#include <stdio.h>

int main() {
/*
	if��
	=���ǽ��� ��, ������ ���� �ٸ� ����̳� ��Ȳ�� �����ϰ� ���ش�
	-else Ű����� ����ó���� �� �� �ִ�.

	if(���ǽ�)
		���
	=> ���ǽ� Ȥ�� ���� ���̸� ����� �����ϰ� �ƴѰ�� �����Ѵ�.
*/

	int number = 0;

	printf("������ �Է��� �ּ��� : ");
	scanf_s("%d", &number);
	
	/*
	if (number % 2 == 0)
		printf("¦���Դϴ�.\n");

	if(number % 2 != 0)
		printf("Ȧ���Դϴ�.\n");
	*/

	/*
		if(���ǽ�)
			���1
		else
			���2
		=> ���ǽ��� ������ ��� else ���2 ����
	*/

	if (number % 2 == 0)
		printf("¦���Դϴ�.\n");

	else
		printf("Ȧ���Դϴ�.\n");

	// if = else �� ������ ��밡��

	char key;

	printf("���� �����Ͽ� ? : ");
	scanf_s(" %c", &key, sizeof(key));

	if (key == 'w')
		printf("���� ���ڼ�\n");
	else if (key == 's')
		printf("�Ʒ��� ���ڼ�\n");
	else if (key == 'a')
		printf("�������� ���ڼ�\n");
	else if (key == 'd')
		printf("���������� ���ڼ�\n");
	else
		printf("�߸��� Ű�� �Է��Ͽ����ϴ�.\n");

	/*
	��ø if�� : if�� �ȿ� if�� ��밡��
	*/

	int number2 = 0;

	printf("���ڸ� �Է��� �ּ��� : ");
	scanf_s(" %d", &number);
	
	if (number2 < 10)
	{
		printf("10�̸��Դϴ�.\n");

		if (number2 < 5)
			printf("5�̸��Դϴ�.\n");
		else
			printf("5�̻��Դϴ�.\n");
	}

	else
		printf("10�̻��Դϴ�.\n");

	return 0;

}