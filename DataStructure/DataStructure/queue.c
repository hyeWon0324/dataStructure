#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node* link;
}Queue;

Queue* get_node()
{
	Queue* tmp;
	tmp = (Queue*)malloc(sizeof(Queue));
	tmp->link = NULL;
	return tmp;
}

void Que_insert(Queue** front, Queue** rear, int data)
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

int main()
{
	Queue* front = NULL, * rear = NULL;

	Que_insert(&front, &rear, 10);
	Que_insert(&front, &rear, 20);
	Que_insert(&front, &rear, 30);

	//printf("%d\n", Que_delete(&front));
	return 0;
}
