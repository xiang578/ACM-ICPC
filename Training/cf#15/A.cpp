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
const int N=5*1024;
const double eps=1e-8;
struct node
{
    double a,x;
}p[N];

int cmp(node n,node m)
{
    return n.x<m.x;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int s,i,ans,j;
    double t,m;
    while(~scanf("%d%lf",&s,&t))
    {
        for(i=0;i<s;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].a);
            p[i].a/=2.0;
        }
        sort(p,p+s,cmp);
        ans=2;
        for(i=1;i<s;i++)
        {
            m=p[i].x-p[i-1].x-p[i].a-p[i-1].a-t;
            if(m<0) continue;
            if(m<eps) ans+=1;
            else ans+=2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
