// 19_pointer.cpp

/*
	포인터 : 특정 개체가 차지하는 메모리 공간의 시작주소를 저장하는 변수, 주소를 가리킨다는 의미에서의 포인터이다.
	 - 포인터는 특정 개체의 시작 주소만을 가리키기 ??문에 특정 개체의 총 크기는 알 수 없다.
	 - 선언과 동시에 초기화 하는것을 권장한다. 초기화 되지 않은 상태로 사용시 의도하지않은 메모리를 사용하거나 변경할 수 있기 때문이다.
	 - 포인터의 크기는 운영 체제에 따라 다르다
	  => 32bit 운영체제 : 4byte
	  => 64bit 운영체제 : 8byte
	  => 32bit와 64bit는 cpu가 데이터를 처리하는데 사용하는 임시 레지스터의 크기를 의미한다.
	  레지스터는 CPU가 명령을 처리하는 데이터의 임시 저장공간임.
	  따라서 CPU가 한번에 처리할 수 있는 데이터량은 레지스터의 크기를 따라갈 수 밖에 없음.
	  32bit 운영체제면 4바이트 주소를 처리하는데 한계이고
	  64bit 운영체제라면 8바이트 크기의 메모리 주소를 처리하는게 한계임.
*/

#include <stdio.h>
#include <string.h>

void pointer();
void pointer_and_arr();
void pointer_and_const();
void void_pointer();
void pointer_and_structure();
void pointer_and_function();
void double_pointer();
void pointer_arr();
void pointer_arr_and_2d_arr();

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
	//pointer_and_arr();
	//pointer_and_const();
	//pointer_and_structure();
	//pointer_and_function();
	//double_pointer();
	//pointer_arr();
	pointer_arr_and_2d_arr();

	return 0;
}

void pointer()
{
	/*
		선언
		자료형* 변수명

		& 연산자  (참조 연산자)  : 데이터의 공간 주소값을 알아오는 연산자
		* 연산자 (역참조 연산자) : 주소값의 데이터 공간에 접근하는 연산자

		주소는 16진수로 표현이 되는데 16진수 2자리마다 1바이트를 의미한다.
		2진수 4자리(4bit) == 16진수 1자리(4bit)
		16진수 2자리(8bit) == 1byte

		%p : 주소(포인터)를 출력할 때 사용하는 형식 지정자
	*/

	int i = 0;
	int* ip1 = &i;

	printf("i의 주소 0x%p \n", &i);
	printf("ip1의 값 0x%p \n", ip1);

	printf("i의 값\t\t %d \n", i);
	printf("ip1의 역참조\t %d\n", *ip1);

	// 32bit, 64bit 차이에 따라 크기가 바뀐다.
	printf("포인터 ip1의 크기 : %d \n\n", sizeof(ip1));
}

void pointer_and_arr()
{
	int arr[5] = { 0,1,2,3,4 }; // 배열의 이름은 배열의 시작주소를 가리킨다.
	int* arr_ptr = arr; // arr == &arr[0]

	printf("arr의 주소\t : 0x%p\n", arr);
	printf("arr의 주소\t : 0x%p\n", &arr);
	printf("arr의 주소\t : 0x%p\n", &arr[0]);
	printf("arr_ptr의 값\t : 0x%p\n\n", arr_ptr);

	printf("arr의 역참조 값 \t: %d\n", *arr);
	printf("arr의 0번지 원소 \t: %d\n", arr[0]);
	printf("arr_ptr의 역참조 값 \t: %d\n", *arr_ptr);

	/*
		arr[0]==*(arr+0)
		arr[0]==*(arr+1)

		포인터는 +, - 연산으로 자료형으 크기만큼 주소를 이동한다.
		자료형이 void인 경우는 불가능
		변수[인덱스]값은 *(변수+ 인덱스)과 동일하다.
	*/

	for (int i = 0; i < 5; i++)
		printf("arr[%d]의 주소 : 0x%p\n", i, &arr[i]);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]의 주소 : 0x%p\n", i, &arr_ptr[i]);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]의 주소 : 0x%p\n", i, arr + i);
	printf("\n");

	for (int i = 0; i < 5; i++)
		printf("arr[%d]의 주소 : 0x%p\n", i, arr_ptr + i);
	printf("\n");
}

