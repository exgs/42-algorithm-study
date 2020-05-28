#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size_check(char *buffer)
{
	int i = 0;
	while (buffer[i])
	{
		i++;
	}
	return (i);
}

int valid_check(char *buffer)
{
	int sum = 0;
	int i = 0;
	while (i < size_check(buffer))
	{
		if (buffer[i] == '(')
			sum++;
		else if (buffer[i] == ')')
			sum--;
		if (sum < 0)
			return (0);
		i++;
	}
	if (sum == 0)
		return (1);
	else
		return (0);
}

int main(void) // "(" 가 양수, ")"가 음수
{
	int count;
	char buffer[50];
	int size;
	scanf("%d",&count);
	memset(buffer,0,50);
	for (size_t i = 0; i < count; i++)
	{
		scanf("%s",buffer);
		size = size_check(buffer);
		if (!(size >= 2 && size <= 50))
			return 0;
		if (valid_check(buffer) == 1)
			printf("YES\n");
		else if (valid_check(buffer)==0)
			printf("NO\n");
		memset(buffer,0,50);
	}
	return (0);
}