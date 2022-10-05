 // 21_enumerated types.cpp

/*
	열거형(Eenumerated types) : 서로 관련이 있는 정수형 상수에 이름을 부여하는 자료형
	 - 코드의 가독성 향상 및 유지 보수가 용이하다.

	정의
   enum 열거형명
   {
	  원소명 = 값
	  ...
   }

   변수명 = 초깃값; <= 정의와 동시에 선언, 생략가능

   - 열거형 명을 생략할 경우, 정의와 동시에 생성하지
   않으면 해당 열거형 변수 생성 불가

   - 원소에 대해 값을 직접 지정할 경우, 해당 원소 이후의 값이
   지정되지 않은 원소는 이전 원소의 값에서 1 증가한 값을 가지게된다.
    
   - 원소명에 대해 지정된 값은 정수형 상수와 동일하게 취급된다.

   - 원소명은 소속과 관계없이 그 자체로 지역 전체에서 사용이 가능하다.
*/

#include<stdio.h>
#include<windows.h>
#include<conio.h>

void enum_();
void mini_rpg();

int main() {
	//enum_();
    mini_rpg();
	return 0;
}

void enum_()
{
    #define RED 0
    #define ORG 1
    #define YEL 2

    int c = 0;

    printf("값 입력 (0 ~ 2)\n");
    scanf_s("%d", &c);

    if (c == RED)
        printf("red\n");

    if (c == ORG)
        printf("orange\n");

    if (c == YEL)
        printf("yellow\n");
    printf("\n");

    {
        enum color
        {
            Red = 0,
            Orange = 1,
            Yellow = 2,
        };

        int c = 0;
        printf("값 입력 ( 0 ~ 2 )\n");
        scanf_s("%d", &c);

        if (c == Red) // 선언한 지역에서 그 자체의 이름으로 선언가능
            printf("Red\n");

        for (c = Red; c <= Yellow; c++)
            printf("%d, ", c);
    }

    { // 지정하지 않은 경우 앞보다 1큰수가 들어간다.
        enum pet { dog, cat = 10, rabbit, hamster };
    }

    enum movement_speed { idle = 0, walk=200, run=500 };
    int p_speed = run;
}

typedef enum
{
    blank = 0,
    wall = 1,
    player = 2,
    monster = 3
}object;

typedef enum
{
    up = 'w',
    down = 's',
    left = 'a',
    right = 'd',
}move_dir;

typedef struct
{
    int x;
    int y;
}location;

int map[10][10] = 
{   {1,1,1,1,1,1,1,1,1,1},
    {1,2,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,3,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,3,0,0,0,3,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

void print_map()
{
    system("cls");

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            switch (map[y][x])
            {
            case blank:
                printf("  ");
                break;
            case wall:
                printf("■");
                break;
            case player:
                printf("★");
                break;
            case monster:
                printf("♬");
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
}

void move(location* const p,const location* const dir)
{
    location dest;
    dest.x = p->x + dir->x;
    dest.y = p->y + dir->y;

    object dest_obj = (object)map[dest.y][dest.x];

    switch (dest_obj)
    {
    case blank:
        map[p->y][p->x] = blank;
        map[dest.y][dest.x] = player;
        p->x = dest.x;
        p->y = dest.y;
        break;

    case wall:
    case player:
        break;
    case monster:
        printf("우징어 발견!\n");
        Sleep(1000);
        printf("우징어 퇴치!\n");
        Sleep(1000);

        map[p->y][p->x] = blank;
        map[dest.y][dest.x] = player;
        p->x = dest.x;
        p->y = dest.y;
        break;
    }
}

void mini_rpg()
{
    location p;
    p.x = 1;
    p.y = 1;

    location dir;
    dir.x = 0;
    dir.y = 0;

    move_dir key;

    while (1) {

        print_map();
        key = (move_dir)_getch();

        switch (key)
        {
        case up:
            dir.x =  0;
            dir.y = -1;
            break;
        case down:
            dir.x = 0;
            dir.y = 1;
            break;
        case left:
            dir.x = -1;
            dir.y = 0;
            break;
        case right:
            dir.x = 1;
            dir.y = 0;
            break;
        }
        move(&p, &dir);
    }
}