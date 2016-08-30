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
int sum[N],n,u[N];
struct node
{
    int id,a;
}p[N];
int cmp(node n1,node n2)
{
    //if(n1.a==n2.a) return n1.id<n2.id;
    return n1.a<n2.a;
}
int get(int x)
{
    int r=0;
    while(x>0)
    {
        r+=sum[x];
        x-=(x&-x);
    }
    return r;
}

void add(int x)
{
    while(x<=n)
    {
        sum[x]++;
        x+=(x&-x);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int k;
    while(~scanf("%d%d",&n,&k))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p[i].a);
            p[i].id=i;
        }
        stable_sort(p+1,p+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            u[p[i].id]=i;
        }
        ll cnt=0;
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        {
            add(u[i]);
            cnt+=i-get(u[i]);
        }
        if(cnt<=k) printf("%d\n",0);
        else printf("%lld\n",cnt-k);
    }
    return 0;
}
