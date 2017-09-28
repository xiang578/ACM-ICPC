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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,k,a[200];
    scanf("%d%d",&n,&k);
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        while(l<=r)
        {
            a[l+100]++;
            l++;
        }
    }
    int mi=mod,mx=-mod;
    for(int i=-50;i<=50;i++)
    {
        if(a[i+100]==0||a[i+101]<k) continue;
        mx=max(i,mx);
        mi=min(i,mi);
    }
    if(mi==mod||mx==-mod) puts("error");
    else printf("%d %d\n",mi,mx);
    return 0;
}
