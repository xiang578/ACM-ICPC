/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */
/*
背包变形，比赛的最后写的有几分背包的样子，但是没有往这方面想过去，所以没有写出来。
首先将两种操作分开来看，发现本质是一样的。
以第一种为例，可以构建出`dp[i]=min(dp[i],dp[i-xi]+1),0<=i<=ai`。
第二种也转化为覆盖0-ai的情况就和第一种一样了。
最后枚举答案，如果为k，那么假设覆盖了第一种中的1到i，那么第二种就覆盖了剩下从n开始的k-i个。第二问答案就是两个dp值相加取最小的。
*/
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
const int inf=0x3f3f3f3f;
struct node
{
    int s,w;
};
vector<node>p[2];

int cmp1(node a,node b)
{
    return a.s<b.s;
}

int cmp2(node a,node b)
{
    return a.s<b.s;
}

int mi(int x,int y)
{
    if(x<y) return x;
    else return y;
}
int l[N],r[N],n,m,u,v,w;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,cas=0,ans1,ans2;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        p[0].clear();p[1].clear();
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            node t;
            t.w=w;
            if(u==1)
            {
                t.s=v;
                p[0].push_back(t);
            }
            else
            {
                t.s=n-v+1;
                p[1].push_back(t);
            }
        }
        sort(p[0].begin(),p[0].end(),cmp1);
        sort(p[1].begin(),p[1].end(),cmp2);
        for(int i=1;i<=n;i++) l[i]=r[i]=inf;
        l[0]=0;
        r[0]=0;
        for(int i=0;i<p[0].size();i++)
        {
            for(int j=p[0][i].s;j>=p[0][i].w;j--)
                l[j]=mi(l[j],l[j-p[0][i].w]+1);
        }
        for(int i=0;i<p[1].size();i++)
        {
            for(int j=p[1][i].s;j>=p[1][i].w;j--)
                r[j]=mi(r[j],r[j-p[1][i].w]+1);
        }
        ans1=0;
        ans2=inf;
        for(int k=n;k>=0;k--)
        {
            for(int i=0;i<=k;i++)
            {
                if(l[i]<inf&&r[k-i]<inf)
                {
                    if(k==ans1) ans2=mi(ans2,l[i]+r[k-i]);
                    else if(k>ans1)
                    {
                        ans1=k;
                        ans2=l[i]+r[k-i];
                    }
                }
            }
            if(ans1>k) break;
        }
        printf("Case %d: %d %d\n",++cas,ans1,ans2);
    }
    return 0;
}


/*
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
const int inf=0x3fffffff;
struct node
{
    int s,e,w;
} p[N];
int cmp(node a,node b)
{
    if(b.s==a.s)
        return a.e<b.e;
    else
        return a.s<b.s;
}

int f[N],d[N],n,m,u,v,w;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,cas=0,ans1,ans2;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(u==1)
            {
                p[i].s=1;
                p[i].e=v;
                p[i].w=w;
            }
            else
            {
                p[i].s=v;
                p[i].e=n;
                p[i].w=w;
            }
        }
        memset(d,0,sizeof(d));
        memset(f,0,sizeof(f));
        sort(p,p+m,cmp);
        for(int j=0; j<m; j++)
        {
            w=p[j].w;
            for(int i=p[j].e; i>=p[j].s+w-1; i--)
            {
                if(f[i-w+1]+w>i) continue;
                if(f[i]<f[i-w]+w)
                {
                    f[i]=f[i-w]+w;
                    d[i]=d[i-w]+1;
                }
                else if(f[i]==f[i-w]+w)
                {
                    d[i]=d[i-w]+1;
                }
            }

            /*
            int t=f[p[j].e];
            for(int i=p[j].s; i<=p[j].e; i++)
            {
                if(p[j].e-f[i]>=p[j].w)
                {
                    if(t<f[i]+p[j].w)
                    {
                        t=f[i]+p[j].w;
                        d[p[j].e]=d[i]+1;
                    }
                    else if(t==f[i]+p[j].w)
                    {
                        d[p[j].e]=min(d[p[j].e],d[i]+1);
                    }
                }
            }
            f[p[j].e]=t;

        }
        ans1=0;
        ans2=inf;
        for(int i=0; i<=n; i++)
        {
            if(f[i]>ans1)
            {
                ans1=f[i],ans2=d[i];
            }
            else if(f[i]==ans1)
            {
                ans2=min(ans2,d[i]);
            }
        }
        printf("Case %d: %d %d\n",++cas,ans1,ans2);
    }
    return 0;
}
*/
