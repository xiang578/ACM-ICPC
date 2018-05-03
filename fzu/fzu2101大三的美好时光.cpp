#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int N=100000+10;
struct node
{
    int t,l,r,v;
} p[N];
int x[2*N],has[2*N],use[2*N],dp[2*N];

int cmp(node a,node b)
{
    if(a.r==b.r) return a.l<b.l;
    return a.r<b.r;
}

int main()
{
    int i,j,n,cnt,m,s;
    while(~scanf("%d",&n))
    {
        cnt=0;
        for(i=0; i<n; i++)
        {
            scanf("%d%d%d%d",&p[i].t,&p[i].l,&p[i].r,&p[i].v);
            x[cnt]=p[i].l;
            cnt++;
            x[cnt]=p[i].r;
            cnt++;
        }
        sort(x,x+cnt);
        m=1;
        has[m]=x[0];
        for(i=1; i<2*n; i++)
        {
            if(x[i]==x[i-1])  continue;
            m++;
            has[m]=x[i];
        }
        for(i=0; i<n; i++)
        {
            p[i].l=lower_bound(has,has+m+1,p[i].l)-has+1;
            p[i].r=lower_bound(has,has+m+1,p[i].r)-has+1;
        }
        s=0;
        memset(use,0,sizeof(use));
        for(i=0; i<n; i++)
        {
            if(p[i].t) continue;
            s+=p[i].v;
            for(j=p[i].l; j<=p[i].r; j++) use[j]=1;
        }
        for(i=1; i<=m; i++) use[i]+=use[i-1];
        sort(p,p+n,cmp);
        memset(dp,0,sizeof(dp));
        for(i=1,j=0; i<=m; i++)
        {
            dp[i]=dp[i-1];
            for(; j<n&&p[j].r==i; j++)
            {
                if(p[j].t&&(use[p[j].r]==use[p[j].l-1]))
                    dp[i]=max(dp[i],dp[p[j].l-1]+p[j].v);
            }
        }
        printf("%d\n",dp[m]+s);
    }
    return 0;
}
