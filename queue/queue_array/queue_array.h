#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct	s_queue
 {
 	unsigned int	max_size;
 	int		last_index;
 	void		**data;
 }		t_queue;
 
t_queue *queue_init(unsigned int max_size);
int queue_size(t_queue *queue);
int queue_push(t_queue *queue, void *data);
void *queue_front(t_queue *queue);
void *queue_pop(t_queue *queue);
void queue_clear(t_queue *queue, void (*free_data)(void *));
void free_queue(t_queue *queue, void (*free_data)(void *));