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
const int N=2*(1e5)+10;
const int up=2*N;
struct node
{
    int l,r,id,ans;
}p[N];
int c[up+10];
map<int,int>mp;

int cmp(node a,node b)
{
    return a.l<b.l;
}

int cmp2(node a,node b)
{
    return a.id<b.id;
}

int lowbit(int x)
{
    return x&-x;
}

int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}

void add(int x,int d)
{
    while(x<=up)
    {
        c[x]+=d;
        x+=lowbit(x);
    }
}
int x[up+10];
int main()
{
    int i,n,cnt,l,r;
    scanf("%d",&n);
    for(i=0; i<=up; i++) c[up]=0;
    cnt=0;
    for(i=0; i<n; i++)
    {
        scanf("%d%d",&r,&r);
        p[i].l=l;
        p[i].r=r;
        p[i].id=i;
        x[cnt]=l;
        cnt++;
        x[cnt]=r;
        cnt++;
    }
    mp.clear();
    sort(x,x+cnt);
    sort(p,p+n,cmp);
    for(i=0; i<cnt; i++)
    {
        mp[x[i]]=i+1;
    }
    for(i=0;i<n;i++)
    {
        p[i].l=mp[p[i].l];
        p[i].r=mp[p[i].r];
        add(p[i].r,1);
    }
    for(i=0;i<n;i++)
    {
        l=p[i].l;
        r=p[i].r;
        if(r-l<2)
            p[i].ans=0;
        else
            p[i].ans=sum(r-1)-sum(l);
        add(p[i].r,-1);
    }
    sort(p,p+n,cmp2);
    for(i=0;i<n;i++)
        printf("%d\n",p[i].ans);
    return 0;
}
