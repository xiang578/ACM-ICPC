#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5000+10;
ll a[N],b[N],c[N],d[N];
int n;
int main()
{
    int m;
    while(~scanf("%d",&n))
    {
        for(int i=n-1; i>=0; i--)
        {
            scanf("%lld",a+i);
            b[i]=a[i];
        }
        sort(b,b+n);
        for(int i=0; i<n; i++)
        {
            int k=lower_bound(b,b+n,a[i])-b;
            a[i]=k+1;
        }
        memset(c,0,sizeof(c));
        b[0]=a[0];
        m=1;
        c[0]=1;
        d[0]=0;
        for(int i=1; i<n; i++)
        {
            int k=lower_bound(b,b+m,a[i])-b;
            if(k==m)
            {
                m++;
                b[k]=a[i];
            }
            else
            {
                b[k]=a[i];
            }
            d[i]=k;
            ll t=0;
            for(int j=i-1;j>=0;j--)
            {
                if(d[j]+1==d[i]&&a[j]<a[i])
                {
                    t+=c[j];
                }
                if(d[i]==d[j]&&a[i]==a[j]) break;
                if(k==0&&j==0) t=1;
            }
            c[i]=t;
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(d[i]==m-1) ans+=c[i];
        }
        printf("%d %lld\n",m,ans);
    }
    return 0;
}
/*#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5000+10;
ll a[N],b[N],c[N],d[N],ans;
int n;
struct node
{
    int id,num;
}p[N];

int cmp(node n1,node n2)
{
    if(n1.num==n2.num)
         return n1.id>n2.id;
    else
        return n1.num<n2.num;
}

ll get(int x)
{
    ll r=0;
    while(x)
    {
        r+=b[x];
        x-=x&(-x);
    }
    return r;
}

void add(int x,ll v)
{
    while(x<=m)
    {
        b[x]+=v;
        x+=x&(-x);
    }
}

int main()
{
    int m;
    while(~scanf("%d",&n))
    {
        for(int i=n-1; i>=0; i--)
        {
            scanf("%lld",a+i);
            b[i]=a[i];
        }
        sort(b,b+n);
        for(int i=0; i<n; i++)
        {
            int k=lower_bound(b,b+n,a[i])-b;
            a[i]=k+1;
        }
        b[0]=a[0];
        m=1;
        p[0].id=0;
        p[0].num=(int)a[0];
        for(int i=1; i<n; i++)
        {
            int k=lower_bound(b,b+m,a[i])-b;
            if(k==m)
            {
                m++;
                b[k]=a[i];
                p[i].id=k+1;
                p[i].num=(int)a[i];
            }
            else
            {
                b[k]=a[i];
                p[i].id=k+1;
                p[i].num=(int)a[i];
            }
        }
        sort(p,p+n,cmp);
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {

            if(p[i].id==1)
                add(1,1);
            else
            {

            }
        }
        ll ans=get(m)-get(m-1);
        printf("%d %lld\n",m,ans);
        /*
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        ll ans=0;
        int k=0;
        while(p[k].id==0&&k<n)
        {
            if(k&&p[k-1].id==p[k].id&&p[k-1].num==p[k].num) {k++;continue;}
            add(p[k].num,1);
            k++;
        }
        for(int i=1;i<m;i++)
        {
            //printf("%d\n",i);
            ans=0;
            while(p[k].id==i&&k<n)
            {
                //printf("%d\n",k);
                 if(k&&p[k-1].id==p[k].id&&p[k-1].num==p[k].num) {k++;continue;}
                ll t=get(p[k].num-1);
                add2(p[k].num,t);
                k++;
            }
            for(int j=0;j<=n;j++)
            {
                b[j]=c[j];
                c[j]=0;
            }
        }
        //printf("111");
        ans=get(n);
         printf("%d %lld\n",m,ans);
         */
        /*memset(d,0,sizeof(d));
        memset(b,0,sizeof(b));
        b[0]=1;
        for(int i=0; i<n; i++)
        {
            int k=p[i].id;
            int j=p[i].num;
            ll t=b[k]-d[k+1][j];
            b[k+1]+=t;
            d[k+1][j]+=t;
            printf("%d %d %lld %lld %lld %lld %lld\n",k,j,d[k+1][j],b[1],b[2],b[3],b[4]);
        }*/
/*
    }
    return 0;
}
*/
/*ll a[N],dp[N],f[N];

int main()
{
    int n;
    ll ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        f[i]=1;
    }
    ans=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[j]>a[i])
            {
                if(dp[j]+1>dp[i])
                {
                    f[i]=f[j];
                    dp[i]=dp[j]+1;
                }
                else if(dp[j]+1==dp[i])
                {
                    f[i]+=f[j];
                }
                ans=max(ans,dp[i]);
            }
        }
    }
    ll cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==ans)
        {
            cnt+=f[i];
        }
    }
    printf("%lld %lld\n",ans,cnt);
    return 0;
}
*/
