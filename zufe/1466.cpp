#include "stdio.h"
#include "string.h"
int main()
{
	char s1[100],s2[100],s3[100];
	scanf("%s %s %s",s1,s2,s3);
	int m1,m2,m3;

	if(strcmp(s1,s2)>0)
	{
		if(strcmp(s3,s1)>0) printf("%s\n%s\n%s\n",s2,s1,s3);
		else
		{
			if(strcmp(s3,s2)>0) printf("%s\n%s\n%s\n",s2,s3,s1);
			else printf("%s\n%s\n%s\n",s3,s2,s1);
		}
	}
	else
	{
		if(strcmp(s3,s2)>0) printf("%s\n%s\n%s\n",s1,s2,s3);
		else
		{
			if(strcmp(s3,s1)>0) printf("%s\n%s\n%s\n",s1,s3,s2);
			else printf("%s\n%s\n%s\n",s3,s1,s2);
		}

	}

	return 0;
}
