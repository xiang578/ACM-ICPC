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
const double eps=1e-8;
double x[N],y[N],w,v,u,t,a,b,l,r,m,ans;
int n;

int get(double q)
{
    int f1,f2;
    f1=f2=0;
    for(int i=0;i<n;i++)
    {
        if(fabs(x[i]*a-q*a-y[i])<eps) continue;
        if(x[i]*a-q*a>y[i]) f1++;
        else f2++;
        if(f1&&f2) return 0;
    }
    return 1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //scanf("%d%lflf%lf",&n,&w,&v,&u);
    cin>>n>>w>>v>>u;
    r=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&x[i],&y[i]);
        r=max(x[i],r);
    }
    t=w/u;
    a=w/(v*t);
    int f1,f2;
    f1=f2=0;
    for(int i=0;i<n;i++)
    {
        if(fabs(x[i]*a-y[i])<eps) continue;
        if(x[i]*a>y[i]) f1++;
        else f2++;
    }
    //printf("%d %d\n",f1,f2);
    if(f1!=0&&f2!=0)
    {
        m=0;
        for(int i=0;i<n;i++)
        {
            m=max(m,x[i]-y[i]/a);
        }
        ans=t+m/v;
        printf("%lf\n",ans);
    }
    else
    {
        printf("%lf\n",t);
    }
    return 0;
}

/*
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
const double eps=1e-8;
double x[N],y[N],w,v,u,t,a,l,r,m,ans;
int n;

int get(double q)
{
    int f1,f2;
    f1=f2=0;
    for(int i=0;i<n;i++)
    {
        if(fabs(x[i]*a-q*a-y[i])<eps) continue;
        if(x[i]*a-q*a>y[i]) f1++;
        else f2++;
        if(f1&&f2) return 0;
    }
    return 1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //scanf("%d%lflf%lf",&n,&w,&v,&u);
    cin>>n>>w>>v>>u;
    r=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&x[i],&y[i]);
        r=max(x[i],r);
    }
    t=w/u;
    a=w/(v*t);
    int f1,f2;
    f1=f2=0;
    for(int i=0;i<n;i++)
    {
        if(fabs(x[i]*a-y[i])<eps) continue;
        if(x[i]*a>y[i]) f1++;
        else f2++;
    }
    //printf("%d %d\n",f1,f2);
    if(f1!=0&&f2!=0)
    {
        l=0;
        while(fabs(r-l)>eps)
        {
            m=(l+r)/2;
            if(get(m)==1)
            {
                ans=m/v+t;
                r=m;
            }
            else
            {
                l=m;
            }
        }
        printf("%lf\n",ans);
    }
    else
    {
        printf("%lf\n",t);
    }
    return 0;
}*/
