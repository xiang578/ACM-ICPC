#include<bits/stdc++.h>
using namespace std;
const int N=100000+5;

int x[N],y[N];

int main()
{
    int n,i,k,flag,cnt,tp,t;
    double p;
    while(~scanf("%d",&n))
    {
        scanf("%lf",&p);
        t=n*p;
        srand(time(0));
        for(i=0;i<n;i++)
            scanf("%d%d",&x[i],&y[i]);
        flag=0;
        if(n<=2) {printf("possible\n");continue;}
        for(i=0;i<1000;i++)
        {
            cnt=2;
            int u=rand()%n,v;
            while(1)
            {
                v=rand()%n;
                if(u!=v) break;
            }
            for(k=0;k<n;k++)
            {
                if(k==u||k==v) continue;
                tp=(x[k]-x[u])*(y[v]-y[u])-(x[v]-x[u])*(y[k]-y[u]);
                if(tp==0) cnt++;
                if(cnt*100>=t) flag=1;
                if(flag) break;
            }
                if(flag) break;
        }
        if(flag) printf("possible\n");
        else printf("impossible\n");
    }
    return 0;
}
