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
    int n,m,mp[128][128],u,v,i;
    while(~scanf("%d%d",&n,&m))
    {
        memset(mp,0,sizeof(mp));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            mp[u][v]=1;
        }
        if(mp[1][n]==1||mp[n][1]) printf("1 %d\n",n*(n-1)/2);
        else printf("1 1\n");
    }
    return 0;
}
