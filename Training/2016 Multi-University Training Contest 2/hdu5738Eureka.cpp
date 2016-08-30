#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll f[1024];
struct node
{
    ll x,y;
}p[1024],t[1024];
int cmp(node n1,node n2)
{
    if(n1.x==n2.x) return n1.y<n2.y;
    else return n1.x<n2.x;
}

int main()
{
    int _,n;
    scanf("%d",&_);
    f[0]=1;
    for(int i=1;i<=1000;i++)
        f[i]=(f[i-1]*2)%mod;
    while(_--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&p[i].x,&p[i].y);
        }
        ll ans=0;
        sort(p,p+n,cmp);
        for(int i=0;i<n;i++)
        {
            int num1=0,cnt=0,d=0,num=0;
            //num1重点个数，d直线条数，num直线上的点个数
            for(int j=i+1;j<n;j++)
            {
                if(p[j].x==p[i].x&&p[j].y==p[i].y)
                {
                    num1++;
                }
                else
                {
                    ll x=p[j].x-p[i].x;
                    ll y=p[j].y-p[i].y;
                    ll tmp=__gcd(x,y);
                    if(tmp<0) tmp=-tmp;
                    t[cnt].x=x/tmp;
                    t[cnt].y=y/tmp;
                    cnt++;
                }
            }
            sort(t,t+cnt,cmp);
            for(int j=0;j<cnt;)
            {
                num=num1+1;
                int k;
                for(k=j+1;k<cnt;k++)
                {
                    if(t[j].x==t[k].x&&t[j].y==t[k].y) num++;
                    else break;
                }
                ans=(ans+f[num]-1)%mod;
                j=k;
                d++;
            }
            ans=(ans-(d-1)*(f[num1]-1)%mod+mod)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
