#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
const double eps=1e-10;
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y) {}
}p[100000+5];
typedef Point Vector;

Vector operator - (Vector a,Vector b)   {return Vector(a.x-b.x,a.y-b.y);}
Vector operator + (Vector a,Vector b)   {return Vector(a.x+b.x,a.y+b.y);}
double cross(Vector a,Vector b) {return a.x*b.y-b.x*a.y;}
double dot(Vector a,Vector b)   {return a.x*b.x+a.y*b.y;}
double Length(Vector A) {return sqrt(dot(A,A));}

int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}

bool operator ==(const Point &a,const Point &b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
int n;
double mx,mi,t;
double pi=2*acos(0);

double distoseg(Point a,Point b)
{
    if(a==b) return Length(p[0]-a);
    Point v1=b-a,v2=p[0]-a,v3=p[0]-b;
    if(dcmp(dot(v1,v2))<0) return Length(v2);
    else if(dcmp(dot(v1,v3))>0) return Length(v3);
    else return fabs(cross(v1,v2))/Length(v1);
}

int main()
{
    while(~scanf("%d",&n))
    {
        scanf("%lf%lf",&p[0].x,&p[0].y);
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        mi=distoseg(p[n],p[1]);
        mx=Length(p[0]-p[n]);
        for(int i=1;i<n;i++)
        {
            t=distoseg(p[i],p[i+1]);
            if(t<mi) mi=t;
            t=Length(p[0]-p[i]);
            if(t>mx) mx=t;
        }
        printf("%.10f\n",pi*(mx*mx-mi*mi));
    }
    return 0;
}
