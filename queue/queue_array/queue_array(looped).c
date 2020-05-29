#include "queue_array(looped).h"

t_queue *queue_init(unsigned int max_size)
{
	if (max_size <= 0)
		return 0;
	t_queue *init;
	init =(t_queue *)malloc(sizeof(t_queue));
	init->max_size = max_size;
	init->first_index = 0; 
	init->last_index = 0;
	init->length =0;
	init->data = (void **)malloc(sizeof(void *) * max_size);
}

int queue_size(t_queue *queue)
{
	int size;
	if (queue == NULL)
		 return (-1);
	/* Don't have to use below paragraph
	// if (queue->first_index < queue->last_index)
	// 	size = (queue->first_index - queue->last_index);
	// else if(queue->first_index > queue->last_index)
	// 	size = queue->max_size - (queue->first_index - queue->last_index);
	// else if (queue->first_index == queue->last_index && queue->length != 0)
	// 	size = queue->max_size;
	// else if (queue->first_index == queue->last_index && queue->length == 0)
	// 	size = 0;
	// return (size);
	*/
	return (queue->length);
}
 
int queue_push(t_queue *queue, void *data)
{
	if (queue == NULL)
		return -1;
	if (queue_size(queue) >= queue->max_size)
		return 0;
	else
	{
		queue->data[queue->last_index] = data;
		queue->last_index++;
		queue->length++;
		if(queue->last_index == queue->max_size)
			queue->last_index = 0;
		return 1;
	}
}

void *queue_front(t_queue *queue)
{
	if (queue == NULL || queue_size(queue) <= 0)
		return (NULL);
	return(queue->data[queue->first_index]);
}


void *queue_pop(t_queue *queue)
{
	void *data;
	int i = 0;
	if (queue == NULL || queue_size(queue) <= 0)
		return (NULL);
	else
	{
		data = queue->data[queue->first_index];
		queue->first_index++;
		queue->length--;
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