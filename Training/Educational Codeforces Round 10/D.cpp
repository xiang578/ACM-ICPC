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
int c[up+10];
int l[N],r[N];
map<int,int>mp;
int lowbit(int x)
{
    return x&-x;
}

int sum(int x)
{
    int ret=0;
    while(x>0)
    {ret+=c[x];
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,n,cnt,tl,tr;
    scanf("%d",&n);
    for(i=0;i<=up;i++) c[up]=0;
    cnt=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        x[cnt]=l[i];
        cnt++;
        x[cnt]=r[i];
        cnt++;
    }
    mp.clear();
    sort(x,x+cnt);
    for(i=0;i<cnt;i++)
    {
        mp[x[i]]=i+1;
    }
    for(i=0;i<cnt;i++)
    {
        tr=mp[r[i]];
        add(tr,1);
    }
    for(i=0;i<cnt;i++)
    {
        printf("%d\n",sum(mp[r[i])-sum(mp[l[i]]));
    }
    return 0;
}
