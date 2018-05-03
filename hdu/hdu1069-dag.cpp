#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,h;
}a[1024];

int dp[1024];

int cmp(node n,node m)
{
    if(n.x==m.x) return n.y<m.y;
    else return n.x<m.x;
}

int main()
{
    int n,m,ans,x,y,z,cas=0;
    while(~scanf("%d",&n)&&n)
    {
        m=1;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            a[m].x=min(x,y);
            a[m].y=max(x,y);
            a[m].h=z;
            m++;
            a[m].x=min(x,z);
            a[m].y=max(x,z);
            a[m].h=y;
            m++;
            a[m].x=min(z,y);
            a[m].y=max(z,y);
            a[m].h=x;
            m++;
        }
        sort(a+1,a+m,cmp);
        memset(dp,0,sizeof(dp));
        a[0].x=-1;
        a[0].y=-1;
        dp[0]=0;
        ans=0;
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i].x>a[j].x&&a[i].y>a[j].y)
                {
                    dp[i]=max(dp[i],dp[j]+a[i].h);
                    ans=max(ans,dp[i]);
                }
            }
        }
        printf("Case %d: maximum height = %d\n",++cas,ans);
    }
    return 0;
}
