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
const int N=2*1e5+10;
int u[N],h[N],in[N];
struct node
{
    int to,num;
};
vector<node>g[N];

void dfs(int x,int fa,int st,int now)
{
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i].to;
        int n=g[x][i].num;
        if(y==fa) continue;
         in[now]=n;
        if(u[y]==1)
        {

            for(int i=st;i<=now;i++)
            {
                h[in[i]]=1;
            }
            dfs(y,x,now,now+1);
        }
        else
        {
            dfs(y,x,st,now+1);
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,t;
    scanf("%d%d",&n,&m);
    memset(u,0,sizeof(u));
    memset(h,0,sizeof(h));
    for(int i=1;i<=2*m;i++)
    {
        scanf("%d",&t);
        u[t]=1;
    }
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        node t;
        t.to=b;
        t.num=i;
        g[a].push_back(t);
        t.to=a;
        t.num=i;
        g[b].push_back(t);
    }
    for(int i=1;i<=n;i++)
    {
        if(u[i]==1)
        {
            dfs(i,0,0,0);
            break;
        }
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        printf("%d %d\n",i,h[i]);
        ans+=h[i];
    }
    cout<<ans<<endl;
    return 0;
}
