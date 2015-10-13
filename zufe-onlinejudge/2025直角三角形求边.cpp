#include "stdio.h"
#include<math.h>
int main()
{
	int cnt=0,a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		cnt++;
		if(a==0) break;
		printf("Triangle #%d\n",cnt);
		if(a==-1)
        {
            if(c*c-b*b>0) printf("a = %.3f\n",sqrt((double)c*c-b*b));
            else printf("Impossible.\n");
        }
		if(b==-1)
            {
            if(c*c-a*a>0) printf("b = %.3f\n",sqrt((double)c*c-a*a));
            else printf("Impossible.\n");
        }
		if(c==-1) printf("c = %.3f\n",sqrt((double)b*b+a*a));
		printf("\n");
		}
	return 0;
}
