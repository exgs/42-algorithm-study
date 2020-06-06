#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_circle
{
	int data;
	struct s_circle *next;
	struct s_circle *prev;
}				t_circle;

t_circle *init_circle_linked_list(int size)
{
	t_circle *head;
	t_circle *node;
	t_circle *temp;
	head = malloc(sizeof(t_circle));
	head->data = 1;
	head->prev = NULL;
	head->next = NULL;
	temp = head;
	for (size_t i = 0; i < size-1; i++)
	{
		node = malloc(sizeof(t_circle));
		node->data = i + 2;
		node->next = NULL;
		node->prev = temp;
		temp->next = node;
		temp = temp->next;
	}
	head->prev = temp;
	temp->next = head;
	return (head);
}

void print_circle_linked_list(t_circle *head, int count)
{
	t_circle *temp;
	temp = head;
	for (size_t i = 0; i < count; i++)
	{
		printf("data : %d\n", temp->data);
		temp = temp->next;
	}
}

int index_circle_linked_list(t_circle **above_head, int search)
{
	t_circle *head;
	head = *above_head;
	int index = 0;
	t_circle *prev_head;
	prev_head = head;
	// printf("head->data : %d\n",head->data);
	// printf("search : %d\n",search);
	while (head->data != search)
	{
		index++;
		prev_head = head;
		head = head->next;
	}
	if (index == 0)
	{
		prev_head = head->prev;
		prev_head->next = head->next;
		head->next->prev = prev_head;
		*above_head = head->next;
		free(head);
	}
	else
	{
		prev_head->next = head->next;
		head->next->prev = prev_head;
		*above_head = head->next;
		free(head);
	}
	return (index);
}

int main()
{
	t_circle *head;
	int size;
	int count;
	int total = 0;
	scanf("%d",&size);
	scanf("%d",&count);
	int search;
	int index;
	
	
	head = init_circle_linked_list(size);
	// print_circle_linked_list(head,size);
	// 지금까지 세팅
	
	for (size_t i = 0; i < count; i++)
	{
		scanf("%d",&search);
		index = index_circle_linked_list(&head,search); // i >= size - i  (= i >= size/2)
		// printf("total ++ : %d\n",index);
		if (index <= size - index)
			total += index;
		else
			total += (size - index);
		size--;
	}
	printf("%d\n",total);
	return 0;
}