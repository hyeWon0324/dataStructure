#include<stdio.h>
#include<stdlib.h>//표준 유틸리티 (동적할당, 난수 , 정수의 연산,함수,검색,정렬
#include<string.h>//문자열처리 함수 

/*
포인터: 기억공간의 주소를 데이터로 사용 *, &연산자 사용 
 * : 주소가 가리키는 곳의 값 
 & : 변수 자신의 주소 
 
 int a = 10 ;
 int *p = &a ; 
 위의 가정에서 a의 주소가 12FF , p의 주소가 34AA
 a 10 
 &a 12FF 
 p 12FF 
 &p 34AA 
 *p 10 
 *a  X 사용안됨 
 a[10]  <-- p[a의 주소]  <--  q[p의 주소] <-- r[p의 주소] 
				 *p = &a				 **q = *p           ***r = *q 
				 *p = &a				 **q = *(&a)		***r=*(*(&a)) 
p 는 a의 주소 *p= a의 값 
q는 p의 주소 *q = p 저장된 값[a의 주소], **q=a의 값 
*r= p의 주소, **r= a의 주소 , ***r = a의 값 

*q 
&q : 자신의 주소 , q의 주소 
q = p의 주소 
*q = p의 값 = a 의 주소 
**q = a 의 값 

int a[5] = {1,2,3,4,5} ; 
a[0]		  a[1]		  a[2]		    a[3]		   a[4]   <-  배열표기 
    1		   2				3				 4				 5  
*(a+0)  *(a+1)		*(a+2)     *(a+3)     *(a+4)   <- 포인터 표기 

int *p ; 
p =a[0] ; 

a[0]		  a[1]		  a[2]		    a[3]		   a[4]			a[5]       <-  배열표기
	1		   2				3				 4				 5				  6 
*(a+0)  *(a+1)		*(a+2)     *(a+3)     *(a+4)     *(a+5)  <- 배열명을 통한 포인터 표기
*(p+0)  *(p+1)		*(p+2)		*(p+3)		 *(p+5)	*(p+5)	


*/

void pointerArry() {
	int arr[5] = { 1,2,3,4,5 }; 
	printf("arr[0] 의 주소 : %p, &arr의 주소 : %p \n " , &arr[0] , &arr); // &arr[0] == &arr
	printf("arr[0] 의 주소 : %p, *arr의 값 : %d \n ", &arr[0], *arr);
	printf("arr[0] 의 주소 : %p, arr의 주소 : %p \n ", &arr[0], arr);      //&arr[0] == arr
	printf("arr[0] 의 값 : %d, *arr의 값 : %d \n ", arr[0], *arr);			//arr[0] == *arr = *(arr+0) 
	printf("arr[0] 의 값 : %d, *(arr+0) 의 값 : %d \n ", arr[0], *(arr+0));	 //arr[0] == *arr = *(arr+0) 
}

void pointerMeaning() {

	int num = 1235; 
	int *ptr = &num; 
	printf("num의 주소 : %p\n", &num); 
	printf("ptr 이 카리키는 곳 : %p\n ", ptr);
	printf("ptr 이 카리키는 곳의 값  : %d\n ", *ptr);

	printf("--------------------------------------\n");
	printf("before : %d\n", num);
	*ptr = 4321;

	printf("after : %d\n", num);


}
void swap2(int, int);  //함수 원형을 먼저 써놓는다 
void pointerMeaning2();

void swap3(int, int);  //함수 원형을 먼저 써놓는다 
void pointerMeaning3();

void pointerArrIncrease(); 

int main() {
//	pointerArry();

	//pointerMeaning2();

	//pointerMeaning3();

	pointerArrIncrease();
}
void swap2(int a, int  b) {
	int temp = a;
	a = b;
	b = temp;
}
void pointerMeaning2() {

	int a = 3, b = 1;

	printf("--------------------------------------\n");
	printf("before a  : %d  , b = %d\n", a, b );
	swap2(a, b);
	printf("after a  : %d  , b = %d\n", a, b);

}

void swap3(int *a, int  *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void pointerMeaning3() {

	int a = 3, b = 1;

	printf("--------------------------------------\n");
	printf("before a  : %d  , b = %d\n", a, b);
	swap3(&a, &b);
	printf("after a  : %d  , b = %d\n", a, b);

}

/* 
길이가 5인 int형 배열을 선언하고 1,2,3,4,5 로 초기화. 이 배열의 첫번째 요소를 가리키는 포인터 변수 
ptr 을 선언하고 모든 배열의 요소를 2 증가시킨다 
*/

void pointerArrIncrease() {
	int arr[5] = { 1,2,3,4,5 };
	int *p; 
	p = arr; 
	//OR 
	// int *ptr =&arr[0];


	for (int i = 0; i < 5; i++) {
		printf("before arr[%d] =  %d \n", i, arr[i]);
		
		//option 1 
	/// 	*(p + i) += 2; 

		//option 2 
		//*p += 2;
		//p++;

		//option 3 
		*(p++) += 2; 
	}

	printf("--------------------------------------\n");
	for (int i = 0; i < 5; i++) {
		
		printf("after  arr[%d] =  %d \n", i, arr[i]);
		printf("%d\n", i, *(arr + i));
		printf("%p \n", i, &arr[i]);
	}
}