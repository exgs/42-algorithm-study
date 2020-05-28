#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int array[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	for (int i = 0; i < n; i++)
	{
		printf("index : %d || value : %d\n", i, array[i]);
	}
	return (0);
}