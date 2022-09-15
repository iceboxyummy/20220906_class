// 07_RandomNumber.cpp

#include <stdio.h>
#include <stdlib.h> // 난수 생성 함수가 포함되어 있는 표준 라이브러리
#include <time.h>   // 시간 관련 함수 라이브러리

/*
   라이브러리 : 함수들의 집합
   - 자주 사용하는 로직을 재활용 가능하도록 만들어 필요할 때 불러와 사용할 수 있다.
*/

int main() {
    
    // Random Number(난수) : 무작위 숫자, rand()를 사용하여 생성.
    //  ctrl + d : 한줄복사

    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("\n\n");

    /*
    동일한 패턴으로 난수가 나오는 이유
    - 난수는 무작위로 만들어지는것이 아닌 시드값에 따른 일정한 규칙에 따라 생성된다.
    프로그램 실행시 초기 시드값은 고정되어 있어서 시드값을 바꿔주지 않으면 난수는 같은 패턴으로 나오게 된다.
    -> 시드값을 변경시켜 나오는 패턴의 값을 바꾸어 해결한다.
    */

    /* 
    srand() : 주어진 값을 시드로 설정해주는 함수
    time()  : 1970년 1월 1일 이후 경과된 시간을 초 단위로 변환해 주는 함수
    - 호출할떄마다 다른 값을 반환하기 때문에 무작위 시드값으로 정해주기좋다.
    */

    srand(10);

    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("\n\n");

    srand(time(NULL));

    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("%d,", rand() % 10 + 1);
    printf("\n\n");

    return 0;
}