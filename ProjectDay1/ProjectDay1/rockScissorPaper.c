#include<stdio.h>
#include<stdlib.h>//ǥ�� ��ƿ��Ƽ (�����Ҵ�, ���� , ������ ����,�Լ�,�˻�,����
#include<string.h>//���ڿ�ó�� �Լ� 

/* C ��� ���� Ȯ�� : ����
����, ����, �� ����: ����(0), ����(1), ��(2) �� ����ڰ� �����ϰ�
��ǻ�Ͱ� ���� ���� �Ŀ� ���Ͽ� ���� ����, �·��� ���Ͽ���
*/

int main() {

	int computer;
	int user;
	int result;
	int winCount , loseCount, totCount ;
	winCount = loseCount = totCount = 0; 
	srand((unsigned)time(NULL));//unsigned �� �ٿ��� ��� 8��Ʈ�ε� ����� ǥ�� ���� 

	//printf("%d\n", computer);

	printf("����, ����, �� ����:\n");

	do {
		printf(" ����(0), ����(1), ��(2) , ����(9)  --> ���ڸ� �Է��ϼ��� \n");
		scanf("%d", &user);
		computer = rand() % 3;
		result = computer - user; 
		if (user ==0) {
			prinf(" ����� : ���� \n");
		}
		else if (user == 1) {
			prinf("����� : ���� \n");
		}
		else if (user == 2) {
			prinf("����� : �� \n");
		}
		else if (user == 9) {
			prinf("����� : ���� \n");
		}
		else {
			printf("����� �Է��ϼ���\n");
			continue;
		}

		if (computer == 0) {
			prinf("��ǻ�� : ���� \n");
		}
		else if (computer == 1) {
			prinf("��ǻ�� : ���� \n");
		}
		else if (computer == 2) {
			prinf("��ǻ�� : �� \n");
		}
		
		totCount++;

		printf("��� : ");
		if (result == 0) {
			printf("���º�\n");
		}
		else if (result == -1 || result == 2) {
			printf("user �̱�\n");
			winCount++;
		}
		else {
			printf(" ��ǻ�� �̱�\n");
			loseCount++; 
		}

	} while ( user != 9);
	printf("%d��  %��  %��  �·�: %.2f%% \n ", totCount, winCount, loseCount, (double)winCount / totCount * 100);
}