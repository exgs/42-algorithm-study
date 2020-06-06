#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char direction = 1;

void strtrim(char *str)
{
	unsigned int i = 0;
	while (str[i])
	{
		i++;
	}
	str[i-1] = '\0';
}

void reverse_array(char * array, int array_size)
{
	int count;
	char temp;
	if (array_size <= 0)
		return ;
	count = array_size/2;
	for (size_t i = 0; i < count; i++)
	{
		temp = array[i];
		array[i] = array[array_size -1 -i];
		array[array_size -1 -i] = temp;
	}
}

void remove_array(char * array, int array_size , char direction)
{
	if (array_size <= 0)
		return ;
	if (direction == 1)
	{
		for (size_t i = 0; i < array_size; i++)//
		{
			array[i] = array[i+1];
		}
	}
	else if (direction == -1)
		array[array_size - 1] = 0;
}

int main()
{
	int count; // <=100
	int array_size;
	char p[100001]; //R or D
	char *array;
	char *buffer_array;
	char *split;
	int j;
	scanf("%d",&count);
	for (size_t i = 0; i < count; i++)
	{
		direction = 1;
		scanf("%s",p);
		scanf("%d",&array_size);
		array = malloc(sizeof(char) * array_size + 1); //마지막에 0값을 넣어놓자
		array[array_size] = '\0';
		// memset(array,0,array_size);
		buffer_array = malloc(sizeof(char) * (array_size * 4 + 2));
		scanf("%s",buffer_array);
		strtrim(buffer_array);
		buffer_array++;
		if (array_size == 1)
		{
			array[0] = (char)atoi(buffer_array);
		}
		else
		{
			split = strtok(buffer_array, ",");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환
			for (size_t i = 0; i < array_size; i++)
			{
				array[i] = (char)atoi(split);
				// printf("%d\n", array[i]);
				split = strtok(NULL, ",");      // 다음 문자열을 잘라서 포인터를 반환
			}
		}
		j = 0;
		while (p[j])
		{
			if (p[j] == 'R')
			{
				direction *= -1;
			}
			else
			{
				remove_array(array,array_size,direction);
				array_size--;
				if (array_size < 0)
					break;
			}
			j++;
		}
		j = 0;
		if (array_size < 0)
			printf("error\n");
		else if (array_size ==0)
			printf("[]\n");
		else if (direction == 1)
		{
			printf("[");
			for (size_t i = 0; i < array_size -1; i++)
			{
				printf("%d,",array[i]);
			}
			printf("%d",array[array_size - 1]);
			printf("]\n");
		}
		else if (direction == -1)
		{
			printf("[");
			for (size_t i = 0; i < array_size -1; i++)
			{
				printf("%d,",array[array_size -1 - i]);
			}
			printf("%d",array[0]);
			printf("]\n");
		}
		free(--buffer_array);
		free(array);
	}
	return 0;
}