#include<stdio.h>
#include<stdlib.h>//ǥ�� ��ƿ��Ƽ (�����Ҵ�, ���� , ������ ����,�Լ�,�˻�,����
#include <malloc.h>
#define EMPTY 0


typedef struct node
{
	int data;
	struct node* link;
}stack;

stack* get_node() {
	stack* tmp; 
	tmp = (stack*)malloc(sizeof(stack));////   heap�� ������ ����� . 0x1000���� 
	tmp->link = NULL;     
	return tmp; // 0x1000���� ��ȯ 
}

void push(stack** top, int data) { //���������ͷ� �޾��ִ� ������ �ּҰ��� �Ѱ��ֱ����� �� 
	stack* tmp = *top;      //top �� ������ �����ϰڴ� //�� �ϳ��̹Ƿ� �ѹ��� ����. // EMPTY �� ���Ѵ� 
	*top = get_node();      //heap ������ �� �ּҰ� ������ 
	(*top)->data = data;	 //10�� ���´� 
	(*top)->link = tmp;
	printf("push **top ==  %d \n", **top);
	printf("push *top ==  %d \n", *top);
	printf("push top ==  %d \n", top);
	//printf("push (*top)->link ==  %d \n", (*top)->link);
	printf("push tmp ==  %d \n", tmp);
	printf("push &tmp ==  %d \n", &tmp);
	//printf("push *tmp ==  %d \n", *tmp);

}
/*int pop(stack** top) {
	if (*top == NULL) {
		return -1;
	}
	stack* tmp = *top;
	int num  = (*top)->data;
	tmp = (*top)->link;

	free(*top); 

	return num;
}*/ 
int pop(stack** top) {
	if (*top == EMPTY) {
		printf("stack is Empty\n");
		return -1;
	}
	stack* tmp = *top;      //���� �������� ������ ���� �ּҰ� . 30 ¥�� 
	int num = tmp->data; 
	*top = tmp->link;        //�̷��� �ؾ� ����  top�� �� �ڿ� ����Ű�� �ִ� ��. 30�� ���ٰŴϱ� 20 ��  top �� �� �� 
	free(tmp);					//30¥���� ������ �����ȴ� 

	return num;
}
int pop2(stack* top) { //�̷��� �ϸ� ������ �������� 
	if (top == EMPTY) {
		printf("stack is Empty\n");
		return -1;
	}
	stack* tmp = top;      //���� �������� ������ ���� �ּҰ� . 30 ¥�� 
	int num = tmp->data;
	top = tmp->link;        //�̷��� �ؾ� ����  top�� �� �ڿ� ����Ű�� �ִ� ��. 30�� ���ٰŴϱ� 20 ��  top �� �� �� 
	free(tmp);					//30¥���� ������ �����ȴ� 

	return num;
}
int main() {
	stack* slist = EMPTY;  //��ó���� ����� ���� ���ڿ� 
	push(&slist, 10); //top�� �ּҰ��� �� 
	push(&slist, 20);
	push(&slist, 30);

	printf("pop %d\n", pop(&slist));
	printf("pop %d\n", pop(&slist));
	printf("pop%d\n", pop(&slist));
	printf("pop %d\n", pop(&slist));   //Data �� ���� ��� 

	/*printf("pop %d\n", pop2(slist));
	printf("pop %d\n", pop2(slist));
	printf("pop%d\n", pop2(slist));
	printf("pop %d\n", pop2(slist));   //Data �� ���� ��� */

	return 0; 
}