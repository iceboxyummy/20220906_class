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

		// dest : ������, ���� ����� ��� ��ġ
		// src  : ���, ����� �ϱ����� �ʿ��� ��

		// strcat_s(dest, 9, src);
		catenate(dest, 9, src);


		printf("%s\n", dest);
	}
	{
		char string[2][9] = { "Hello", "Hello" };
		printf("%s, %s\n", string[0], string[1]);
		if (compare(string[0], string[1]) == 0)
	  //if (strcmp(string[0], string[1] == 0)
			printf("�����ϴ�\n");
		else
			printf("�ٸ��ϴ�!\n");

		printf("��� �� : %d", compare(string[0], string[1]));
	}
	return 0;
}

void string(){
	/*
		���ڿ� : NULL����('\0')�� ����Ǵ� ������ �迭
	*/

	//{
	//	char hello[] = { 'h', 'e', 'l', 'l', 'o', '\0'}; // ���Ҹ� �ϳ��� �־���
	//	for (int i = 0; i < 5; i++)
	//	{
	//		printf("%c", hello[i]);
	//	}
	//	printf("\n");
	//	printf("%s\n", hello); // ���ڿ� ���·� ��½� '\0'�� �б������� ����� �ϱ� ������ �ڿ� �̻��� ���� ��µȴ�.

	//	//'\0'���ڸ� �־� ������ ���� ǥ�����ش�.
	//	hello[4] = '\0';
	//	printf("%s", hello); //hell���

	//}

		
	// char hello[] = { 'h', 'e', 'l', 'l', 'o', '\0', }; // ���Ҹ� �ϳ��� �־���
	// printf("%s\n", hello); 

	// hello[2] = '\0'; // ������ ���� l �� '\0'�� �־���

	// printf("%s\n", hello); // he���

	// for (int i = 0; i < 6; i++)
	// {
	//		printf("%c", hello[i]); // \0���ڸ� ����ϸ� �ƹ��͵� ������ �ʴ´�. -> \0���ڸ� ������ ���ڵ鸸 ��µ�.
	// }

		// ���ڿ� ���·� �־��� ��� �ڵ����� '\0'����
		char hello[] = "hello";
		printf("%s\n", hello);
}

int length(char string[]) 
// NULL���ڸ� ������ ���ڿ��� ���� ������ �����ִ� �Լ�
{
	int count = 0;

	while (string[count] != '\0')
		count++;

	return count;
}

void copy(char dest[], int count, char src[]) 
//src�� ���ڿ� ���̰� dest�� ���� �������� ª�����,src�� ���ڿ��� dest�� �����ϴ� �Լ�
{
	int length_src = length(src);
	//�۾��� �ϸ� �ȵǴ� �����ϋ� return�����־� ������ ���ִ�.
	//if (length_src >= count) return 0;

	if(length_src < count)
		for (int i = 0; i <= length_src; i++) 
		{
			dest[i] = src[i];
		}

}

void catenate(char dest[], int count, char src[])
// dest�� src�� ���ڿ� ������ ���� dest�� ������ ���� ���� ª�����, src�� ���ڿ��� dest�� ���ڿ��� �����ϴ� �Լ�
{
	int length_dest = length(dest);
	int length_src = length(src);

	if (length_dest + length_src < count)
		for (int i = 0; i <= length_src; i++)
			dest[length_dest + i] = src[i];
}

int compare(char string1[], char string2[])
// �� ���ڿ��� ���ٸ� 0, ���� �ٸ� ���ڸ� ������ ��ġ�� ���Ҹ� ���Ͽ� string1�� ũ�ٸ� +1 string2�� ũ�ٸ�-1�� ��ȯ�ϴ� �Լ�
{
	for (int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++)
	{
		if (string1[i] > string2[i]) return 1;
		if (string1[i] < string2[i]) return -1;	
	}
	return 0;
}
