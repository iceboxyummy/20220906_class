// 08_while.cpp

#include<stdio.h>
#include<conio.h> // �ֿܼ� ������Լ� ���̺귯��, _getch()
#include<stdlib.h> // ����
#include<time.h> // �ð� ����

int main() {
	/*
		while�� : ���ǽ��� true�� ���� ��ɹ��� �ݺ��Ѵ�.
		-������ �ݺ��ϰų� Ư�� ������ �����Ҷ����� �ݺ��ؾ��ϴ� ��� ����Ѵ�.

		while(���ǽ�) 
		{
			��ɹ�
		}
		
		1. ���ǽ��� �˻��Ѵ�.
		2. ���̸� ��ɹ� ����, �����̸� while���� �����Ѵ�.
		3. ��ɹ��� ������ �ٽ� 1������ ����.

		���ѷ���
		- while�� ���ο��� ���ǽ��� ����� �����ϴ� ��ɹ��� ������ �߻�
		- ���ѷ����� �ǵ������� ����Ų ���, �ݵ�� ���ǽ��� ����� �����ϴ� ��ɹ��� �����ؾ��Ѵ�
	*/

	bool my_heart = true;
	bool the_end_world = false;

	while (the_end_world == false && my_heart == true) // Ż������ ���ϴ� ���ѷ��� �߻�
	{
		printf("I love you\n");

		printf("������? [�� : 1 �ƴϿ� : 0] : ");
		int answer = -1;
		scanf_s("%d", &answer);

		if (answer == 0)
			my_heart = false;
	
	}
	printf("\n\n");
	while (true)
	{
		char key = '\0';

		printf("�̵�Ű �Է� [w : �� s : �� a : �� d : ��] = > ");
		key = _getch();

		if (key == 'q')
			break; //break�� �ݺ����� �����ų �� �ִ�.

		//scanf_s(" %c". &key, sizeof(char));

		switch (key)
		{
		case 'w': printf("��\n"); break;
		case 's': printf("��\n"); break;
		case 'a': printf("��\n"); break;
		case 'd': printf("��\n"); break;
		default: printf("�߸� �������ϴ�.\n"); break;
		}
	}
	printf("\n\n");

	/*
		do while
		 - ��ɹ��� �ѹ� ���� �� ���ǽ��� �˻��Ѵ�.
		 - ������ �ѹ��� ����� �����ؾ��ϴ� ��쿡 ����Ѵ�.
		 
		 do
		 {
		 ��ɹ�
		 } while()
	*/

	const int secret_code = 123123; // �������, ��� : �������� ���ϴ� ����
	int password = 0;
	int try_count = 0;

	do {

		if (try_count >= 5) {
			printf("5ȸ ����! ������ ��ݵ˴ϴ�.\n");
			break;
		}

		printf("��й�ȣ �Է�(5ȸ ���н� ���, ���� ����Ƚ�� : %d) : ", try_count);
		scanf_s("%d", &password); 

		try_count++;
	} while (secret_code != password);

	srand(time(NULL));
	int key2 = rand() % 100 + 1;
	int answer = 0;

	int low = 1;
	int high = 100;

	printf("****UP&DOWN****\n");
	while(1){

		printf("���� ���� : %d ~ %d \n", low, high);
		printf("�Է� => ");
		scanf_s("%d", &answer);

		if (key2 == answer)
		{
			printf("�����Դϴ�~~\n\n");
			break;
		}
		else if (low < answer && answer < high)
		{
			if (answer < key2)
			{
				printf("UP!\n");
				low = answer + 1;
			}
			else
			{
				printf("DOWN!\n");
				high = answer - 1;
			}
		}
		else
			printf("������ ��� �Է��Դϴ�\n");
	}
	return 0;
}