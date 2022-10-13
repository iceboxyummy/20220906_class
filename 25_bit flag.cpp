 // 25_bit flag.cpp

/*
	bit flag : 2������ 0�� 1�� �� ���� ������ ǥ���Ǵµ� �̸� on(1)/off(0)�� �������� ����ϴ� ��
	  - �ϳ��� �������� �������¸� �����Ҽ��ִ�.
	  - bool �ڷ����� ���� ���� �� ���� ��츸�� ǥ���ϱ� ������ 1��Ʈ�� ũ�⸸ �ʿ������� 
	  �޸��� �ּ�ũ��� 1����Ʈ�̱� ������ bool�� 8��Ʈ�� ������ �־� ������ ����ǰ��ִ�. 
	  ���� ũ�⸦ ���� char �ڷ����� ������ ��Ʈ�÷��׷� ����ϸ� char�ڷ����ϳ��� 
	  8���� on/off�� ������ ���ִ�.

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
	// ��� = > 0

	// 6
	// 0000 0001 & 0000 0001
	// ��� => 01

	for (int i = 7; i >= 0; i--) 
	{
		printf("%d", (b >> i) & 1);
	}
	printf("\n");
}

void bit_operator()
{
	/*
		AND(&) : �� ��Ʈ�� 1�϶� 1
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
	OR(|) : �� ��Ʈ�� �ϳ��� 1�̸� 1
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
	NOT(&) : ��Ʈ����
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
	XOR(^) : �� ��Ʈ�� ���� �ٸ��� 1
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
	right shift(>>) : ������ �� ��ŭ ��Ʈ�� ��� ���������� �̵�
	1100 1011
	--------- >>4
	0000 1100
	--------- >>3
	0000 0001

	����(10����) ������ �����ϸ� /2�� �Ѵٰ� �����ϸ� �ȴ�.
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
	left shift(<<) : ������ �� ��ŭ ��Ʈ�� ��� �������� �̵�
	1100 1011
	--------- <<4
	1011 0000
	--------- <<3
	1000 0000

	����(10����) ������ �����ϸ� *2�� �Ѵٰ� �����ϸ� �ȴ�.
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
{ // �÷��� Ȯ��
	printf("----�÷��̾� ����â----\n");
	if (status & god_mode) printf("�÷��̾�� ���Դϴ�.\n");
	if (status & invisible) printf("�����ΰ�.\n");
	if (status & jump) printf("��¦��¦.\n");
	if (status & fly) printf("�Ĵ��Ĵ�.\n");
	if (status & swam) printf("÷��÷��.\n");
	if (status & frozen) printf("�ղǹ߲�.\n");
	if (status &burn) printf("�ҿ�ȰȰ.\n");
	if (status & bleeding) printf("�ǰ� öö.\n");
	printf("\n");
}
void bit_flag_example()
{
	unsigned char player_status = 0b0000'0000;
	print_status(player_status);

	// �÷��� �߰�
	{
		player_status |= god_mode;
		player_status |= burn;
		player_status |= swam;
	}
	print_status(player_status);
	
	/*
		�÷��� ����

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
