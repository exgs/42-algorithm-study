#include "queue.h"

// 일부러 overflow 나게 해주기!

void print_queue(t_queue *queue)
{
	printf("queue->size : %d\n",queue_size(queue));
	if (queue_front(queue) == NULL)
		printf("queue->front : NULL (size = 0)\n");
	else
		printf("queue->front(data) : %s\n",(char *)queue_front(queue)->data);
}

int main()
{
	void *data;
	t_node *node;
	t_queue *queue;
	queue = queue_init();
	print_queue(queue);
	//pop overflow
	queue_pop(queue);
	print_queue(queue);
	
	printf("%d\n",queue_push(queue,strdup("abc")));
	printf("%d\n",queue_push(queue,strdup("1")));
	printf("%d\n",queue_push(queue,strdup("2bc")));
	printf("%d\n",queue_push(queue,strdup("3bc")));
	printf("%d\n",queue_push(queue,strdup("4bc")));
	printf("%d\n",queue_push(queue,strdup("5")));
	printf("%d\n",queue_push(queue,strdup("67554c")));
	printf("%d\n",queue_push(queue,strdup("74basdfasdfasdfasdc")));
	print_queue(queue);	
	
	for (size_t i = 0; i < 10; i++)
	{
		if (NULL == (node = queue_pop(queue)))
			printf("queue->pop : NULL\n");	
		else
		{
			printf("queue->pop : %s\n",node->data);
			free(node->data);
			free(node);
		}
	}
	
	queue_clear(queue, free);
	print_queue(queue);
	printf("===============================================\n");
	queue_push(queue,strdup("abc"));
	queue_push(queue,strdup("1"));
	queue_push(queue,strdup("2bc"));
	queue_push(queue,strdup("3bc"));
	queue_push(queue,strdup("4bc"));
	queue_push(queue,strdup("5"));
	queue_push(queue,strdup("67554c"));
	queue_push(queue,strdup("74basdfasdfasdfasdc"));
	
	for (size_t i = 0; i < 5; i++)
	{
		if (NULL == (node = queue_pop(queue)))
			printf("queue->pop : NULL\n");	
		else
		{
			printf("queue->pop : %s\n",node->data);
			free(node->data);
			free(node);
		}
	}
	print_queue(queue);
	queue_clear(queue, free);
	print_queue(queue);
	
	// queue_push(queue,strdup("67554c"));
	free_queue(queue,free);
	return 0;
}