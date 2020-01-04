#include<stdio.h>

int fact(int n) {
	if (n == 1) {
		return 1;
	}
	else
		return (n * fact(n - 1));
}

void main() {
	int x = 5; 
	printf("연산 결과 값은 %d 입니다. \n", fact(x));

}