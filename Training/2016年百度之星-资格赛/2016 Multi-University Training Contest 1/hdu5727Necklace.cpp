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
const int MAXN=500+5;
const int INF=1<<28;
int Mx[MAXN],My[MAXN],Nx,Ny;
int dx[MAXN],dy[MAXN],dis;
bool vst[MAXN];

vector<int>G[MAXN];

bool searchP()
{
    queue<int>Q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=1; i<=Nx; i++)
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
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            if(dy[v]==-1)
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
    }
    return dis!=INF;
}

bool DFS(int u)
{
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!vst[v]&&dy[v]==dx[u]+1)
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
        for(int i=1; i<=Nx; i++)
            if(Mx[i]==-1&&DFS(i))  res++;
    }
    return res;
}

int main()
{
    int n,m,i,j,u,v,gg[100][100],ans,p[10],has[10][10];
    while(~scanf("%d%d",&n,&m))
    {
        memset(gg,0,sizeof(gg));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            gg[u][v]=1;
        }
        Nx=n;
        Ny=n;
        ans=n;
        for(int i=1;i<=n;i++) p[i]=i;
        if(m!=0)
        {
            do
            {
                for(i=1; i<=n; i++)
                    G[i].clear();
                memset(has,0,sizeof(has));
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(i==1) u=p[n];
                        else u=p[i-1];

                        v=p[i];
                        if(gg[j][u]||gg[j][v]) continue;
                        if(!has[i][j]) G[i].push_back(j);
                        if(!has[i][j]) G[i].push_back(j);
                        has[i][j]=has[i][j]=1;
                    }
                }
                ans=min(ans,n-MaxMatch());
                if(ans==0) break;
            }while(next_permutation(p+2,p+1+n));
        }
        else ans=0;
        printf("%d\n",ans);
    }
    return 0;
}
