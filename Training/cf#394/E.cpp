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
#define yes puts("YES")
#define no puts("NO")
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
const int M=1e6+10;
int n;
ll x[50],y[50];
vector<int>g[50];

void dfs(int k,int f,int l,int d)
{
    for(int i=0;i<g[k].size();i++)
    {
        int j=g[k][i];
        if(j==f) continue;
        ll len=(ll)(1<<l);
        //printf("%d %d %d %d %lld\n",k,j,d,l,len);
        if(d==0)
        {
            x[j]=x[k];
            y[j]=y[k]+len;
            dfs(j,k,--l,3);
        }
        else if(d==1)
        {
            x[j]=x[k]+len;
            y[j]=y[k];
            dfs(j,k,--l,0);
        }
         else if(d==2)
        {
            x[j]=x[k];
            y[j]=y[k]-len;
            dfs(j,k,--l,1);
        }
         else if(d==3)
        {
            x[j]=x[k]-len;
            y[j]=y[k];
            dfs(j,k,--l,2);
        }
        d=(d+1)%4;
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //yes;
    //no;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    int ok=1;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
       if(g[u].size()>4||g[v].size()>4) ok=0;
    }
    if(!ok) puts("NO");
    else
    {
        puts("YES");
        x[1]=0;
        y[1]=0;
        dfs(1,0,n,0);
        for(int i=1;i<=n;i++)
        {
            cout<<x[i]<<" "<<y[i]<<endl;
        }
    }
    return 0;
}
