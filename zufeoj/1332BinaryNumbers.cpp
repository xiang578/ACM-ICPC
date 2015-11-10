#include<stdio.h>
int main()
{
   int n,i,ans,cas;
   scanf("%d",&cas);
   while(cas--)
   {
   		scanf("%d",&n);
   		ans=0;
   		i=0;
   		while(n)
   		{
   			if(n%2==1)
            {
                if(ans==0) {printf("%d",i);ans++;}
                else printf(" %d",i);
            }
   			n=n/2;
   			i++;
   		}
   		printf("\n");
   }
    return 0;
}
