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
	Queue* tmp = get_node();
	if (*front == NULL)
		*front = tmp;
	else (*rear)->link = tmp;

	*rear = tmp;
	tmp->data = data;
}
int Que_delete(Queue** front)
{
	Queue* tmp;
	int data;
	tmp = *front;
	*front = tmp->link;
	data = tmp->data;
	free(tmp);
	return data;
}

int main()
{
	Queue* front = NULL, * rear = NULL;
	Que_insert(&front, &rear, 10);
	Que_insert(&front, &rear, 20);
	Que_insert(&front, &rear, 30);
	while (front != NULL)
		printf("%d\n", Que_delete(&front));
	return 0;
}
