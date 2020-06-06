#include "deque.h"

void print_deque(t_deque *deque)
{
	t_node *head;
	t_node *tail;
	head = deque->front;
	tail = deque->back;
	if (deque->size <= 0)
		printf("NO node.\n");
	else
		printf("front : %d || back : %d || size : %d \n", *(int *)head->data, *(int *)(tail->data), deque->size);
}

int main()
{
	int count = 100;
	unsigned int i = 0;
	int a[100];
	while (i < 100)
	{
		a[i] = i;
		i++;
	}
	i = 0;
	t_node *node;
	t_deque *deque;
	deque = deque_init();
	print_deque(deque);
	for (size_t j = 0; j < count; j++)
	{
		if (j % 2 == 0)
			printf("Does push success  = %d\n",deque_push_front(deque,&a[j]));
		else
			printf("Does push success  = %d\n",deque_push_back(deque,&a[j]));
	}
	print_deque(deque);
	deque_clear(deque,free);
	print_deque(deque);
	for (size_t j = 0; j < count; j++)
	{
		if (j % 2 == 0)
			printf("Does push success  = %d\n",deque_push_front(deque,&a[j]));
		else
			printf("Does push success  = %d\n",deque_push_back(deque,&a[j]));
	}
	print_deque(deque);
	for (size_t i = 0; i < count/2; i++)
	{
		if(NULL !=(node = deque_pop_back(deque)))
			printf("back(1) node->data : %d\n",*(int *)node->data);
		else
			printf("pop NULL\n");
	}
	print_deque(deque);
	for (size_t i = 0; i < count/2+10; i++)
	{
		if(NULL !=(node = deque_pop_front(deque)))
			printf("front(2) node->data : %d\n",*(int *)node->data);
		else
			printf("pop NULL\n");
		print_deque(deque);
	}
	printf("--------------------------------------\n");
	print_deque(deque);
	
}