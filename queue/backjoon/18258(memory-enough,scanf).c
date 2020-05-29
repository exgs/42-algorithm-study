#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int g_head = 0; //초기화 가능
unsigned int g_tail = 0;
/*
push X: 정수 X를 큐에 넣는 연산이다.
1<=N<=100,000
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

void push(int *array, int x) //tail은 현재 채워넣어야하는 위치(현재 0)
{
	array[g_tail]=x;
	g_tail++;
}
void pop(int *array)
{
	if(g_head == g_tail)
	{
		printf("%d\n",-1);
		return; 
	}
	else
	{
		printf("%d\n",array[g_head]);
		g_head++;
	}
}
void size(int *array)
{
	printf("%d\n", (g_tail-g_head) );
}
void empty(int *array)
{
	printf("%d\n",(g_tail == g_head) ? 1 : 0);
}
void front(int *array)
{
	if (g_head == g_tail)
		printf("%d\n",-1);
	else
		printf("%d\n",array[g_head]);
}

void back(int *array)
{
	if (g_head == g_tail)
		printf("%d\n",-1);
	else
		printf("%d\n",array[(g_tail - 1)]); //g_tail == 0 인 경우는 처음 시작 밖에 없으므로 g_head == g_tail에서 걸러짐.
}

void command(int *array, char *str)
{
	int temp;
	//gets랑 scanf()를 번갈아가면쓰면, 안되겠지?
	//이미 "push 2" 숫자까지 같이 받은 상태
	if (!strncmp("pu",str,2))
	{
		scanf("%d",&temp);
		push(array,temp);
	}
	else if(!strncmp("po",str,2))
		pop(array);
	else if(!strncmp("si",str,2))
		size(array);
	else if(!strncmp("em",str,2))
		empty(array);
	else if(!strncmp("fr",str,2))
		front(array);
	else if(!strncmp("ba",str,2))
		back(array);
	return ;
}

void array_zero(int * array, int count)
{
	for (size_t i = 0; i < count; i++)
	{
		array[i] = 0;
	}
}

int main()
{
	int count;
	char buffer[10];
	scanf("%d",&count);
	int *array;
	// int array[2000000]; //int array[2,000,000]을 넣으면 실행이안됨.
	array = malloc(sizeof(int) * count);
	array_zero(array, count);
	
	// memset(buffer,0,10);
	for (size_t i = 0; i < count; i++)
	{
		scanf("%s",buffer);
		command(array,buffer);
	}
	free(array);
	return 0;
}