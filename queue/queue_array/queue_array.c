#include "queue_array.h"
 
t_queue *queue_init(unsigned int max_size)
{
	if (max_size <= 0)
		return 0;
	t_queue *init;
	init =(t_queue *)malloc(sizeof(t_queue));
	init->max_size = max_size;
	init->last_index = -1; //last_index는 값이 있는 데이터의 index를 가리키는 것으로 한다.
	init->data = (void **)malloc(sizeof(void *) * max_size);
}

int queue_size(t_queue *queue)
{
	 if (queue == NULL)
		 return (-1);
	 return(queue->last_index + 1);
}
 
int queue_push(t_queue *queue, void *data)
{
	if (queue == NULL)
		return -1;
	if (queue_size(queue) >= queue->max_size)
		return 0;		
	else
	{
		queue->last_index++;
		queue->data[queue->last_index] = data;
		return 1;
	}
}

void *queue_front(t_queue *queue)
{
	if (queue == NULL || queue_size(queue) <= 0)
		return (NULL);
	return(queue->data[0]);
}


void *queue_pop(t_queue *queue)
{
	void *data;
	int i = 0;
	if (queue == NULL || queue_size(queue) <= 0)
		return (NULL);
	else
	{
		data = queue->data[0];
		queue->last_index--;
		while (i < queue_size(queue))
		{
			queue->data[i] = queue->data[i + 1];
			i++;
		}
		return (data);
	}
}

void queue_clear(t_queue *queue, void (*free_data)(void *))
{
	if(queue == NULL || free_data == NULL)
		return;
	for (size_t i = 0; i < queue_size(queue); i++)
	{
		free_data(queue->data[i]);
		queue->data[i] = 0;
	}
	queue->last_index = -1;
}

void free_queue(t_queue *queue, void (*free_data)(void *))
{
	if(queue == NULL || free_data == NULL)
		return;
	queue_clear(queue, free_data);
	free(queue);
	queue = 0;
}