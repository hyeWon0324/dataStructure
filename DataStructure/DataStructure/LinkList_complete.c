#include <stdio.h>
#include <malloc.h>

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

//	printf("%d \n", tmp);
	return tmp;
}

void InsertNode(Linklist** head, int data)
{
	if (*head == NULL)
	{
	
		*head = get_node();
		(*head)->data = data;
		printf("%d data node inserted\n ", (*head)->data);
		return;
	}
	InsertNode(&(*head)->link, data);
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

void AddNode(Linklist** head, int find, int data)
{
	Linklist* tmp;

	if ((*head) == NULL) return;
	else
	{
		if ((*head)->data == find)
		{
			tmp = (*head)->link;
			(*head)->link = get_node();
			(*head)->link->data = data;
			(*head)->link->link = tmp;
			printf("%d data node Added \n ", data );
		}
		else AddNode(&((*head)->link), find, data);
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
		printf("%d :  %p\n", (*head)->data,  &(*head));
		PrintNode(&(*head)->link);
	}
}
void SearchNode(Linklist** head, int find) {
	if ( (*head) == NULL) {
		printf("%d data node not found\n" , find); 
		return; 
	}
	else {
		if ((*head)->data == find)
		{
			printf("%d data node exists \n ", (*head)->data);
			return;
		}
		else SearchNode( &((*head)->link), find);
	}
}
int main()
{
	Linklist* head = NULL;

	InsertNode(&head, 10);
	InsertNode(&head, 20);
	InsertNode(&head, 30);
	PrintNode(&head);

	AddNode(&head, 10, 15);
	AddNode(&head, 20, 25);
	AddNode(&head, 30, 35);

	//EditNode(&head, 10, 100);
	//EditNode(&head, 20, 200);
	//EditNode(&head, 30, 300);

	PrintNode(&head);
	printf("\n");

	//SearchNode(&head, 15); 
	//SearchNode(&head, 10);

	//DeleteNode(&head, 20); //지정한 데이터 삭제
	//DeleteNode(&head, 10);
	//DeleteNode(&head, 35);
	//PrintNode(&head);


	printf("\n");
	return 0;
}