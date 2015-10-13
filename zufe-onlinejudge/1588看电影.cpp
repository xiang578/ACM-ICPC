#include <stdio.h>
#include <stdlib.h>
struct
{
    int y;int x;
}d[120];

int compare(const void *a,const void *b)
{
    return  *(int*)a-*(int*)b;
}
int main()
{
    int n,i,j,t,p,a,b;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        int c=0,k=0;
        for(i=0;i<n;i++) scanf("%d",&d[i].x);
        for(i=0;i<n;i++) scanf("%d",&d[i].y);
        scanf("%d%d",&a,&b);
        t=0;p=b;
        qsort(d,n,sizeof(d[0]),compare);
        for(i=0;i<n;i++)
        {

            if((d[i].y<=a)&&(d[i].x>=t)){k++;t=d[i].y;}
            else if((d[i].x>=b)&&(d[i].x>=p)){c++;p=d[i].y;}
        }
        printf("%d\n",c+k);
    }
    return 0;
}
