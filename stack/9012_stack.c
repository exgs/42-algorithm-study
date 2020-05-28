#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <string.h>

typedef struct	s_node
{
	void		*data;
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

t_node *create_elem(void *data)
{
	t_node *new_elem;
	new_elem = malloc(sizeof(t_node));

	if (new_elem == NULL) //이미 push에서 검증한 사례라서 걸리지않음
		return 0;
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

int stack_push(t_stack *stack, void *data)
{
	t_node *push_elem;

	if (stack == NULL)
		return 0;
	stack->size++;
	push_elem = create_elem(data);
	push_elem->next = stack->top;
	stack->top = push_elem;
	return (1);
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

int stack_pop(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	t_node *pop_elem;
	if (NULL == (pop_elem = stack->top))
		return -1;
	stack->top = pop_elem->next;
	stack->size--;
	pop_elem->next = NULL;
	return (1);
}

void stack_clear(t_stack *stack, void (*free_data)(void *))
{
	t_node *curr_elem;
	t_node *temp_elem;

	if (stack == NULL || free_data == NULL)
		return ;
	if (NULL == (curr_elem = stack->top))
		return ;
	// for (unsigned int i = (stack->size); i > 0; i--)
	while(curr_elem)
	{
		temp_elem = curr_elem->next;
		free_data(curr_elem->data);
		free(curr_elem);
		curr_elem = temp_elem;
	}
	stack->top = 0; //청소 사용한공간은 모두
	stack->size = 0; //청소 사용한공간은 모두
}

void free_stack(t_stack *stack, void (*free_data)(void *))
{
	stack_clear(stack, free_data);
	free(stack);
	return ;
}

int size_check(char *buffer)
{
	int i = 0;
	while (buffer[i])
	{
		i++;
	}
	return (i);
}

int main(void) // "(" 가 양수, ")"가 음수
{
	int count;
	char buffer[50];
	int size;
	int flag = 0;
	t_stack *stack = stack_init();
	scanf("%d",&count);
	memset(buffer,0,50);
	for (size_t i = 0; i < count; i++)
	{
		scanf("%s",buffer);
		size = size_check(buffer);
		if (!(size >= 2 && size <= 50))
			return 0;
		for (size_t i = 0; i < size; i++)
		{
			if (buffer[i] == '(')
				stack_push(stack,NULL);
			else if (buffer[i] == ')')
				if(stack_pop(stack) == -1)
				{
					flag = 1;
					printf("NO\n");
					break;
				}
		}
		if (stack->size == 0 && flag == 0)
		{
			printf("YES\n");
		}
		else if (stack->size != 0 && flag == 0)
		{
			printf("NO\n");
		}
		flag = 0;
		stack_clear(stack,free);
		memset(buffer,0,50);
	}
	
	free_stack(stack,free);
	return (0);
}