#include<stdio.h>
#include<stdlib.h>//ǥ�� ��ƿ��Ƽ (�����Ҵ�, ���� , ������ ����,�Լ�,�˻�,����
#include<string.h>//���ڿ�ó�� �Լ� 

/*
������: �������� �ּҸ� �����ͷ� ��� *, &������ ��� 
 * : �ּҰ� ����Ű�� ���� �� 
 & : ���� �ڽ��� �ּ� 
 
 int a = 10 ;
 int *p = &a ; 
 ���� �������� a�� �ּҰ� 12FF , p�� �ּҰ� 34AA
 a 10 
 &a 12FF 
 p 12FF 
 &p 34AA 
 *p 10 
 *a  X ���ȵ� 
 a[10]  <-- p[a�� �ּ�]  <--  q[p�� �ּ�] <-- r[p�� �ּ�] 
				 *p = &a				 **q = *p           ***r = *q 
				 *p = &a				 **q = *(&a)		***r=*(*(&a)) 
p �� a�� �ּ� *p= a�� �� 
q�� p�� �ּ� *q = p ����� ��[a�� �ּ�], **q=a�� �� 
*r= p�� �ּ�, **r= a�� �ּ� , ***r = a�� �� 

*q 
&q : �ڽ��� �ּ� , q�� �ּ� 
q = p�� �ּ� 
*q = p�� �� = a �� �ּ� 
**q = a �� �� 

int a[5] = {1,2,3,4,5} ; 
a[0]		  a[1]		  a[2]		    a[3]		   a[4]   <-  �迭ǥ�� 
    1		   2				3				 4				 5  
*(a+0)  *(a+1)		*(a+2)     *(a+3)     *(a+4)   <- ������ ǥ�� 

int *p ; 
p =a[0] ; 

a[0]		  a[1]		  a[2]		    a[3]		   a[4]			a[5]       <-  �迭ǥ��
	1		   2				3				 4				 5				  6 
*(a+0)  *(a+1)		*(a+2)     *(a+3)     *(a+4)     *(a+5)  <- �迭���� ���� ������ ǥ��
*(p+0)  *(p+1)		*(p+2)		*(p+3)		 *(p+5)	*(p+5)	


*/

void pointerArry() {
	int arr[5] = { 1,2,3,4,5 }; 
	printf("arr[0] �� �ּ� : %p, &arr�� �ּ� : %p \n " , &arr[0] , &arr); // &arr[0] == &arr
	printf("arr[0] �� �ּ� : %p, *arr�� �� : %d \n ", &arr[0], *arr);
	printf("arr[0] �� �ּ� : %p, arr�� �ּ� : %p \n ", &arr[0], arr);      //&arr[0] == arr
	printf("arr[0] �� �� : %d, *arr�� �� : %d \n ", arr[0], *arr);			//arr[0] == *arr = *(arr+0) 
	printf("arr[0] �� �� : %d, *(arr+0) �� �� : %d \n ", arr[0], *(arr+0));	 //arr[0] == *arr = *(arr+0) 
}

void pointerMeaning() {

	int num = 1235; 
	int *ptr = &num; 
	printf("num�� �ּ� : %p\n", &num); 
	printf("ptr �� ī��Ű�� �� : %p\n ", ptr);
	printf("ptr �� ī��Ű�� ���� ��  : %d\n ", *ptr);

	printf("--------------------------------------\n");
	printf("before : %d\n", num);
	*ptr = 4321;

	printf("after : %d\n", num);


}
void swap2(int, int);  //�Լ� ������ ���� ����´� 
void pointerMeaning2();

void swap3(int, int);  //�Լ� ������ ���� ����´� 
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
���̰� 5�� int�� �迭�� �����ϰ� 1,2,3,4,5 �� �ʱ�ȭ. �� �迭�� ù��° ��Ҹ� ����Ű�� ������ ���� 
ptr �� �����ϰ� ��� �迭�� ��Ҹ� 2 ������Ų�� 
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