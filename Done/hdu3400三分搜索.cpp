#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
struct point
{
    double x,y;
}a,b,c,d;
double p,q,rt,ab,cd,ans;

double dis(point x,point y)
{
    double tmp;
    tmp=(x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
    return sqrt(tmp+eps);
}

double fcd(double t1,double t2)
{
    double ret;
    point n,m;
    n.x=t2/ab*(b.x-a.x)+a.x;
    n.y=t2/ab*(b.y-a.y)+a.y;

    m.x=t1/cd*(c.x-d.x)+d.x;
    m.y=t1/cd*(c.y-d.y)+d.y;
    //printf("%lf %lf %lf %lf\n",n.x,n.y,m.x,m.y);
    ret=t1/q+t2/p+dis(n,m)/rt;
    //cout<<p<<q<<r<<endl;
    //cout<<ret<<endl;
    //printf("%lf %lf\n",r,dis(n,m)/r);
    return ret;
}

double f(double t)
{
    double l,r,mid,mmid,f1,f2,ret=1e8;
    l=0;r=cd;
    while(fabs(r-l)>eps)
    {
        mid=(l+r)/2;
        mmid=(mid+r)/2;
        f1=fcd(mid,t);
        f2=fcd(mmid,t);
        if(f1<f2)
            r=mmid;
        else
            l=mid;
        ret=min(ret,min(f1,f2));
    }
    return ret;
}

int main()
{
    int _;
    scanf("%d",&_);
    double l,r,mid,mmid,f1,f2;
    while(_--)
    {
        scanf("%lf%lf",&a.x,&a.y);
        scanf("%lf%lf",&b.x,&b.y);
        scanf("%lf%lf",&c.x,&c.y);
        scanf("%lf%lf",&d.x,&d.y);
        scanf("%lf%lf%lf",&p,&q,&rt);
        ab=dis(a,b);
        cd=dis(c,d);
        //printf("%lf %lf",r,cd/q);
        l=0;
        r=ab;
        ans=1e8;
        while(fabs(r-l)>eps)
        {
            mid=(l+r)/2;
            mmid=(mid+r)/2;
            f1=f(mid);
            f2=f(mmid);
            if(f1<f2)
                r=mmid;
            else
                l=mid;
            //printf("%lf %lf\n",r,l);
            ans=min(ans,min(f1,f2));
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
