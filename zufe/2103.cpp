#include<stdio.h>
int main()
{
    int m,n,i,t;
    while(~scanf("%d %d",&n,&m))
    {
    	t=0;
        if(m%4!=0) t=0;
        else
        {
        	m=m/4;
        	i=n-m;
        	if(i>=0&&m-i>=0) t=1;
        }
        if(t==0) printf("NO\n");
        else printf("%d %d\n",m-i,i );
    }
    return 0;
}
