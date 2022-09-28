// 19_pointer.cpp

/*
	������ : Ư�� ��ü�� �����ϴ� �޸� ������ �����ּҸ� �����ϴ� ����, �ּҸ� ����Ų�ٴ� �ǹ̿����� �������̴�.
	 - �����ʹ� Ư�� ��ü�� ���� �ּҸ��� ����Ű�� ??���� Ư�� ��ü�� �� ũ��� �� �� ����.
	 - ����� ���ÿ� �ʱ�ȭ �ϴ°��� �����Ѵ�. �ʱ�ȭ ���� ���� ���·� ���� �ǵ��������� �޸𸮸� ����ϰų� ������ �� �ֱ� �����̴�.
	 - �������� ũ��� � ü���� ���� �ٸ���
	  => 32bit �ü�� : 4byte
	  => 64bit �ü�� : 8byte
	  => 32bit�� 64bit�� cpu�� �����͸� ó���ϴµ� ����ϴ� �ӽ� ���������� ũ�⸦ �ǹ��Ѵ�.
	  �������ʹ� CPU�� ����� ó���ϴ� �������� �ӽ� ���������.
	  ���� CPU�� �ѹ��� ó���� �� �ִ� �����ͷ��� ���������� ũ�⸦ ���� �� �ۿ� ����.
	  32bit �ü���� 4����Ʈ �ּҸ� ó���ϴµ� �Ѱ��̰�
	  64bit �ü����� 8����Ʈ ũ���� �޸� �ּҸ� ó���ϴ°� �Ѱ���.
*/

#include <stdio.h>
#include <string.h>

void pointer();
void pointer_and_arr();
void pointer_and_const();
void void_pointer();
void pointer_and_structure();
void pointer_and_function();

typedef struct {
	char name[100];
	char grade[100];
	int damage;
}weapon;

typedef struct {
	char name[100];
	int hp;
	weapon* equip_weapon;
}player;

void print_player(const player *  const p);

int main() {
	//pointer();
	pointer_and_arr();
	//pointer_and_const();
	pointer_and_structure();
	pointer_and_function();
	return 0;
}

void pointer()
{
	/*
		����
		�ڷ���* ������

		& ������  (���� ������)  : �������� ���� �ּҰ��� �˾ƿ��� ������
		* ������ (������ ������) : �ּҰ��� ������ ������ �����ϴ� ������

		�ּҴ� 16������ ǥ���� �Ǵµ� 16���� 2�ڸ����� 1����Ʈ�� �ǹ��Ѵ�.
		2���� 4�ڸ�(4bit) == 16���� 1�ڸ�(4bit)
		16���� 2�ڸ�(8bit) == 1byte

		%p : �ּ�(������)�� ����� �� ����ϴ� ���� ������
	*/

	int i = 0;
	int* ip1 = &i;

	printf("i�� �ּ� 0x%p \n", &i);
	printf("ip1�� �� 0x%p \n", ip1);

	printf("i�� ��\t\t %d \n", i);
	printf("ip1�� ������\t %d\n", *ip1);

	// 32bit, 64bit ���̿� ���� ũ�Ⱑ �ٲ��.
	printf("������ ip1�� ũ�� : %d \n\n", sizeof(ip1));
}

void pointer_and_arr()
{
	int arr[5] = { 0,1,2,3,4 }; // �迭�� �̸��� �迭�� �����ּҸ� ����Ų��.
	int* arr_ptr = arr; // arr == &arr[0]

	printf("arr�� �ּ�\t : 0x%p\n", arr);
	printf("arr�� �ּ�\t : 0x%p\n", &arr);
	printf("arr�� �ּ�\t : 0x%p\n", &arr[0]);
	printf("arr_ptr�� ��\t : 0x%p\n\n", arr_ptr);

	printf("arr�� ������ �� \t: %d\n", *arr);
	printf("arr�� 0���� ���� \t: %d\n", arr[0]);
	printf("arr_ptr�� ������ �� \t: %d\n", *arr_ptr);

	/*
		arr[0]==*(arr+0)
		arr[0]==*(arr+0)

		�����ʹ� +, - �������� �ڷ����� ũ�⸸ŭ �ּҸ� �̵��Ѵ�.
		�ڷ����� void�� ���� �Ұ���
		����[�ε���]���� *(����+ �ε���)�� �����ϴ�.
	*/

	for (int i = 0; i < 5; i++)
		printf("arr[%d]�� �ּ� : 0x%p\n", i, &arr[i]);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]�� �ּ� : 0x%p\n", i, &arr_ptr[i]);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]�� �ּ� : 0x%p\n", i, arr + i);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]�� �ּ� : 0x%p\n", i, arr_ptr + i);
	printf("\n");
}

