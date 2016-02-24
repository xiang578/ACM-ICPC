#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <math.h>

using namespace std;
const double eps = 1e-8;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
};
struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
};

struct node
{
    double x,y;
    int id;
};

//ÅÐ¶ÏÏß¶ÎÏà½»
bool inter(Line l1,Line l2)
{
    return
        max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
        max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
        max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
        max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
        sgn((l2.s-l1.s)^(l1.e-l1.s))*sgn((l2.e-l1.s)^(l1.e-l1.s)) <= 0 &&
        sgn((l1.s-l2.s)^(l2.e-l2.s))*sgn((l1.e-l2.s)^(l2.e-l2.s)) <= 0;
}
const int MAXN = 100010;
Line line[MAXN];
node a[MAXN];

int cmp(node n,node m)
{
    return n.x<m.x;
}

int main()
{
    int n,ans,_,pa,pb,up;
    double x1,y1,x2,y2;
    scanf("%d",&_);
    while(_--)
    {
        ans=0;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            line[i] = Line(Point(x1,y1),Point(x2,y2));
            if(x1>x2) swap(x1,x2),swap(y1,y2);
            a[i*2-1].x=x1,a[i*2-1].y=y1,a[i*2-1].id=i;
            a[i*2].x=x2,a[i*2].y=y2,a[i*2].id=-i;
        }
        sort(a+1,a+2*n+1,cmp);
        for(int i = 1; i <=2*n; i++)
        {
            if(a[i].id<0) continue;
            for(int j=i+1;j<=2*n;j++)
                if(a[i].id==-a[j].id)
            {
                up=j;
                break;
            }
            for(int j=i+1; j<=2*n; j++)
            {
                if(a[up].x<a[j].x) break;
                if(a[j].id<0) continue;
                pa=a[i].id,pb=a[j].id;
                if(inter(line[pa],line[pb]))
                    ans++;
            }

        }
        printf("%d\n",ans);
    }

    return 0;
}
