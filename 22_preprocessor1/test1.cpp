#include"test1.h"
#include <stdio.h>

int z = 20; // 외부파일에서 접근가능한 전역변수
static int w = 10; // static 키워드를 붙이면 외부에서 접근 불가능하다.

void print_hello()
{
	printf("Hello\n");
}

void test()
{
	printf("Test\n");
} 
