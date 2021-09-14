#include <stdio.h>
#include <ctype.h>
char switchitdown(char letter);
int main()
{
	char letter;
	printf("Enter in letter\n");
	scanf("%c",&letter);
	char catch;
	printf("After the convertion\n");
	catch = switchitdown(letter);
	printf("%c \n",catch);
	
	return 0;
}
char switchitdown(char letter)
{
	char tmp;
	tmp = tolower(letter);
	return tmp;
}
