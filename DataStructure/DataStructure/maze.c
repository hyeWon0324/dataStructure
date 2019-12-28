// Stack�� �̿��Ͽ� "*"�� ��� �Ǵ� ���� ��ǥ�� ����
// ���� �� ��ǥ�� hr.x = 25 , hr.y = 0 �κ� ���� ���
// �ݵ�� Stack�� ������� ��� Stack EMPTY ��� �ǵ��� �ڵ� ����

#include <stdio.h>
#include<stdlib.h>//ǥ�� ��ƿ��Ƽ (�����Ҵ�, ���� , ������ ����,�Լ�,�˻�,����
#include <Windows.h>
#include <malloc.h>
#define EMPTY 0

typedef struct hero
{//��ǥ �����ϴ� ����ü 
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
	tmp = (stack*)malloc(sizeof(stack));////   heap�� ������ ����� . 0x1000���� 
	tmp->link = NULL;
	return tmp; // 0x1000���� ��ȯ 
}

void push(stack** top, HERO data) { //���������ͷ� �޾��ִ� ������ �ּҰ��� �Ѱ��ֱ����� �� 
	stack* tmp = *top;      //top �� ������ �����ϰڴ� //�� �ϳ��̹Ƿ� �ѹ��� ����. // EMPTY �� ���Ѵ� 
	*top = get_node();      //heap ������ �� �ּҰ� ������ 
	(*top)->data = data;	 //10�� ���´� 
	(*top)->link = tmp;
}
HERO pop(stack** top) {
	HERO hr;
	if (*top == EMPTY) {
		
		
		hr.x =-1;
		hr.y = -1;
		return hr;
	}
	stack* tmp = *top;      //���� �������� ������ ���� �ּҰ� . 30 ¥�� 
	hr = tmp->data;
	*top = tmp->link;        //�̷��� �ؾ� ����  top�� �� �ڿ� ����Ű�� �ִ� ��. 30�� ���ٰŴϱ� 20 ��  top �� �� �� 
	free(tmp);					//30¥���� ������ �����ȴ� 

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
				printf("��");
			}else if (MAP[i][j] == 1)
			{
				printf("��");           //1�� �����ִ� ���� ����ִ� ���ڷ� ǥ�� 
			}
			else if (MAP[i][j] == 2)
			{
				printf("��");			//2�� ����� ���� * �� ������Ʈ�� ���̴� 
			}
		}
		printf("\n");
	}
	gotoxy(hr.x, hr.y);    
	printf("��");				//ū �� ��� 
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
	print_MAP(MAP, hr);   //(2,0) ���� ���� 


	while (1)
	{//������ 
		push(&slist, hr);
		if (MAP[hr.y][(hr.x / 2) - 1] == 1)   //x��// ���� 
		{//Ư�� ���ڴ� ������ ȭ�鿡�� 2ĭ�� �����Ѵ� //x�� 2�� �����ϹǷ� 
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.x -= 2;
		}
		else if (MAP[hr.y][(hr.x / 2) + 1] == 1)//x�� //������ 
		{
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.x += 2;										 //���������� �̵� 
		}
		else if (MAP[hr.y + 1][(hr.x / 2)] == 1) //y�� //�Ʒ��� 
		{
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.y += 1;										//�Ʒ��� �̵� 
		}
		else if (MAP[hr.y - 1][(hr.x / 2)] == 1)//y�� //���� 
		{
			MAP[hr.y][(hr.x / 2)] = 2;
			hr.y -= 1;										//���� �̵� 
		}
		else
			break;
		print_MAP(MAP, hr);				//���� �ٲٰ� �ٽ� ���� �׷��ش� 
		Sleep(100);								//���� 0.1�� 
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
		hr.y++; //�� �����ٿ� ��� 
		Sleep(100);
	   }
	system("pause");
	return 0;
}