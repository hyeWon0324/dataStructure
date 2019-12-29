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
		*head = get_node();
		(*head)->data = data;
		return;
	}
	InsertNode(&(*head)->link, data);    //연결된 다음 노드의 주소를 **head 에 
}

int DeleteNode(Linklist** head, int data)
{
	Linklist* tmp;
	if (*head == NULL)
		return -1;
	else
	{
		if ((*head)->data == data)
		{
			tmp = (*head)->link;
			free(*head);
			*head = tmp;
		}
		else DeleteNode(&(*head)->link, data);
	}
	return data;
}

int main()
{
	Linklist* head = NULL;

	InsertNode(&head, 10);
	InsertNode(&head, 20);
	InsertNode(&head, 30);

	printf("%d\n", DeleteNode(&head, 20)); //지정한 데이터 삭제
	DeleteNode(&head, 10);
	DeleteNode(&head, 30);
	return 0;
}