void pointer_and_const()
{
	/*
	const는 앞의 자료형을 상수화 시켜준다. => 해당 메모리 공간이 수정이 안된다.
	예외적으로 const가 맨앞에 있을 경우 뒤의 자료형을 상수화시킨다.
	*/


	// 1
	const double PI1 = 3.14;
	double const PI2 = 3.14;

	//PT1 = 1.24; <- 상수를 변경시키려 할는 에러 발생

	
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
		const int* a_ptr = &a; // int를 상수화
		//*a_ptr = 10; <= 에러 발생
		a_ptr = &b;
	}

	{ // 4
		int a = 10;
		int b = 10;
		int* const a_ptr = &a; // *을 상수화
		*a_ptr = 10;
		// a_ptr = &b; <= 에러 발생
	}

	{ // 5
		int a = 10;
		int b = 10;
		int const * const a_ptr = &a; // int와 *을 상수화
		// *a_ptr = 10; <= 에러 발생
		// a_ptr = &b; <= 에러 발생
	}

	{ // 6.c에서만 가능
		const int a = 10;
		// a = 10; <= 에러발생
		//int* a_ptr = &a;
		//a_ptr의 int가 상수가 아니라 수정 가능-> 문제 발생의 여지가 생긴다.
		//*a_ptr = 15; // .c에서는 가능	 	
	}
}

void void_pointer()
{
	/*
		void 포인터
		 - 자료형이 정해지지 않은 포인터
		 - 어떤 자료형의 주소든 void 포인터에 저장 가능하다.
		 - 주소를 역참조 하기 위해서는 형변환 해주어야 한다.
	*/

	int i[3] = { 0 };
	int* int_ptr = i; // ok, 알맞은 자료형 포인터
	// double* double_ptr = i; // no, cpp에서는 서로 다른 자료형 포인터로 담지 못한다.
	void* void_ptr = i; // 어떤 자료형의 주소인지는 모르지만 모두 받을 수 있다.

	/* 
		printf("%d", *void_ptr); <= 에러 발생
		 - 가지고 있는 주소의 자료형을 알 수 없어 역참조가 안된다. 
		 - 읽어야하는 크기도 모르고 읽는 방법도 모름
	*/

	// void_ptr를 int*로 형변환 하여 역참조
	printf("%d\n", *(int*)void_ptr);

	// void_ptr++; <= 포인터 연산도 불가능, 띄어야 하는 크기르 모름
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
		구조체 멤버 접근 방법
		- 구조체변수이름.
		- .(member access operator) : 구조체 멤버를 참조하는 연산자
	*/

	struct person p = { "홍길동", 30,175.25f };
	p.height = 180.35f;

	printf("p의 height : %f\n", p.height);
	printf("p의 height 주소 : 0x%p\n\n", &p.height); // . 연산자는 &보다 우선순위가 높다.

	{ // 구조체는 선언한 영역에 영향을 받는다.
		struct book
		{
			char test;
			char test1;
		};

		// book a;
	}
	// book b; <= 에러발생

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
		// best_friend = test; <= error : 구조체 이름은 시작 주소를 가리키지 않는다.
		best_friend = &my_friend[0];

		/*
			구조체 포인터로 멤버에 접근하는 법
			* or -> 사용
		*/

		// *보다.연산자가 우선순위가 높으므로()로 우선순위를 정해주어야함
		// best_friend.full_names; <= error : . 연산자가 먼저 처리됨
		(*best_friend).full_names; // ok

		printf("best_friend[0] 이름\t: %s\n", (*best_friend).full_names.given);

		//구조체 포인터 에서는 ->는 구조체에서의. 연산자와같다.
		printf("best_friend[0] 성\t: %s\n", best_friend->full_names.family);

		best_friend++; // 구조체 단위 이동
		printf("best_friend[1] 이름\t: %s\n", (*best_friend).full_names.given);
		printf("best_friend[1] 성\t: %s\n", best_friend->full_names.family);
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
	printf("%s 사망\n", c->name);
}

