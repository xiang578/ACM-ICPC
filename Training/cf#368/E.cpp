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
const int N=2048;
struct node
{
    int x,y;
    ll w;
};
vector<node>e[N];
int n,m,k,t,q,flag[N],last[N];
ll sum[N][N];
int lowbit(int x)
{
    return x&-x;
}

ll get(int x,int y)
{
    ll ret=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        for(int j=y;j>0;j-=lowbit(j))
        {
            ret+=sum[i][j];
        }
    }
    return ret;
}

void add(int x,int y,ll v)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        for(int j=y;j<=m;j+=lowbit(j))
        {
            sum[i][j]+=v;
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i=1;i<=k;i++) e[i].clear();
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&t);
            node tmp;
            for(int j=0;j<t;j++)
            {
                scanf("%d%d%lld",&tmp.x,&tmp.y,&tmp.w);
                e[i].push_back(tmp);
            }
            flag[i]=1;
            last[i]=0;
        }
        scanf("%d",&q);
        while(q--)
        {
            char s[100];
            scanf("%s",s);
            if(s[0]=='S')
            {
                scanf("%d",&t);
                flag[t]^=1;

            }
            else
            {
                int a1,a2,b1,b2;
                scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
                for(int i=1;i<=k;i++)
                {
                    if(last[i]!=flag[i])
                    {
                        int f;
                        if(flag[i]==1)
                            f=1;
                        else
                            f=-1;
                        for(int j=0;j<e[i].size();j++)
                            add(e[i][j].x,e[i][j].y,f*e[i][j].w);
                        last[i]=flag[i];
                    }
                }
                ll ans=get(a2,b2)+get(a1-1,b1-1)-get(a2,b1-1)-get(a1-1,b2);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
