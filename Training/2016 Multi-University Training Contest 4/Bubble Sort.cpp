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
const int N=100000+10;
int l[N],r[N],a[N],c[N],n;
int lowbit(int x)
{
    return x&(-x);
}

void add(int x)
{
    while(x<=n)
    {
       c[x]+=1;
       x+=lowbit(x);
    }
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    scanf("%d",&_);
    for(int k=1; k<=_; k++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            l[a[i]]=r[a[i]]=i;
        }
        memset(c,0,sizeof(c));
        for(int i=n; i>=1; i--)
        {
            l[a[i]]=min(a[i],l[a[i]]);
            r[a[i]]=max(a[i],i+sum(a[i]-1));
            add(a[i]);
        }
        printf("Case #%d:",k);
        for(int i=1; i<=n; i++)
        {
            printf(" %d",r[i]-l[i]);
        }
        printf("\n");
    }
    return 0;
}

/*int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,t;
    scanf("%d",&_);
    for(int k=1; k<=_; k++)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            l[a[i]]=r[a[i]]=i;
        }
        for(int i=1; i<=n; i++)
        {
            int ok=0;
            for(int j=n; j>i; j--)
            {
                if(a[j-1]>a[j])
                {
                    ok++;
                    swap(a[j],a[j-1]);
                    l[a[j]]=min(l[a[j]],j);
                    l[a[j-1]]=min(l[a[j-1]],j-1);
                    r[a[j]]=max(r[a[j]],j);
                    r[a[j-1]]=max(r[a[j-1]],j-1);
                }
            }
            if(ok==0) break;
        }
        printf("Case #%d:",k);
        for(int i=1; i<=n; i++)
        {
            printf(" %d",r[i]-l[i]);
        }
        printf("\n");
    }
    return 0;
}*/

/*int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,t,l,r;
    scanf("%d",&_);
    for(int k=1;k<=_;k++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            if(t<i) l=t;
            else l=i;
            if(i>t) r=i;
            else r=t;
            ans[t]=r-l;
        }
        printf("Case #%d:",k);
        for(int i=1;i<=n;i++)
        {
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}*/
