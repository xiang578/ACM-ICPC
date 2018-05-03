#include "stdio.h"
#include "string.h"
int main()
{
	char s[100];
	while(gets(s))
	{
		if(strcmp(s,"accept")==0||strcmp(s,"Accept")==0)
			printf("send a balloon.\n");
		else printf("try again.\n");
	}
	return 0;
}
