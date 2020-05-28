#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void char_print_buffer(char *buffer)
{
	for (size_t i = 0; i < 100; i++)
	{
		printf("%c",buffer[i]);
	}
	return ;
}

int check_small_parentheses(char c)
{
	if ( !(c == '(' || c == ')') )
		return (0);
	else if(c == '(')
		return (1);
	else if(c == ')')
		return (2);
}

int check_big_parentheses(char c)
{
	if ( !(c == '[' || c == ']') )
		return (0);
	else if(c == '[')
		return (1);
	else if(c == ']')
		return (2);
}

void change_buffer(char *buffer)
{
	int r = 0; //read_index
	int w = 0; //write_index
	while (buffer[r])
	{
		if (check_small_parentheses(buffer[r]) || check_big_parentheses(buffer[r]))
		{
			buffer[w] = buffer[r];
			w++;
		}
		r++;
	}
	while (w < r)
	{
		buffer[w] = 0;
		w++;
	}
}

typedef struct	s_node
{
	char			data;
	struct s_node	*next;
}		t_node;

typedef struct	s_stack
{
	unsigned int	size;
	t_node		*top;
}		t_stack;

t_stack *stack_init(void)
{
	t_stack *new_stack;
	new_stack = malloc(sizeof(t_stack));
	new_stack->size = 0;
	new_stack->top = NULL;
	return (new_stack);
}

t_node *create_elem(char c)
{
	t_node *new_elem;
	new_elem = malloc(sizeof(t_node));

	if (new_elem == NULL) //이미 push에서 검증한 사례라서 걸리지않음
		return 0;
	new_elem->data = c;
	new_elem->next = NULL;
	return (new_elem);
}

void stack_push(t_stack *stack, char c)
{
	t_node *push_elem;

	if (stack == NULL)
		return ;
	stack->size++;
	push_elem = create_elem(c);
	push_elem->next = stack->top;
	stack->top = push_elem;
	return ;
}

int stack_size(t_stack *stack)
{
	if (stack == NULL)
		return (-1);
	return (stack->size);
}

t_node *stack_peek(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	return (stack->top);
}

char stack_pop(t_stack *stack)
{
	char c;
	if (stack == NULL)
		return (0);
	t_node *pop_elem;
	if (NULL == (pop_elem = stack->top))
		return 0;
	stack->top = pop_elem->next;
	stack->size--;
	pop_elem->next = NULL;
	c = pop_elem->data;
	free(pop_elem);
	return (c);
}

void stack_clear(t_stack *stack)
{
	t_node *curr_elem;
	t_node *temp_elem;

	if (stack == NULL)
		return ;
	if (NULL == (curr_elem = stack->top))
		return ;
	// for (unsigned int i = (stack->size); i > 0; i--)
	while(curr_elem)
	{
		temp_elem = curr_elem->next;
		free(curr_elem);
		curr_elem = temp_elem;
	}
	stack->top = 0; //청소 사용한공간은 모두
	stack->size = 0; //청소 사용한공간은 모두
}

void free_stack(t_stack *stack)
{
	stack_clear(stack);
	free(stack);
	return ;
}

int validation_stack(t_stack *stack, char *buffer)
{
	int r = 0;
	while (buffer[r])
	{
		if (buffer[r]=='(' || buffer[r] == '[')
		{
			stack_push(stack, buffer[r]);
		}
		else if (buffer[r]==')')
		{
			if ( '(' != stack_pop(stack))
				return (0);
		}
		else if (buffer[r] == ']')
		{
			if( '[' != stack_pop(stack))
				return (0);
		}
		r++;
	}
	if (stack->size == 0)
	{
		return (1);
	}
	else
		return (0);
}

int main(void)
{
	// char buffer[100];
	// memset(buffer,0,100);
	char *buffer = NULL;
	size_t n = 100;
	t_stack *stack;
	stack = stack_init();
	while (1)
	{
		// scanf("%[^"\n"]s",buffer); //띄어쓰기까지 가져와야하기때문에
		getline(&buffer, &n, stdin);
		// gets(buffer);
		if(buffer[0] == '.')
			return 0;
		// printf("%s\n",buffer);
		change_buffer(buffer);
		if (validation_stack(stack, buffer))
			printf("yes\n");
		else
			printf("no\n");
		
		// memset(buffer,0,100);
		stack_clear(stack);
		free(buffer);
		buffer = NULL;
	}
	free_stack(stack);

	return 0;	
}