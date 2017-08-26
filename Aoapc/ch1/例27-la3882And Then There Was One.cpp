#include <stdio.h>

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int pre,i,n,k,m,ans;
    while(~scanf("%d%d%d",&n,&k,&m))
    {
        if(n==0&&k==0&&m==0) break;
        pre=0;
        for(i=2;i<=n;i++)
        {
            ans=(pre+k)%i;
            pre=ans;
            //printf("%d ",ans);
        }
        ans=(ans-k+m+1)%n;
        if(ans<=0) ans+=n;
        printf("%d\n",ans);
    }
    return 0;

}
