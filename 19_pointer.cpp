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

int main() {
	//pointer();
	pointer_and_arr();
	//pointer_and_const();

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
		arr[0]==*(arr+0)

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
	const double PT1 = 3.14;
	double const PT2 = 3.14;

	//PT1 = 1.24; <- 상수를 변경시키려 할떄는 에러 발생

	
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
		int* a_ptr = &a;
		//a_ptr의 int가 상수가 아니라 수정 가능-> 문제 발생의 여지가 생긴다.
		*a_ptr = 15; // .c에서는 가능	 	
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

		book a;
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
		//best_friend = test; <= error : 구조체 이름은 시작 주소를 가리키지 않는다.
		best_friend = &my_friend[0];

		/*
			구조체 포인터로 멤버에 접근하는 법
			* or -> 사용
		*/
	}
}
 