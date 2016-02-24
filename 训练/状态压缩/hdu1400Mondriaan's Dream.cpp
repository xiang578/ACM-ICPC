#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int db[1<<12],n,m,up;
ll dp[12][1<<12];

int lowbit(int x)
{
    return x&-x;
}
int get(int x)
{
    int a,b;
    while(x>0)
    {
        a=lowbit(x);
        x-=lowbit(x);
        if(x==0) return 0;
        b=lowbit(x);
        x-=lowbit(x);
        if (b>a*2) return 0;
    }
    return 1;
}
int main()
{
    int i,j,k,cnt,tmp;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(dp,0,sizeof(dp));
        up=1<<m;
        cnt=0;
        for(i=0; i<up; i++)
        {
            if(get(i))
                db[cnt++]=i;
        }
        for(i=0; i<cnt; i++)
        {
            dp[1][db[i]]=1;
        }

        for(k=2;k<=n;k++)
        {
            for(i=0;i<up;i++)
            {
                if(dp[k-1][i]==0) continue;
                tmp=(up-1)^i;
                for(j=0;j<cnt;j++)
                {
                    if(tmp&db[j]) continue;
                    dp[k][tmp|db[j]]+=dp[k-1][i];
                }
            }
        }
        printf("%lld\n",dp[n][up-1]);
    }
    return 0;
}
