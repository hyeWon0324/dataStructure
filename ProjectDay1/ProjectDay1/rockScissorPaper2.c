#include<stdio.h>
#include<stdlib.h>//ǥ�� ��ƿ��Ƽ (�����Ҵ�, ���� , ������ ����,�Լ�,�˻�,����
#include<string.h>//���ڿ�ó�� �Լ� 

/* C ��� ���� Ȯ�� : ����
����, ����, �� ����: ����(0), ����(1), ��(2) �� ����ڰ� �����ϰ�
��ǻ�Ͱ� ���� ���� �Ŀ� ���Ͽ� ���� ����, �·��� ���Ͽ���
*/

int fight(int c, int u) {
	if (u == c) {
		return 0;
	}
	else if ((u + 1) % 3 == c) {
		return -1;
	}
	else {
		return 1;
	}
}


int main() {
	int computer;
	int user;
	int result;
	int winning = 0;
	int opportunity = 0;
	char* name[3] = { "����", "����", "��" }; // ������������ ���� ���ڿ� ǥ��
	srand((unsigned)time(NULL));//unsigned �� �ٿ��� ��� 8��Ʈ�ε� ����� ǥ�� ���� 
	computer = rand() % 3;
	//printf("%d\n", computer);

	printf("����, ����, �� ����:\n");
	do {
		printf(" ����(0), ����(1), ��(2) , ����(-1)  --> ���ڸ� �Է��ϼ��� \n");

		scanf("%d", &user);

		if (user == -1) {
			return;
		}
		printf("��ǻ��: %s \n ", name[computer]);
		printf("�����: %s \n ", name[user]);
		opportunity++;
		result = fight(computer, user);

		printf("��� : ");
		if (result == 0) {
			printf("���º�\n");
		}
		else if (result == 1) {
			printf("�̱�\n");
			winning++;
		}
		else {
			printf("��\n");
		}
		printf("�·� %d / %d: \n ", winning, opportunity);

	} while (1);

}

