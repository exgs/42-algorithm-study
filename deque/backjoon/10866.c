#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_deque
{
	int data;
	struct s_deque *next;
	struct s_deque *prev;
}			t_deque;

typedef struct s_admin
{
	unsigned int size;
	t_deque *head;
	t_deque *tail;
}			t_admin;

void push_front(t_admin *admin, int x);
void push_first(t_admin *admin, int x);
void push_back(t_admin *admin, int x);
void pop_front(t_admin *admin);
void pop_back(t_admin *admin);
void free_deque(t_admin *admin);
void command(t_admin *admin, char buffer[30]);
t_admin *init_admin();
void size(t_admin *admin);
void empty(t_admin *admin);
void front(t_admin *admin);
void back(t_admin *admin);
/*
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
void push_front(t_admin *admin, int x)
{
	t_deque *node;
	if (admin->size == 0)
		push_first(admin, x);
	else
	{
		node = malloc(sizeof(t_deque));
		node->data = x;
		node->prev = NULL;
		node->next = admin->head;
		admin->head->prev = node;
		admin->head = node;
	}
	admin->size++;
}

void push_first(t_admin *admin, int x)
{
	t_deque *node;
	node = malloc(sizeof(t_deque));
	node->data = x;
	node->prev = NULL;
	node->next = NULL;
	admin->head = node;
	admin->tail = node;
}

void push_back(t_admin *admin, int x)
{
	t_deque *node;
	if (admin->size == 0)
		push_first(admin, x);
	else
	{
		node = malloc(sizeof(t_deque));
		node->data = x;
		node->next = NULL;
		admin->tail->next = node;
		node->prev = admin->tail;
		admin->tail = node;
	}
	admin->size++;
}

void pop_front(t_admin *admin)
{
	t_deque *deque;
	if (admin->size == 0)
	{
		printf("%d\n",-1);
		return ;
	}
	else
	{
		deque = admin->head;
		printf("%d\n",deque->data);
		if (admin->size == 1)
		{
			admin->head = NULL;
			admin->tail = NULL;
		}
		else
		{
			admin->head = deque->next;
			admin->head->prev = NULL;
		}
		deque->data = 0;
		deque->next = NULL;
		deque->prev = NULL;
		free(deque);
	}
	admin->size--;
	return ;
}

void pop_back(t_admin *admin)
{
	t_deque *deque;
	if (admin->size == 0)
	{
		printf("%d\n",-1);
		return ;
	}
	else
	{
		deque = admin->tail;
		printf("%d\n",deque->data);
		if (admin->size == 1)
		{
			admin->head = NULL;
			admin->tail = NULL;
		}
		else
		{
			admin->tail = deque->prev;
			admin->tail->next = NULL;
		}
		deque->data = 0;
		deque->next = NULL;
		deque->prev = NULL;
		free(deque);
	}
	admin->size--;
	return ;
}

void free_deque(t_admin *admin)
{
	t_deque *deque;
	t_deque *temp;
	deque = admin->head;
	temp = deque;
	for (size_t i = 0; i < admin->size; i++)
	{
		deque = deque->next;
		temp->data = 0;
		temp->next = NULL;
		temp->prev = NULL;
		free(temp);
		temp = deque;
	}
	admin->head = NULL;
	admin->tail = NULL;
	admin->size = 0;
	free(admin);
}

void command(t_admin *admin, char buffer[30])
{
	char buffer_num[8];
	
	if (!strncmp(buffer, "push_front",6))
	{
		scanf("%s",buffer_num);
		push_front(admin, atoi(buffer_num));
	}
	else if (!strncmp(buffer,"push_back",6))
	{
		scanf("%s",buffer_num);
		push_back(admin, atoi(buffer_num));
	}
	else if (!strncmp(buffer,"pop_front",5))
		pop_front(admin);
	else if (!strncmp(buffer,"pop_back",5))
		pop_back(admin);
	else if (!strncmp(buffer,"size",4))
		size(admin);
	else if (!strncmp(buffer,"empty",4))
		empty(admin);
	else if (!strncmp(buffer,"front",4))
		front(admin);
	else if (!strncmp(buffer,"back",4))
		back(admin);
}

t_admin *init_admin()
{
	t_admin *admin;
	admin = malloc(sizeof(t_admin));
	admin->head = NULL;
	admin->tail = NULL;
	admin->size =0;
	return (admin);	
}

void size(t_admin *admin)
{
	printf("%d\n",admin->size);
}

void empty(t_admin *admin)
{
	if (admin->size == 0)
		printf("%d\n",1);
	else
		printf("%d\n",0);
}

void front(t_admin *admin)
{
	if (admin->size == 0)
		printf("%d\n",-1);
	else
		printf("%d\n",admin->head->data);
}

void back(t_admin *admin)
{
	if (admin->size == 0)
		printf("%d\n",-1);
	else
		printf("%d\n",admin->tail->data);
}

int main()
{
	int count;
	char buffer[30];
	t_admin *admin; //함수에 계속 넣을꺼니깐
	admin = init_admin();
	
	scanf("%d",&count);
	for (size_t i = 0; i < count; i++)
	{
		scanf("%s",&buffer);
		command(admin,buffer);
	}
	
	free_deque(admin);
	return 0;
}