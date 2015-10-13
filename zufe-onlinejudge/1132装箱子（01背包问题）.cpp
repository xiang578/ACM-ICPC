#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int a,b[25000],i,j,v,n;
    while (scanf("%d",&v)!=EOF)
    {
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        b[0]=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            for(j=v;j>=0;j--)
            if(j+a<=v&&b[j]) b[j+a]=1;
        }
        i=v;
        while(!b[i]&&i>0) i--;
        printf("%d\n",v-i);
    }
    return 0;
}
