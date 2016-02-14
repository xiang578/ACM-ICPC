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
const double eps=1e-10;

struct point
{
    double x,y;
    double dis;
    int id;
}p[100000+5];

int cmp(point a,point b)
{
    return a.dis<b.dis;
}

double dis(int a,int b)
{
    return sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));
}

int get(int a,int b)
{
    double a1=p[a].x-p[1].x;
    double b1=p[a].y-p[1].y;
    double a2=p[b].x-p[1].x;
    double b2=p[b].y-p[1].y;
    double t=a1*b2-b1*a2;
    if(t<0) t=-t;
    //printf("%d %d %lf\n",a,b,t);
    if(fabs(t)<eps) return 1;
    else return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,i,a,b;
    while(~scanf("%d",&n))
    {
        scanf("%lf%lf",&p[1].x,&p[1].y);
        for(i=2;i<=n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            p[i].id=i;
            p[i].dis=dis(1,i);
        }
        sort(p+2,p+n+1,cmp);
        a=b=0;
        for(i=2;i<=n;i++)
        {
            if(!a&&!b)
            {
                a=i;
            }
            else if(a&&!b)
            {
                if(get(a,i)==1)
                    continue;
                b=i;
            }
            else if(a&&b)
                break;
        }
        printf("1 %d %d\n",p[a].id,p[b].id);
    }
    return 0;
}
