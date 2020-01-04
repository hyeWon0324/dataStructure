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
		printf("InsertNode null head %p %d \n", head, *head); // *head 의 주소는 00000000 , 값은 0
		*head = get_node();
		(*head)->data = data;
		printf("InsertNode getNode %p %d \n", *head, *head); // *head 의 주소는 00000000 , 값은 0
		return;
	}
	printf("InsertNode %p %d , %d \n", &(*head)->link, &(*head)->link, (*head)->data);
	InsertNode(&(*head)->link, data);    //연결된 다음 노드의 주소를 **head 에 
}

int DeleteNode(Linklist** head, int data)
{
	Linklist* tmp;
	if (*head == NULL)
		return -1;
	else
	{
		if ((*head)->data == data) //*head 는 head 가 가리키는 공간 
		{
			tmp = (*head)->link; //지우고자 하는 곳이 가리키고 있던 다음 노드 (0x3000) 번지 
			free(*head);				//기존의 것 0x2000 에 있는 것은 공간 할당이 해제된다  
			*head = tmp;				// *head 는 이제 0x3000 번지가 된다 
		}
		else DeleteNode(&(*head)->link, data);
	}
	return data;
}
void AddNode(Linklist** head, int find, int data)
{																			//head 에 넘겨준 주소가  0x1000 번지. 첫번째 노드라면 
	Linklist* tmp;

	if ((*head) == NULL)
		return;
	else
	{
		if ((*head)->data == find)    //*head 가 가리키는 곳인 0x1000번지에 가서 data 접근하면 처음에는 10 
		{
			printf("AddNode else , if  (*head)->data == %d\n", (*head)->data);
			tmp = (*head)->link;			//*head 의 링크는 2000번지
			(*head)->link = get_node();  //*head 의 링크에 새로운 주소를 넣어준다. 1500번지 
			(*head)->link->data = data;   //새로운 노드의  데이터는 15 
			(*head)->link->link = tmp;   //새로운 노드의 링크에는 2000번지 
		}
		else {
			printf("AddNode else %p,", &((*head)->link));
			
			AddNode(&((*head)->link), find, data);
			//(*head)->link 의 주소는 1004번지이다        &  ((*head)->link) 
			//그다음에는 1504번지 
			//(*head) 이면 head 가 가리키는 곳인 0x2000번지에가라는 뜻. 
										// (*head) -> link 라면  0x2000번지 노드의 link 를 말한다. 이 노드의 link의 실제 주소는 2004번지. 

		}
	}
}

int main()
{
	Linklist* head = NULL;   

	InsertNode(&head, 10);
	InsertNode(&head, 20);
	InsertNode(&head, 30);

	AddNode(&head, 10, 15);
	AddNode(&head, 20, 25);
	AddNode(&head, 30, 35);

	printf("%d\n", DeleteNode(&head, 20)); //지정한 데이터 삭제
	DeleteNode(&head, 10);
	DeleteNode(&head, 30);
	return 0;
}