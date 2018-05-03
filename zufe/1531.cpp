#include<stdio.h>
int main()
{
    int a,b,d;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        d=a+b;
        int i,c=0,s[100];
        while(d!=0)
        {
            i=d%2;
            s[c]=i;
            c++;
            d=d/2;
        }
        for(;c>=1;c--)
	{
		printf("%d",s[c-1]);
	}
        printf("\n");
    }
    return 0;
}
