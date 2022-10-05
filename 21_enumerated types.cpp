 // 21_enumerated types.cpp

/*
	������(Eenumerated types) : ���� ������ �ִ� ������ ����� �̸��� �ο��ϴ� �ڷ���
	 - �ڵ��� ������ ��� �� ���� ������ �����ϴ�.

	����
   enum ��������
   {
	  ���Ҹ� = ��
	  ...
   }

   ������ = �ʱ갪; <= ���ǿ� ���ÿ� ����, ��������

   - ������ ���� ������ ���, ���ǿ� ���ÿ� ��������
   ������ �ش� ������ ���� ���� �Ұ�

   - ���ҿ� ���� ���� ���� ������ ���, �ش� ���� ������ ����
   �������� ���� ���Ҵ� ���� ������ ������ 1 ������ ���� �����Եȴ�.
    
   - ���Ҹ� ���� ������ ���� ������ ����� �����ϰ� ��޵ȴ�.

   - ���Ҹ��� �ҼӰ� ������� �� ��ü�� ���� ��ü���� ����� �����ϴ�.
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

    printf("�� �Է� (0 ~ 2)\n");
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
        printf("�� �Է� ( 0 ~ 2 )\n");
        scanf_s("%d", &c);

        if (c == Red) // ������ �������� �� ��ü�� �̸����� ���𰡴�
            printf("Red\n");

        for (c = Red; c <= Yellow; c++)
            printf("%d, ", c);
    }

    { // �������� ���� ��� �պ��� 1ū���� ����.
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
                printf("��");
                break;
            case player:
                printf("��");
                break;
            case monster:
                printf("��");
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
        printf("��¡�� �߰�!\n");
        Sleep(1000);
        printf("��¡�� ��ġ!\n");
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