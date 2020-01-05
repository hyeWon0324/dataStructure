#include <stdio.h>
#include <malloc.h>

/*
 <Stack >
				Null
 Main :    *head 
				(0x100) 

				0x100				   30
Insert :    **head				   data 

				0x1004				30
Insert2 :    **head				data

				0x2004				30
Insert2 :    **head				data


getNode:   0x3000
					*tmp 

 <Heap >
	10				0x1000
	data				 *link
 (0x1000)		(0x1004) 
		 ____________l
		 |
		V
	20				 0x3000
	data				 *link
 (0x2000)		(0x2004)
		 ____________l
		 |
		V
	30				   NULL 
	data				 *link
 (0x3000)		(0x3004)


*/
typedef struct node
{
	int data;
	struct node* link;
}Linklist;

Linklist* get_node()
{
	Linklist* tmp;
	tmp = (Linklist*)malloc(sizeof(Linklist));
	tmp->link = NULL;
	return tmp;
}

void InsertNode(Linklist** head, int data)
{
	if (*head == NULL)
	{
		printf("InsertNode null head %p %d \n", head, *head); // *head �� �ּҴ� 00000000 , ���� 0
		*head = get_node();
		(*head)->data = data;
		printf("InsertNode getNode %p %d \n", *head, *head); // *head �� �ּҴ� 00000000 , ���� 0
		return;
	}
	printf("InsertNode %p %d , %d \n", &(*head)->link, &(*head)->link, (*head)->data);
	InsertNode(&(*head)->link, data);    //����� ���� ����� �ּҸ� **head �� 
}

int DeleteNode(Linklist** head, int data)
{
	Linklist* tmp;
	if (*head == NULL)
		return -1;
	else
	{
		if ((*head)->data == data) //*head �� head �� ����Ű�� ���� 
		{
			tmp = (*head)->link; //������� �ϴ� ���� ����Ű�� �ִ� ���� ��� (0x3000) ���� 
			free(*head);				//������ �� 0x2000 �� �ִ� ���� ���� �Ҵ��� �����ȴ�  
			*head = tmp;				// *head �� ���� 0x3000 ������ �ȴ� 
		}
		else DeleteNode(&(*head)->link, data);
	}
	return data;
}
void AddNode(Linklist** head, int find, int data)
{																			//head �� �Ѱ��� �ּҰ�  0x1000 ����. ù��° ����� 
	Linklist* tmp;

	if ((*head) == NULL)
		return;
	else
	{
		if ((*head)->data == find)    //*head �� ����Ű�� ���� 0x1000������ ���� data �����ϸ� ó������ 10 
		{
			printf("AddNode else , if  (*head)->data == %d\n", (*head)->data);
			tmp = (*head)->link;			//*head �� ��ũ�� 2000����
			(*head)->link = get_node();  //*head �� ��ũ�� ���ο� �ּҸ� �־��ش�. 1500���� 
			(*head)->link->data = data;   //���ο� �����  �����ʹ� 15 
			(*head)->link->link = tmp;   //���ο� ����� ��ũ���� 2000���� 
		}
		else {
			printf("AddNode else %p,", &((*head)->link));
			
			AddNode(&((*head)->link), find, data);
			//(*head)->link �� �ּҴ� 1004�����̴�        &  ((*head)->link) 
			//�״������� 1504���� 
			//(*head) �̸� head �� ����Ű�� ���� 0x2000����������� ��. 
										// (*head) -> link ���  0x2000���� ����� link �� ���Ѵ�. �� ����� link�� ���� �ּҴ� 2004����. 

		}
	}
}
void EditNode(Linklist** head, int find, int data)
{
	if ((*head) == NULL) return;
	else
	{
		if ((*head)->data == find)
		{
			(*head)->data = data;
			printf("%d data node edited \n ", (*head)->data);
		}
		else EditNode(&((*head)->link), find, data);
	}
}

void PrintNode(Linklist** head)
{
	if (*head != NULL)
	{
		printf("%d ", (*head)->data);
		PrintNode(&(*head)->link);
	}
}
void SearchNode(Linklist** head, int find) {
	if ((*head) == NULL) {
		printf("%d data node not found\n", find);
		return;
	}
	else {
		if ((*head)->data == find)
		{
			printf("%d data node exists \n ", (*head)->data);
			return;
		}
		else SearchNode(&((*head)->link), find);
	}
}
int main()
{
	Linklist* head = NULL;   

	Linklist* head = NULL;

	InsertNode(&head, 10);
	InsertNode(&head, 20);
	InsertNode(&head, 30);

	AddNode(&head, 10, 15);
	AddNode(&head, 20, 25);
	AddNode(&head, 30, 35);

	EditNode(&head, 10, 100);
	EditNode(&head, 20, 200);
	EditNode(&head, 30, 300);

	PrintNode(&head);
	printf("\n");

	SearchNode(&head, 15);
	SearchNode(&head, 10);

	DeleteNode(&head, 20); //������ ������ ����
	DeleteNode(&head, 10);
	DeleteNode(&head, 35);
	PrintNode(&head);
	return 0;
}