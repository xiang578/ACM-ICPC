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
int n,m,x,y,a[N],b[N],hasa[N],hasb[N];
ll ans;

void add1(int x)
{
    while(x<=n)
    {
        a[x]++;
        x+=x&(-x);
    }
}
void add2(int x)
{
     while(x<=n)
    {
        b[x]++;
        x+=x&(-x);
    }
}
int get1(int x)
{
    int ret=0;
    while(x)
    {
        ret+=a[x];
        x-=x&(-x);
    }
    return ret;
}

int get2(int x)
{
    int ret=0;
    while(x)
    {
        ret+=b[x];
        x-=x&(-x);
    }
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    ans=(ll)n*n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(hasa,0,sizeof(hasa));
    memset(hasb,0,sizeof(hasb));
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(hasa[x]==0)
        {
            hasa[x]=1;
            int t=get2(n);
            ans-=n-t;
            add1(x);
        }

        if(hasb[y]==0)
        {
            hasb[y]=1;
            int t=get1(n);
            ans-=n-t;
            add2(y);
        }
        cout<<ans<<endl;
    }
    return 0;
}
