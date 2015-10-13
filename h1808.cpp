#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int a[100000+5],f[100000+5];
int main()
{
    int i,j,c,n,sum,t,st;
    while(~scanf("%d%d",&c,&n))
    {
        if(c==0&&n==0) break;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(f,0xff,sizeof(f));
        st=0;
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=a[i];
            t=sum%c;
            sum=sum%c;
            if(t==0)
            {
                for(j=1;j<i;j++)
                    printf("%d ",j);
                printf("%d\n",j);
                break;
            }
            else if(f[t]!=-1)
            {
                for(j=f[t]+1;j<i;j++)
                    printf("%d ",j);
                printf("%d\n",j);
                break;
            }
            f[t]=i;
        }
    }
    return 0;
}
