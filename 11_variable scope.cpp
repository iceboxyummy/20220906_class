// 11_variable scope.cpp

/*
	변수의 유효범위 : 변수를 어느 위치에 선언하느냐에 따라서 
	변수는 유효번위, 소멸시기, 초기화 여부, 메모리에 저장되는 장소가 다르다.
	- 크게 지역(local), 전역(global)으로 나뉜다.
*/

#include <stdio.h>

/*
	전역 변수 : 특정	지역세 속하지 않는 변수, { }외부에서 선언한다. 
	 - 유효범위는 프로그램 전체이며 프로그램 종료시 소멸한다. 
	 - 초기화되디 않을시 0으로 자동으로 초기화 된다. 
	 - 데이터 영역에 저장된다.
*/
int global;
char val1 = 'G';
void LocalCount();
void StateCount();

int main() {

	printf("초기화 되지 않은 global 값 : %d\n", global);

	/*
		지역변수 : 특정 지역 { } 내에서 생성된 변수.
		- 접근 범위는 지역내이며, 속한 지역을 이탈할 경우 자동으로 소멸한다.
		- 스택 영역에 저장된다.
	*/
	return 0;
}

void LocalCount()
{
}

void StateCount()
{
}
