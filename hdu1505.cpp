#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int N=50005;
int n,k,m;
int s[1005];
int v[1005][1005],r[1005][1005],x[1005][1005],a[1005][1005];
char c[1005];
int main()
{
    int i,j,ans;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(s,0,sizeof(s));
        memset(r,0,sizeof(r));
        memset(x,0,sizeof(x));
        for(i=1; i<=n; i++)
        {
            scanf("%s",c);
            for(j=0;j<n;j++)
                a[i][j+1]=c[j]-'0';
        }
        x[n+1][n]=0;
        r[n][n+1]=0;
        v[n+1][n+1]=0;
        ans=0;
        for(i=n; i>=1; i--)
        {
            for(j=n; j>=1; j--)
            {
                if(a[i][j])
                {
                    v[i][j]=min(min(v[i+1][j+1],r[i][j+1]),x[i+1][j]);
                    r[i][j]=r[i][j+1]+1;
                    x[i][j]=x[i+1][j]+1;
                    v[i][j]++;
                }
                else
                    v[i][j]=r[i][j]=x[i][j]=0;
                ans=max(ans,v[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
