#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
typedef long long ll;
const int N=50000+10;
struct node
{
    int l,r,id;
}Q[N];

int pos[N],n,m,L,R;
int cmp(node a,node b)
{
    if(pos[a.l]==pos[b.l])
        return a.r<b.r;
    return pos[a.l]<pos[b.l];
}

ll a[N],up[N],down[N],cnt[N],p1,p2,tmp;

void add(int x)
{
    int t=a[x];
    p1=p1-cnt[t]*cnt[t]+cnt[t];
    cnt[t]++;
    p1=p1+cnt[t]*cnt[t]-cnt[t];
}

void del(int x)
{
    int t=a[x];
    p1=p1-cnt[t]*cnt[t]+cnt[t];
    cnt[t]--;
    p1=p1+cnt[t]*cnt[t]-cnt[t];
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int sz=sqrt(n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[i]=i/sz;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&Q[i].l,&Q[i].r);
            Q[i].id=i;
        }
        sort(Q+1,Q+1+m,cmp);
        memset(cnt,0,sizeof(cnt));
        L=1;
        R=0;
        p1=0;
        p2=0;
        for(int i=1;i<=m;i++)
        {
            while(L<Q[i].l)
            {
                del(L);
                L++;
            }
            while(L>Q[i].l)
            {
                L--;
                add(L);
            }
            while(R<Q[i].r)
            {
                R++;
                add(R);
            }
            while(R>Q[i].r)
            {
                del(R);
                R--;
            }
            if(p1==0)
            {
                up[Q[i].id]=0;
                down[Q[i].id]=1;
            }
            else
            {
                p2=(ll)(R-L+1)*(R-L);
                tmp=__gcd(p1,p2);
                up[Q[i].id]=p1/tmp;
                down[Q[i].id]=p2/tmp;
            }
        }
        for(int i=1;i<=m;i++)
            printf("%lld/%lld\n",up[i],down[i]);
    }
    return 0;
}
