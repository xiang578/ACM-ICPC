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
vector<int>g[N];
int n,m,dis[N][N];
struct node
{
    int v,w;
}p[N][4];

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
            v=g[u][v];
            if(dis[x][u]>dis[x][v]+1)
            {
                dis[x][u]=dis[x][v]+1;
                if(inq[u]==0)
                {
                    inq[u]=1;
                    q.push(u);
                }
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int u,v,a,b,c,d,mx,tmp,a1,b1,c1,d1,k;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        g[i].clear();
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        spfa(i);
    mx=-1;
    printf("%d %d %d %d\n",a1,b1,c1,d1);
    return 0;
}
