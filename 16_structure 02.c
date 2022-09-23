// 16_structure 02.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // Sleep

#define NUM 2

/*
	����ü : ����ڰ� �����ڷ����� ���� �ϳ��� ����� �� �ִ� ����� �����Ѵ�.
	 = ����ü�� �迭�� ���� ����
	 = struct Ű���带 ����Ͽ� ����

	  * ������
	 
	 struct �̸�
		{
			�ڷ��� �����̸� 
			�ڷ��� �����̸�
		};

		- �⺻���� ������ 
		= c������(.c)�� ���� ������ ��� ����ü�� ���鶧���� struct Ű���带 ����ؾ��� -> typedef�� �̿��Ͽ� �ذᰡ��
*/

struct Human
{
	char name[256];
	char gender[256];
	int age;
	float tall;
};

// Human h1; <= .c������ ������ ����.
struct Human h2;

/*
	typedef struct �̸�
	{
		�ڷ��� �����̸�
	}��Ī;

	 - typedef�� ��Ī�� �����ִ� Ű����
	 = struct�� ������� �ʾƵ� ��Ī�� �̿��Ͽ� ���𰡴�
	 - ����ü�� ��Ī�� ������ �̸��� �����ذ� �ȴ�. => �͸���ü��� �θ���.
*/

typedef int HP;
HP mt_hp;

typedef struct _Monster
{
	char name[256];
	int hp;
	int atk;
	int exp;
}Monster;

Monster m1; //.c���� struct Ű���带 �����ϰ� ���𰡴�

typedef struct // ����ü �̸��� ������ �͸� ����ü
{	
	char name[256];
	int hp;
	int atk;
	int exp;
	int gold;
}Player;

Player p1;

// ����ü �ʱ�ȭ
Player p2 = { "���ΰ�", 500, 100, 0, 0 };

// .C������ ������ ����ü �ʱ�ȭ ����
Player p3 = { .name = "���ΰ�", .gold = 100, .atk = 100 };

void input_human();
void rpg();


int main() {
	// input_human();
	rpg();

	return 0;
}

void input_human()
{
	/*
	struct Human
	{
		char name[256];
		char gender[256];
		int age;
		float tall;
	};
	*/

	struct Human humans[NUM];

	printf("%d���� �Է��� �޽��ϴ�. \n", NUM);

	for (int i = 0; i < NUM; i++)
	{
		printf("�̸� �Է� => ");
		scanf_s("%s", &humans[i].name, sizeof(humans[i].name));

		printf("���� �Է� => ");
		scanf_s("%s", &humans[i].gender, sizeof(humans[i].gender));

		printf("���� �Է� => ");
		scanf_s("%d", &humans[i].age);

		printf("Ű �Է� => ");
		scanf_s("%f", &humans[i].tall);
	}
	printf("\n");

	for (int i = 0; i < NUM; i++) 
	{
		printf("%d��° ����� �̸��� %s, ������ %s ���̴� %d, Ű��%f\n",
			i + 1, humans[i].name, humans[i].gender, humans[i].age, humans[i].tall);
	}
	printf("\n");
}

