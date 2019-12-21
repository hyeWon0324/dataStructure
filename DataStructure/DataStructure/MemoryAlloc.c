#include<stdio.h>
#include<stdlib.h>//ǥ�� ��ƿ��Ƽ (�����Ҵ�, ���� , ������ ����,�Լ�,�˻�,����
#include<string.h>//���ڿ�ó�� �Լ� 

/* 
malloc �� �ּҰ��� ��ȯ�ϰԵȴ�. Heap �޸� �������� �Ҵ� ���� ������ �ݵ�� ��ȯ 
malloc(sizeof(int)) 

int *arr = (int *) malloc (sizeof(int)); 
�ּҰ��� �����Ҷ��� (int *) �� �ٿ�����Ѵ� . �� �ּҿ� �־���ϴ� ���� �������̾���Ѵ�.

 ������ �ּҸ� �����Ѵٴ� �ǹ̿��� * �� ���δ�. 
 int *arr �� ���ÿ� ���� �ȴ� 


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
	strcpy_s(name, 10, "����");
	printf("�̸��� %s �Դϴ�.\n", name); 
	printf("����: %d, ����: %d , ���� : %d\n", *kor, *eng, *math);
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