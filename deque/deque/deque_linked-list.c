#include "deque.h"

t_deque *deque_init(void)
{
	t_deque *init;
	if (NULL == (init = malloc(sizeof(t_deque))))
		return (NULL);
	init-> front = 0;
	init-> back = 0;	
	init-> size = 0;
	return (init);
}

t_node *create_elem(void *data)
{
	t_node *new_node;
	if (NULL == (new_node = malloc(sizeof(t_node))))
		return (NULL);
	new_node->data = data;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

int deque_push_front(t_deque *deque, void *data)
{
	if (deque == NULL)
		return (0);
	t_node *new_node;
	t_node *deque_front;
	new_node = create_elem(data);
	if (deque->size == 0)
	{
		deque->front = new_node;
		deque->back = new_node;
		deque->size++;
		return (1);
	}
	else if (deque->size > 0)
	{
		deque_front = deque->front;
		deque_front->prev = new_node;
		new_node->next = deque_front;
		deque->front = new_node;
		deque->size ++;
		return (1);
	}
	else //논리구조상 나올 수 없는 형태이지만, 처리해줌
	{
		return (0);
	}
}

int deque_push_back(t_deque *deque, void *data)
{
	if (deque == NULL)
		return (0);
	t_node *new_node;
	t_node *deque_back;
	new_node = create_elem(data);
	if (deque->size == 0)
	{
		deque->front = new_node;
		deque->back = new_node;
		deque->size++;
		return (1);
	}
	else if (deque->size > 0)
	{
		deque_back = deque->back;
		deque_back->next = new_node;
		new_node->prev = deque_back;
		deque->back = new_node;
		deque->size++;
		return (1);
	}
	else //논리구조상 나올 수 없는 형태이지만, 처리해줌
	{
		return (0);
	}
}

int deque_size(t_deque *deque)
{
	if (deque == NULL)
		return (-1);
	return (deque->size);
}

t_node *deque_front(t_deque *deque)
{
	if (deque == NULL)
		return (NULL);
	return (deque->front);
}

t_node *deque_back(t_deque *deque)
{
	if (deque == NULL)
		return (NULL);
	return (deque->back);
}

t_node *deque_pop_front(t_deque *deque)
{
	t_node *deque_front;
	if (deque == NULL)
		return (NULL);
	if (deque->size <= 0)
		return (NULL);
	else if (deque->size > 0)
	{
		deque_front = deque->front;
		deque->front = deque->front->next;
		if(deque->front != NULL)
			deque->front->prev = NULL;
		deque->size--;
		/*내외부*/
		deque_front->next = NULL;
		deque_front->prev = NULL;
		return (deque_front);
	}
}

t_node *deque_pop_back(t_deque *deque)
{
	t_node *deque_back;
	if (deque == NULL)
		return (NULL);
	if (deque->size <= 0)
		return (NULL);
	else if (deque->size > 0)
	{
		deque_back = deque->back;
		deque->back = deque->back->prev;
		if (deque->back != NULL) //연결시켜주는 작업
			deque->back->next = NULL;
		deque->size--;
		/*내외부*/
		deque_back->next = NULL;
		deque_back->prev = NULL;
		return (deque_back);
	}
}

void deque_clear(t_deque *deque, void (*free_data)(void *))
{
	if (deque == NULL || free_data == NULL || deque->size == 0)
		return ;
	t_node *deque_front;
	t_node *temp;
	deque_front = deque->front;
	for (size_t i = 0; i < deque->size; i++)
	{
		temp = deque_front;
		deque_front=deque_front->next;
		temp->prev = NULL;
		temp->next = NULL;
		free_data(temp->data);
		temp->data = NULL;
		free(temp);
	}
	deque->front = 0;
	deque->back = 0;
	deque->size = 0;
}

void free_deque(t_deque *deque, void (*free_data)(void *))
{
	if (deque == NULL || free_data == NULL)
		return ;
	deque_clear(deque, free);
	free(deque);
}