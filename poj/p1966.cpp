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
const int N=100+5;
const int inf=1<<24;
int g[N][N],n,m;
queue<int>Q;

int maxflow(int s,int t)
{
    int f[N][N],a[N],p[N],u,v,ans;
    memset(f,0,sizeof(f));
    ans=0;
    while(1)
    {
        memset(a,0,sizeof(a));
        memset(p,0xff,sizeof(p));
        while(!Q.empty()) Q.pop();
        Q.push(s);
        a[s]=inf;
        p[s]=-2;
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            for(v=0;v<2*n;v++)
            {
                if(p[v]==-1&&f[u][v]<g[u][v])
                {
                     p[v]=u;Q.push(v);
                    a[v]=min(a[u],g[u][v]-f[u][v]);
                }
            }

            if(p[t]!=-1)
            {
                v=t;
                while(p[v]>=0)
                {
                    u=p[v];
                    f[u][v]+=a[t];
                    f[v][u]-=a[t];
                    v=u;
                }
                break;
            }
        }
        if(p[t]==-1) return ans;
        else ans+=a[t];
    }
}

int main()
{
    int ans,u,v,i,j;
    while(~scanf("%d%d",&n,&m))
    {
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++) g[i][i+n]=1;
        for(i=0;i<m;i++)
        {
            scanf(" (%d,%d)",&u,&v);
            g[v+n][u]=g[u+n][v]=inf;
        }
        ans=inf;
        for(i=1;i<n;i++)
            ans=min(maxflow(0+n,i),ans);
        if(ans==inf) ans=n;
        printf("%d\n",ans);
    }
    return 0;
}
