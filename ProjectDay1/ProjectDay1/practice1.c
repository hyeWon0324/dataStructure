#include<stdio.h>
#include<stdlib.h>//ǥ�� ��ƿ��Ƽ (�����Ҵ�, ���� , ������ ����,�Լ�,�˻�,����
#include<string.h>//���ڿ�ó�� �Լ� 

/* C ��� ���� Ȯ�� : 
*/

int main() {
    int a, b;
	printf("���� 2�� �Է� : \n");
	scanf('%d%d', &a, &b);
	//scanf("a: %d   b: %d \n", a, b);
	
	
	char arr[50] = "abcdef";  //string  �� char �� �迭 
	printf("%s", arr);
	//arr = "fdsd" ;  ///�̷��� �ϸ� �� �ȴ� 
	strcpy(arr, "dddsdfgfwefd");
	printf("%s", arr);

	char c[50];
	printf("���ڿ� 1�� �Է� : ");
	scanf("%s", c);
	printf("a: %s \n", c);

	// ȭ��Ʈ �����̽� : �����̽� �� ��� ���� ġ�� �ФФФ� �־��ָ�  ȭ��Ʈ �����̽��� �����ڷ� 
	//�����Ƿ� ���ε��� ��� 

	char d[50];
	char e[50];
	//printf("���ڿ� 2�� �Է� : " ); 
	//scanf("%s %s", c, d);					// ����� ���еǾ� ���� 
	printf("�̸� �ּ�(���� ����) �� �Է� : "); 
	printf("�̸� �Է� scanf: ");
//	scanf("%s ", c);				///���ӵ� ���� ������ ���⸦ �����ڷ� ���´� 
	scanf("%s %*c", c);
	printf("�ּ� �Է� gets: "); 
	gets(d);									//�����ڸ� ���ͷ� �����. �����̽� ġ�� ���ӵǾ� ������ ����ġ�� ������ 
	//�ذ��� : ����ġ�� ���ۿ� ����	//%*c   �� ���� buffer �� �� ���� �����ش�. 
	//--> ���ϴ� ������� �Է��� �� �ִ� // getchar() �� ���� �͵� �ذ��� �� ������ ������ �ϳ� �� ���� 
	//���� �ּҸ� �ް� ó�� ������ �ϳ� �� ���ܾ��ϹǷ� �����ϳ� �����ִ� ���� �� ȿ�����̴� 
												//printf("c: %s \n", c);
	printf("�̸�: %s �ּ� : %s  \n", c, d); 
//	practiceChar();

}
/*���� 1 : ��ȣ (int) �̸� (���ڿ�) �ּ�( ���ڿ�: ��������) , ���� (char) �Է� �� ��� 
(�� , : m �Ǵ� f ������ ���� ���� ���ڸ� ����ϴ� ���� (����) �����ڷ� �ۼ�  */
void  practiceChar() {
	int num;
	char name[20], addr[50], gender;

	printf("��ȣ, �̸�, �ּ� , ����  �Է� : \n ");
	scanf("%d ", &num);
	scanf("%s %*c", name);
	gets(addr);

	printf("���� (char) �Է� : ");
	scanf("%c ", &gender);

	printf("���� : %d �̸�: %s �ּ� : %s  ���� : %s \n", num, name, addr, (gender == 'm') ? "����" : "����");

	if (gender == 'f')
		printf("���� : ���� ");
	else {
		printf("���� : ���� ");
	}
	//	printf("���� : %s ", (gender == 'm') ? "����" : "����");

}
void  practiceChar2() {
	int num;
	char name[50];
	char address[50];
	char gender;

	printf("��ȣ �Է� : ");
	scanf("%d", &num);

	printf("�̸� (���ڿ�) �Է� : ");
	scanf("%s%*c", name);

	printf("�ּ�( ���ڿ�: ��������) �Է� : ");
	gets(address);

	printf("���� (char) �Է� : ");
	scanf("%c", &gender);

	printf("���� : %d \n", num);
	printf("�̸�: %s �ּ� : %s  \n", name, address);
	//printf("���� : %s ", (gender == 'm') ? "����" : "����");
	if (gender == 'f')
		printf("���� : ���� ");
	else {
		printf("���� : ���� ");
	}
}