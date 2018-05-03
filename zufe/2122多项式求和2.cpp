#include<stdio.h>
int main()
{
   int n,i,a,b;
   double ans;
   while(~scanf("%d",&n))
   {
   		if(n==0) break;
   		a=2;b=1;
   		ans=0;
   		for(i=1;i<=n;i++)
   		{
   			ans+=1.0*a/b;
   			a+=b;
   			b=a-b;
   		}
   		printf("%.3f\n",ans );

   }
    return 0;
}
