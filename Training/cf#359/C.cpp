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
int n,m,x,y,ans,use[10],a[10],b[10];

int get(int k)
{
    int ret=0;
    if(k==0) ret=1;
    while(k>0)
    {
        k/=7;
        ret++;
    }
    return ret;
}

void dfs2(int k)
{
    if(k==y)
    {
        int now=0;
        for(int i=y-1;i>=0;i--)
        {
            now=now*7+b[i];
        }
        //printf("   %d\n",now);
        if(now>=m) return ;
        ans++;
    }
    else
    {
        for(int i=0;i<7;i++)
        {
            if(use[i]==0)
            {
                use[i]=1;
                b[k]=i;
                dfs2(k+1);
                use[i]=0;
            }
        }
    }
}


void dfs1(int k)
{
    if(k==x)
    {
        int now=0;
        for(int i=x-1;i>=0;i--)
        {
            now=now*7+a[i];
        }
        if(now>=n) return ;
        //printf("%d\n",now);
        memset(b,0,sizeof(b));
        dfs2(0);
    }
    else
    {
        for(int i=0;i<7;i++)
        {
            if(use[i]==0)
            {
                use[i]=1;
                a[k]=i;
                dfs1(k+1);
                use[i]=0;
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    x=get(n-1);
    y=get(m-1);
    //printf("%d %d\n",x,y);
    ans=0;
    memset(use,0,sizeof(use));
    memset(a,0,sizeof(a));
    if(x+y<=7)
    {
        dfs1(0);
    }
    cout<<ans<<endl;
    return 0;
}
