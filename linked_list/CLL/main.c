#include "list.h"
#include <stdio.h>

void print_CLL(t_linked_list *list);
int int_cmp(void *data1, void *data2);
void int_f(void *data);

int main()
{
	unsigned int count = 10;
	int *datas[10];
	int i;
	for (size_t i = 0; i < count; i++)
	{
		datas[i] = malloc(sizeof(int));
		*datas[i] = i;
	}

	t_linked_list *list_head;
	list_head = list_init();

	for (size_t i = 0; i < count; i++)
	{
		printf("%d\n",list_add(list_head,datas[i],i));

		print_CLL(list_head);
	}
	printf("-------------------------------------------\n");
	list_add(list_head, datas[0],-1);
	list_remove(list_head, -1, free);
	print_CLL(list_head);


	printf("-------------------------------------------\n");
	printf("list_size || size of list : %d\n", list_size(list_head));
	i = 2;
	if (NULL != (t_node *)list_get(list_head, i))
		printf("list_get || value of node : %d\n", *(int *)(list_get(list_head, i)->data));

	list_move_head_to_next(list_head);
	print_CLL(list_head);
	list_move_head_to_prev(list_head);
	print_CLL(list_head);

	printf("list_find || index : %d\n",list_find(list_head, datas[5], int_cmp));
	printf("-------------------------------------------\n");
	list_foreach(list_head, int_f);
	print_CLL(list_head);

	// list_clear(list_head,free);
	free_list(list_head, free);

	for (size_t i = 0; i < count; i++)
	{
		free(datas[i]);
	}
	printf("END");
}

void int_f(void *data)
{
	(*(int *)data)++;
}

int int_cmp(void *data1, void *data2)
{
	if (*(int *)data1 == *(int *)data2)
		return (0);
	else
		return (1);
}

void print_CLL(t_linked_list *list)
{
	t_linked_list *list_head = list;
	t_node *curr;
	curr = list_head->head;
	unsigned int i=0;
	unsigned int size;
	size = list_size(list);
	while (i < size)
	{
		printf("index : %d  data : %d\n",i,*(int *)(curr->data));
		curr = curr->next;
		i++;
	}
}
