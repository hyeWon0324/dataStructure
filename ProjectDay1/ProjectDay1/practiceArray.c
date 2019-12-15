#include<stdio.h>
#include<stdlib.h>//ǥ�� ��ƿ��Ƽ (�����Ҵ�, ���� , ������ ����,�Լ�,�˻�,����
#include<string.h>//���ڿ�ó�� �Լ� 

void arrayInitialize() {
	//�迭�� �ݺ����� �����͸� �̿� 
//�ڹٿ� �޸� ó������ �ʱ갪�� ���� �ʾƵ��ȴ� 
	char arr[5] = { 1, 2, 3,4,5 };
	for (int i = 0; i < 5; i++) {
		arr[i] = i + 1;
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

void arrayInitSize() {
//�迭�� ũ��� ����� ���� 
	int size = 5; 
	const int  SIZE = 5;
	int a[6] = { 1,3,4,5,5 };

	//�迭�� ũ�⸦ �������������� �ʱ갪�� �� �־��� �� 
	//�迭�� ���ڸ� �ε������� �����Ⱚ�� �������̴�. 
	//ũ�⸦ �����شٸ� 0 ���� �ʱ�ȭ�Ǿ� �ִ�. 

	int b[6] = { 0 }; // �迭�� ��� �ε��� 0���� �ʱ�ȭ 
	for (int i = 0; i < 5; i++) {
		a[i] = i + 1;
		printf("a[%d] = %d\n", i, a[i]);
	}
}

void MultiArrayInitialize() {

	int arr[2][5] = { { 1, 2, 3,4,5 } , { 1, 2, 3,4,5 } } ;
	for (int i = 0; i <2 ; i++) {
		for (int j = 0; j < 5; j++) {

			printf("arr[%d][%d] = %d\n", i, j ,  arr[i][j]);
		}	
	}
}

/* ���� 
���α׷� ����ڷκ��� �ϳ��� ���ܾ �Է¹޾Ƽ� �Է¹��� ���ܾ��� ���̸� ����Ͽ� ��� 
*/
void AlphabetArrayPrint() {
	char word[30] ;
	int size = 0; 

	printf("input a word : "); 
	scanf("%s", word);

	for (int i = 0; i < 30; i++) {
		if (isalpha(word[i]))
			size++;
		else {
			break;
		}
	}
	printf("word Size :%d ", size);
}
void AlphabetArrayPrint2() {
	char word[30];
	int size = 0;

	printf("input a word : ");
	scanf("%s", word);

	while (word[size] != '\0') {
		size++;
	}

	printf("word Size :%d ", size);
}

/* ���� 2 
���α׷� ����ڷκ��� ���ܾ �Է¹޾�  char �� �迭�� �����Ѵ� 
�׸��� ���ܾ �������� �ٲ� ����ϴ� ���α׷� 

*/
void arrPrintBackward2() {
	char word[30];
	int size = 0;
 
	printf("input a word : ");
	scanf("%s", word);

	while (word[size] != '\0') {
		size++;
	}
	for (int i = size - 1; i >= 0; i--) {
		printf("%c", word[i]);
	}
	printf("\n");
}
void arrPrintBackward() {
	char word[30];

	printf("input a word : ");
	scanf("%s", word);

	int size = sizeof(word) -1 ;
	while (size >= 0 ) {
	
		printf("%c", word[size]);
		size--;
	}

}
void swap(int a , int  b) {
	int temp = a; 
	a = b; 
	b = temp; 
}
void  arrPrintBackward3() {
	char word[30] = { NULL }; 
	//�̷��� ������ ������ ���鹮�ڷ� �ʱ�ȭ�Ǿ� ����� �Ҷ� ���鹮�ڵ� �� ����Ʈ �ȴ� 
	//char  �����ϸ� ���ڿ� �ش��ϴ� �ƽ�Ű�ڵ尡 �� ������ 
	int size = 0;
	char tmp; 
	printf("input a word : ");
	scanf("%s", word);

	while (word[size] != '\0') {
		size++;
	}

	for (int i = 0; i < size / 2; i++) {  //swap word from back with front 
		tmp = word[i];
		word[i] = word[size - i - 1];
		word[size - i - 1] = tmp;
	}

	printf("%s\n", word); //backward print 

	//re-backward // original word 
	for (int i = sizeof(word) /*/ sizeof(char) - 1*/; i >= 0; i--) {
		if (word[i] != 0) printf("%c", word[i]);
	}
}
/*���� 3 
���α׷� ����ڷκ��� ���ܾ �Է¹ް� ���ܾ �����ϴ� ������ 
�ƽ�Ű �ڵ��� ���� ���� ū ���ڸ� ã�Ƽ� ����ϴ� ���α׷� 
*/
void findMaxAscii() {
	char word[30] = { NULL };

	int size = 0;

	printf("input a word : ");
	scanf("%s", word);

	while (word[size] != '\0') {
		size++;
	}

	char asciiNum = word[0];
	for (int i= 0; i < size ; i++) {
		if (&asciiNum < &word[i])
			asciiNum = word[i];
	}
	printf("%c\n", asciiNum);
	printf("%d", asciiNum);
	printf("\n");
}
void findMaxAscii2() {
	char word[30] = { NULL };

	int size = 0;

	printf("input a word : ");
	scanf("%s", word);

	while (word[size] != '\0') {
		size++;
	}

	int asciiNum = word[0];
	for (int i = 0; i < size; i++) {
		if (asciiNum < word[i])
			asciiNum = word[i];
	}
	printf("%c\n", asciiNum);
	printf("%d", asciiNum);
	printf("\n");
}

int main() {
	// arrayInitialize();

//	MultiArrayInitialize();
	//AlphabetArrayPrint();

//	AlphabetArrayPrint2();

	//arrPrintBackward2();

	//arrPrintBackward();

	// arrPrintBackward3();
	findMaxAscii();
}
