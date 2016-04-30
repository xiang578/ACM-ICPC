#include<bits/stdc++.h>
using namespace std;
const int N=1024;
int g[N][N],r[N],h[N][N],l[N];
char s[N][N],st[N];
int n,m;

int fcn(int k)
{
    if(k==0)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i][j]=='a'||s[i][j]=='w'||s[i][j]=='z'||s[i][j]=='y')
                    g[i][j]=1;
                else g[i][j]=0;
            }
        }
    }

    if(k==1)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i][j]=='b'||s[i][j]=='w'||s[i][j]=='z'||s[i][j]=='x')
                {
                    g[i][j]=1;
                }
                else g[i][j]=0;
            }
        }
    }

    if(k==2)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i][j]=='c'||s[i][j]=='x'||s[i][j]=='z'||s[i][j]=='y')
                {
                    g[i][j]=1;
                }
                else g[i][j]=0;
            }
        }
    }
}
int main()
{
    int _,i,j,k,ans1,ans;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1; i<=n; i++)
        {
            scanf("%s",st);
            for(j=1; j<=m; j++)
            {
                s[i][j]=st[j-1];
            }

        }
        ans=0;
        for(k=0; k<3; k++)
        {
            fcn(k);
            memset(h,0,sizeof(h));
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=m; j++)
                {
                    if(g[i][j]==0)  h[i][j]=0;
                    else   h[i][j]=h[i-1][j]+1;
                }
            }
            ans1=0;
            for(i=1; i<=n; i++)
            {
                for(j=1;j<=m;j++)
                    l[j]=r[j]=j;
                h[i][0]=h[i][m+1]=-1;
                for(j=m; j>=1; j--)
                {
                    while(h[i][r[j]+1]>=h[i][j])
                        r[j]=r[r[j]+1];
                }
                for(j=1; j<=m; j++)
                {
                    while(h[i][l[j]-1]>=h[i][j])
                        l[j]=l[l[j]-1];
                }
                for(j=1; j<=m; j++)
                {
                    ans1=max(ans1,(r[j]-l[j]+1)*h[i][j]);
                }
            }
            ans=max(ans1,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
