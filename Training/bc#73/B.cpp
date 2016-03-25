/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
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
int p[120];
struct node
{
    int u,v,use;
}g[120];

int Find(int x)
{
    if(x==p[x]) return x;
    else return p[x]=Find(p[x]);
}

int get(int n)
{
    int i=0,cnt=1;
    for(i=1;i<=n;i++)
        p[i]=i;
    for(i=0;i<=n;i++)
    {
        if(g[i].use==0) continue;
        int fu=Find(g[i].u);
        int fv=Find(g[i].v);
        if(fu!=fv)
        {
            cnt++;
            p[fu]=fv;
        }
    }
    if(cnt==n) return 1;
    else return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,j,n,u,v,ans;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        ans=0;
        for(i=0; i<=n; i++)
        {
            scanf("%d%d",&g[i].u,&g[i].v);
            g[i].use=1;
        }
        for(i=0; i<=n; i++)
        {
            g[i].use=0;
            if(get(n)) ans++;
            g[i].use=1;
        }
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                g[i].use=g[j].use=0;
                if(get(n)) ans++;
                g[i].use=g[j].use=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
