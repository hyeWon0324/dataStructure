#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY 0 
int flag = 0; 
int last_id = 999;

typedef struct StudentNode {
	int id; 
	char name[20];
	int kor, eng, math, sum; 
	double avg; 
	struct node* link;
}LinkList ;

LinkList* GetNode() {
	LinkList* tmp; 
	tmp = (LinkList*)malloc(sizeof(LinkList));
	tmp->link = EMPTY;
	return tmp;
}
LinkList GetData() {
	LinkList data; 
	printf("Student Name: ");
	scanf_s("%s", data.name, sizeof(data.name));
	while (1) {
		printf("%s Student Korean  : ", data.name);
		scanf_s("%d", &data.kor);
		printf("%s Student English  : ", data.name);
		scanf_s("%d", &data.eng);
		printf("%s Student Math  : ", data.name);
		scanf_s("%d", &data.math);

		if (data.kor >= 0 && data.kor <= 100 &&
			data.eng >= 0 && data.eng <= 100 &&
			data.math >= 0 && data.math <= 100)
			break;
		else printf("0 ~100 ������ ���� �Է����ּ��� \n"); 

		data.sum = data.kor + data.eng + data.math; 
		data.avg = data.sum / 3.0; 
		return data;
	}
	
}
void SetData(LinkList* head, LinkList data) {
	strcpy_s(head->name, sizeof(head->name), data.name); 
	head->avg = data.avg; 
	head->sum = data.sum; 
	head->kor = data.kor; 
	head->eng = data.eng; 
	head->math = data.math;
}
void CleanNode(LinkList** head) {
	if (!*head) {
		printf("���� �� �����Ͱ� �����ϴ�.\n"); 
		return; 
	}
	if ((*head)->link)
		CleanNode(&(*head)->link);  //�� �ҷ����� �ڿ������� ���������� 
	free(*head);
	*head = EMPTY;
	printf("�����Ǿ����ϴ�\n ");
}
void InsertNode(LinkList** head) {
	LinkList data; 
	if (*head == EMPTY) {
		*head = GetNode(); 
		(*head)->id = ++last_id;
		data = GetData();
		SetData(*head, data);
		return;
	}
	InsertNode(&(*head)->link);
}
int PrintMenu() {

	int menu = 0;
	system("cls"); 
	printf("<<===Student Manage Program === >> \n"); 
	printf("1. �л� ���� ��� \n"); 
	printf("2. �л� ���� �Է� \n");
	printf("3. �л� ���� ���� \n");
	scanf_s("%d", &menu);

	return menu;
}
void PrintNode(LinkList** head) {
	if (!*head) { //head �� Null�̸� 
		printf("data not existing\n");
		return;
	}
	if (!flag) {
		printf("<<===Student Manage Program === >> \n");
		printf("Num\tName\tKorean\tEnglish\tMath\tTotal\Average\n"); 
		flag = 1;  ///ó���� �� ���� ��� 
	}
	printf("%4d\t%-5s\t3d\t3d\t3d\t3d\t%6.2lf\n",
		(*head)->id, (*head)->name, (*head)->kor, (*head)->eng, (*head)->math,
		(*head)->sum, (*head)->avg);
	if ((*head)->link)
		PrintNode(&(*head)->link);

}
int main() {
	LinkList* head = EMPTY;
	while (1) {
		switch (PrintMenu())
		{
		case 1: PrintNode(&head); system("pause");  break; 
		case2: InsertNode(&head); break; 
		case3: CleanNode(&head); printf("���α׷� ���� \n"); system("pause"); return 0;
		default:
			break;
		}
	}
	return 0;
}