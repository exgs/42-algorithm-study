#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int init = 1;
	int j;
	scanf("%d",&j);
	if (j == 1)
	{
		printf("%d\n",j);
		return (0);
	}
	int *array = malloc(sizeof(int) * j * 2);
	// memset(array, 0, j*2); int형이라 안됨
	// int array[j*2] = {0,}; 가변인자라 안됨
	for (size_t i = 0; i < j*2; i++)
	{
		array[i] = 0;
	}
	for (size_t i = 0; i < j; i++) //{1,2,3,4, ...}
	{
		array[i+1] = i+1;
	}
	
	while (1)
	{
		array[init] = 0;
		init++;
		if(init == j)
		{
			printf("%d\n",array[j]);
			break;
		}
		j++;
		array[j] = array[init];
		array[init] = 0;
		init++;
	}
	free(array);
	return (0);
}