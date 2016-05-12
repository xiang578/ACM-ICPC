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
int u[100000+10];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,flag,ans,a,b,mx2,mx1,mi1,mi2,d1,d2;
    scanf("%d%d",&n,&m);
    memset(u,0,sizeof(u));
    flag=1;
    ans=0;
    mx1=mx2=mi1=mi2=-1;
    d1=d2=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        if(flag==0) continue;
        if(a>b) swap(a,b);
        if(u[a]==1) {flag=0;continue;}
        if(u[b]==2) {flag=0;continue;}
        if(u[a]==0)
        {u[a]=2;d1++;}
        if(u[b]==0)
        {
            u[b]=1;d2++;
        }
        if(mx1==-1||mx1<b) mx1=b;
        if(mx2==-1||mx2<a) mx2=a;
        if(mi1==-1||mi1>b) mi1=b;
        if(mi2==-1||mi2>a) mi2=a;
    }
    //printf("%d %d %d\n",flag,mx2,mi1);
    if(mx2>mi1) flag=0;
    if(flag)
    {
        //ans=1;
        if(mi1==-1) mi1=n;
        if(mx2==-1) mx2=1;
        int cnt=mi1-mx2-1;
        ans=cnt+1;
    }
    printf("%d\n",ans);
    return 0;
}
