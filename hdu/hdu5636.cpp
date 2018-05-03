#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const long long mod=1e9+7;
int dis[10][10],a[10];

int main()
{
    long long ans;
    int _,n,m,s,t;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<6; i++)
            scanf("%d",&a[i]);
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
                dis[i][j]=abs(a[i]-a[j]);
            }
        }
        dis[0][1]=dis[1][0]=1;
        dis[2][3]=dis[3][2]=1;
        dis[4][5]=dis[5][4]=1;
        for(int k=0;k<6;k++)
        {
            for(int i=0;i<6;i++)
            {
                for(int j=0;j<6;j++)
                {
                    dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        ans=0;
        for(int k=1; k<=m; k++)
        {
            scanf("%d%d",&s,&t);
            int tmp=abs(s-t);
            for(int i=0;i<6;i++)
            {
                for(int j=0;j<6;j++)
                {
                    tmp=min(tmp,dis[i][j]+abs(a[i]-s)+abs(a[j]-t));
                }
            }
            ans+=((long long)k*tmp)%mod;
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}
