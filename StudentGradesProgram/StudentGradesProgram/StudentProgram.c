#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY 0

int flag = 0;
int last_id = 999; // 학생번호 값

typedef struct node {
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

void SetData(LinkList* head, LinkList data)
{
	strcpy_s(head->name, sizeof(head->name), data.name);
	head->avg = data.avg;
	head->sum = data.sum;
	head->kor = data.kor;
	head->eng = data.eng;
	head->math = data.math;
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


int PrintMenu()
{
	int menu = 0;
	system("cls");
	printf("<< === 학생 관리 프로그램 === >>\n");
	printf("1. 학생 정보 출력\n");
	printf("2. 학생 정보 입력\n");
	printf("3. 학생 정보 검색\n");
	printf("4. 학생 정보 수정\n");
	printf("5. 학생 정보 추가\n");
	printf("6. 학생 정보 삭제\n");
	printf("7. 학생 정보 종료\n");
	printf("번호 : ");
	scanf_s("%d", &menu);
	return menu;
}

void PrintNode(LinkList** head)
{
	if (!*head) {
		printf("출력 할 데이터가 없습니다.\n");
		return;
	}
	if (!flag) {
		printf("<< === 학생 정보 출력 === >>\n");
		printf("번호\t이름\t국어\t영어\t수학\t합계\t평균\n");
		flag = 1;
	}
	printf("%4d\t%-5s\t%3d\t%3d\t%3d\t%3d\t%6.2lf\n",
		(*head)->id, (*head)->name, (*head)->kor, (*head)->eng,
		(*head)->math, (*head)->sum, (*head)->avg);
	if ((*head)->link)
		PrintNode(&(*head)->link);
	flag = 0;
}

void CleanNode(LinkList** head)
{
	if (!*head) {
		printf("삭제 할 데이터가 없습니다.\n");
		return;
	}
	if ((*head)->link)
		CleanNode(&(*head)->link);
	free(*head);
	*head = EMPTY;
	printf("삭제되었습니다.\n");
}

// strcmp (비교할 대상1, 비교할 대상2) --> 같으면 "0" 반환, 다르면 "-1" 반환
void SearchNode(LinkList** head, char index_name[])
{
	if (!*head) {
		printf("검색 데이터가 존재하지 않습니다.\n");
		return;
	}
	else {
		if (!strcmp((*head)->name, index_name)) {
			printf("<< === 학생 정보 출력 === >>\n");
			printf("번호\t이름\t국어\t영어\t수학\t합계\t평균\n");
			printf("%4d\t%-5s\t%3d\t%3d\t%3d\t%3d\t%6.2lf\n",
				(*head)->id, (*head)->name, (*head)->kor, (*head)->eng,
				(*head)->math, (*head)->sum, (*head)->avg);
			return;
		}
		else SearchNode(&((*head)->link), index_name);
	}
}

void EditNode(LinkList** head, int index_num)
{
	if (!*head) {
		printf("검색 데이터가 존재하지 않습니다.\n");
		return;
	}
	else
	{
		if ((*head)->id == index_num)
		{
			LinkList data = GetData();
			SetData(*head, data);
			printf("수정이 완료되었습니다.\n");
		}
		else EditNode(&((*head)->link), index_num);
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

void AddNode(LinkList** head, int index_num)
{
	LinkList* tmp;
	LinkList data;
	if (!*head) {
		printf("추가할 수 없습니다.\n");
		return;
	}
	if ((*head)->id == index_num) {
		tmp = GetNode();
		data = GetData();
		SetData(tmp, data);
		tmp->id = index_num;
		tmp->link = *head;
		*head = tmp;
		last_id++;
		printf("학생정보 추가 완료!\n");
		FixID(tmp->link, 1);
	}
	else AddNode(&(*head)->link, index_num);
}

void DeleteNode(LinkList** head, int index_num)
{
	LinkList* tmp;
	if (!*head) {
		printf("삭제 할 데이터가 존재하지 않습니다.\n");
		return;
	}
	if ((*head)->id == index_num)
	{
		tmp = (*head)->link;
		free(*head);
		*head = tmp;
		printf("삭제가 완료되었습니다.\n");
		last_id--;
		FixID(tmp, -1);
	}
	else DeleteNode(&(*head)->link, index_num);
}

int main()
{
	LinkList* head = EMPTY;
	char index_name[20] = { "\0" };
	int index_num = 0;
	while (1) {
		switch (PrintMenu()) {
		case 1: PrintNode(&head); system("pause"); break;
		case 2: InsertNode(&head); break;
		case 3: printf("찾을 학생의 이름 입력: "); scanf_s("%s", index_name, sizeof(index_name));
			SearchNode(&head, index_name); system("pause"); break;
		case 4: printf("수정 하실 학생의 번호 입력: "); scanf_s("%d", &index_num);
			EditNode(&head, index_num); system("pause"); break;
		case 5: printf("추가 하실 학생의 번호 입력: "); scanf_s("%d", &index_num);
			AddNode(&head, index_num); system("pause"); break;
		case 6: printf("삭제 하실 학생의 번호 입력: "); scanf_s("%d", &index_num);
			DeleteNode(&head, index_num); system("pause"); break;
		case 7: CleanNode(&head); printf("프로그램 종료\n"); system("pause"); return 0;
		default: break;
		}
	}
	return 0;
}








