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
		����ü(union) : �ϳ��� �޸𸮸� �پ��� �ڷ����� ���� ������� �����ؼ� ���� ��
		 - ����ü�� ��������� ����ü�� ��� ������ ������ �ְ� ����ü�� �ϳ��� ������ ����� �����Ѵ�.
	*/
	{
		union my_union
		{
			char c;
			int i;
			double d;
		};

		union my_union uni;

		// ���Ͽ��� ũ��� ����� ���� ū �ڷ����� ���������Ѵ�.
		// ū ������ �־ �ڱ� ũ�⸸ŭ�� ����Ѵ�.
		printf("���Ͽ� ������ ������ : %d\n", sizeof(uni));
		printf("���Ͽ� ��� c�� ������ : %d\n", sizeof(uni.c));
		printf("���Ͽ� ��� i�� ������ : %d\n", sizeof(uni.i));
		printf("���Ͽ� ��� d�� ������ : %d\n\n", sizeof(uni.d));

		// �����ϳ��� �����ϹǷ� �����ּҰ� ���� �����ϴ�.
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
			bool is_int; // ���������� �ڷ������� �Ǵ��ϱ� ���� ����
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


		{ // �ٸ� �̸�/�������� ��밡��
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
	// ���� ������ ��� �ֹε�Ϲ�ȣ����
	char rrn1[7];
	char rrn2[8];
}; // 12356-1234567

struct company_owner
{
	// ȸ�� ������ ��� ����ڵ�Ϲ�ȣ ����
	char crn1[4];
	char crn2[3];
	char crn3[6];
}; // 123-12-12345

struct car_data
{
	char model[15];
	int status; // Personal or Company, �����ְ� ���������� �Ǵ��ϴ±���

	union
	{ // �����ֿ� ���� po�� co�� ���·� �����͸� ����Ѵ�.
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
		 �ϳ��� ������ �پ��� Ÿ������ �ٷ�� ���� ��� �޷θ��� �����Ҽ��ִ�.

		 ������ �����ְ� �����̳� ȸ�������� ���� �˸��� ������ ������ �����ϰ� ����ϴ� �ڵ�
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
		char���� ����Ҷ� 78�� ��������
	*/
	/*
	endian ����
	*/
}