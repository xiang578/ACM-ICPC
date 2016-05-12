/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int inf=0x3fffffff;
const int N=3000+10;
vector<int>g[N],gt[N];
int n,m,dis[N][N];
struct node
{
    int v,w;
}p[N][10],pt[N][10];

void spfa(int x)
{
    int inq[N],u,v;
    queue<int>q;
    memset(inq,0,sizeof(inq));
    for(int i=1;i<=n;i++)
        dis[x][i]=inf;
    dis[x][x]=0;
    q.push(x);
    inq[x]=1;
    while(!q.empty())
    {
        u=q.front();
        inq[u]=0;
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(dis[x][v]>dis[x][u]+1)
            {
                dis[x][v]=dis[x][u]+1;
                if(inq[v]==0)
                {
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    int u,v,a,b,c,d,mx,tmp,a1,b1,c1,d1,k;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
    {
        g[i].clear();
        gt[i].clear();
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
       for(int j=0;j<4;j++)
            pt[i][j].w=-1;
        spfa(i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<4;j++)
            p[i][j].w=-1;
        for(int j=1;j<=n;j++)
        {
            v=j;
            if(dis[i][j]==inf||i==j) continue;
            p[i][4].w=dis[i][v];
            p[i][4].v=v;
            for(k=3;k>=0;k--)
            {
                if(p[i][k+1].w>p[i][k].w)
                    swap(p[i][k+1],p[i][k]);
                else
                    break;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dis[j][i]==inf||i==j) continue;
            pt[i][4].w=dis[j][i];
            pt[i][4].v=j;
            for(k=3;k>=0;k--)
            {
                if(pt[i][k+1].w>pt[i][k].w)
                    swap(pt[i][k+1],pt[i][k]);
                else
                    break;
            }
        }
    }

    mx=-1;
    for(a=1;a<=n;a++)
    {
        for(b=1;b<=n;b++)
        {
            tmp=dis[a][b];
            if(tmp==inf||a==b) continue;
            for(k=0;k<4;k++)
            {
                if(p[b][k].v==a||p[b][k].v==b) continue;
                else if(p[b][k].w==-1) continue;
                else break;
            }
            if(k==4) continue;
            tmp+=p[b][k].w;
            c=p[b][k].v;
            for(k=0;k<4;k++)
            {
                if(pt[a][k].v==a||pt[a][k].v==b||pt[a][k].v==c) continue;
                else if(pt[a][k].w==-1) continue;
                else break;
            }
            if(k<4)
            {
                if(mx<tmp+pt[a][k].w)
                {
                    a1=a;
                    b1=b;
                    c1=c;
                    d1=pt[a][k].v;
                    mx=tmp+pt[a][k].w;
                }
            }
        }
    }
    printf("%d %d %d %d\n",d1,a1,b1,c1);
    return 0;
}
