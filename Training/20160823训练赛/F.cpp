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
const int N=2048;
const int inf=1e9;
int n,m,s,a1,b1,a2,b2;
struct node
{
    int to,w;
};
vector<node>g[N];

int spfa(int st,int ed)
{
    int inq[N],dis[N],u,v,w;
    for(int i=1; i<=n; i++)
    {
        dis[i]=inf;
        inq[i]=0;
    }
    dis[st]=0;
    queue<int>q;
    q.push(st);

    while(!q.empty())
    {
        u=q.front();
        q.pop();
        inq[u]=0;
        for(int i=0; i<g[u].size(); i++)
        {
            v=g[u][i].to;
            w=g[u][i].w;
            if(dis[v]>=dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(inq[v]==0)
                {
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
    //printf("%d\n",dis[ed]);
    return dis[ed];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        int u,v,w;
        for(int i=1;i<=n;i++) g[i].clear();
        scanf("%d%d%d%d%d",&s,&a1,&b1,&a2,&b2);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            node tmp;
            tmp.to=v;
            tmp.w=w;
            g[u].push_back(tmp);
        }
        int ans;
        ans=spfa(s,a1)+spfa(a1,b1)+spfa(b1,a2)+spfa(a2,b2);

        ans=min(ans,spfa(s,a1)+spfa(a1,a2)+spfa(a2,b1)+spfa(b1,b2));
        ans=min(ans,spfa(s,a1)+spfa(a1,a2)+spfa(a2,b2)+spfa(b2,b1));

        ans=min(ans,spfa(s,a2)+spfa(a2,b2)+spfa(b2,a1)+spfa(a1,b1));

        ans=min(ans,spfa(s,a2)+spfa(a2,a1)+spfa(a1,b2)+spfa(b2,b1));
        ans=min(ans,spfa(s,a2)+spfa(a2,a1)+spfa(a1,b1)+spfa(b1,b2));
        printf("%d\n",ans);
    }
    return 0;
}
