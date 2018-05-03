#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;
typedef long long ll;
const int N=100000+10;
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

ll a[N],b[N],out[N],ans,mp[N],has[N];

void add(int x)
{
    int t=a[x];
    ans=ans-mp[t]*mp[t]*mp[t];
    mp[t]++;
    ans=ans+mp[t]*mp[t]*mp[t];
}

void del(int x)
{
    int t=a[x];
    ans=ans-mp[t]*mp[t]*mp[t];
    mp[t]--;
    ans=ans+mp[t]*mp[t]*mp[t];
}

int main()
{
    while(~scanf("%d",&n))
    {
        int sz=(int)sqrt(1.0*n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            pos[i]=i/sz;
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        int t=1;
        has[t]=b[1];
        for(int i=2;i<=n;i++)
        {
            if(b[i]==b[i-1]) continue;
            t++;
            has[t]=b[i];
        }
        for(int i=1;i<=n;i++)
        {
            a[i]=lower_bound(has+1,has+t+1,a[i])-has+1;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&Q[i].l,&Q[i].r);
            Q[i].id=i;
        }
        sort(Q+1,Q+1+m,cmp);
       memset(mp,0,sizeof(mp));
        L=1;
        R=0;
        ans=0;
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
            out[Q[i].id]=ans;
        }
        for(int i=1;i<=m;i++)
            printf("%lld\n",out[i]);
    }
    return 0;
}
