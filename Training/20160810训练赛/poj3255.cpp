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
const int N=1e5+10;
const int inf=0x3fffffff;
int n,m;
struct node
{
    int to,w;
};
vector<node>g[N];
int dis[N],dis2[N],inq[N];

void spfa()
{
    int u,v,w,w2;
    for(int i=1; i<=n; i++)
    {
        dis[i]=inf;
        dis2[i]=inf;
        inq[i]=0;
    }
    queue<int>q;
    queue<int>l;
    q.push(1);
    l.push(0);
    dis[1]=0;
    while(!q.empty())
    {
        u=q.front();
        w=l.front();
        //printf("%d %d\n",u,w);
        q.pop();
        l.pop();
        if(dis2[u]<w) continue;
        for(int i=0; i<g[u].size(); i++)
        {
            v=g[u][i].to;
            w2=g[u][i].w+w;
            //printf("%d %d %d\n",v,w2,w);
            if(dis[v]>w2)
            {
                swap(dis[v],w2);
                q.push(v);
                l.push(dis[v]);

            }

            if(dis2[v]>w2&&w2>dis[v])
            {
                //printf("%d\n",w2);
                dis2[v]=w2;
                q.push(v);
                l.push(dis2[v]);
            }
            //printf("%d\n",w);
        }
    }

}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
            g[i].clear();
        int u,v,w;
        int ans=0;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            node tmp;
            tmp.to=v;
            tmp.w=w;
            g[u].push_back(tmp);
            tmp.to=u;
            g[v].push_back(tmp);
        }
        spfa();
        //printf("1111\n");
        printf("%d\n",dis2[n]);
    }
    return 0;
}
