#include <stdio.h>
int func(int data)
{
	if (data)
	{
		printf("%d + ", data);
		return func(data - 1) + data;
	}
	printf("\b\b= ");
	return 0;
}

int main()
{
	int i = 3;
	printf("%d\n", func(i));
}
