#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	char *value;
	scanf("%d",&n);
	value = malloc(sizeof(char) * (2*n));
	memset(value, 0 , 2*n);
	for (size_t i = 0; i < n; i++)
	{
		printf("%d\n", value[i]);
	}
	
	// printf()
}