/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Mon Nov  6 14:30:42 2017
File Name     :cf877e.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
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
using namespace std;
const int n=400000+10;
int N,sum[4*n],lazy[4*n],in[n],out[n],a[n],mp[n],cnt;
vector<int>g[n];

void dfs(int x)
{
    in[x]=++cnt;
    mp[cnt]=x;
    for(int i=0;i<g[x].size();i++)
        dfs(g[x][i]);
    out[x]=cnt;
}

void build(int rt,int l,int r)
{
    lazy[rt]=0;
    if(l==r) {sum[rt]=a[mp[l]];}
    else {
        int mid = (l+r)/2;
        build(rt*2,l,mid);
        build(rt*2+1,mid+1,r);
        sum[rt]=sum[rt*2]+sum[rt*2+1];
    }
}

void pushdown(int rt,int l,int r)
{
    lazy[rt]=0;
    int mid=(l+r)/2;
    sum[rt*2]=mid-l+1-sum[rt*2];
    sum[rt*2+1]=r-(mid+1)+1-sum[rt*2+1];
    lazy[rt*2]^=1;
    lazy[rt*2+1]^=1;
}

int query(int rt,int l,int r,int ql,int qr)
{
    if(l>=ql&&r<=qr)
    {
        return sum[rt];
    }
    else
    {
        int mid = (l+r)/2;
        if(lazy[rt]) pushdown(rt,l,r);
        int ret=0;
        if(mid>=ql) ret+=query(rt*2,l,mid,ql,qr);
        if(mid+1<=qr) ret+=query(rt*2+1,mid+1,r,ql,qr);
        return ret;
    }
}

void change(int rt,int l,int r,int ql,int qr)
{

    if(l>=ql&&qr>=r)
    {
        sum[rt]=r-l+1-sum[rt];
        lazy[rt]^=1;
    }
    else{
        int mid = (l+r)/2;
        if(lazy[rt]) pushdown(rt,l,r);
        if(mid>=ql) change(rt*2,l,mid,ql,qr);
        if(mid+1<=qr) change(rt*2+1,mid+1,r,ql,qr);
        sum[rt]=sum[rt*2]+sum[rt*2+1];
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cnt=0;
    scanf("%d",&N);
    for(int i=2;i<=N;i++)
    {
        int t;
        scanf("%d",&t);
        g[t].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",a+i);
    }
    build(1,1,N);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        char s[10];
        int c;
        scanf("%s%d",s,&c);
        if(s[0]=='g')
        {
            //printf("%d %d\n",in[c],out[c]);
            printf("%d\n",query(1,1,N,in[c],out[c]));
        }
        else
        {
            //printf("%d %d\n",in[c],out[c]);
            change(1,1,N,in[c],out[c]);
        }
    }
    return 0;
}
