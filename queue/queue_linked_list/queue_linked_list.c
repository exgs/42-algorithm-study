#include "queue.h"

t_queue *queue_init(void)
{
	t_queue *init;
	init = malloc(sizeof(t_queue));
	init->size = 0;
	init->head = NULL;
	init->tail = NULL;
	return (init);
}

t_node *create_elem(void *data)
{
	if (data == NULL)
		return (NULL);
	t_node *node;
	if (NULL == (node = malloc(sizeof(t_node))))
		return (NULL);
	node -> next = NULL;
	node -> data = data;
	return (node);
}

int queue_push(t_queue *queue, void *data)
{
	if (queue == NULL || data == NULL)
		return (0);
	t_node *tail;
	t_node *new_tail;
	if (NULL == (new_tail = create_elem(data)) )
		return (0);
	else
	{
		queue->size++;
		if (queue->tail == NULL) // 동치: queue->head == NULL 같이 진행함
		{
			queue->tail = new_tail;
			queue->head = new_tail;
			return (1);
		}
		else
		{
			tail = queue->tail;
			tail->next = new_tail;
			queue->tail = new_tail;
			return (1);
		}
	}
}

int queue_size(t_queue *queue)
{
	if (queue == NULL)
		return (-1);
	return (queue->size);
}

t_node *queue_front(t_queue *queue)
{
	if (queue == NULL || queue->size == 0)
		return (NULL);
	return (queue->head);
}

t_node *queue_pop(t_queue *queue)
{
	if (queue == NULL || queue->size == 0)
		return (NULL);
	t_node *head;
	queue->size--;
	// t_node *new_head;
	head = queue->head;
	if (head->next == NULL)
		queue->tail = NULL;
	queue->head = head->next;
	head->next = 0; //꺼낼 때, 다음 주소에 접근 못하게 초기화
	return(head);
}

void queue_clear(t_queue *queue, void (*free_data)(void *))
{
	if (queue == NULL || free_data == NULL || queue->size == 0)
		return ;
	t_node *node;
	t_node *temp;
	node = queue->head;
	while (node)
	{
		temp = node;
		free_data(temp->data);
		temp->data=0;
		free(temp);
		node = node->next;
	}
	queue->size = 0;
	queue->head = 0;
	queue->tail = 0;
}

void free_queue(t_queue *queue, void (*free_data)(void *))
{
	if (queue == NULL || free_data == NULL)
		return ;
	queue_clear(queue,free_data);
	free(queue);
}