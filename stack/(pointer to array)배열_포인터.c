#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum(int (*a)[])
{
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d\n", (*a)[i]);
	}

}
int main()
{
	int (*a)[10];
	int b[10];
	a = &b;
	*(a[0]) = 11;
	printf("b : %p\n", b);
	printf("b : %p\n", &b);

	printf("a : %p\n", a);
	printf("*a : %p\n", *a);
	printf("a[0] : %p\n", a[0]);
	printf("*a[0] : %d\n", *a[0]);
	printf("*(a[0]) : %d\n", *(a[0]));
	printf("(*a)[0] : %d\n", (*a)[0]);
	// a[3]=1111;
	// // int a[10];
	// for (size_t i = 0; i < 5; i++)
	// {
	// 	printf("%d\n",a[i]);
	// }
	// for (size_t i = 0; i < 5; i++)
	// {
	// 	printf("%p\n",a);
	// }
	// printf("----------\n");
	// sum(a);
	return 0;
}