// 17_string.cpp

#include<stdio.h>
#include<string.h>

void string();

int length(char string[]);
void copy(char dest[], int count, char src[]);
void catenate(char dest[], int count, char src[]);
int compare(char string1[], char string2[]);

int main() {
	// string();
	//printf("%d\n", strlen("Hello"));
	//printf("%d\n", length("Hello"));
	{
		char dest[9] = "";
		char src[] = "Hello";

		copy(dest, 9, src);
		//strcpy_s(dest, 9, src);
		printf("%s\n", dest);
	}

	{
		char dest[9] = "Cat";
		char src[] = "holic";

		// dest : 목적지, 계산된 결과가 담길 위치
		// src  : 재료, 계산을 하기위해 필요한 값

		// strcat_s(dest, 9, src);
		catenate(dest, 9, src);


		printf("%s\n", dest);
	}
	{
		char string[2][9] = { "Hello", "Hello" };
		printf("%s, %s\n", string[0], string[1]);
		if (compare(string[0], string[1]) == 0)
	  //if (strcmp(string[0], string[1] == 0)
			printf("같습니다\n");
		else
			printf("다릅니다!\n");

		printf("결과 값 : %d", compare(string[0], string[1]));
	}
	return 0;
}

void string(){
	/*
		문자열 : NULL문자('\0')로 종결되는 문자의 배열
	*/

	//{
	//	char hello[] = { 'h', 'e', 'l', 'l', 'o', '\0'}; // 원소를 하나씩 넣어줌
	//	for (int i = 0; i < 5; i++)
	//	{
	//		printf("%c", hello[i]);
	//	}
	//	printf("\n");
	//	printf("%s\n", hello); // 문자열 형태로 출력시 '\0'를 읽기전까지 출력을 하기 때문에 뒤에 이상한 값이 출력된다.

	//	//'\0'문자를 넣어 문장의 끝을 표시해준다.
	//	hello[4] = '\0';
	//	printf("%s", hello); //hell출력

	//}

		
	// char hello[] = { 'h', 'e', 'l', 'l', 'o', '\0', }; // 원소를 하나씩 넣어줌
	// printf("%s\n", hello); 

	// hello[2] = '\0'; // 세번쨰 원소 l 에 '\0'을 넣어줌

	// printf("%s\n", hello); // he출력

	// for (int i = 0; i < 6; i++)
	// {
	//		printf("%c", hello[i]); // \0문자를 출력하면 아무것도 나오지 않는다. -> \0문자를 제외한 문자들만 출력됨.
	// }

		// 문자열 형태로 넣어줄 경우 자동으로 '\0'포함
		char hello[] = "hello";
		printf("%s\n", hello);
}

int length(char string[]) 
// NULL문자를 제외한 문자열의 문자 갯수를 세어주는 함수
{
	int count = 0;

	while (string[count] != '\0')
		count++;

	return count;
}

void copy(char dest[], int count, char src[]) 
//src의 문자열 길이가 dest의 원소 개수보다 짧을경우,src의 문자열을 dest로 복사하는 함수
{
	int length_src = length(src);
	//작업을 하면 안되는 조건일떄 return시켜주어 끊어줄 수있다.
	//if (length_src >= count) return 0;

	if(length_src < count)
		for (int i = 0; i <= length_src; i++) 
		{
			dest[i] = src[i];
		}

}

void catenate(char dest[], int count, char src[])
// dest와 src의 문자열 길이의 합이 dest의 원소의 갯수 보다 짧을경우, src의 문자열을 dest의 문자열에 연결하는 함수
{
	int length_dest = length(dest);
	int length_src = length(src);

	if (length_dest + length_src < count)
		for (int i = 0; i <= length_src; i++)
			dest[length_dest + i] = src[i];
}

int compare(char string1[], char string2[])
// 두 문자열이 같다면 0, 서로 다른 문자를 가지는 위치의 원소를 비교하여 string1이 크다면 +1 string2가 크다면-1을 반환하는 함수
{
	for (int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++)
	{
		if (string1[i] > string2[i]) return 1;
		if (string1[i] < string2[i]) return -1;	
	}
	return 0;
}
