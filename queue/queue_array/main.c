#include "queue_array.h"

void print_queue(t_queue *queue)
{
	printf("------------------------------------------\n");
	if(queue == NULL)
	{
		printf("queue == NULL\n");
		printf("------------------------------------------\n");
		return ;
	}
	else if(queue->last_index == -1)
	{
		printf("queue has no data\n");
		printf("------------------------------------------\n");
		return ;
	}
	printf("queue->size : %d\n",queue_size(queue));
	printf("queue->front : %s\n",(char *)queue_front(queue));
	for (size_t i = 0; i < queue_size(queue); i++)
	{
		printf("queue->data : %s\n", queue->data[i]);
	}
	
	printf("------------------------------------------\n");
}


int main()
{
	int n = 10;
	int i = 0;
	char *str;
	void *data;
	t_queue *queue;
	queue = queue_init(n);
	print_queue(queue);
	for(size_t i = 0; i < n + 10; i++)
	{
		printf("queue_push(%d) = %d\n",i,queue_push(queue, strdup("abc")) );
	}
	print_queue(queue);
	queue_clear(queue, free);
	printf("----------queue_push-----------------------\n");
	print_queue(queue);
	
	i = 0;
	printf("queue_push(%d) = %d\n",i++,queue_push(queue, strdup("abc")) );
	printf("queue_push(%d) = %d\n",i++,queue_push(queue, strdup("ac")) );
	printf("queue_push(%d) = %d\n",i++,queue_push(queue, strdup("axxbc")) );
	printf("queue_push(%d) = %d\n",i++,queue_push(queue, strdup("abzzc")) );
	printf("queue_push(%d) = %d\n",i++,queue_push(queue, strdup("aqqwc")) );
	printf("queue_push(%d) = %d\n",i++,queue_push(queue, strdup("1")) );
	printf("queue_push(%d) = %d\n",i++,queue_push(queue, strdup("a22")) );
	printf("queue_push(%d) = %d\n",i++,queue_push(queue, strdup("a33wc")) );
	print_queue(queue);
	printf("pop-------------------------------------------------\n");
	printf("%queue_pop(%d) = %s\n",i--, (char *)(data = queue_pop(queue)));
	free(data); data = 0;
	printf("%queue_pop(%d) = %s\n",i--, (char *)(data = queue_pop(queue)));
	free(data); data = 0;
	printf("%queue_pop(%d) = %s\n",i--, (char *)(data = queue_pop(queue)));
	free(data); data = 0;
	printf("%queue_pop(%d) = %s\n",i--, (char *)(data = queue_pop(queue)));
	free(data); data = 0;
	printf("%queue_pop(%d) = %s\n",i--, (char *)(data = queue_pop(queue)));
	free(data); data = 0;
	printf("%queue_pop(%d) = %s\n",i--, (char *)(data = queue_pop(queue)));
	free(data); data = 0;
	print_queue(queue);
	
	
	
	
	
	
	free_queue(queue, free);
}

// t_queue *queue_init(unsigned int max_size);
// int queue_size(t_queue *queue);
// int queue_push(t_queue *queue, void *data);
// void *queue_front(t_queue *queue);
// void *queue_pop(t_queue *queue);
// void queue_clear(t_queue *queue, void (*free_data)(void *));
// void free_queue(t_queue *queue, void (*free_data)(void *));