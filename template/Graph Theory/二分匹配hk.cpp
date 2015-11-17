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
const int MAXN=3000+5;
const int INF=1<<28;
int g[MAXN][MAXN],Mx[MAXN],My[MAXN],Nx,Ny;
int dx[MAXN],dy[MAXN],dis;
bool vst[MAXN];

bool searchP()
{
    queue<int>Q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=1;i<=Nx;i++)
        if(Mx[i]==-1)
        {
            Q.push(i);
            dx[i]=0;
        }
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        if(dx[u]>dis)  break;
        for(int v=1;v<=Ny;v++)
            if(g[u][v]&&dy[v]==-1)
            {
                dy[v]=dx[u]+1;
                if(My[v]==-1)  dis=dy[v];
                else
                {
                    dx[My[v]]=dy[v]+1;
                    Q.push(My[v]);
                }
            }
    }
    return dis!=INF;
}
bool DFS(int u)
{
    for(int v=1;v<=Ny;v++)
       if(!vst[v]&&g[u][v]&&dy[v]==dx[u]+1)
       {
           vst[v]=1;
           if(My[v]!=-1&&dy[v]==dis) continue;
           if(My[v]==-1||DFS(My[v]))
           {
               My[v]=u;
               Mx[u]=v;
               return 1;
           }
       }
    return 0;
}
int MaxMatch()
{
    int res=0;
    memset(Mx,-1,sizeof(Mx));
    memset(My,-1,sizeof(My));
    while(searchP())
    {
        memset(vst,0,sizeof(vst));
        for(int i=1;i<=Nx;i++)
          if(Mx[i]==-1&&DFS(i))  res++;
    }
    return res;
}


int main()
{
    int _,n,m,i,j,cas=0;
    double t,tp,x1[MAXN],y1[MAXN],t1[MAXN],x[MAXN],y[MAXN];
    scanf("%d",&_);
    while(_--)
    {
        memset(g,0,sizeof(g));
        scanf("%lf",&t);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%lf%lf%lf",&x1[i],&y1[i],&t1[i]);

        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%lf%lf",&x[i],&y[i]);

        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
        {
            tp=(x1[i]-x[j])*(x1[i]-x[j])+(y1[i]-y[j])*(y1[i]-y[j]);
            tp=sqrt(tp);
            if(tp<=t1[i]*t)
                g[i][j]=1;
        }
        Nx=n;
        Ny=m;
        printf("Scenario #%d:\n%d\n\n",++cas,MaxMatch());
    }
    return 0;
}
