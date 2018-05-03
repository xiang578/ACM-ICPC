#include<stdio.h>
int main()
{
	int a,b,i,c;
	while (~scanf("%d",&a))
    {
	while(a--)
	{
		scanf("%d",&b);
		c=0;
		for(i=1;i<=b;i++)
		{
			if(i*i<=b) c++;
		}
		printf("%d\n",c);
	}
}
	return 0;
}
