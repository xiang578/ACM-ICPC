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
const int M=1e6+10;
int n,a[N],u[N],ok;
vector<int>v[N];

void dfs(int x,int cnt)
{
    if(ok) return ;
    a[cnt]=x;
    if(cnt==n)
    {
        ok=1;
        for(int i=1;i<n;i++) printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    else
    {
        for(int i=0;i<v[x].size();i++)
        {
           int  y=v[x][i];
            if(u[y]) continue;
            u[y]=1;
            dfs(y,cnt+1);
            u[y]=0;
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=0;i<n*(n-1)/2;i++)
        {
            int a,b;
            cin>>a;
            cin>>b;
            v[a].push_back(b);
        }
        ok=0;
        for(int i=1;i<=n;i++)
        {
            memset(u,0,sizeof(u));
            u[i]=1;
            dfs(i,1);
            if(ok==1) break;
        }
        if(!ok) puts("Impossible");
    }
    return 0;
}
