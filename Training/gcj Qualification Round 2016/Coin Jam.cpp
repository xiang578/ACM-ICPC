#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get(ll x)
{
    int i,n=0,t[100];
    ll ret=0;
    memset(t,0,sizeof(t));
    while(x>0)
    {

        t[n]=x%2;
        n++;
        x/=2;
    }
    for(i=n-1; i>=0; i--)
        ret=ret*10+t[i];
    return ret;
}

ll prime(ll x)
{
    ll i;
    for(i=2; i*i<=x; i++)
        if(x%i==0) return i;
    return 0;
}

ll get2(ll x,ll b)
{
    ll ret=0,t=1;
    while(x>0)
    {
        ret+=x%10*t;
        t*=b;
        x/=10;
    }
    return ret;
}

int main()
{

    //freopen("C-small-attempt1.in","r",stdin);
    freopen("C-large.in","r",stdin);
    //freopen("C-out-1.out","w",stdout);
    freopen("C-out-2.out","w",stdout);
    int n,i,j,_,__,cnt;
    ll up,now,tmp,t,k;
    scanf("%d",&_);
    for(__=1; __<=_; __++)
    {
        scanf("%d%d",&n,&j);
        printf("Case #%d:\n",__);
        cnt=0;
        now=(1<<(n-1))+1;
        up=1<<n;
        while(now<up)
        {
            //printf("%lld\n",now);
            tmp=get(now);
            for(k=2; k<=10; k++)
            {
               // printf("%lld\n",now);
                t=get2(tmp,k);
                if(prime(t)==0)
                    break;
            }
            if(k>10)
            {
                cnt++;
                printf("%lld",tmp);
                for(k=2; k<=10; k++)
                {
                    t=get2(tmp,k);
                    printf(" %lld",prime(t));
                }
                printf("\n");
            }
            if(cnt==j) break;
            now+=2;
        }
    }
    return 0;
}