void rpg()
{
	Monster monster_table[2] =
	{
		{"���� ��¡��", 100, 100, 50},
		{"����� ����", 60, 150, 70}
	};

	Player p;

	printf("\n���ӿ� ���Ű� ȯ���մϴ�!!\n");

	printf("����� �̸���? : ");
	scanf_s("%s", &p.name, sizeof(p.name));

	printf("����� hp��? : ");
	scanf_s("%d", &p.hp);

	printf("����� atk? : ");
	scanf_s("%d", &p.atk);

	p.exp = 0;
	p.gold = 0;

	printf("********** Ž�� ���� ********** \n");

	srand(time(NULL));

	while (1)
	{
		if (p.hp <= 0)
		{
			printf("%s ��� ���� ����...\n", p.name);
			break;
		}

		printf("���� �������ϴ�(�̵�)\n");
		Sleep(1500); // 1/1000, 1500 -> 1.5��

		int event_key = rand() % 6;

		switch (event_key)
		{
		case 0: // ��� ȹ��
			printf("%s�� �������� �߰�! ��� +100\n", p.name);
			Sleep(1000);

			int rank = rand() % 3;

			switch (rank)
			{
			case 0:
				printf("ö���ڸ� �߰�! gold +50\n");
				p.gold += 50;
				Sleep(1000);
				break;

			case 1:
				printf("�����ڸ� �߰�! gold +100\n");
				p.gold += 100;
				Sleep(1000);
				break;

			case 2:
				printf("�ݻ��ڸ� �߰�! gold +200\n");
				p.gold += 200;
				Sleep(1000);
				break;
			}

			printf("���� ���� ��� : %d\n", p.gold);
			Sleep(1000);

			printf("�������� �̵��մϴ�.\n");
			Sleep(1000);
			break;

		case 1: // ü�� ȸ��
			printf("%s�� ������ �칰 �߰�! HP+100\n", p.name);
			Sleep(1000);
			p.hp += 100;

			printf("���� %s�� ü�� : %d\n", p.name, p.hp);
			Sleep(1000);

			printf("�������� �̵��մϴ�.\n");
			Sleep(1000);
			break;

		case 2: // ü�°���
			printf("%s�� ������ �������ϴ�. HP-100\n", p.name);
			Sleep(1000);
			p.hp -= 100;

			printf("���� %s�� ü�� : %d\n", p.name, p.hp);
			Sleep(1000);

			printf("�������� �̵��մϴ�.\n");
			Sleep(1000);
			break;

			break;
		case 3: // ����ġ ����
			printf("%s�� ����ġ ���� �߰�! EXP+100\n", p.name);
			Sleep(1000);
			p.hp += 100;

			printf("���� %s�� ����ġ : %d\n", p.name, p.exp);
			Sleep(1000);

			printf("�������� �̵��մϴ�.\n");
			Sleep(1000);
			break;


			break;
		case 4: // ���� ����
		{
			int m_num = rand() % 2;
			Monster m = monster_table[m_num];

			printf("%s �εε���! ���� ����!\n", m.name);
			Sleep(1000);

			while (1)
			{	
				//�÷��̾��� ����
				printf("%s�� ����!\n", p.name);
				Sleep(1000);
				printf("%d�� ������!\n", p.atk);
				Sleep(1000);
				printf("%s�� ü�� %d -> %d\n", m.name, m.hp, m.hp - p.atk);
				Sleep(1000);
				m.hp -= p.atk;

				if (m.hp <= 0)
				{
					printf("%s �¸�! exp + %d\n", p.name, m.exp);
					Sleep(1000);

					p.exp += m.exp;
				}
				//������ ����
				printf("%s�� ����!\n", m.name);
				Sleep(1000);
				printf("%d�� ������!\n", m.atk);
				Sleep(1000);
				printf("%s�� ü�� %d -> %d\n", p.name, p.hp, p.hp - m.atk);
				Sleep(1000);
				p.hp -= m.atk;

				if (p.hp <= 0)
				{
					printf("%s �й�!\n", p.name);
					Sleep(1000);
					break;
				}
			}
		}

		case 5:
			printf("������ �߰��Ͽ����ϴ�!\n");
			printf("���⸦ �����Ͻðڽ��ϱ�? ���� :200gold\n");
			printf("��(0), �ƴϿ�(1)");
			int sel;
			scanf_s("%d", &sel);

			if (sel == 0)
			{
				if (p.gold >= 200)
				{
					printf("%s�� ���⸦ ���� atk : %d -> %d\n", p.name, p.atk, p.atk + 30);
					Sleep(1000);
					p.atk += 30;
					printf("���� ���  : %d- > %d\n", p.gold, p.gold - 200);
					Sleep(1000);
					p.gold -= 200;
					printf("�������� �̵��մϴ�.\n");
					Sleep(1000);
				}
				else
				{
					printf("���� �����մϴ�.\n");
					Sleep(1000);
					printf("�׳� �������ϴ�,,,\n");
					Sleep(1000);
				}
			}
			else 
			{
				printf("�׳� �������ϴ�,,,\n");
				Sleep(1000);
			}

			break;

		default:
			printf("�߸��� Ű �Է��Դϴ�.\n");
			break;
		}
	}
}

/*
	���� : rpg���� ���׷��̵�
		1. �������� �̺�Ʈ ����
		2. ���� �ִ� �̺�Ʈ �ϳ� �����ؼ� ���׷��̵�
		3. �߰������� ������ �̺�Ʈ �ϳ� �����
	+ ���� ����� ������ �����
*/