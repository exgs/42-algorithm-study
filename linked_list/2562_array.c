#include <stdio.h>

int main()
{
	unsigned int array[9];
	int max;
	int index;
	for (size_t i = 0; i < 9; i++)
	{
		scanf("%d",&array[i]);
	}
	max = array[0];
	index = 0;
	for (size_t i = 0; i < 8; i++)
	{
		if (max < array[i + 1])
		{
			max = array[i + 1];
			index = i + 1;
		}
	}
	printf("%d\n",max);
	printf("%d\n",index + 1);
	return(0);
}