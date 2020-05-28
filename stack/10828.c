#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_stack
{
	int data[100000];
	int top_index;
}t_stack;

void push(t_stack *stack, int x)
{
	if (stack == NULL)
		return ;
	stack->top_index++;
	stack->data[stack->top_index] = x;
	return ;
}
void pop(t_stack *stack)
{
	int temp;
	if (stack == NULL || stack->top_index < 0)
	{
		printf("%d\n",-1);
		return ;
	}
	temp = stack->data[stack->top_index];
	stack->data[stack->top_index] = 0;
	stack->top_index--;
	printf("%d\n",temp);
	return ;
}
void size(t_stack *stack)
{
	printf("%d\n",stack->top_index + 1);
	return ;
}
void empty(t_stack *stack)
{
	if (stack == NULL)
	{
		printf("%d\n",-1);
		return ;
	}
	if (stack->top_index == -1)
		printf("%d\n",1);
	else if (stack->top_index >= 0)
		printf("%d\n",0);
	return ;
}
void top(t_stack *stack)
{
	if (stack->top_index==-1 || stack == NULL)
	{
		printf("%d\n",-1);
		return ;
	}
	printf("%d\n",stack->data[stack->top_index]);
	return ;
}

void command(t_stack *stack, char *str)
{
	int temp;
	if (!strncmp("pu",str,2))
	{
		str=str+4;
		temp = atoi(str);
		push(stack,temp);
	}
	else if(!strncmp("po",str,2))
		pop(stack);
	else if(!strncmp("si",str,2))
		size(stack);
	else if(!strncmp("em",str,2))
		empty(stack);
	else if(!strncmp("to",str,2))
		top(stack);
	return ;
}

int main()
{
	int order;
	char buffer[10];
	char **orders;
	// scanf("%d\n",&order);
	gets(buffer); //같은 종류의 것을 써야함
	order = atoi(buffer);
	orders =(char **)malloc(sizeof(char *) * order);
	for (size_t i = 0; i < order; i++)
	{
		// printf("aaa%s\n",buffer);
		// printf("---------\n");
		gets(buffer);
		// scanf("%[^\n]s",buffer);
		// fgets(buffer,10,stdin);
		orders[i] = strdup(buffer);
	}
	t_stack *stack = malloc(sizeof(t_stack));
	stack->top_index = -1;
	memset(stack->data,0,100000);
	for (size_t i = 0; i < order; i++)
	{
		// printf("c---------------c\n");
		command(stack,orders[i]);
	}

	for (size_t i = 0; i < order; i++)
	{
		free(orders[i]);
	}
	free(orders);
	free(stack);
	return 0;
}