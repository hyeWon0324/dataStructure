#include <stdio.h>
int count = 0;

int func(int data);
int func2(int data);
int func3(int data);
int main() {
	int a = 10;
	printf("%d\n", func(a));
}
int func(int data) {
	data = 222;
	count++;
	if (count == 10)return data;
	data = func2(data);
	return data;
}
int func2(int data) {
	data = 555;
	count++;
	if (count == 9)return data;
	func3(data);
	return data;
}
int func3(int data) {
	data = 999;
	count++;
	if (count == 7)return data;
	func(data);
	return data;

}
