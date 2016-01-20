#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
    int id;
    ll a;
} p[100000+5];
ll sum[100000+5],b[100000+5];
int cmp1(node x,node y)
{
    return x.a<y.a;
}

int cmp2(node x,node y)
{
    return x.id<y.id;
}
int pos,i,n;
ll l,r,ans,p1,p2,tp,c,cnt,m,A,cf,cm,amin,cost,mid;

int main()
{

    while(~scanf("%d%lld%lld%lld%lld",&n,&A,&cf,&cm,&m))
    {
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&p[i].a);
            b[i]=p[i].a;
            p[i].id=i;
        }
        sort(p+1,p+1+n,cmp1);
        sort(b+1,b+1+n);
        sum[0]=0;
        for(i=1; i<=n; i++)
            sum[i]=sum[i-1]+p[i].a;
        cost=m;
        cnt=0;
        l=0;
        r=A;
        while(l<=r)
        {
            mid=(l+r)/2;
            pos=lower_bound(b+1,b+n+1,mid)-b-1;
            //printf("%d\n",pos);
            if(pos>=n) pos=n;
            if(mid*pos-sum[pos]<=cost)
            {
                c=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        ans=cm*c;
        p1=pos;
        p2=n+1;
        amin=c;
        //printf("%lld\n",amin);
        for(i=n; i>=1; i--)
        {
            cnt++;
            if(p[i].a!=A)
                cost-=A-p[i].a;
            if(cost>=0)
            {
                l=0;
                r=A;
                c=0;
                while(l<=r)
                {
                    mid=(l+r)/2;
                    pos=lower_bound(b+1,b+n+1,mid)-b-1;
                    if(pos>=i-1) pos=i-1;
                    if(mid*pos-sum[pos]<=cost)
                    {
                        c=mid;
                        l=mid+1;
                    }
                    else
                    {
                        r=mid-1;
                    }
                }
                if(cf*cnt+cm*c>ans)
                {
                    ans=cf*cnt+cm*c;
                    p1=pos;
                    p2=i;
                    amin=c;
                }
            }
        }

        for(i=p2; i<=n; i++)
            p[i].a=A;

        for(i=1; i<=p1; i++)
            p[i].a=amin;

        sort(p+1,p+n+1,cmp2);
        printf("%lld\n",ans);
        for(i=1; i<=n; i++)
        {
            if(i!=1) printf(" ");
            printf("%lld",p[i].a);
        }
        printf("\n");
    }
    return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
    int id;
    ll a;
} p[100000+5];
ll sum[100000+5];
int cmp1(node x,node y)
{
    return x.a<y.a;
}

int cmp2(node x,node y)
{
    return x.id<y.id;
}
int pos,i,n;
ll l,r,ans,p1,p2,tp,c,cnt,m,A,cf,cm,amin,cost,mid;


int main()
{

    while(~scanf("%d%lld%lld%lld%lld",&n,&A,&cf,&cm,&m))
    {
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&p[i].a);
            p[i].id=i;
        }
        sort(p+1,p+1+n,cmp1);
        sum[0]=0;
        for(i=1; i<=n; i++)
            sum[i]=sum[i-1]+p[i].a;
        cost=m;
        cnt=0;
        l=0;
        r=A;
        while(l<=r)
        {
            mid=(l+r)/2;
            pos=lower_bound(sum+1,sum+n+1,mid)-sum-1;
            //printf("%d\n",pos);
            if(pos>=n) pos=n;
            if(mid*pos-sum[pos]<=cost)
            {
                c=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        ans=cm*c;
        p1=pos;
        p2=n+1;
        amin=c;
        //printf("%lld\n",amin);
        for(i=n; i>=1; i--)
        {
            cnt++;
            if(p[i].a!=A)
                cost-=A-p[i].a;
            if(cost>=0)
                {
            l=0;
            r=A;
            c=0;
            while(l<=r)
            {
                mid=(l+r)/2;
                pos=lower_bound(sum+1,sum+n+1,mid)-sum-1;
                if(pos>=i-1) pos=i-1;
                if(mid*pos-sum[pos]<=cost)
                {
                    c=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            if(cf*cnt+cm*c>ans)
            {
                ans=cf*cnt+cm*c;
                p1=pos;
                p2=i;
                amin=c;
            }
                }
        }

        for(i=p2; i<=n; i++)
            p[i].a=A;

        for(i=1; i<=p1; i++)
            p[i].a=amin;

        sort(p+1,p+n+1,cmp2);
        printf("%lld\n",ans);
        for(i=1; i<=n; i++)
        {
            if(i!=1) printf(" ");
            printf("%lld",p[i].a);
        }
        printf("\n");
    }
    return 0;
}
*/
