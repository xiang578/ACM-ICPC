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
const int N=2048;

struct data
{
    int x,y,w;
}a[15000+10];

int cmp(data n,data m)
{
    return n.w<m.w;
}

int p[15000+10];

int Find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=Find(p[x]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int ans,cnt,i,j,n,m,fx,fy,_;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
        sort(a,a+m,cmp);
        ans=0x7fffffff;
        for(i=0;i<=m;i++)
        {
            cnt=1;
            for(j=1;j<=n;j++) p[j]=j;
            for(j=i;j<m;j++)
            {
                fx=Find(a[j].x);
                fy=Find(a[j].y);
                if(fx==fy) continue;
                cnt++;
                p[fx]=fy;
                if(cnt==n) break;
            }
            if(cnt==n)
                ans=min(ans,a[j].w-a[i].w);
        }
        if(ans==0x7fffffff) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
