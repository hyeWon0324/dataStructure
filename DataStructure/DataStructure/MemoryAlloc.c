#include<stdio.h>
#include<stdlib.h>//표준 유틸리티 (동적할당, 난수 , 정수의 연산,함수,검색,정렬
#include<string.h>//문자열처리 함수 

/* 
malloc 은 주소값을 반환하게된다. Heap 메모리 영역에서 할당 받은 공간은 반드시 반환 
malloc(sizeof(int)) 

int *arr = (int *) malloc (sizeof(int)); 
주소값을 리턴할때는 (int *) 을 붙여줘야한다 . 그 주소에 있어야하는 것은 정수값이어야한다.

 지금은 주소를 전달한다는 의미에서 * 를 붙인다. 
 int *arr 은 스택에 들어가게 된다 


*/

void mallocA() {
	int* arr = (int*)malloc(sizeof(int));

	char* arr2 = (char*)malloc(sizeof(char) * 10);

	*arr = 10;
	//strcpy_s(arr2, sizeof(10), "Test");
	strcpy_s(arr2, 10, "Test");
	printf("arr1 = %d\n", *arr);
	printf("arr2 = %s\n", arr2);

	free(arr);
	free(arr2);

}
void mallocPractice1() {
	int *kor = (int *)malloc(sizeof(int));
	int *eng = (int *)malloc(sizeof(int));
	int *math = (int *)malloc(sizeof(int));
	char *name = (char *)malloc(sizeof(char) * 20);
	*kor = 100; 
	*eng = 80; 
	*math = 60; 
	strcpy_s(name, 10, "강사");
	printf("이름은 %s 입니다.\n", name); 
	printf("국어: %d, 영어: %d , 수학 : %d\n", *kor, *eng, *math);
	free(kor), free(eng), free(math), free(name);

}
struct A {
	int a;
	int b;
};
struct B {
	struct A a; 
	int b; 
};

void mallocWithStruct() {
	printf("struct B Size = %d Byte \n", sizeof(struct B)); // 12byte 
	struct B *p = (struct B*)malloc(sizeof(struct B)); 
	p->a.a = 10; 
	p->a.b = 20; 
	p->b = 30; 
	printf("a.a = %d, a.b = %d, b = %d\n", p->a.a, p->a.b, p->b);
	free(p);
}


int main() {
	//mallocA();
	//mallocPractice1();
	mallocWithStruct();
	return 0;
}