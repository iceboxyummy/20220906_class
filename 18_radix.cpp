// 18_radix.cpp

/*
   기수
   - 진법을 나타내는 기본수를 의미함 ex) 10진법의 기수 => 10, 2진법의 기수는 2
   - 거듭제곱의 지수가 0인경우 값은 1, 지수? => 곱하는 횟수
   - 거듭제곱의 지수가 음수인 경우 부호가 양수인 거듭제곱의 역수와 같다 => x^-n = 1/x^n
*/

/*
   10진수(Decimal)
   - 기수가 10
   - 사용하는 숫자 : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

   ex) 123.45(10진수) =>(1 * 10^2) + (2 * 10^1) + (3 * 10^0) + (4 * 10^-1) + (5 * 10^-2)
*/

/*
   2진수(Binary)
   - 기수가 2
   - 사용하는 숫자 : 0, 1
   - 숫자앞에 0b를 붙여 표현한다.

   ex 101.101 = (1 * 2^2) + (0 * 2^1) + (0 * 2^0) + (1 * 2^-1) + (0 * 2^-2) + (0 * 2^-3)
*/

/*
   8진수(Octal)
   - 기수가 8
   - 사용하는 숫자 : 0, 1, 2, 3, 4, 5, 6, 7
   - 숫자앞에 0을 붙여 표현한다.
   - 2진수를 3자리로 끊으면 8진수로 변환 가능
   => 1101110 => 1 101 110 => 156
*/

/*
   16진수(Hexa_Decimal)
   - 기수가 16
   - 사용하는 숫자 : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f
   - 숫자앞에 0x를 붙여 표현한다.
   - 2진수를 4자리로 끊으면 16진수로 변환 가능
   => 11100101 => 1110 0101 => e5
*/

#include<stdio.h>

int main() {
	int d = 100;
	int b = 0b100;
	int o = 0100;
	int hd = 0x100;
	// int o2 = 09; -> error : 잘못된 8진수 표현

	printf("10진수\t:100 : %d\n", d);
	printf("2진수\t:100 : %d\n", b);
	printf("8진수\t:100 : %d\n", o);
	printf("16진수\t:100 : %d\n", hd);

	// 대입하는 값이 크다면 '을 사용하여 자릿수를 구분할 수 있다. 
	int i1 = 10000000;
	int i2 = 10'000'000;
	int i3 = 1'000'00'0'0;

	// ' 는 값을 대입할때 아무런 영향을 끼치지 않는다.
	printf("10000000\t\t : %d\n", i1);
	printf("10'000'000\t\t : %d\n", i2);
	printf("1'000'00'0'0\t\t : %d\n", i3);

	return 0;
}
