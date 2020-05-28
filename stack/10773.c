#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int **a, int data ,int *i)
{
	*(a[*i]) = data;
	(*i)++;
}
void sum(int **a, int count)
{
	unsigned int sum;

	sum = 0;
	for (size_t i = 0; i < count; i++)
	{
		sum = sum + *(a[i]);
	}
	printf("%d\n",sum);
	return ;
}

void sum_array(int a[], int count)
{
	unsigned int sum;

	sum = 0;
	for (size_t i = 0; i < count; i++)
	{
		sum = sum + a[i];
	}
	printf("%d\n",sum);
	return ;
}

void pop(int **a, int *i)
{
	(*i)--;
	*(a[*i]) = 0;
}

int main()
{
	int temp;
	int count;
	int top;
	int **stack;
	top = 0;
	scanf("%d",&count);
	stack = malloc(sizeof(int *) * count);
	for (size_t i = 0; i < count; i++)
	{
		stack[i] = malloc(sizeof(int));
		memset(stack[i],0,4);
	}

	for (size_t i = 0; i < count; i++)
	{
		scanf("%d",&temp);
		if (temp == 0 && top == 0)
			continue ;
		if (temp == 0)
		{
			pop(stack,&top);
			continue;
		}
		push(stack,temp,&top);
	}
	// for (size_t i = 0; i < count; i++)
	// {
	// 	printf("%d\n",stack[i][0]);
	// }
	sum(stack, count);

	for (size_t i = 0; i < count; i++)
	{
		free(stack[i]);
	}
	free(stack);
	return 0;
}