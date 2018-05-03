#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int t,a,b,c,i;
    while(~scanf("%d%d",&b,&c))
    {
        for(i=b;;i++)
        {
            if(i%b==0&&i%c==0) break;
        }
        printf("%d\n",i);
    }
    return 0;
}
