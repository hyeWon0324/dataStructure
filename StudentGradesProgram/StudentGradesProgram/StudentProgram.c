#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY 0

int flag = 0;
int last_id = 999; // �л���ȣ ��

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
	printf("<< === �л� ���� ���α׷� === >>\n");
	printf("1. �л� ���� ���\n");
	printf("2. �л� ���� �Է�\n");
	printf("3. �л� ���� �˻�\n");
	printf("4. �л� ���� ����\n");
	printf("5. �л� ���� �߰�\n");
	printf("6. �л� ���� ����\n");
	printf("7. �л� ���� ����\n");
	printf("��ȣ : ");
	scanf_s("%d", &menu);
	return menu;
}

void PrintNode(LinkList** head)
{
	if (!*head) {
		printf("��� �� �����Ͱ� �����ϴ�.\n");
		return;
	}
	if (!flag) {
		printf("<< === �л� ���� ��� === >>\n");
		printf("��ȣ\t�̸�\t����\t����\t����\t�հ�\t���\n");
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
		printf("���� �� �����Ͱ� �����ϴ�.\n");
		return;
	}
	if ((*head)->link)
		CleanNode(&(*head)->link);
	free(*head);
	*head = EMPTY;
	printf("�����Ǿ����ϴ�.\n");
}

// strcmp (���� ���1, ���� ���2) --> ������ "0" ��ȯ, �ٸ��� "-1" ��ȯ
void SearchNode(LinkList** head, char index_name[])
{
	if (!*head) {
		printf("�˻� �����Ͱ� �������� �ʽ��ϴ�.\n");
		return;
	}
	else {
		if (!strcmp((*head)->name, index_name)) {
			printf("<< === �л� ���� ��� === >>\n");
			printf("��ȣ\t�̸�\t����\t����\t����\t�հ�\t���\n");
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
		printf("�˻� �����Ͱ� �������� �ʽ��ϴ�.\n");
		return;
	}
	else
	{
		if ((*head)->id == index_num)
		{
			LinkList data = GetData();
			SetData(*head, data);
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
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
		printf("�߰��� �� �����ϴ�.\n");
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
		printf("�л����� �߰� �Ϸ�!\n");
		FixID(tmp->link, 1);
	}
	else AddNode(&(*head)->link, index_num);
}

void DeleteNode(LinkList** head, int index_num)
{
	LinkList* tmp;
	if (!*head) {
		printf("���� �� �����Ͱ� �������� �ʽ��ϴ�.\n");
		return;
	}
	if ((*head)->id == index_num)
	{
		tmp = (*head)->link;
		free(*head);
		*head = tmp;
		printf("������ �Ϸ�Ǿ����ϴ�.\n");
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
		case 3: printf("ã�� �л��� �̸� �Է�: "); scanf_s("%s", index_name, sizeof(index_name));
			SearchNode(&head, index_name); system("pause"); break;
		case 4: printf("���� �Ͻ� �л��� ��ȣ �Է�: "); scanf_s("%d", &index_num);
			EditNode(&head, index_num); system("pause"); break;
		case 5: printf("�߰� �Ͻ� �л��� ��ȣ �Է�: "); scanf_s("%d", &index_num);
			AddNode(&head, index_num); system("pause"); break;
		case 6: printf("���� �Ͻ� �л��� ��ȣ �Է�: "); scanf_s("%d", &index_num);
			DeleteNode(&head, index_num); system("pause"); break;
		case 7: CleanNode(&head); printf("���α׷� ����\n"); system("pause"); return 0;
		default: break;
		}
	}
	return 0;
}







