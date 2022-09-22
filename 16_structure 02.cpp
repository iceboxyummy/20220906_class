// 16_structure 02.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // Sleep

#define NUM 2

/*
	구조체 : 사용자가 여러자료형을 묶어 하나로 사용할 수 있는 기능을 제공한다.
	 = 구조체도 배열로 선언 가능
	 = struct 키워드를 사용하여 선언

	  * 선언방법
	 
	 struct 이름
		{
			자료형 변수이름 
			자료형 변수이름
		};

		- 기본적인 선언방식 
		= c에서는(.c)와 같이 선언할 경우 구조체를 만들때마다 struct 키워드를 사용해야함 -> typedef을 이용하여 해결가능
*/

struct Human
{
	char name[256];
	char gender[256];
	int age;
	float tall;
};

// Human h1; <= .c에서는 에러가 난다.
struct Human h2;

/*
	typedef struct 이름
	{
		자료형 변수이름
	}별칭;

	 - typedef는 별칭을 지어주는 키워드
	 = struct를 사용하지 않아도 별칭을 이용하여 선언가능
	 - 구조체의 별칭을 넣으면 이름을 생략해고 된다. => 익명구조체라고 부른다.
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

Monster m1; //.c에서 struct 키워드를 제거하고 선언가능

typedef struct // 구조체 이름을 생략한 익명 구조체
{	
	char name[256];
	int hp;
	int atk;
	int exp;
	int gold;
}Player;

Player p1;

// 구조체 초기화
Player p2 = { "주인공", 500, 100, 0, 0 };

// .C에서만 가능한 구조체 초기화 문법
Player p3 = { .name = "주인공", .gold = 100, .atk = 100 };

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

	printf("%d명의 입력을 받습니다. \n", NUM);

	for (int i = 0; i < NUM; i++)
	{
		printf("이름 입력 => ");
		scanf_s("%s", &humans[i].name, sizeof(humans[i].name));

		printf("성별 입력 => ");
		scanf_s("%s", &humans[i].gender, sizeof(humans[i].gender));

		printf("나이 입력 => ");
		scanf_s("%d", &humans[i].age);

		printf("키 입력 => ");
		scanf_s("%f", &humans[i].tall);
	}
	printf("\n");

	for (int i = 0; i < NUM; i++) 
	{
		printf("%d번째 사람의 이름은 %s, 성별은 %s 나이는 %d, 키는%f\n",
			i + 1, humans[i].name, humans[i].gender, humans[i].age, humans[i].tall);
	}
	printf("\n");
}

void rpg()
{
	Monster monster_table[2] =
	{
		{"심해 우징어", 100, 100, 50},
		{"배고픈 우진", 60, 150, 70}
	};

	Player p;

	printf("\n게임에 오신걸 환영합니다!!\n");

	printf("당신의 이름은? : ");
	scanf_s("%s", &p.name, sizeof(p.name));

	printf("당신의 hp는? : ");
	scanf_s("%d", &p.hp);

	printf("당신의 atk? : ");
	scanf_s("%d", &p.atk);

	p.exp = 0;
	p.gold = 0;

	printf("********** 탐험 시작 ********** \n");

	srand(time(NULL));

	while (1)
	{
		if (p.hp <= 0)
		{
			printf("%s 사망 게임 종료...\n", p.name);
			break;
		}

		printf("한층 내려갑니다(이동)\n");
		Sleep(1500); // 1/1000, 1500 -> 1.5초

		int event_key = rand() % 5;

		switch (event_key)
		{
		case 0: // 골드 획득
			printf("%s가 보물상자 발견! 골드 +100\n", p.name);
			Sleep(1000);
			p.gold += 100;

			printf("현재 보유 골드 : %d\n", p.gold);
			Sleep(1000);

			printf("다음으로 이동합니다.\n");
			Sleep(1000);
			break;

		case 1: // 체력 회복
			printf("%s가 생명의 우물 발견! HP+100\n", p.name);
			Sleep(1000);
			p.hp += 100;

			printf("현재 %s의 체력 : %d\n", p.name, p.hp);
			Sleep(1000);

			printf("다음으로 이동합니다.\n");
			Sleep(1000);
			break;

		case 2: // 체력감소

			break;
		case 3: // 경험치 증가
			break;
		case 4: // 몬스터 등장
		{
			int m_num = rand() % 2;
			Monster m = monster_table[m_num];

			printf("%s 두두둥장! 전투 시작!\n", m.name);
			Sleep(1000);

			while (1)
			{	
				//플레이어의 공격
				printf("%s의 공격!\n", p.name);
				Sleep(1000);
				printf("%d의 데미지!\n", p.atk);
				Sleep(1000);
				printf("%s의 체력 %d -> %d\n", m.name, m.hp, m.hp - p.atk);
				Sleep(1000);
				m.hp -= p.atk;

				if (m.hp <= 0)
				{
					printf("%s 승리! exp + %d\n", p.name, m.exp);
					Sleep(1000);

					p.exp += m.exp;
				}
				//몬스터의 공격
				printf("%s의 공격!\n", m.name);
				Sleep(1000);
				printf("%d의 데미지!\n", m.atk);
				Sleep(1000);
				printf("%s의 체력 %d -> %d\n", p.name, p.hp, p.hp - m.atk);
				Sleep(1000);
				p.hp -= m.atk;

				if (p.hp <= 0)
				{
					printf("%s 패배!\n", p.name);
					Sleep(1000);
					break;
				}
			}
		}

			break;

		default:
			printf("잘못된 키 입력입니다.\n");
			break;
		}
	}
}

/*
	과제 : rpg게임 업그레이드
		1. 구현안한 이벤트 구현
		2. 원래 있던 이벤트 하나 선택해서 업그레이드
		3. 추가적으로 본인이 이벤트 하나 만들기
	+ 던전 입장시 선택지 만들기
*/
