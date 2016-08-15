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
int bin[N],a[N],to[N],q[N];
vector<int>G[N];
int Find(int x)
{
    if(bin[x]==x) return x;
    else return bin[x]=Find(bin[x]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {scanf("%d",a+i);bin[i]=i;G[i].clear();}
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        int fu=Find(u);
        int fv=Find(v);
        if(fu!=fv)
        {
            bin[fu]=fv;
        }
    }
    int cnt=1;
    memset(to,0,sizeof(to));
    for(int i=1;i<=n;i++)
    {
        int f=Find(i);
        if(to[f]==0)
        {
            to[f]=cnt;
            cnt++;
        }
        G[to[f]].push_back(a[i]);
    }
    for(int i=1;i<cnt;i++)
        sort(G[i].begin(),G[i].end(),greater<int>());

    memset(q,0,sizeof(q));
    for(int i=1;i<=n;i++)
    {
        int f=Find(i);
        printf("%d ",G[to[f]][q[to[f]]]);
        q[to[f]]++;
    }
    return 0;
}
