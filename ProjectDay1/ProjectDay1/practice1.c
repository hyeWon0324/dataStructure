#include<stdio.h>
#include<stdlib.h>//표준 유틸리티 (동적할당, 난수 , 정수의 연산,함수,검색,정렬
#include<string.h>//문자열처리 함수 

/* C 언어 문법 확인 : 
*/

int main() {
    int a, b;
	printf("정수 2개 입력 : \n");
	scanf('%d%d', &a, &b);
	//scanf("a: %d   b: %d \n", a, b);
	
	
	char arr[50] = "abcdef";  //string  은 char 의 배열 
	printf("%s", arr);
	//arr = "fdsd" ;  ///이렇게 하면 안 된다 
	strcpy(arr, "dddsdfgfwefd");
	printf("%s", arr);

	char c[50];
	printf("문자열 1개 입력 : ");
	scanf("%s", c);
	printf("a: %s \n", c);

	// 화이트 스페이스 : 스페이스 바 띄고 엔터 치고 ㅠㅠㅠㅠ 넣어주면  화이트 스페이스를 구분자로 
	//받으므로 따로따로 출력 

	char d[50];
	char e[50];
	//printf("문자열 2개 입력 : " ); 
	//scanf("%s %s", c, d);					// 띄어쓰기로 구분되어 들어간다 
	printf("이름 주소(띄어쓰기 포함) 를 입력 : "); 
	printf("이름 입력 scanf: ");
//	scanf("%s ", c);				///연속된 것이 들어오고 띄어쓰기를 구분자로 들어온다 
	scanf("%s %*c", c);
	printf("주소 입력 gets: "); 
	gets(d);									//구분자를 엔터로 잡느다. 스페이스 치면 연속되어 들어가지만 엔터치면 끝낸다 
	//해결방법 : 엔터치면 버퍼에 들어간다	//%*c   를 쓰면 buffer 를 한 문자 지워준다. 
	//--> 원하는 방식으로 입력할 수 있다 // getchar() 를 쓰는 것도 해결일 수 있지만 로직이 하나 더 들어가고 
	//복귀 주소를 받고 처리 공간이 하나 더 생겨야하므로 버퍼하나 지워주는 것이 더 효율적이다 
												//printf("c: %s \n", c);
	printf("이름: %s 주소 : %s  \n", c, d); 
//	practiceChar();

}
/*문제 1 : 번호 (int) 이름 (문자열) 주소( 문자열: 공백포함) , 성별 (char) 입력 후 출력 
(단 , : m 또는 f 성별을 통해 남자 여자를 출력하는 조건 (삼항) 연산자로 작성  */
void  practiceChar() {
	int num;
	char name[20], addr[50], gender;

	printf("번호, 이름, 주소 , 성별  입력 : \n ");
	scanf("%d ", &num);
	scanf("%s %*c", name);
	gets(addr);

	printf("성별 (char) 입력 : ");
	scanf("%c ", &gender);

	printf("숫자 : %d 이름: %s 주소 : %s  성별 : %s \n", num, name, addr, (gender == 'm') ? "남자" : "여자");

	if (gender == 'f')
		printf("성별 : 여자 ");
	else {
		printf("성별 : 남자 ");
	}
	//	printf("성별 : %s ", (gender == 'm') ? "남자" : "여자");

}
void  practiceChar2() {
	int num;
	char name[50];
	char address[50];
	char gender;

	printf("번호 입력 : ");
	scanf("%d", &num);

	printf("이름 (문자열) 입력 : ");
	scanf("%s%*c", name);

	printf("주소( 문자열: 공백포함) 입력 : ");
	gets(address);

	printf("성별 (char) 입력 : ");
	scanf("%c", &gender);

	printf("숫자 : %d \n", num);
	printf("이름: %s 주소 : %s  \n", name, address);
	//printf("성별 : %s ", (gender == 'm') ? "남자" : "여자");
	if (gender == 'f')
		printf("성별 : 여자 ");
	else {
		printf("성별 : 남자 ");
	}
}