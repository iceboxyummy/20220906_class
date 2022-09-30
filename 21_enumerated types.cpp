 // 21_enumerated types.cpp

/*
	������(Eenumerated types) : ���� ������ �ִ� ������ ����� �̸��� �ο��ϴ� �ڷ���
	 - �ڵ��� ������ ��� �� ���� ������ �����ϴ�.

	����
   enum ��������
   {
	  ���Ҹ� = ��
	  ...
   }

   ������ = �ʱ갪; <= ���ǿ� ���ÿ� ����, ��������

   - ������ ���� ������ ���, ���ǿ� ���ÿ� ��������
   ������ �ش� ������ ���� ���� �Ұ�

   - ���ҿ� ���� ���� ���� ������ ���, �ش� ���� ������ ����
   �������� ���� ���Ҵ� ���� ������ ������ 1 ������ ���� �����Եȴ�.
    
   - ���Ҹ� ���� ������ ���� ������ ����� �����ϰ� ��޵ȴ�.

   - ���Ҹ��� �ҼӰ� ������� �� ��ü�� ���� ��ü���� ����� �����ϴ�.
*/

#include<stdio.h>

void enum_();
void mini_rpg();

int main() {
	enum_();

	return 0;
}

void enum_()
{
    #define RED 0
    #define ORG 1
    #define YEL 2

    int c = 0;

    printf("�� �Է� (0 ~ 2)\n");
    scanf_s("%d", &c);

    if (c == RED)
        printf("red\n");

    if (c == ORG)
        printf("orange\n");

    if (c == YEL)
        printf("yellow\n");
    printf("\n");

    {
        enum color
        {
            Red = 0,
            Orange = 1,
            Yellow = 2,
        };

        int c = 0;
        printf("�� �Է� ( 0 ~ 2 )\n");
        scanf_s("%d", &c);

        if (c == Red) // ������ �������� �� ��ü�� �̸����� ���𰡴�
            printf("Red\n");

        for (c = Red; c <= Yellow; c++)
            printf("%d, ", c);
    }

    { // �������� ���� ��� �պ��� 1ū���� ����.
        enum pet { dog, cat = 10, rabbit, hamster };
    }
}

void mini_rpg()
{
}
