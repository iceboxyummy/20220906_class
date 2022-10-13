// 23_union.cpp

#include<stdio.h>
#include<string.h>

void union_();
void union_and_structure1();
void union_and_structure2();
void endianness();

int main() {
	//union_();
	//union_and_structure1();
	//union_and_structure2();
	endianness();

	return 0;
}

void union_()
{
	/*
		공용체(union) : 하나의 메모리를 다양한 자료형을 가진 멤버들이 공유해서 쓰는 것
		 - 구조체와 비슷하지만 구조체는 멤버 각각의 공간이 있고 공용체는 하나의 공간을 멤버가 공유한다.
	*/
	{
		union my_union
		{
			char c;
			int i;
			double d;
		};

		union my_union uni;

		// 유니온의 크기는 멤버중 가장 큰 자료형을 기준으로한다.
		// 큰 공간에 있어도 자기 크기만큼만 사용한다.
		printf("유니온 공간의 사이즈 : %d\n", sizeof(uni));
		printf("유니온 멤버 c의 사이즈 : %d\n", sizeof(uni.c));
		printf("유니온 멤버 i의 사이즈 : %d\n", sizeof(uni.i));
		printf("유니온 멤버 d의 사이즈 : %d\n\n", sizeof(uni.d));

		// 공간하나를 공유하므로 시작주소가 전부 동일하다.
		printf("0x%p\n", &uni);
		printf("0x%p\n", &uni.c);
		printf("0x%p\n", &uni.i);
		printf("0x%p\n\n", &uni.d);

		{
			union my_union
			{
				char c;
				int i;
				float f;
			};

			my_union uni;

			uni.i = 1234567890;
			printf("%d %f %d %c\n\n", uni.i, uni.f, uni.c, uni.c);

			uni.c = 'A';
			printf("%d %f %d %c\n\n", uni.i, uni.f, uni.c, uni.c);

			uni.f = 1.1f;
			printf("%d %f %d %c\n\n", uni.i, uni.f, uni.c, uni.c);
		}
	}
}

void union_and_structure1()
{
	{
		struct ptr
		{
			union
			{
				int* ip;
				float* fp;
			};
			bool is_int; // 무슨형태의 자료형인지 판단하기 위한 변수
		};

		ptr ptr;

		int i = 10;
		float f = 1.0f;

		ptr.ip = &i;
		ptr.is_int = true;

		if (ptr.is_int == true)
		{
			printf("ptr is int : %d\n", *ptr.ip);
		}
		else
		{
			printf("ptr is float : %d\n", *ptr.fp);
		}


		{ // 다른 이름/형식으로 사용가능
			struct Location
			{
				union
				{
					struct { double x; double y; };
					struct { double arr[2]; };
				};
			};
			Location loc = { 1.1,2.2 };

			printf("%lf, %lf\n", loc.x, loc.y);
			printf("%lf, %lf\n", loc.arr[0], loc.arr[1]);
		}
	}
}

enum owner
{
	Personal,
	Company
};

struct porsonal_owner
{
	// 개인 소유일 경우 주민등록번호저장
	char rrn1[7];
	char rrn2[8];
}; // 12356-1234567

struct company_owner
{
	// 회사 소유일 경우 사업자등록번호 저장
	char crn1[4];
	char crn2[3];
	char crn3[6];
}; // 123-12-12345

struct car_data
{
	char model[15];
	int status; // Personal or Company, 소유주가 누구인지를 판단하는기준

	union
	{ // 소유주에 따라 po나 co의 형태로 데이터를 사용한다.
		porsonal_owner po;
		company_owner co;
	};
};

void print_car(struct car_data const* const data)
{
	switch (data->status)
	{
	case Personal:
		printf("Personal owner = %s-%s\n", data->po.rrn1, data->po.rrn2);
		break;

	case Company:
		printf("Company owner = %s-%s-%s\n", data->co.crn1, data->co.crn2, data->co.crn3);
		break;
	}
}

void union_and_structure2()
{
	/*
		 하나의 변수를 다양한 타입으로 다루기 위해 사용 메로리를 절약할수있다.

		 차량의 소유주가 개인이나 회사인지에 따라 알맞은 형식의 정보를 저장하고 출력하는 코드
	*/

	struct car_data my_car =
	{
		"Avante", Personal,
	};
	strcpy_s(my_car.po.rrn1, 7, "123456");
	strcpy_s(my_car.po.rrn2, 8, "1234567");

	struct car_data company_car =
	{
		"Avante", Company,
	};
	strcpy_s(company_car.co.crn1, 4, "123");
	strcpy_s(company_car.co.crn2, 3, "12");
	strcpy_s(company_car.co.crn3, 6, "12345");

	print_car(&my_car);
	print_car(&company_car);
}

void endianness()
{
	union my_union
	{
		int i;
		char c;
	};

	my_union uni;
	uni.i = 0x12345678;

	printf("0x12345678\n");
	printf("i :%x\n", uni.i);
	printf("c :%x\n", uni.c);

	/*
		char형을 출력할때 78이 나온이유
	*/
	/*
	endian 설명
	*/
}