void pointer_and_const()
{
	/*
	const�� ���� �ڷ����� ���ȭ �����ش�. => �ش� �޸� ������ ������ �ȵȴ�.
	���������� const�� �Ǿտ� ���� ��� ���� �ڷ����� ���ȭ��Ų��.
	*/


	// 1
	const double PT1 = 3.14;
	double const PT2 = 3.14;

	//PT1 = 1.24; <- ����� �����Ű�� �ҋ��� ���� �߻�

	
	{ // 2
		int a = 10;
		int b = 10;
		int* a_ptr = &a;
		*a_ptr = 10;
		a_ptr = &b;
	}

	{ // 3
		int a = 10;
		int b = 10;
		const int* a_ptr = &a; // int�� ���ȭ
		//*a_ptr = 10; <= ���� �߻�
		a_ptr = &b;
	}

	{ // 4
		int a = 10;
		int b = 10;
		int* const a_ptr = &a; // *�� ���ȭ
		*a_ptr = 10;
		// a_ptr = &b; <= ���� �߻�
	}

	{ // 5
		int a = 10;
		int b = 10;
		int const * const a_ptr = &a; // int�� *�� ���ȭ
		// *a_ptr = 10; <= ���� �߻�
		// a_ptr = &b; <= ���� �߻�
	}

	{ // 6.c������ ����
		const int a = 10;
		// a = 10; <= �����߻�
		//int* a_ptr = &a;
		//a_ptr�� int�� ����� �ƴ϶� ���� ����-> ���� �߻��� ������ �����.
		//*a_ptr = 15; // .c������ ����	 	
	}
}

void void_pointer()
{
	/*
		void ������
		 - �ڷ����� �������� ���� ������
		 - � �ڷ����� �ּҵ� void �����Ϳ� ���� �����ϴ�.
		 - �ּҸ� ������ �ϱ� ���ؼ��� ����ȯ ���־�� �Ѵ�.
	*/

	int i[3] = { 0 };
	int* int_ptr = i; // ok, �˸��� �ڷ��� ������
	// double* double_ptr = i; // no, cpp������ ���� �ٸ� �ڷ��� �����ͷ� ���� ���Ѵ�.
	void* void_ptr = i; // � �ڷ����� �ּ������� ������ ��� ���� �� �ִ�.

	/* 
		printf("%d", *void_ptr); <= ���� �߻�
		 - ������ �ִ� �ּ��� �ڷ����� �� �� ���� �������� �ȵȴ�. 
		 - �о���ϴ� ũ�⵵ �𸣰� �д� ����� ��
	*/

	// void_ptr�� int*�� ����ȯ �Ͽ� ������
	printf("%d\n", *(int*)void_ptr);

	// void_ptr++; <= ������ ���굵 �Ұ���, ���� �ϴ� ũ�⸣ ��
	(int*)void_ptr + 1;

}

void pointer_and_structure()
{
	struct person
	{
		char name[50];
		int age;
		float height;
	};

	/*
		����ü ��� ���� ���
		- ����ü�����̸�.
		- .(member access operator) : ����ü ����� �����ϴ� ������
	*/

	struct person p = { "ȫ�浿", 30,175.25f };
	p.height = 180.35f;

	printf("p�� height : %f\n", p.height);
	printf("p�� height �ּ� : 0x%p\n\n", &p.height); // . �����ڴ� &���� �켱������ ����.

	{ // ����ü�� ������ ������ ������ �޴´�.
		struct book
		{
			char test;
			char test1;
		};

		book a;
	}
	// book b; <= �����߻�

	{
		struct names
		{
			char given[50];
			char family[50];
		};

		struct friend_info
		{
			struct names full_names;
			char mobile[50];
		};

		struct friend_info my_friend[2] =
		{
			{{"BB", "Cream"}, "1234-1234"}, // friend[0]
			{{"ICE", "Cream"}, "5678-5678"}, // friend[1]
		};

		struct friend_info test;
		struct friend_info* best_friend = NULL;
		// best_friend = test; <= error : ����ü �̸��� ���� �ּҸ� ����Ű�� �ʴ´�.
		best_friend = &my_friend[0];

		/*
			����ü �����ͷ� ����� �����ϴ� ��
			* or -> ���
		*/

		// *����.�����ڰ� �켱������ �����Ƿ�()�� �켱������ �����־����
		// best_friend.full_names; <= error : . �����ڰ� ���� ó����
		(*best_friend).full_names; // ok

		printf("best_friend[0] �̸�\t: %s\n", (*best_friend).full_names.given);

		//����ü ������ ������ ->�� ����ü������. �����ڿͰ���.
		printf("best_friend[0] ��\t: %s\n", best_friend->full_names.family);

		best_friend++; // ����ü ���� �̵�
		printf("best_friend[1] �̸�\t: %s\n", (*best_friend).full_names.given);
		printf("best_friend[1] ��\t: %s\n", best_friend->full_names.family);
	}

	{
		weapon sword = {
			"mastersword",
			"legend",
			500
		};

		weapon bow = {
			"brokenbow",
			"common",
			20
		};

		player p = {
			"player",
			100,
			NULL
		};

		p.equip_weapon = &sword;
		print_player(&p);

		p.equip_weapon = &bow;
		print_player(&p);

	}
}

