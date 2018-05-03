#include<bits/stdc++.h>
using namespace std;
const int N=50000+10;
int a[N],ans,l[N],r[N],n,u[N];

void get(int x)
{
    if(x==0) return ;
    int t=0;
    for(int i=x-1;i>=1;i--)
    {
        if(u[i]==1) break;
        if(t==0) t=i;
        else if(a[i]>a[t]) t=i;
    }
    l[x]=t;

    int k=0;
    for(int i=x+1;i<=n;i++)
    {
        if(u[i]==1) break;
        if(k==0) k=i;
        else if(a[i]>a[k]) k=i;
    }
    r[x]=k;
    u[k]=u[t]=1;
    get(t);
    get(k);
}

int main()
{
    int __,_,mx;
    scanf("%d",&__);
    for(_=1;_<=__;_++)
    {
        scanf("%d",&n);
        mx=1;
        memset(u,0,sizeof(u));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            if(a[i]>a[mx]) mx=i;
        }
        u[mx]=1;
        get(mx);
        printf("Case %d:\n",_);
        for(int i=1;i<=n;i++)
        {
            printf("%d %d\n",l[i],r[i]);
        }
    }
    return 0;
}
