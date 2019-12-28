// Stack을 이용하여 "*"이 출력 되는 곳의 좌표를 저장
// 저장 된 좌표를 hr.x = 25 , hr.y = 0 부분 부터 출력
// 반드시 Stack이 비어있을 경우 Stack EMPTY 출력 되도록 코드 구현

#include <stdio.h>
#include <Windows.h>
#define EMPTY 0

typedef struct hero
{
	short x;
	short y;
}HERO, * PHERO;

typedef struct node
{
	HERO data;
	struct node* link;
}stack;

stack* get_node()
{
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack));
	tmp->link = NULL;
	return tmp;
}

void push(stack** top, HERO data)
{
	stack* tmp = *top;
	*top = get_node();
	(*top)->data = data;
	(*top)->link = tmp;
}

HERO pop(stack** top)
{
	HERO data;
	if (*top == EMPTY) {
		data.x = -1;
		return data;
	}
	stack* tmp = *top;
	data = tmp->data;
	*top = tmp->link;
	free(tmp);
	return data;
}

void gotoxy(int x, int y)
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void print_MAP(int MAP[10][10], HERO hr)
{
	int i, j;
	gotoxy(0, 0);
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (MAP[i][j] == 0)
			{
				printf("■");
			}
			else if (MAP[i][j] == 1)
			{
				printf("□");
			}
			else if (MAP[i][j] == 2)
			{
				printf("＊");
			}
		}
		printf("\n");
	}
	gotoxy(hr.x, hr.y);
	printf("☆");
}

int main()
{
	HERO hr;
	stack* top = EMPTY;
	HERO data;

	int MAP[10][10] =
	{
		{0,1,0,0,0,0,0,0,0,0},
		{0,1,1,0,0,1,1,1,0,0},
		{0,0,1,0,1,1,0,1,0,0},
		{0,0,1,1,1,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	};
	hr.x = 2;
	hr.y = 0;
	print_MAP(MAP, hr);


	while (1)
	{
		push(&top, hr);
		if (MAP[hr.y][(hr.x / 2) - 1] == 1) // 별 기준 왼쪽
		{
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.x -= 2;
		}
		else if (MAP[hr.y][(hr.x / 2) + 1] == 1) // 별 기준 오른쪽
		{
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.x += 2;
		}
		else if (MAP[hr.y + 1][(hr.x / 2)] == 1) // 별 기준 아래쪽
		{
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.y += 1;
		}
		else if (MAP[hr.y - 1][(hr.x / 2)] == 1) // 별 기준 위쪽
		{
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.y -= 1;
		}
		else
			break;
		print_MAP(MAP, hr);
		Sleep(100);
	}

	hr.x = 25;
	hr.y = 0;

	while (1) {
		data = pop(&top);
		gotoxy(hr.x, hr.y);
		if (data.x == -1) {
			printf("Stack is EMPTY\n");
			break;
		}
		printf("%2d . %2d\n", data.x, data.y);
		hr.y++;
		Sleep(100);
	}
	system("pause");
	return 0;
}