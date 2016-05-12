#include<bits/stdc++.h>
using namespace std;
int p[1024],g[1024];

int dp[1024][1024],N,flag,l;

int main()
{
    int _,n,k,up;
    scanf("%d",&_);
    string s;
    char st[1024];
    while(_--)
    {
        scanf("%d%d%d",&n,&k,&l);
        memset(g,0,sizeof(g));
        up=-1;
        flag=0;
        for(int t=0;t<n;t++)
        {
            scanf("%s",st);
            s="$#";
            for(int i=0;st[i]!=0;i++)
            {
                s+=st[i];
                s+="#";
            }
            memset(p,0,sizeof(p));
            int mx=0,id=0;
            int len=s.size();
            for(int i=1;i<=len;i++)
            {
                if(mx>i)
                {
                    p[i] = (p[2*id - i] < (mx - i) ? p[2*id - i] : (mx - i));
                }
                else
                {
                    p[i]=1;
                }
                while(s[i-p[i]]==s[i+p[i]])
                    p[i]++;
                if(i+p[i]>mx)
                {
                    mx=i+p[i];
                    id=i;
                }
            }
            for(int i=1;i<=len;i++)
            {
                if(p[i]-1>up) up=p[i]-1;
                g[p[i]-1]++;
            }
        }
        N=k;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int cost;
        for(int i=1;i<=up;i++)
        {
            if(g[i]==0) continue;
            for(int j=1;j<=g[i];j*=2)
            {
                g[i]-=j;
                cost=j*i;
                if(cost>l) continue;
                for(int a=k;a>=0;a--)
                {
                    if(j+a>k) continue;
                    for(int b=l-cost;b>=0;b--)
                    {
                        if(dp[a][b])
                            dp[a+j][b+cost]=1;
                    }
                }
            }
        }
        if(dp[k][l]==0) puts("False");
        else puts("True");
    }
    return 0;
}
