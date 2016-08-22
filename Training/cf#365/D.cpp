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
const int N=1e6+10;
map<int,int>mp;
int n,m,sum[N],ans[N],a[N];
struct node
{
    int l,r,id;
}p[N];

int cmp(node n1,node n2)
{
    if(n1.r==n2.r)
        return n1.l<n2.l;
    else
        return n1.r<n2.r;
}

void add(int x,int v)
{
    while(x)
    {
        sum[x]^=v;
        x-=x&(-x);
    }
}

int get(int x)
{
    int ret=0;
    while(x<=n)
    {
        ret^=sum[x];
        x+=x&(-x);
    }
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&p[i].l,&p[i].r);
        p[i].id=i;
    }
    sort(p,p+m,cmp);
    mp.clear();
    memset(sum,0,sizeof(sum));
    int r=0;
    for(int i=0;i<m;i++)
    {
        while(r<=p[i].r)
        {
            add(mp[a[r]],a[r]);
            mp[a[r]]=r;
            r++;
        }
        ans[p[i].id]=get(p[i].l);
    }
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
