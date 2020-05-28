#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	float max;
	float avg = 0;
	int i = 0;
	scanf("%d",&N);
	// int *grade;
	// grade= malloc(sizeof(int)* N);
	int grade[N];// 가변인자배열
	while (i< N)
	{
		scanf("%d", &grade[i]);
		i++;
	}
	max = grade[0];
	for (i = 0; i < N - 1; i++)
	{
		if (max < grade[i + 1])
			max = grade[i + 1];
	}
	for (i = 0; i < N; i++)
		avg += grade[i] / max * 100;
	avg /= N;
	free(grade);
	printf("%f", avg);
	return 0;
}