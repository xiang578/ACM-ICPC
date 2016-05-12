#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e6;
const int N=1<<20;

struct node
{
    int l,r,id;
}Q[M];

ll ans,p[M],flag[N];
int a[N],pos[N];

int cmp(node n1,node n2)
{
    if(pos[n1.l]==pos[n2.l])
        return n1.r<n2.r;
    return pos[n1.l]<pos[n2.l];
}

int n,m,k;

void del(int x)
{
    flag[a[x]]--;
    ans-=flag[a[x]^k];
}

void add(int x)
{
    ans+=flag[a[x]^k];
    flag[a[x]]++;
}

int main()
{
    int sz,L=1,R=0;
    scanf("%d%d%d",&n,&m,&k);
    a[0]=0;
    sz=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]=a[i-1]^a[i];
        pos[i]=i/sz;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].id=i;
    }
    sort(Q+1,Q+1+m,cmp);
    flag[0]=1;
    ans=0;
    for(int i=1;i<=m;i++)
    {
        while(L<Q[i].l)
        {
            del(L-1);
            L++;
        }
        while(L>Q[i].l)
        {
            L--;
            add(L-1);
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
        p[Q[i].id]=ans;
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",p[i]);
    return 0;
}
