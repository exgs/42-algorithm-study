#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char buffer[100];
	while(1)
	{
		gets(buffer);
		printf("%s\n",buffer);
	}
	return 0;
}