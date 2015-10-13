#include<stdio.h>
int main()
{
   int n,i,ans,cas;
   scanf("%d",&cas);
   while(cas--)
   {
   		int a[1024]={0};
   		scanf("%d",&n);
   		ans=0;
   		i=0;
   		while(n)
   		{
   			if(n%2==1) ans+=i;
   			n=n/2;
   			i++;
   		}
   		printf("%d\n",ans);
   }
    return 0;
}