void revive(character* c)
{
	printf("%s 부활\n", c->name);
	c->hp = 200;
}

void set_location_to_town(character* c)
{
	printf("마을로 이동합니다.\n");
	strcpy_s(c->location, sizeof(c->location), "Town");
}
void pointer_and_function()
{	
	/*
		함수 포인터 : 특정 자료형을 반환하고 특정 인자 목록을 가지는 함수를 저장하는 포인터
		 - 함수의 이름은 함수의 주소
		 - 프로그램을 유연하게 짤 수있다.

		 선언
		 자료형 (*변수명)(자료형, ...)

		 사용
		 변수명(값, ...)
	 */
	 
	// 사용자로부터 + 또는 - 의 연산자와 두 정수를 입력받아 연산 결과를 출력하는 함수
	char op = '\0';
	printf("연산자 입력 : ");
	scanf_s(" %c", &op, sizeof(op));

	int x = 0;
	printf("피연산자 입력 : ");
	scanf_s("%d", &x);

	int y = 0;
	printf("피연산자 입력 : ");
	scanf_s("%d", &y);

	int (*compute)(int, int) = NULL;

	switch (op) 
	{
	case '+':compute = Add; break; // 함수의 이름은 함수의 주소
	case '-':compute = Sub; break; // 함수의 이름은 함수의 주소
	}

	if(compute != NULL)
		printf("결과 : %d\n", compute(x, y));

	// 특정 이벤트에서 실행시킬 함수를 걸어둘 수 있다.

	character c = {
		"Mage",
		"Dungeon",
		100,
		{NULL, NULL,NULL,NULL,NULL}
	};

	// 사망 이벤트 발생시 실행시킬함수를 넣어줌
	c.if_dead[0] = print_dead;
	c.if_dead[1] = revive;
	c.if_dead[2] = set_location_to_town;

	printf("%s의 위치 : %s hp : %d\n", c.name, c.location, c.hp);

	while (1)
	{
		int dmg = 0;
		printf("받을피해 입력(현재 체력 %d) : ", c.hp);
		scanf_s("%d", &dmg);
		c.hp -= dmg;
		if (c.hp <= 0)
		{
			for (int i = 0; i < 5; i++)
				if (c.if_dead[i] != NULL) // 이벤트가 있다면 호출해준다.
					c.if_dead[i](&c);
			break;
		}
	}

	printf("%s의 위치 : %s hp : %d\n", c.name, c.location, c.hp);
}

void print_player(const player * const p)
{
	printf("\n플레이어 이름\t: %s\n", p->name);
	printf("플레이어 hp\t: %d\n", p->hp);
	printf("소지 무기\t: %s\n", p->equip_weapon->name);
	printf("소지 무기등급\t: %s\n\n", p->equip_weapon->grade);
}

