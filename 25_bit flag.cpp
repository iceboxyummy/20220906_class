 // 25_bit flag.cpp

/*
	bit flag : 2진수는 0과 1의 두 가지 값으로 표현되는데 이를 on(1)/off(0)의 개념으로 사용하는 것
	  - 하나의 데이터의 여러상태를 저장할수있다.
	  - bool 자료형은 참과 거짓 두 가지 경우만을 표시하기 때문에 1비트의 크기만 필요하지만 
	  메모리의 최소크기는 1바이트이기 때문에 bool은 8비트를 가지고 있어 공간이 낭비되고있다. 
	  같은 크기를 가진 char 자료형의 각각의 비트플래그로 사용하면 char자료형하나로 
	  8개의 on/off를 저장할 수있다.

*/
#include <stdio.h>

void print_bit(unsigned char b);
void bit_operator();
void bit_flag_example();

int main() {

	//print_bit('A');
	//bit_operator();
	bit_flag_example();

	return 0;
}

void print_bit(unsigned char b)
{
	// 65 : 0100 0001

	// 7
	// 0000 0000 & 0000 0001
	// 결과 = > 0

	// 6
	// 0000 0001 & 0000 0001
	// 결과 => 01

	for (int i = 7; i >= 0; i--) 
	{
		printf("%d", (b >> i) & 1);
	}
	printf("\n");
}

void bit_operator()
{
	/*
		AND(&) : 두 비트가 1일때 1
		0000 1101
		0000 1011
		---------&
		0000 1001
	*/
	{
		unsigned char b1 = 0b0000'1101;
		unsigned char b2 = 0b0000'1011;
		unsigned char rb = b1 & b2;

		printf("-----AND-----\n");
		printf("b1 : ");
		print_bit(b1);
		printf("\n");

		printf("b2 : ");
		print_bit(b2);
		printf("\n-------------\n");

		printf("rb : ");
		print_bit(rb);
		printf("\n\n");
	}

	/*
	OR(|) : 두 비트중 하나라도 1이면 1
	0000 1101
	0000 1011
	---------|
	0000 1111
	*/
	{
		unsigned char b1 = 0b0000'1101;
		unsigned char b2 = 0b0000'1011;
		unsigned char rb = b1 | b2;

		printf("-----OR-----\n");
		printf("b1 : ");
		print_bit(b1);
		printf("\n");

		printf("b2 : ");
		print_bit(b2);
		printf("\n-------------\n");

		printf("rb : ");
		print_bit(rb);
		printf("\n\n");
	}

	/*
	NOT(&) : 비트반전
	0000 1101
	---------~
	1111 0010
	*/
	{
		unsigned char b = 0b0000'1101;
		unsigned char rb = ~b;

		printf("------NOT----\n");
		printf("b : ");
		print_bit(b);
		printf("\n");

		printf("-------------\n");
		printf("rb : ");
		print_bit(rb);
		printf("\n\n");
	}

	/*
	XOR(^) : 두 비트가 서로 다르면 1
	0000 1101
	0000 1011
	---------^
	0000 0110
	*/
	{
		unsigned char b1 = 0b0000'1101;
		unsigned char b2 = 0b0000'1011;
		unsigned char rb = b1 ^ b2;

		printf("-----XOR-----\n");
		printf("b1 : ");
		print_bit(b1);
		printf("\n");

		printf("b2 : ");
		print_bit(b2);
		printf("\n-------------\n");

		printf("rb : ");
		print_bit(rb);
		printf("\n\n");
	}	

	/*
	right shift(>>) : 지정한 수 만큼 비트를 모두 오른쪽으로 이동
	1100 1011
	--------- >>4
	0000 1100
	--------- >>3
	0000 0001

	정수(10진수) 정수로 생각하면 /2를 한다고 생각하면 된다.
	1000 : 8
	0100 : 4
	0010 : 2
	0001 : 1
	*/
	{
		unsigned char b = 0b1100'1011;
		unsigned char rb1 = b >> 4;
		unsigned char rb2 = rb1 >> 3;

		printf("-----right-----\n");
		printf("b : ");
		print_bit(b);
		
		printf("\n------------->>4\n");
		printf("rb1 : ");
		print_bit(rb1);

		printf("\n------------->>3\n");
		printf("rb2 : ");
		print_bit(rb2);
		printf("\n\n");
	}

	/*
	left shift(<<) : 지정한 수 만큼 비트를 모두 왼쪽으로 이동
	1100 1011
	--------- <<4
	1011 0000
	--------- <<3
	1000 0000

	정수(10진수) 정수로 생각하면 *2를 한다고 생각하면 된다.
	0001 : 1
	0010 : 2
	0100 : 4
	1000 : 8
	*/
	{
		unsigned char b = 0b1100'1011;
		unsigned char rb1 = b << 4;
		unsigned char rb2 = rb1 << 3;

		printf("-----left-----\n");
		printf("b : ");
		print_bit(b);
		
		printf("\n-------------<<4\n");
		printf("rb1 : ");
		print_bit(rb1);

		printf("\n-------------<<3\n");
		printf("rb2 : ");
		print_bit(rb2);
		printf("\n\n");
	}
}

enum status
{
	god_mode	= 0b1000'0000,
	invisible	= 0b0100'0000,
	jump		= 0b0010'0000,
	fly			= 0b0001'0000,
	swam		= 0b0000'1000,
	frozen		= 0b0000'0100,
	burn		= 0b0000'0010,
	bleeding	= 0b0000'0001
};
void print_status(unsigned char status)
{ // 플래그 확인
	printf("----플래이어 상태창----\n");
	if (status & god_mode) printf("플레이어는 신입니다.\n");
	if (status & invisible) printf("투명인간.\n");
	if (status & jump) printf("폴짝폴짝.\n");
	if (status & fly) printf("파닥파닥.\n");
	if (status & swam) printf("첨벙첨벙.\n");
	if (status & frozen) printf("손꽁발꽁.\n");
	if (status &burn) printf("불에활활.\n");
	if (status & bleeding) printf("피가 철철.\n");
	printf("\n");
}
void bit_flag_example()
{
	unsigned char player_status = 0b0000'0000;
	print_status(player_status);

	// 플래그 추가
	{
		player_status |= god_mode;
		player_status |= burn;
		player_status |= swam;
	}
	print_status(player_status);
	
	/*
		플래그 제거

		player_status   == 1000 1010
		god_mode        == 1000 0000

		player_status   == 1000 1010
		~god_mode       == 0111 1111
					    == 0000 1010
	*/

	{
		player_status &= ~god_mode;
		player_status &= ~burn;
	}
	print_status(player_status);
}
