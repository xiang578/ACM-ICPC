#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct Point
{
    int x,y;

}p[1024],ch[1024];

Point operator - (Point a,Point b)
{
    Point c;
    c.x=a.x-b.x;
    c.y=a.y-b.y;
    return c;
}

int cross(Point a,Point b)
{
    return a.x*b.y-b.x*a.y;
}

double dot(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp(Point a,Point b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}

int main()
{
    int i,k,n,m,l;
    double ans;
    while(~scanf("%d%d",&n,&l))
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        sort(p,p+n,cmp);
        m=0;
        for(i=0;i<n;i++)
        {
            while(m>1&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
            ch[m++]=p[i];
        }
        k=m;
        for(i=n-2;i>=0;i--)
        {
            while(m>k&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
            ch[m++]=p[i];
        }
        if(n>1) m--;
        ans=0;
        for(i=0;i<m;i++)
        {
            ans+=dot(ch[i],ch[i+1]);
        }
        printf("%.0f\n",ans+2*3.1415926*l);
    }
    return 0;
}
