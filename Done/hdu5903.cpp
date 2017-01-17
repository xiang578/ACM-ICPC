#include<bits/stdc++.h>
using namespace std;
int dp[1024][1024],p[1024][1024];
char s[1024],ans[1024];

int main()
{
    int _,n,m,k;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",s+1);
        k=n/2;
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));
        dp[k+1][0]=1;
        for(int i=k;i>=1;i--)
        {
            if(s[i]==s[i+k])
            {
                for(int j=0;j<=m;j++)
                {
                    if(dp[i+1][j]==1)
                        dp[i][j+2]=dp[i][j]=1;
                }
            }
            else if(s[i]!=s[i+k])
            {
                for(int j=0;j<=m;j++)
                {
                    if(dp[i+1][j]==1)
                        dp[i][j+1]=dp[i][j+2]=1;
                }
            }
        }
        if(dp[1][m]==0) {puts("Impossible");continue;}
        int now=m;
        for(int i=1;i<=k;i++)
        {
            if(s[i]==s[i+k])
            {
                if(s[i]=='a')
                {
                    if(dp[i+1][now]==1)
                    {
                        now-=0;
                        ans[i]=s[i];
                    }
                    else
                    {
                        now-=2;
                        ans[i]='b';
                    }
                }
                else
                {
                    if(dp[i+1][now-2]==1)
                    {
                        now-=2;
                        ans[i]='a';
                    }
                    else
                    {
                        now-=0;
                        ans[i]=s[i];
                    }
                }
            }
            else
            {
                char t='a';
                if(t==s[i]||t==s[i+k]) t++;
                if(t==s[i]||t==s[i+k]) t++;
                if(t=='a')
                {
                    if(dp[i+1][now-2]==1)
                    {
                        now-=2;
                        ans[i]='a';
                    }
                    else
                    {
                        now-=1;
                        ans[i]=min(s[i],s[i+k]);
                    }
                }
                else if(t=='b')
                {
                    if(dp[i+1][now-1]==1)
                    {
                        now-=1;
                        ans[i]='a';
                    }
                    else
                    {
                        now-=2;
                        ans[i]='b';
                    }
                }
                else if(t=='c')
                {
                    if(dp[i+1][now-1]==1)
                    {
                        now-=1;
                        ans[i]='a';
                    }
                    else
                    {
                        now-=2;
                        ans[i]='c';
                    }
                }
            }
        }
        printf("%s%s\n",ans+1,ans+1);
    }
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
char s[1024];
int dp[1024][1024];
int x[1024][1024],y[1024][1024];

