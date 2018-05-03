#include<bits/stdc++.h>
using namespace std;
const int N=50000+10;
const double eps=1e-8;
double ans,x[N],w[N];
int n;

double get(double k)
{
    double ret=0;
    for(int i=0;i<n;i++)
    {
        double t=fabs(x[i]-k);
        ret+=t*t*t*w[i];
    }
    return ret;
}

int main()
{
    int _,__;
    double L=1e6,R=-1e6,ll,rr;
    scanf("%d",&__);
    for(_=1;_<=__;_++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",x+i,w+i);
            L=min(L,x[i]);
            R=max(R,x[i]);
        }
        while(R-L>eps)
        {
            ll=(2*L+R)/3;
            rr=(2*R+L)/3;
            double al=get(ll);
            double ar=get(rr);
            if(al<ar)
                R=rr;
            else
                L=ll;
        }
        printf("Case #%d: %.0f\n",_,get(R));
    }
    return 0;
}
