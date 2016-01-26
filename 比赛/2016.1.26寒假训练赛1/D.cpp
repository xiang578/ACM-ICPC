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

char s[1024];
int main()
{
    int p,n,m,i,j,t;
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            for(j=0;j<m;j++)
                g[i+1][j+1]=s[j]-'0';
        }
        Nx=n;
        Ny=m;
        t=MaxMatch();
        if(t>p) printf("NOT ENOUGH TANK\n");
        else
        {
           printf("%d\n",t);
            int r[1024],c[1024];
            memset(r,0,sizeof(r));
            memset(c,0,sizeof(c));
            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
            {
                if(g[i][j]&&My[j]==-1)
                    r[i]=1;
            }
             for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
            {
                if(g[i][j])
                    {
                        if(!r[i])
                            c[j]=1;
                    }
            }
            printf("ROW:");
            for(i=1;i<=n;i++)
                if(r[i]) printf(" %d",i);
            printf("\n");
            printf("COLUMN:");
             for(i=1;i<=m;i++)
                if(c[i]) printf(" %d",i);
            printf("\n");
        }
    }
    return 0;
}
/*
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
const int MAXN=1024;
const int MAXM=1024*100;

int head[MAXN],tot,mx[MAXN],cx[MAXN],cy[MAXN],mk[MAXN],g[1024][1024],n,m;

int dfs(int u)
{
    for(int v=1; v<=m; v++)
    {
        if(g[u][v]&&!mk[v])
        {
            mk[v]=1;
            if(cy[v]==-1||dfs(cy[v]))
            {
                cy[v]=u;
                cx[u]=v;
                return 1;
            }
        }
    }
    return 0;
}

int Maxmatch()
{
    int res=0;
    memset(cx,0xff,sizeof(cx));
    memset(cy,0xff,sizeof(cy));
    for(int i=1; i<=n; i++)
    {
        if(cx[i]==-1)
        {
            memset(mk,0,sizeof(mk));
            res+=dfs(i);
        }
    }
    return res;
}

char s[1024];

int main()
{
    int p,i,j,t;
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        memset(g,0,sizeof(g));
        for(i=0; i<n; i++)
        {
            scanf("%s",s);
            for(j=0; j<m; j++)
                g[i+1][j+1]=s[j]-'0';
        }
        t=Maxmatch();
        if(t>p) printf("NOT ENOUGH TANK\n");
        else
        {
            printf("%d\n",t);
            int r[1024],c[1024];
            memset(r,0,sizeof(r));
            memset(c,0,sizeof(c));
            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
            {
                if(g[i][j]&&cy[j]==-1)
                    r[i]=1;
            }
             for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
            {
                if(g[i][j])
                    {
                        if(!r[i])
                            c[j]=1;
                    }
            }
            printf("ROW:");
            for(i=1;i<=n;i++)
                if(r[i]) printf(" %d",i);
            printf("\n");
            printf("COLUMN:");
             for(i=1;i<=m;i++)
                if(c[i]) printf(" %d",i);
            printf("\n");

        }
    }
    return 0;
}
*/
