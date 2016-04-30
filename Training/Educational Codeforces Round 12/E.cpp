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
const int N=2e7+1;
long long  ans;
int n,k,tot;
int ch[N][2];
long long v[N];

void get(int sum)
{
    int x,y,u=1;
    for(int i=30; i>=0; i--)
    {
        x=(sum>>i)&1^1;
        y=(k>>i)&1;
        if(y==0)
        {
            ans+=v[ch[u][x]];
            u=ch[u][x^1];
        }
        else
            u=ch[u][x];
    }
    ans+=v[u];
}
void add(int sum)
{
    int u=1;
    for(int i=30; i>=0; i--)
    {
        int p=(sum>>i)&1;
        if(ch[u][p]==0)
        {
            ch[u][p]=tot;
            tot++;
        }
        v[u]++;
        u=ch[u][p];
    }
    v[u]++;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,sum=0;
    scanf("%d%d",&n,&k);
    ans=0;
    tot=2;
    memset(ch,0,sizeof(ch));
    memset(v,0,sizeof(v));
    add(0);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&t);
        sum=sum^t;
        get(sum);
        add(sum);
        //printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}
