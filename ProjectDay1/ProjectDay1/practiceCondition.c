#include<stdio.h>
#include<stdlib.h>//ǥ�� ��ƿ��Ƽ (�����Ҵ�, ���� , ������ ����,�Լ�,�˻�,����
#include<string.h>//���ڿ�ó�� �Լ� 

void swichGrade() {
	int grade;
	char result[2];
	printf("���� �Է�: ");
	scanf("%d", &grade);
	switch (grade / 10) {
	case 10:
	case 9:
		strcpy(result, "A+");
		break;

	case 8:
	case 7:
		strcpy(result, "B");
		break;
	case 6:
	case 5:

		strcpy(result, "C");
		break;
	case 4:
	case 3:
		strcpy(result, "D");
		break;
	default:
		strcpy(result, "F");
		break;
	}

	printf("%s", result);

}
/*��¥�� �Է� �� �ش� ��¥�� ������ ����Ͻÿ� . ���� ���� ��������
*/

void swichMonth_Day() {
	//2019.12.14  Sat 
	int date;
	char day[10];
	printf("��¥ �Է�: ");
	scanf("%d", &date);

	switch (date %7) {
	case 1:
		strcpy(day, "�Ͽ���");
		break;
	case 2:
		strcpy(day, "������");
		break;
	case 3:
		strcpy(day, "ȭ����");
		break;
	case 4:
		strcpy(day, "������");
		break;
	case 5:
		strcpy(day, "�����");
		break;
	case 6:
		strcpy(day, "�ݿ���");
		break;
	case 0:
		strcpy(day, "�����");
		break;
	default:
		strcpy(day, "  ");
		break;
	}

	printf("%s", day);
}
void DanglingEx() {
	//dangling else
   //else  �� ���� ����� if �� �ٰԵȴ� 
   //����� Ȯ���ϰ� ���� 
	int a = 2, b = 3;
	if (a < 2)
		if (a < 1) b = 5;
		else
			b = 6;//6�� ����� �ȵȴ�. �ǵ��� �ٸ��� . ��ø�Ǿ� �ִ� ���ǹ����� ���ؼ�

}
/* �⵵�� �Է¹޾� ���⿩�θ� ����Ͻÿ� 
  ifSwitch �� ��� �� ����ص� ��. 4�⸶�� ����, 100�� ���� ��� , 400�� ���� ���� 
*/
void  isLeapYr() {
	int year;

	printf("�⵵�� �Է��Ͻÿ� : ");
	scanf("%d", &year);
	if((year %4 == 0 && year %100 != 0 ) || (year % 400  == 0 ))
		printf("%d���� �����Դϴ�.\n", year);

	else
		printf("%d���� ������ �ƴմϴ�.\n", year);

}

int main() {

	//swichMonth_Day();

	isLeapYr();0
}
