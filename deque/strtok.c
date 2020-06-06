#include <stdio.h>
#include <string.h>    // strtok 함수가 선언된 헤더 파일

void strtrim(char *str)
{
	unsigned int i = 0;
	while (str[i])
	{
		i++;
	}
	str[i - 1] = '\0';
}

int main()
{
    char s1[30] = "[1,3,34,123,35,12]";  // 크기가 30인 char형 배열을 선언하고 문자열 할당
	strtrim(s1);
    char *ptr = strtok(&s1[1], ",");      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환

    while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
    {
        printf("%s\n", ptr);          // 자른 문자열 출력
        ptr = strtok(NULL, ",");      // 다음 문자열을 잘라서 포인터를 반환
    }

    return 0;
}