// 09_for.cpp

#include<stdio.h>
	/*
		for�� : ��ɹ��� ������ Ƚ����ŭ �����ϰ� ���� �� ����ϸ� while������ �������� ����.
		 - �ʱ�� ���ǽ� �������� �����ϰ� ������ ������� ������ ���� ������ �� �ִ�.
		
		for(�ʱ�� ; ���ǽ� ; ������)
		{
			��ɹ�
		}
		
		�������
			1. �ʱ�� ���� : �ݺ��� ������ ����� ���� �ʱ�ȭ ���ش�.
			2. ���ǽ� �˻� : �����ϰ�� �ݺ��� ����
			3. ��ɹ� ����
			4. ������ ���� : ������ ������ �ٽ� 2�� �̵�
	*/
int main() {
	/*
	for (int i = 0; i < 5; i++) 
	{	
		printf("for�� ��ɾ� %d�� �ݺ���\n", i + 1);
	}
	*/

	/*
	 for���� while���� ����

	 �ۼ� ������ ���̰� �־� �ַ� ���ó�� �ٸ� ��
	 for���� while�� ó�� while���� for��ó�� ����� �� �ִ�.
    */

	//while���� for��ó��

	/*
	int i = 0;

	while (1)
	{
		 printf("while�� %�� �ݺ���\n", i + 1); << ��ɹ�
		 i++; << ������

		 if (i > 4) << ���ǽ�
			break;
	}
	*/


    // for���� while��ó��

    /*
	 for (;;)
	  {
		 printf("���ѷ���\n");
	  }
    */

	/*
	for (char c = 'A'; c <= 'Z'; c++)
	{
		printf("%c ", c);
	}
	printf("\n\n");

	for (char c = 'Z'; c >= 'A'; c--)
		printf("%c ", c);
	*/

	/*
	int total = 0;
	int num = 0;

	printf("0���� num������ ������ ���մϴ�. num��? : ");
	scanf_s("%d", &num);

	for (int i = 0; i <= num; i++)
	{
		total = total + i;
	}
	printf("0���� %d ������ ���� = %d\n", num, total);
	*/

	/*
	int total = 0;
	int num = 0;

	printf("1���� num������ Ȧ���� ���� ���մϴ�. num��? : ");
	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++)
		if (i % 2 == 1)
			total  += i;

	printf("0���� %d ������ Ȧ���� �� = %d\n", num, total);
	*/

	//��ø for��

	// *****
	// *****
	// *****
	// *****
	// *****

	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	// *
	// **
	// ***
	// ****
	// *****
	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}