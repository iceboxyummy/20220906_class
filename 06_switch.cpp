// 06_switch.cpp

#include <stdio.h>
#define Intro 1
#define Game 2
#define Option 3
#define Exit 4

int main() {

	/*
		switch�� : ��ȣ���� ���� ���� �ش��ϴ� case�� �̵��� ������ �����Ѵ�.
		-�������� ���� �� �ִ�. �Ǽ��� �Ұ���

		switch(���� or ����) {
		case ��1:
			���1
			break;

		case ��2:
			���2
			break;

		default:
			����ó�����
			break;
		}

		defalut : �������� �ش��ϴ�  case�� ���� ��� ó���ȴ�.

		break : ���� �����ϰ��ִ� statement�� �����Ѵ�.

		statement(~��) : ���α׷��ֿ��� ���డ���� �ּ����� �������� �ڵ� ����, �ڵ��� ������ ����

		*/

	int sel_menu = 0;

	printf("�޴��� �����ϼ���[1.��Ʈ�� 2.���� 3.�ɼ� 4.����]\n");
	printf("selMenu -> ");
	scanf_s("%d", &sel_menu);

	switch (sel_menu) {

	case Intro:
		printf("\n ��Ʈ�� ������ �����Դϴ�.\n");
		break;

	case Game:
		printf("\n ���� ������ �����Դϴ�.\n");
		break;

	case Option:
		printf("\n �ɼ� ������ �����Դϴ�.\n");
		break;

	case Exit:
		printf("\n ���� ������ �����Դϴ�.\n");
		break;

	default:
		printf("\n �߸����Է��Դϴ�.\n");
		break;
	}

	printf("\n");

	int time = 0;
	int count = 0;

	printf("�ð��� �Է����ּ��� : ");
	scanf_s("%d", &time);

	if (time < 12)
	{
		count = 1;
	}
	else if (time > 12)
	{
		count = 2;
	}
	else
	{
		count = 3;
	}


	switch (count)
	{
	case 1:
		printf("\n�����Դϴ�.");
		break;
	case 2:
		printf("\n�����Դϴ�.");
		break;
	case 3:
		printf("\n�����Դϴ�.");
		break;
	default:
		break;
	}

		return 0;
	
}