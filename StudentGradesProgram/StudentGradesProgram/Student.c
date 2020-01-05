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
}LinkList;

LinkList* GetNode() {
	LinkList* tmp; 
	tmp = (LinkList*)malloc(sizeof(LinkList));
	tmp->link = EMPTY;
	return tmp;
}
LinkList GetData()
{
	LinkList data;
	printf("�л� �̸�: ");
	scanf_s("%s", data.name, sizeof(data.name));
	while (1)
	{
		printf("%s �л� ���� : ", data.name);
		scanf_s("%d", &data.kor);
		printf("%s �л� ���� : ", data.name);
		scanf_s("%d", &data.eng);
		printf("%s �л� ���� : ", data.name);
		scanf_s("%d", &data.math);
		if (data.kor >= 0 && data.kor <= 100 &&
			data.eng >= 0 && data.eng <= 100 &&
			data.math >= 0 && data.math <= 100)
			break;
		else printf("<0~100�� ���̸� �Է��� �ּ���>\n");
	}
	data.sum = data.kor + data.eng + data.math;
	data.avg = data.sum / 3.0;
	return data;
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
void InsertNode(LinkList** head)
{
	LinkList data;
	if (*head == EMPTY)
	{
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
	printf("3. �л� ���� �˻� \n");
	printf("4. �л� ���� ���� \n");	
	printf("5. �л� ���� �߰� \n");
	printf("6. �л� ���� ���� \n");
	printf("��ȣ : ");
	scanf_s("%d", &menu);

	return menu;
}
void PrintList(LinkList** head) {
	if (!*head) { //head �� Null�̸� 
		printf("data not existing\n");
		return;
	}
	if (!flag) {
		printf("<<===Student Manage Program === >> \n");
		printf("Num\tName\tKorean\tEnglish\tMath\tTotal\tAverage\n"); 
		flag = 1;  ///ó���� �� ���� ��� 
	}
	printf("%4d\t%-5s\t%3d\t%3d\t%3d\t%3d\t%6.2lf\n",
		(*head)->id, (*head)->name, (*head)->kor, (*head)->eng,
		(*head)->math, (*head)->sum, (*head)->avg);
	if ((*head)->link) 
		PrintList(&((*head)->link));//���� �ִٴ� ���� �������� �� ��尡 �ִٴ� �� 

}
void SearchNode(LinkList** head, char* name) {


	if ((*head) == NULL) {
		printf("data node not found\n");
		return;
	}
	else {
		if (!strcmp((*head)->name, name))
		{
			printf("��ȣ\t�̸�\t����\t����\t����\t�հ�\t���\n");
			printf("%4d\t%-5s\t%3d\t%3d\t%3d\t%3d\t%6.2lf\n",
				(*head)->id, (*head)->name, (*head)->kor, (*head)->eng,
				(*head)->math, (*head)->sum, (*head)->avg);
			return;
		}
		else SearchNode(&((*head)->link), name);
	}

}
void EditNode(LinkList** head, int fID)
{
	if (!*head) {
		printf("Student not found\n");
		return;
	}
	else
	{
		if ((*head)->id== fID)
		{
			LinkList data = GetData();
			SetData(*head, data);
			return;
		}
		else EditNode(&((*head)->link), fID);
	}
}
void EditNodeID(LinkList** head, int increaseFlag) {
	if ((*head) == NULL) return;
	else
	{
		if (increaseFlag)
			(*head)->id++;
		else
			(*head)->id--;
		EditNodeID(&(*head)->link, increaseFlag);
	}
}
void AddNode(LinkList** head, int fID)
{
	LinkList* tmp;

	if ((*head) == NULL) return;
	else
	{
		if ((*head)->id == fID)
		{
			tmp = *head;
			*head= GetNode();  //new node 
			(*head)->id =fID;
			LinkList data = GetData();
			SetData(*head, data);
			(*head)->link = tmp; 
			last_id++;
		   EditNodeID(&(*head)->link, 1);
			//FixID(tmp->link, 1);
		}
		else AddNode( &(*head)->link, fID);
	}
}

void FixID(LinkList* head, int flag)
{
	if (!head)
		return;
	FixID(head->link, flag);
	if (flag == 1)
		head->id++;
	else if (flag == -1)
		head->id--;
}

int main() {
	LinkList* head = EMPTY;
	char index_name[20] = { "\0" };
	int index =0 ; 
	while (1) {
		switch (PrintMenu())
		{
		case 1: PrintList(&head); system("pause");  break;

		case 2: InsertNode(&head); break; 

		case 3: 
			printf("ã�� �л��� �̸�: ");  scanf_s("%s", index_name, sizeof(index_name));
			SearchNode(&head, index_name);  system("pause"); break;

		case 4:
			printf("������ �л� ��ȣ�� �Է��ϼ��� :");   scanf_s("%d", &index);
			EditNode(&head, index);	system("pause");  break;

		case 5:  
			printf("�߰��� �л� ��ȣ�� �Է��ϼ��� :");   scanf_s("%d", &index);
			AddNode(&head , index );  system("pause");  break;
			
		case 6:CleanNode(&head); printf("���α׷� ���� \n"); system("pause"); return 0;
		default: break;
		}
	}
	return 0;
}