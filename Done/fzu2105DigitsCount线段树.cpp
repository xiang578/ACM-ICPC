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
const int N=1000000+10;

int a[N];
struct tree
{
    int l,r,s,f;
} t[4*N+10];

void build(int o,int l,int r)
{
    t[o].l=l;
    t[o].r=r;
    t[o].f=-1;
    t[o].s=0;
    if(l==r)
    {
        t[o].s=t[o].f=a[l];
    }
    else
    {
        int mid=(l+r)/2;
        build(o*2,l,mid);
        build(o*2+1,mid+1,r);
        t[o].s=t[o*2].s+t[o*2+1].s;
        if(t[o*2].f==t[o*2+1].f&&t[o].f==-1)
            t[o].f=t[o*2].f;
    }
}

void pushdown(int o)
{
    if(t[o].f!=-1)
    {
        t[o*2].f=t[o*2+1].f=t[o].f;
        t[o*2].s=t[o].f*(t[o*2].r-t[o*2].l+1);
        t[o*2+1].s=t[o].f*(t[o*2+1].r-t[o*2+1].l+1);
        t[o].f=-1;
    }
}

int query(int o,int l,int r)
{
    //printf("%d %d\n",l,r);
    if(t[o].l==l&&t[o].r==r)
    {
        return t[o].s;
    }
    else
    {
        if(t[o].f!=-1)  pushdown(o);
        int mid=(t[o].l+t[o].r)/2;
        if (r<=mid) return query(o*2,l,r);
        else if (l>mid) return query(o*2+1,l,r);
        else return query(o*2,l,mid)+query(o*2+1,mid+1,r);
    }
}

//0 xor
//2 or
//1 and
void update(int o,int l,int r,int v,int k)
{
    //printf("%d %d\n",l,r);
    if(t[o].l>=l&&t[o].r<=r&&t[o].f!=-1)
    {
        if(k==0) t[o].f=t[o].f^v;
        else if(k==1) t[o].f=t[o].f&v;
        else if(k==2) t[o].f=t[o].f|v;
        t[o].s=t[o].f*(t[o].r-t[o].l+1);
    }
    else
    {
        if(t[o].f!=-1) pushdown(o);
        int mid=(t[o].l+t[o].r)/2;
        if(l<=mid) update(o*2,l,r,v,k);
        if(r>mid) update(o*2+1,l,r,v,k);
        t[o].s=t[o*2].s+t[o*2+1].s;
        if(t[o*2].f==t[o*2+1].f&&t[o].f==-1)
            t[o].f=t[o*2].f;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,n,m,l,r,op;
    string s;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        build(1,1,n);
        for(i=1; i<=m; i++)
        {
            cin>>s;
            if(s=="SUM")
            {
                scanf("%d%d",&l,&r);
                l++,r++;
                printf("%d\n",query(1,l,r));
            }
            else if(s=="XOR")
            {
                scanf("%d%d%d",&op,&l,&r);
                l++,r++;
                update(1,l,r,op,0);
            }
            else if(s=="AND")
            {
                scanf("%d%d%d",&op,&l,&r);
                l++,r++;
                update(1,l,r,op,1);
            }
            else if(s=="OR")
            {
                scanf("%d%d%d",&op,&l,&r);
                l++,r++;
                update(1,l,r,op,2);
            }
        }
    }
    return 0;
}
