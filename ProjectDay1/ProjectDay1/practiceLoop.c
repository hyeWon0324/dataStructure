#include<stdio.h>
#include<stdlib.h>//표준 유틸리티 (동적할당, 난수 , 정수의 연산,함수,검색,정렬
#include<string.h>//문자열처리 함수 

void GuGuDan() {

	for (int dan = 1; dan < 10; dan++) {
		for (int num = 1; num < 10; num++) {
			printf("%d X %d  = %d\t",num ,dan, dan * num);
		}
		printf("\n");
	}

}
void StarPrint() {
	//rectangle 
	for (int i = 0; i < 5; i++) {     //row 
		for (int j = 0; j < 5; j++) { // col 
			printf("*");
		}
		printf("\n");
	}
}
void StarPrint2() {
	for (int i = 0; i < 5; i++) {     //row 
		for (int j = 0; j <=i; j++) { // col 
			printf("*");
		}
		printf("\n");
	}
}
void StarPrint3() {
	for (int i = 0; i < 5; i++) {     //row 
		for (int j =0; j < 5-i; j++) { // col 
			 printf(" ");
		}
		for (int j = 5 - i ; j <= 5; j++) {
			printf("*");
		}
		printf("\n");
	}
}
void StarPrint4() {
	//triangle 
	/*
			  #		
			##
		  ###
		####
	*/
	for (int i = 1; i <= 5; i++) {     //row 
		for (int j = 1; j <= 5 - i; j++) { // col 
			printf(" ");
		}
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}
void StarPrint5() {
	//pyramid 
	for (int i = 1; i <= 5; i++) {     //row 
		for (int j = 1; j <= 5 - i; j++) { // col 
			printf(" ");
		}
		for (int j = 1; j <= i *2 - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
}
void StarPrint6() {

	for (int i = 1; i <= 5; i++) {     //row 
		for (int j = 1; j <= 5 - i; j++) { // col 
			printf(" ");
		}
		for (int j = 1; j <= i * 2 - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	//mistake of pyramid upside down  
	for (int i = 5; i >= 1; i--) {     //row 

		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}
void StarPrint7() {
	//pyramid print 
	for (int i = 1; i <= 5; i++) {     //row 
		for (int j = 1; j <= 5 - i; j++) { // col 
			printf(" ");
		}
		for (int j = 1; j <= i * 2 - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 1; i<= 5; i++) {     //row 
		//pyramid upside down  
		for (int j = 1; j <= i; j++) {
			//space counted as little as  i 
			printf(" ");
		}	 
		for (int j = 1; j <= (5 - i) * 2 - 1; j++) {   //  rest should be all stars so (5-i)
	      	printf("*");
		}
	
		printf("\n");
	}
}
void StarPrint8() {
	//outline of first pyramid 
	for (int i = 1; i <= 5; i++) {     //row 
		for (int j = 1; j <= 5 - i; j++) { // col 
			printf(" ");
		}
		for (int j = 1; j <= i * 2 - 1; j++) {
			if ( j == 1 ||   j ==  2* i- 1 ) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	//outline of second pyramid upside down 
	for (int i = 1; i <= 5; i++) {     //row 

		for (int j = 1; j <= i; j++) {
			printf(" ");
		}
		for (int j = 1; j <= (5 - i) * 2 - 1; j++) {
			if (j == 1 || j == (5 - i) * 2 - 1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}

		printf("\n");
	}
}
int main() {

	//GuGuDan();
	//StarPrint();
//	StarPrint2();
//	StarPrint3();
//	StarPrint4();
	//StarPrint5();
// StarPrint6();
	//StarPrint7();
	StarPrint8();
}
