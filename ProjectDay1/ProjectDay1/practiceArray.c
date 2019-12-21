#include<stdio.h>
#include<stdlib.h>//표준 유틸리티 (동적할당, 난수 , 정수의 연산,함수,검색,정렬
#include<string.h>//문자열처리 함수 

void arrayInitialize() {
	//배열은 반복문과 포인터를 이용 
//자바와 달리 처음부터 초깃값을 알지 않아도된다 
	char arr[5] = { 1, 2, 3,4,5 };
	for (int i = 0; i < 5; i++) {
		arr[i] = i + 1;
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

void arrayInitSize() {
//배열의 크기는 상수만 가능 
	int size = 5; 
	const int  SIZE = 5;
	int a[6] = { 1,3,4,5,5 };

	//배열의 크기를 정해주지않은면 초깃값을 안 주었을 떄 
	//배열의 마자막 인덱스에는 쓰레기값이 있을것이다. 
	//크기를 정해준다면 0 으로 초기화되어 있다. 

	int b[6] = { 0 }; // 배열의 모든 인덱스 0으로 초기화 
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

/* 문제 
프로그램 사용자로부터 하나의 영단어를 입력받아서 입력받은 영단어의 길이를 계산하여 출력 
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

/* 문제 2 
프로그램 사용자로부터 영단어를 입력받아  char 형 배열에 저장한다 
그리고 영단어를 역순으로 바꿔 출력하는 프로그램 

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
	//이렇게 해주지 않으면 공백문자로 초기화되어 역출력 할때 공백문자도 다 프린트 된다 
	//char  선언하면 문자에 해당하는 아스키코드가 다 정해짐 
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
/*문제 3 
프로그램 사용자로부터 영단어를 입력받고 영단어를 구성하는 문자중 
아스키 코드의 값이 가장 큰 문자를 찾아서 출력하는 프로그램 
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
