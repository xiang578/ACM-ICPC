
#include<bits/stdc++.h>
using namespace std;
const int N=1024;
int g[N][N],n,m,t[N],num[2],cnt[2][N],to[N],q[N],dp[N];
char s[10*N];

int top()
{
    int in[N];
    memset(in,0,sizeof(in));
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(t[i]!=t[j]) continue;
            if(g[i][j]) in[i]++;
            else if(g[j][i]) in[j]++;
        }
    }
    num[0]=num[1]=0;
    for(int i=1;i<=n;i++)
    {
        int j=1;
        for(j=1;j<=n;j++)
        {
            if(in[j]==0)
                break;
        }
        if(j==n+1) return 0;
        to[j]=num[t[j]];
        cnt[t[j]][num[t[j]]++]=j;

        for(int k=1;k<=n;k++)
        {
            if(g[k][j]==1&&t[j]==t[k])
            {
                in[k]--;
            }
        }
        in[j]=-1;
    }
    return 1;
}

int get(int x)
{
    int ret=-1;
    int i;
    for(i=0;i<num[1];i++)
    {
        int y=cnt[1][i];
        if(g[y][x]) break;
    }
    ret=i;
    for(;i<num[1];i++)
    {
        int y=cnt[1][i];
        if(g[x][y]) return -1;
    }
    return ret;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        getchar();
        for(int i=1;i<=n;i++)
        {
            //getchar();
            gets(s);
            int t=1;
            int len=strlen(s);
            for(int j=0;j<len;j++)
            {
                if(s[j]==' ') continue;
                g[i][t++]=s[j]-'0';
            }
        }
        memset(t,0,sizeof(t));
        for(int i=0;i<m;i++)
        {
            int k;
            scanf("%d",&k);
            t[k]=1;
        }
        if(top()==0) printf("NO\n");
        else
        {
            printf("YES ");
            int mx=num[0],ans=0;
            for(int i=0;i<mx;i++)
            {
                q[i]=get(cnt[0][i]);
            }
            memset(dp,0,sizeof(dp));
            for(int i=0;i<mx;i++)
            {
                if(q[i]==-1) continue;
                dp[i]=1;
                for(int j=0;j<i;j++)
                {
                    if(q[j]==-1) continue;
                    if(q[i]>=q[j])
                        dp[i]=max(dp[i],dp[j]+1);
                }
                ans=max(ans,dp[i]);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
