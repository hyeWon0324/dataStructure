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
}Queue;

Queue* get_node()
{
	Queue* tmp;
	tmp = (Queue*)malloc(sizeof(Queue));
	tmp->link = NULL;
	return tmp;
}

void Que_insert(Queue** front, Queue** rear, HERO data)
{
	Queue* tmp;
	if (*front == NULL)
	{
		*front = get_node();
		tmp = *front;
	}
	else
	{
		(*rear)->link = get_node();
		tmp = (*rear)->link;
	}
	*rear = tmp;
	tmp->data = data;
}
HERO Que_delete(Queue** front)
{
	HERO data;
	if (*front == NULL) {
		data.x = -1;
		return data;
	}
	Queue* tmp = *front;

	 data = tmp->data;
	*front = tmp->link;

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
				printf("��");
			}
			else if (MAP[i][j] == 1)
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
	Queue* front = NULL, * rear = NULL;
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
		Que_insert(&front, &rear, hr);
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
		HERO data = Que_delete(&front);

		gotoxy(hr.x, hr.y);
		if (data.x == -1) {
			printf("Queue Empty\n");
			break;
		}
		printf("%d :  x=%2d  , y=%2d \n", i, data.x, data.y);
		hr.y++; //�� �����ٿ� ��� 
		Sleep(100);
	}
	system("pause");
	return 0;
}