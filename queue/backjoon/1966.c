#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	int index;
	int data;
	struct s_node *next;
}			t_node;

void queue_free(t_node *init)
{
	t_node *temp;
	while (init)
	{
		temp = init;
		init= init->next;
		free(temp);
	}
	init = NULL;
}

t_node *queue_room(int count)
{
	t_node *init;
	t_node *node;
	t_node *temp;
	init = malloc(sizeof(t_node)); //초항
	init->next = NULL;
	init->index = 0;
	temp = init;
	// init->data = 0;
	for (size_t i = 1; i < count; i++)
	{
		node = malloc(sizeof(t_node));
		node->next = NULL;
		node->index = i; //index data 넣어줌
		temp->next = node;
		temp = node;
	}
	return (init);
}

t_node *queue_get(t_node *head)
{
	if (head == NULL)
		return (0);
	t_node * return_head;
	return_head = head;
	/*return_head->next = NULL;*/ // main에서 쓸꺼임
	// head = head->next; //main에 영향을 주지못한다.
	return(return_head);
}

void queue_put(t_node *head, t_node *tail)
{
	if(tail == NULL)
		return ;
	t_node *temp;
	temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = tail;
	tail->next = NULL;
}

int top_data(t_node *head)
{
	int max = 0 ;
	t_node *temp = head;
	max = head->data;
	while (temp)
	{
		if(temp->data > max)
			max = temp->data;
		temp = temp->next;
		// printf("-------\n");
	}
	return (max);
}

int main()
{
	int count;
	int n;
	int m;
	int input;
	int count2 = 1;
	t_node *init;
	t_node *temp;
	t_node *head;
	scanf("%d",&count);
	for (size_t i = 0; i < count; i++)
	{
		scanf("%d",&n); // 인쇄물 갯수
		scanf("%d",&m); // 인쇄물의 index
		init = queue_room(n);
		temp = init;
		for (size_t i = 0; i < n; i++)
		{
			scanf("%d",&input); // input 중요도 data
			temp->data = input;
			temp = temp->next;
		}
		temp = NULL;
		head = init;
		// printf("head->index : %d  head->data : %d   top_data(head) : %d\n", head->index, head->data, top_data(head));
		while ( !(head->index == m && head->data >= top_data(head)))
		{
			if (head->data >= top_data(head))
			{
				temp = queue_get(head);
				head = temp->next;
				temp->next = NULL;
				free(temp); //실행과 동시에 free
				count2++;
				// printf("head->index : %d  head->data : %d   top_data(head) : %d\n", head->index, head->data, top_data(head));
			}
			else if(head->data < top_data(head))
			{
				temp = queue_get(head);
				head = temp->next;
				queue_put(head, temp);
				// printf("000000\n");
			}
		}
		printf("%d\n",count2);
		count2 = 1;
	}
}