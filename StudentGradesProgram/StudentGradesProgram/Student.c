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
	printf("학생 이름: ");
	scanf_s("%s", data.name, sizeof(data.name));
	while (1)
	{
		printf("%s 학생 국어 : ", data.name);
		scanf_s("%d", &data.kor);
		printf("%s 학생 영어 : ", data.name);
		scanf_s("%d", &data.eng);
		printf("%s 학생 수학 : ", data.name);
		scanf_s("%d", &data.math);
		if (data.kor >= 0 && data.kor <= 100 &&
			data.eng >= 0 && data.eng <= 100 &&
			data.math >= 0 && data.math <= 100)
			break;
		else printf("<0~100점 사이만 입력해 주세요>\n");
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
		printf("삭제 할 데이터가 없습니다.\n"); 
		return; 
	}
	if ((*head)->link)
		CleanNode(&(*head)->link);  //다 불러놓고 뒤에서부터 지워나간다 
	free(*head);
	*head = EMPTY;
	printf("삭제되었습니다\n ");
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
	printf("1. 학생 정보 출력 \n"); 
	printf("2. 학생 정보 입력 \n");
	printf("3. 학생 정보 검색 \n");
	printf("4. 학생 정보 수정 \n");	
	printf("5. 학생 정보 추가 \n");
	printf("6. 학생 정보 종료 \n");
	printf("번호 : ");
	scanf_s("%d", &menu);

	return menu;
}
void PrintList(LinkList** head) {
	if (!*head) { //head 가 Null이면 
		printf("data not existing\n");
		return;
	}
	if (!flag) {
		printf("<<===Student Manage Program === >> \n");
		printf("Num\tName\tKorean\tEnglish\tMath\tTotal\tAverage\n"); 
		flag = 1;  ///처음에 한 번만 출력 
	}
	printf("%4d\t%-5s\t%3d\t%3d\t%3d\t%3d\t%6.2lf\n",
		(*head)->id, (*head)->name, (*head)->kor, (*head)->eng,
		(*head)->math, (*head)->sum, (*head)->avg);
	if ((*head)->link) 
		PrintList(&((*head)->link));//값이 있다는 것은 다음으로 갈 노드가 있다는 것 

}
void SearchNode(LinkList** head, char* name) {


	if ((*head) == NULL) {
		printf("data node not found\n");
		return;
	}
	else {
		if (!strcmp((*head)->name, name))
		{
			printf("번호\t이름\t국어\t영어\t수학\t합계\t평균\n");
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
			printf("찾을 학생의 이름: ");  scanf_s("%s", index_name, sizeof(index_name));
			SearchNode(&head, index_name);  system("pause"); break;

		case 4:
			printf("수정할 학생 번호를 입력하세요 :");   scanf_s("%d", &index);
			EditNode(&head, index);	system("pause");  break;

		case 5:  
			printf("추가할 학생 번호를 입력하세요 :");   scanf_s("%d", &index);
			AddNode(&head , index );  system("pause");  break;
			
		case 6:CleanNode(&head); printf("프로그램 종료 \n"); system("pause"); return 0;
		default: break;
		}
	}
	return 0;
}