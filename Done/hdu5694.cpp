#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,f[65],a[65];

ll dfs(int n,ll x)
{
    if(n==0||x==0) return 0;
    if(n==1) return 1;
    ll m=f[n-1];
    if(x<=m) return dfs(n-1,x);
    //else if(x==f[n]) return a[n];
    else
    {
        //printf("%d %d %d %d\n",a[n-1],x,2*(m+1)-x-1,dfs(n-1,2*(m+1)-x-1));
        return a[n-1]+1+x-m-1-(a[n-1]-dfs(n-1,2*(m+1)-x-1));
    }
}
int main()
{
    f[0]=1;
    for(int i=1;i<=60;i++)
    {
        f[i]=f[i-1]*2;
    }
    f[0]=0;
    for(int i=1;i<=60;i++)
    {
        a[i]=f[i-1]+1;
        f[i]--;
    }
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld%lld",&l,&r);
        int n,m;
        for(n=1;n<=60;n++)
        {
            if(f[n]>=r) break;
        }
        l--;
        for(m=0;m<=60;m++)
        {
            if(f[m]>=l) break;
        }
        printf("%lld\n",dfs(n,r)-dfs(m,l));
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,f[65];

ll dfs(ll x,ll y,int n)
{
    //printf("%lld %lld %d",x,y,n);
    ll ret=0;
    if(n==1) return 1;
    ll m=f[n-1]+1;
    if(y<=m)
    {
        if(y==m) {ret++;y--;}
        ret+=dfs(x,y,n-1);
    }
    else if(x>=m)
    {
        if(x==m) {ret++;x++;}
        ret+=(y-x+1)-dfs(2*m-y,2*m-x,n-1);
    }
    else
    {
        ret=1;
        ret+=dfs(x,f[n-1],n-1)+(y-m)-dfs(2*m-y,f[n-1],n-1);
    }
    return ret;
}
int main()
{
    f[0]=1;
    for(int i=1;i<=60;i++)
    {
        f[i]=f[i-1]*2;
    }
    for(int i=1;i<=60;i++)
    {
        f[i]--;
    }
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld%lld",&l,&r);
        int n;
        for(n=1;n<=60;n++)
        {
            if(f[n]>=r) break;
        }
        printf("%lld\n",dfs(l,r,n));
    }
    return 0;
}
5
3 1000
4 23423412
6 2343240132125134125
734214 2412342423434
34222 554134234123
*/