int main()
{
    int _,n,m,k;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",s+1);
        k=n/2;
        memset(dp,0,sizeof(dp));

        if(s[1]==s[k+1])
        {
            dp[1][0]=s[1];
            if(s[1]=='a') dp[1][2]='b';
            else dp[1][2]='a';
        }
        else
        {
            dp[1][1]=min(s[1],s[k]);
            if(s[1]!='a'&&s[k]!='a') dp[1][2]='a';
            else if(s[1]!='b'&&s[k]!='b') dp[1][2]='b';
            else if(s[1]!='c'&&s[k]!='c') dp[1][2]='c';
        }
        for(int i=2; i<=k; i++)
        {
            if(s[i]==s[i+k])
            {
                for(int j=0; j<=m; j++)
                {
                    if(dp[i-1][j]==0) continue;
                    int t=dp[i-1][j];
                    t+=s[i];
                    if(dp[i][j]==0||t<dp[i][j]) dp[i][j]=t;
                    t=dp[i-1][j];
                    if(s[i]!='a'&&s[i+k]!='a') t+="a";
                    else if(s[i]!='b'&&s[i+k]!='b') t+="b";
                    else if(s[i]!='c'&&s[i+k]!='c') t+="c";
                    if(dp[i][j+2]==""||t<dp[i][j+2]) dp[i][j+2]=t;
                }
            }
            else if(s[i]!=s[i+k])
            {
                for(int j=0; j<=m; j++)
                {
                    if(dp[i-1][j]=="") continue;
                    string t=dp[i-1][j];
                    t+=min(s[i],s[k+i]);
                    if(dp[i][j+1]==""||t<dp[i][j+1]) dp[i][j+1]=t;
                    t=dp[i-1][j];
                    if(s[i]!='a'&&s[i+k]!='a') t+="a";
                    else if(s[i]!='b'&&s[i+k]!='b') t+="b";
                    else if(s[i]!='c'&&s[i+k]!='c') t+="c";
                    if(dp[i][j+2]==""||t<dp[i][j+2]) dp[i][j+2]=t;
                }
            }
        }
        if(dp[k][m]=="") puts("Impossible");
        else cout<<dp[k][m]<<dp[k][m]<<endl;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
char s[1024];
string dp[1024][1024];

int main()
{
    int _,n,m,k;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",s+1);
        k=n/2;
        for(int i=1; i<=1000; i++)
            for(int j=1; j<=1000; j++)
                dp[i][j]="";
        if(s[1]==s[k+1])
        {
            dp[1][0]=s[1];
            if(s[1]=='a') dp[1][2]="b";
            else dp[1][2]="a";
        }
        else
        {
            dp[1][1]=min(s[1],s[k]);
            if(s[1]!='a'&&s[k]!='a') dp[1][2]="a";
            else if(s[1]!='b'&&s[k]!='b') dp[1][2]="b";
            else if(s[1]!='c'&&s[k]!='c') dp[1][2]="c";
        }
        for(int i=2; i<=k; i++)
        {
            if(s[i]==s[i+k])
            {
                for(int j=0; j<=m; j++)
                {
                    if(dp[i-1][j]=="") continue;
                    string t=dp[i-1][j];
                    t+=s[i];
                    if(dp[i][j]==""||t<dp[i][j]) dp[i][j]=t;
                    t=dp[i-1][j];
                    if(s[i]!='a'&&s[i+k]!='a') t+="a";
                    else if(s[i]!='b'&&s[i+k]!='b') t+="b";
                    else if(s[i]!='c'&&s[i+k]!='c') t+="c";
                    if(dp[i][j+2]==""||t<dp[i][j+2]) dp[i][j+2]=t;
                }
            }
            else if(s[i]!=s[i+k])
            {
                for(int j=0; j<=m; j++)
                {
                    if(dp[i-1][j]=="") continue;
                    string t=dp[i-1][j];
                    t+=min(s[i],s[k+i]);
                    if(dp[i][j+1]==""||t<dp[i][j+1]) dp[i][j+1]=t;
                    t=dp[i-1][j];
                    if(s[i]!='a'&&s[i+k]!='a') t+="a";
                    else if(s[i]!='b'&&s[i+k]!='b') t+="b";
                    else if(s[i]!='c'&&s[i+k]!='c') t+="c";
                    if(dp[i][j+2]==""||t<dp[i][j+2]) dp[i][j+2]=t;
                }
            }
        }
        if(dp[k][m]=="") puts("Impossible");
        else cout<<dp[k][m]<<dp[k][m]<<endl;
    }
    return 0;
}
*/
/*
int main()
{
    int _,n,m,k;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",s+1);
        k=n/2;
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));
        dp[0][0]=1;
        for(int i=1;i<=k;i++)
        {
            if(s[i]==s[i+k])
            {
                for(int j=0;j<m;j++)
                {
                    if(dp[i-1][j]==1)
                        dp[i][j+2]=dp[i][j]=1;
                }
            }
            else if(s[i]!=s[i+k])
            {
                for(int j=0;j<m;j++)
                {
                    if(dp[i-1][j]==1)
                        dp[i][j+1]=dp[i][j+2]=1;
                }
            }
        }
        if(dp[k][m]==0) {puts("Impossible");continue;}
        int now=m;
        for(int i=k;i>=1;i--)
        {
            if(dp[i-1][now]==1)
            {
                ans[i]=ans[i+k]=s[i];
            }
            else if(dp[i-1][now-1]==1)
            {
                ans[i]=ans[i+k]=min(s[i],s[i+k]);
                now-=1;
            }
            else if(dp[i-1][now-2]==1)
            {
                if(s[i]==s[i+k])
                {
                    if(s[i]=='a') ans[i]=ans[i+k]='b';
                    else ans[i]=ans[i+k]='a';
                }
                else
                {
                    if(s[i]!='a'&&s[i+k]!='a') ans[i]=ans[i+k]='a';
                    else if(s[i]!='b'&&s[i+k]!='b') ans[i]=ans[i+k]='b';
                    else if(s[i]!='c'&&s[i+k]!='c') ans[i]=ans[i+k]='c';
                }
                now-=2;
            }
        }
        printf("%s\n",ans+1);
    }
    return 0;
}
*/
