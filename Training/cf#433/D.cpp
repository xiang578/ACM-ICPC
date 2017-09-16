#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <set>
#include <time.h>
#include <cmath>
using namespace std;
const int N=1000000+10;
typedef long long ll;
const ll mx=1e18;
int n,m,k;
long long cost[N],l[N],r[N];
struct node
{
    int d,f,t;
    ll c;
}p[N];
int cmp(node a,node b)
{
    return a.d<b.d;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<N;i++)
        cost[i]=l[i]=r[i]=-1;
    int up=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d%lld",&p[i].d,&p[i].f,&p[i].t,&p[i].c);
    }
    sort(p,p+m,cmp);
    int cnt=0;
    ll all=0;
    int now=1;
    up=p[m-1].d;
    for(int i=0;i<m;i++)
    {
        while(now<p[i].d)
        {
            now++;
            l[now]=l[now-1];
        }
        if(p[i].f==0) continue;
        if(cost[p[i].f]==-1)
        {
            cnt++;
            all+=p[i].c;
            cost[p[i].f]=p[i].c;
        }
        else if(cost[p[i].f]>p[i].c)
        {
            all=all-cost[p[i].f]+p[i].c;
            cost[p[i].f]=p[i].c;
        }
        if(cnt==n) l[now]=all;
    }
    memset(cost,0xff,sizeof(cost));
    cnt=0;
    all=0;
    now=up;
    for(int i=m-1;i>=0;i--)
    {
        while(now>p[i].d)
        {
            now--;
            r[now]=r[now+1];
        }
        if(p[i].f!=0) continue;
        if(cost[p[i].t]==-1)
        {
            cnt++;
            all+=p[i].c;
            cost[p[i].t]=p[i].c;
        }
        else if(cost[p[i].t]>p[i].c)
        {
            all=all-cost[p[i].t]+p[i].c;
            cost[p[i].t]=p[i].c;
        }
        if(cnt==n) r[now]=all;
    }
    ll ans=mx;
    for(int i=1;i<=up;i++)
    {
        if(i+k+1>up)
            break;
        if(l[i]==-1||r[i+k+1]==-1) continue;
        ans=min(ans,l[i]+r[i+k+1]);
    }
    if(ans==mx) ans=-1;
    printf("%lld\n",ans);
    return 0;
}
