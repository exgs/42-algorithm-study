#include "list.h"

t_linked_list *list_init(void)
{
	t_linked_list *new;

	if (NULL == (t_linked_list *)malloc(sizeof(t_linked_list) * 1 ))
		return (NULL);
	new->size = 0;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}
t_node *create_elem(int data)
{
	t_node *new;

	if (NULL == (new = (t_node *)malloc(sizeof(t_node) * 1)))
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
int list_size(t_linked_list *list)
{
	if (list == NULL)
		return (0);
	int size = 0;
	t_node *curr = list->head;
	while (curr != NULL)
	{
		curr = curr->next;
		size++;
	}
	return (size);
}
t_node *list_get(t_linked_list *list, int n)
{
	int i = 0;
	t_node *curr = list->head;
	if (list_size(list) <= n || n < 0 || list == NULL) // n == list_size(list)이면 ->next = NULL;
		return (NULL);
	while (i < n) // n < list_size(list) 인 경우만 존재
	{
		curr = curr->next;
		i++;
	}
	return (curr);
}
int list_add(t_linked_list *list, int data, int n)
{
	t_node *prev;
	t_node *next;
	t_node *new;
	if (list_size(list) <= n)
	{
		//조건문 내에 선언이 있어도되나???
		new = create_elem(data);
		prev = list_get(list,list_size(list) - 1);
		prev->next = new;
		new->prev = prev;
		return (list_size(list));
	}
	prev = list_get(list,(n-1));
	next = list_get(list,(n));
	new = create_elem(data);
	new->next = prev->next;
	new->prev = prev;
	prev->next = new;
	next->prev = new;
	return (n);
}
int list_remove(t_linked_list *list, int n)
{
	t_node *prev;
	t_node *next;

	if (list_size(list) < n)
		return (0);
	prev = list_get(list, n - 1);
	free(prev->next);
	prev->next = next;
	next->prev = prev;
	return (1);
}
void list_clear(t_linked_list *list)
{
	t_node *curr;
	t_node *temp;
	curr = list->tail;
	temp = curr;
	while (curr)
	{
		curr = curr->next;
		free(temp);
		temp = curr;
	}
}
void free_list(t_linked_list *list)
{
	list_clear(list);
	free(list);
}