#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_all(char *stack,int a)
{
	int i = 0;
	// int count = 100;
	while (stack[i] && i < a)
	{
		printf("%c\n",stack[i]);
		i++;
	}
	// for (size_t i = 0; i < count; i++)
	// {
	// 	printf("%c\n",stack[i]);
	// }
	
	return ;
}

void print_input(char *stack, char c,int i)
{
	stack[i] = c;
	return ;
}

void zero_forward(int *stack, int *temp)
{
	int i = *temp;
	while (stack[i] == 0 && i > 0)
	{
		i++;
	}
	*temp = i;
}

void zero_backward(int *stack, int *temp)
{
	int i = *temp;
	while (stack[i] == 0 && i > 0) //에러나지 말라고 해줬네
	{
		i--;
	}
	*temp = i;
}


int main()
{
	int count;
	int input;
	int flag = 1;
	int temp = 0;
	int a=0;
	scanf("%d",&count);
	int n = 0;
	char *print_c;
	// unsigned int stack[count];
	int *stack;
	stack = malloc(sizeof(int) * (count + 1));
	print_c = malloc(sizeof(char) * (2 * count));
	memset(print_c, 0, 2*count);
	for (size_t i = 0; i < count + 1; i++)
	{
		stack[i] = i;
	}
	// print_all(print_c);
	while (n < count)
	{
		scanf("%d", &input);
		if (temp < input)
		{
			while(temp != input)
			{
				
				print_input(print_c,'+',a);
				a++;
				temp++;
				zero_forward(stack, &temp);
				// print_c[a++] = '+';
				// printf("+\n");
			}
			stack[temp] = 0;
			print_input(print_c,'-',a);
			a++;
			// print_c[a++] = '-';
			// printf("-\n");
		}
		else if (temp >= input)
		{
			temp--;
			zero_backward(stack, &temp);
			if (temp != input)//&& n != count -1
			{
				flag = 0;
				break;
			}
			print_input(print_c,'-',a);
			a++;
			stack[temp] = 0;
			// print_c[a++] = '-';
			// printf("-\n");
		}
		n++;
	}
	if (flag == 0)
		printf("NO\n");
	else
	{
		print_all(print_c,a);
	}
	free(stack);
	free(print_c);
	return 0;
}
