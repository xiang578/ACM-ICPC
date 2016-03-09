#include <cstdio>
#include <string.h>
using namespace std;
int num[20],dp[20][200000];
int dfs(int pos,int s,int lim)
{
    int ans=0,now_s,i,u;
    if(s<0) return 0;
    if(pos<=0) return 1;
    if(!lim&&dp[pos][s]!=-1)   return dp[pos][s];

    u=lim?num[pos]:9;
    for(i=0;i<=u;i++)
    {
        now_s=s-i*(1<<(pos-1));
        ans+=dfs(pos-1,now_s,lim&&i==u);
    }
    if(!lim) dp[pos][s]=ans;
    return ans;
}

int main()
{
    int _,t,a,b,i,j,tmp;
    scanf("%d",&_);
    memset(dp,0xff,sizeof(dp));
    for(t=1;t<=_;t++)
    {
        scanf("%d%d",&a,&b);
        i=0;
        while(b)
        {
            num[++i]=b%10;
            b/=10;
        }
        tmp=0;
        j=1;
        while(a)
        {
            tmp+=j*(a%10);
            a/=10;
            j<<=1;
        }
        printf("Case #%d: %d\n",t,dfs(i,tmp,1));
    }
    return 0;
}
