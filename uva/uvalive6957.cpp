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

int main()
{
    int i,a,b,n,m[10000+5][2],p[10000+5],tot;
    while(~scanf("%d",&n))
    {
        memset(m,0,sizeof(m));
        memset(p,0,sizeof(p));
        tot=0;
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            if(p[a]<2&&p[b]<2)
            {
                m[a][p[a]]=m[b][p[b]]=++tot;
                p[a]++;
                p[b]++;
            }
            else if(p[a]==2)
            {
                m[b][p[b]]=m[a][1];
                p[b]++;
            }
            else if(p[b]==2)
            {
                m[a][p[a]]=m[b][1];
                p[a]++;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(m[i][0]==0) m[i][0]=++tot;
            if(m[i][1]==0) m[i][1]=++tot;
        }
        for(i=1;i<=n;i++)
            printf("%d %d\n",m[i][0],m[i][1]);
    }
    return 0;
}
