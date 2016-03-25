#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int dp[2000000],t;

void zeroonepack(int cost,int weight)
{
    for(int i=t;i>=cost;i--)
    {
        dp[i]=max(dp[i],dp[i-cost]+weight);
    }
}

void completepack(int cost,int weight)
{
    for(int i=cost;i<=t;i++)
    {
        dp[i]=max(dp[i],dp[i-cost]+weight);
    }
}

void multiplepack(int cost,int weight,int amount)
{
    if(amount*cost>=t)
        completepack(cost,weight);
    else
    {
        int k=1;
        while(k<amount)
        {
            zeroonepack(cost*k,weight*k);
            amount-=k;
            k*=2;
        }
        zeroonepack(cost*amount,weight*amount);
    }
}
int main()
{
    int n,v,i,j,a[100+5],b[100+5];
    while(~scanf("%d",&n))
    {
        if(n<=0) break;
        v=0;

        for(i=0;i<n;i++)
            {
                scanf("%d %d",&a[i],&b[i]);
                v+=a[i]*b[i];
            }

        t=v/2;
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            multiplepack(a[i],a[i],b[i]);
        }
        printf("%d %d\n",v-dp[t],dp[t]);
    }
    return 0;
}