/*
	인자를 받을 포인터 변수가 가진 값(변수의 주소)를 받는다.
	 -> 포인터 변수가 가진 변수의 값을 수정할 수는 있지만 
	 해당 값을 넘겨준 원본이 소유한 값(변수의 주소)자체는 변경이 안된다.
*/
void swap_ptr1(int* ptr1, int* ptr2)
{
	int* temp = NULL;

	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

/*
	포인터 변수의 주소값을 인자로 받아 
	포인터 변수가 가지는 값(변수의 주소)의 수정이 가능해진다.
*/
void swap_ptr2(int** ptr1, int** ptr2)
{
	int* temp = NULL;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}


void double_pointer()
{
	/*
		이중 포인터(double pointer) : 포인터 변수의 주소를 저장하는 변수
		 - 삼중 이상도 가능하지만 사용하진 않음
		 - 포인터 변수의 값을 변경하기위해 사용
	*/

	/*
								 0x121|
								 0x122|    7
								 0x123|
								 0x124|

								 0x125|
		int a = 7;               0x126|    0x121
		int *ptr = &a;           0x127|
		int **pptr = &ptr;       0x128|

								 0x129|
								 0x130|    0x125
								 0x131|
								 0x132|
	*/

	int a = 7; // 변수
	int* ptr = &a; // 변수의 주소를 저장하는 단일 포인터
	int** pptr = &ptr;	// 포인터 주소의 변수를 버방하는 이중 포인터

	/*
		pptr == &ptr
		*pptr == *&ptr == ptr == &a
		**pptr == **&ptr == *ptr == *&a == a
	*/

	printf("&pptr = 0x%p\n", &pptr);
	printf("&ptr = 0x%p\n", &ptr);
	printf("&a = 0x%p\n", &a);

	printf("pptr == &ptr\n");
	printf("pptr : 0x%p\n", pptr);
	printf("&ptr : 0x%p\n", &ptr);

	printf("*pptr == ptr == &a \n");
	printf("*pptr = 0x%p\n", *pptr);
	printf("ptr = 0x%p\n", ptr);
	printf("&a = 0x%p\n", &a);

	printf("**pptr == *ptr == a \n");
	printf("**pptr = %d\n", **pptr);
	printf("*ptr = %d\n", *ptr);
	printf("a = %d\n", a);

	int b = 1;
	int c = 2;
	int* ptr1 = &b;
	int* ptr2 = &c;

	printf("***** before swap ptr1 *****\n");
	printf("ptr1 : 0x%p\n", ptr1);
	printf("ptr2 : 0x%p\n\n", ptr2);

	// 포인터가 가진 변수의 주소값이 인자로 들어감
	swap_ptr1(ptr1, ptr2);

	printf("***** after swap ptr1 *****\n");
	printf("ptr1 : 0x%p\n", ptr1);
	printf("ptr2 : 0x%p\n\n", ptr2);

	// 포인터 변수의 메모리 주소를 넘겨주므로 포인터 변수의 값 수정가능
	swap_ptr2(&ptr1, &ptr2);

	printf("***** after swap ptr2 *****\n");
	printf("ptr1 : 0x%p\n", ptr1);
	printf("ptr2 : 0x%p\n\n", ptr2);
}

void pointer_arr()
{ // 포인터 배열 : 포인터를 원소로 가지는 배열
	int a, b, c;
	a = 1;
	b = 2;
	c - 3;

	int* ptr_arr[3] = { &a,&b,&c };

	for (int i = 0; i < 3; i++)
	{
		printf("arr[%d] : 0x%p\n", i, ptr_arr[i]);
		printf("*arr[%d] : %d\n", i, *ptr_arr[i]);
		printf("*arr[%d] : %d\n", i, ptr_arr[i][0]);
	}

	// 문자열의 시작주소를 가지고 있는 포인터 배열
	char* names1[4] =
	{
		"Aladdin",
		"Jasmine",
		"Magic Carpet",
		"Genie"
	};

	for (int i = 0; i < 4; i++)
		printf("%s 문자열의 주소 : 0x%p\n", names1[i], names1[i]);
	printf("\n");

	// 복사하여 받는것이 아닌 해당 문자열 상수의 시작 주소를 받는다.
	char* test1 = "Hello";

	// 위와 다르게 시작 주소를 받는게 아닌 배열에 값을 복사한다.
	char test2[] = "Hello";

	// 문자열 상수의 값을 바꾸려 시도하면 문제가 발생한다.
	//test1[0] = "h";

	// 복사한 값을 저장한 변수를 수정할 뿐이므로 가능
	test2[0] = "h";

	// "Hello" 문자열에 덮어 씌우는 것이 아닌 새로운 문자열의 시작주소로 바꿈
	test1 = "hhhhh";

}

void pointer_arr_and_2d_arr()
{
	float arr[2][4] =
	{
		{1.0f, 2.0f, 3.0f, 4.0f},
		{5.0f, 6.0f, 7.0f, 8.0f}
	};

	/*
		arr = &arr[0] == arr[0] == &arr[0][0]

		*arr == arr[0]
		**arr == arr[0][0]
		 
		 - 2차원 배열의 시작주소는 0행의 시작주소이다.
	*/

	// 첫 시작주소를 표현하는 법
	printf("&a[0][0] : 0x%p\n", arr);
	printf("&a[0][0] : 0x%p\n", arr[0]);
	printf("&a[0][0] : 0x%p\n", &arr[0]);
	printf("&a[0][0] : 0x%p\n\n", &arr[0][0]);

	// 한번 역참조하면 *arr == arr[0]
	printf("&a[0][0] : 0x%p\n", *arr);
	printf("&a[0][0] : 0x%p\n", &arr[0]);
	printf("&a[0][0] : 0x%p\n\n", &arr[0][0]);

	// 0행 0열 원소 접근
	printf("arr[0][0] : %f, %f\n\n", **arr, arr[0][0]);

	/*
		arr[4][5]

		*(*(arr + 1) + 3) == arr[1][3]

		ㅁ ㅁ ㅁ ㅁ ㅁ
		ㅁ ㅁ ㅁ ㅇ ㅁ
		ㅁ ㅁ ㅁ ㅁ ㅁ
		ㅁ ㅁ ㅁ ㅁ ㅁ
	
	*/

	
	// 행 이동 : arr[0][0] -> arr[1][0]
	printf("0x%p\n", (arr + 1));
	printf("0x%p\n", (&arr[1]));
	printf("0x%p\n", *(arr + 1));
	printf("0x%p\n", (&arr[0] + 1));
	printf("0x%p\n\n", (&arr[1][0]));

	// 행열 이동 arr[0][0] -> arr[0 + 1][0 + 2] -> arr[1][2]
	// 1행으로 이동 후 2열 이동
	printf("%f\n\n", *(*(arr + 1) + 2));

	// 2차원 배열을 포인터에 넣기
	{ // 1차원 배열을 단일 포인터에 담았으니 2차원은 2중 포인터에 담으면 될까?
		int arr2[2][3] =
		{
			{ 0, 1, 2 },
			{ 3, 4, 5 }
		};

		//int** ptr_arr = arr2; <= 자료형이 다르다는 경고가 나옴

		//printf("%d", ptr_arr[0][0]); <= 엑세스 위반으로 error
	}

	{ // 1차원 배열과 포인터 배열로 2차원 배열표현
		int arr0[3] = { 1, 2, 3 };
		int arr1[3] = { 4, 5, 6 };

		int* ptr_arr[2] = { arr0, arr1 };
		
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d( == %d, %d) => 0x%p\n",
					ptr_arr[i][j],
					*(ptr_arr[i] + j),
					*(*(ptr_arr + i) + j),
					&ptr_arr[i][j]);
			}

		}
		printf("\n");
	}

	{ //2차원 배열과 포인터 배열을 조합하여 표현

		int my_arr[2][3] = { {1,2,3}, {4,5,6} };

		//포인터 배열
		int* ptr_arr[3];
		ptr_arr[0] = my_arr[0];
		ptr_arr[1] = my_arr[1];

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d %d %d %d 0x%p\n",
					my_arr[i][j],
					ptr_arr[i][j],
					*(ptr_arr[i] + j),
					*(*(ptr_arr + i) + j),
					&my_arr[i][j]
				);
			}
		}
		printf("\n");
	}

	{	/*
			배열 포인터 : 특정 크기와 자료형을 가진 배열을 가리키는 포인터
			 - 선언후 배열만 대입해주면 추가 작업없이 다룰 수 있다.
			 - 하나의 주소만 담을 수 있다.
			 - 포인터 연산시 행단위로 이동함

			 선언

			 자료형(*변수명)[배열의 크기]
		*/

		int arr1[3] = { 0,1,2 };

		int arr2[2][3] =
		{
			{0,1,2},
			{3,4,5},
		};

		int arr3[3][3] = {
			{0,1,2},
			{3,4,5},
			{6,7,8}
		};

		// 1차원 배열은 .c 에서만 가능하다.
		int(*ptr_arr)[3] = arr1;

		for (int j = 0; j < 3; j++)
			printf("%d, ", ptr_arr[0][j]);
		printf("\n\n");

		ptr_arr = arr2;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
				printf("%d, ", ptr_arr[i][j]);
			printf("\n");
		}
		printf("\n");

		ptr_arr = arr3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				printf("%d, ", ptr_arr[i][j]);
			printf("\n");
		}
		printf("\n");
	}	
}
