#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100000+10],b[100000+10],k;

int get(long long x)
{
    long long tmp=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]*x>b[i])
        {
            tmp+=a[i]*x-b[i];
        }
        if(tmp>k) return 0;
    }
    //printf("%lld",k);
    return 1;
}
int main()
{
    while(~scanf("%d%lld",&n,&k))
    {
        for(int i=0;i<n;i++)
            scanf("%lld",a+i);
        for(int i=0;i<n;i++)
            scanf("%lld",b+i);
        long long L=0,R=2e9,mid,ans=0;
        while(L<=R)
        {
            mid=L+(R-L)/2;
            if(get(mid)==1)
            {
                ans=mid;
                L=mid+1;
            }
            else
            {
                R=mid-1;
            }

        }
        printf("%lld\n",ans);
    }
    return 0;
}
