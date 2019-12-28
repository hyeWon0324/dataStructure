// Stack을 이용하여 "*"이 출력 되는 곳의 좌표를 저장
// 저장 된 좌표를 hr.x = 25 , hr.y = 0 부분 부터 출력
// 반드시 Stack이 비어있을 경우 Stack EMPTY 출력 되도록 코드 구현

#include <stdio.h>
#include<stdlib.h>//표준 유틸리티 (동적할당, 난수 , 정수의 연산,함수,검색,정렬
#include <Windows.h>
#include <malloc.h>
#define EMPTY 0

typedef struct hero
{//좌표 저장하는 구조체 
	short x;
	short y;
}HERO, * PHERO;

typedef struct node
{
	HERO data;
	struct node* link;
}stack;

stack* get_node() {
	stack* tmp;
	tmp = (stack*)malloc(sizeof(stack));////   heap에 공간이 생긴다 . 0x1000번지 
	tmp->link = NULL;
	return tmp; // 0x1000번지 반환 
}

void push(stack** top, HERO data) { //이중포인터로 받아주는 이유는 주소값을 넘겨주기위한 것 
	stack* tmp = *top;      //top 의 내용을 저장하겠다 //별 하나이므로 한번만 간다. // EMPTY 를 말한다 
	*top = get_node();      //heap 공간과 그 주소가 정해짐 
	(*top)->data = data;	 //10이 들어온다 
	(*top)->link = tmp;
}
HERO pop(stack** top) {
	HERO hr;
	if (*top == EMPTY) {
		
		
		hr.x =-1;
		hr.y = -1;
		return hr;
	}
	stack* tmp = *top;      //가장 마지막에 저장한 것의 주소값 . 30 짜리 
	hr = tmp->data;
	*top = tmp->link;        //이렇게 해야 이제  top은 그 뒤에 가리키고 있던 것. 30을 없앨거니까 20 이  top 이 될 것 
	free(tmp);					//30짜리는 공간이 해제된다 

	return hr;
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
			}else if (MAP[i][j] == 1)
			{
				printf("□");           //1로 써져있는 것은 비어있는 상자로 표현 
			}
			else if (MAP[i][j] == 2)
			{
				printf("＊");			//2로 변경된 것은 * 로 업데이트될 것이다 
			}
		}
		printf("\n");
	}
	gotoxy(hr.x, hr.y);    
	printf("☆");				//큰 별 찍기 
}


int main()
{
	stack* slist = EMPTY;
	HERO hr;
	
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
	print_MAP(MAP, hr);   //(2,0) 부터 시작 


	while (1)
	{//별기준 
		push(&slist, hr);
		if (MAP[hr.y][(hr.x / 2) - 1] == 1)   //x축// 왼쪽 
		{//특수 문자는 실제로 화면에서 2칸을 차지한다 //x는 2씩 증가하므로 
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.x -= 2;
		}
		else if (MAP[hr.y][(hr.x / 2) + 1] == 1)//x축 //오른쪽 
		{
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.x += 2;										 //오른쪽으로 이동 
		}
		else if (MAP[hr.y + 1][(hr.x / 2)] == 1) //y축 //아래쪽 
		{
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.y += 1;										//아래로 이동 
		}
		else if (MAP[hr.y - 1][(hr.x / 2)] == 1)//y축 //위쪽 
		{
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.y -= 1;										//위로 이동 
		}
		else
			break;
		print_MAP(MAP, hr);				//값을 바꾸고 다시 새로 그려준다 
		Sleep(100);								//지연 0.1초 
	}
	hr.x = 25; 
	hr.y = 0;

	int i = 0;
	while (1) {
		i++; 
		HERO data = pop(&slist);
		gotoxy(hr.x, hr.y);
		if (data.x == -1) {
			printf("stack is Empty\n");
			break;
		}
		printf("%d :  x=%2d  , y=%2d \n", i, data.x, data.y);
		hr.y++; //그 다음줄에 출력 
		Sleep(100);
	   }
	system("pause");
	return 0;
}