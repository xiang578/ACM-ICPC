//hdu 3829
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
char s1[1024][10],s2[1024][10];
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
    int n,m,i,j,p;
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        for(i=0; i<=p; i++)
            G[i].clear();
        for(i=1; i<=p; i++)
        {
            scanf("%s%s",s1[i],s2[i]);
        }
        for(i=1; i<=p; i++)
        {
            for(j=i+1; j<=p; j++)
            {
                if(strcmp(s1[i],s2[j])==0||strcmp(s2[i],s1[j])==0)
                {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }
        Nx=Ny=p;
        printf("%d\n",p-MaxMatch()/2);
    }
    return 0;
}