int Add(int x, int y) { return x + y; }
int Sub(int x, int y) { return x - y; }

typedef struct _character
{
	char name[100];
	char location[100];
	int hp;
	void(*if_dead[5])(struct _character*);
}character;

void print_dead(character* c)
{
	printf("%s ���\n", c->name);
}

void revive(character* c)
{
	printf("%s ��Ȱ\n", c->name);
	c->hp = 200;
}

void set_location_to_town(character* c)
{
	printf("������ �̵��մϴ�.\n");
	strcpy_s(c->location, sizeof(c->location), "Town");
}
void pointer_and_function()
{	
	/*
		�Լ� ������ : Ư�� �ڷ����� ��ȯ�ϰ� Ư�� ���� ����� ������ �Լ��� �����ϴ� ������
		 - �Լ��� �̸��� �Լ��� �ּ�
		 - ���α׷��� �����ϰ� © ���ִ�.

		 ����
		 �ڷ��� (*������)(�ڷ���, ...)

		 ���
		 ������(��, ...)
	 */
	 
	// ����ڷκ��� + �Ǵ� - �� �����ڿ� �� ������ �Է¹޾� ���� ����� ����ϴ� �Լ�
	char op = '\0';
	printf("������ �Է� : ");
	scanf_s(" %c", &op, sizeof(op));

	int x = 0;
	printf("�ǿ����� �Է� : ");
	scanf_s("%d", &x);

	int y = 0;
	printf("�ǿ����� �Է� : ");
	scanf_s("%d", &y);

	int (*compute)(int, int) = NULL;

	switch (op) 
	{
	case '+':compute = Add; break; // �Լ��� �̸��� �Լ��� �ּ�
	case '-':compute = Sub; break; // �Լ��� �̸��� �Լ��� �ּ�
	}

	if(compute != NULL)
		printf("��� : %d\n", compute(x, y));

	// Ư�� �̺�Ʈ���� �����ų �Լ��� �ɾ�� �� �ִ�.

	character c = {
		"Mage",
		"Dungeon",
		100,
		{NULL, NULL,NULL,NULL,NULL}
	};

	c.if_dead[0] = print_dead;
	c.if_dead[1] = revive;
	c.if_dead[2] = set_location_to_town;

	printf("%s�� ��ġ : %s hp : %d\n", c.name, c.location, c.hp);

	while (1)
	{
		int dmg = 0;
		printf("�������� �Է�(���� ü�� %d) : ", c.hp);
		scanf_s("%d", &dmg);
		c.hp -= dmg;
		if (c.hp <= 0)
		{
			for (int i = 0; i < 5; i++)
				if (c.if_dead[i] != NULL) // �̺�Ʈ�� �ִٸ� ȣ�����ش�.
					c.if_dead[i](&c);
			break;
		}
	}

	printf("%s�� ��ġ : %s hp : %d\n", c.name, c.location, c.hp);
}

void print_player(const player * const p)
{
	printf("\n�÷��̾� �̸�\t: %s\n", p->name);
	printf("�÷��̾� hp\t: %d\n", p->hp);
	printf("���� ����\t: %s\n", p->equip_weapon->name);
	printf("���� ������\t: %s\n\n", p->equip_weapon->grade);
}