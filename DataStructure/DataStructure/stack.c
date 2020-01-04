#include<stdio.h>
#include<stdlib.h>//표준 유틸리티 (동적할당, 난수 , 정수의 연산,함수,검색,정렬
#include <malloc.h>
#define EMPTY 0


typedef struct node
{
	int data;
	struct node* link;
}stack;

stack* get_node() {
	stack* tmp; 
	tmp = (stack*)malloc(sizeof(stack));////   heap에 공간이 생긴다 . 0x1000번지 
	tmp->link = NULL;     
	return tmp; // 0x1000번지 반환 
}

void push(stack** top, int data) { //이중포인터로 받아주는 이유는 주소값을 넘겨주기위한 것 
	stack* tmp = *top;      //top 의 내용을 저장하겠다 //별 하나이므로 한번만 간다. // EMPTY 를 말한다 
	*top = get_node();      //heap 공간과 그 주소가 정해짐 
	(*top)->data = data;	 //10이 들어온다 
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
	stack* tmp = *top;      //가장 마지막에 저장한 것의 주소값 . 30 짜리 
	int num = tmp->data; 
	*top = tmp->link;        //이렇게 해야 이제  top은 그 뒤에 가리키고 있던 것. 30을 없앨거니까 20 이  top 이 될 것 
	free(tmp);					//30짜리는 공간이 해제된다 

	return num;
}
int pop2(stack* top) { //이렇게 하면 포인터 오류난다 
	if (top == EMPTY) {
		printf("stack is Empty\n");
		return -1;
	}
	stack* tmp = top;      //가장 마지막에 저장한 것의 주소값 . 30 짜리 
	int num = tmp->data;
	top = tmp->link;        //이렇게 해야 이제  top은 그 뒤에 가리키고 있던 것. 30을 없앨거니까 20 이  top 이 될 것 
	free(tmp);					//30짜리는 공간이 해제된다 

	return num;
}
int main() {
	stack* slist = EMPTY;  //전처리기 기능을 가진 문자열 
	push(&slist, 10); //top의 주소값과 값 
	push(&slist, 20);
	push(&slist, 30);

	printf("pop %d\n", pop(&slist));
	printf("pop %d\n", pop(&slist));
	printf("pop%d\n", pop(&slist));
	printf("pop %d\n", pop(&slist));   //Data 가 없는 경우 

	/*printf("pop %d\n", pop2(slist));
	printf("pop %d\n", pop2(slist));
	printf("pop%d\n", pop2(slist));
	printf("pop %d\n", pop2(slist));   //Data 가 없는 경우 */

	return 0; 
}