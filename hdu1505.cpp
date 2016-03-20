#include<bits/stdc++.h>
using namespace std;
const int N=1024;
int g[N][N],r[N][N],h[N][N],l[N][N];

int main()
{
    int _,n,m,i,j,k,ans;
    char s[4000];
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        //getchar();
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%s",s);
                if(s[0]=='R') g[i][j]=0;
                else g[i][j]=1;
                r[i][j]=l[i][j]=j;
            }
        }
        memset(h,0,sizeof(h));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(g[i][j]==0) h[i][j]=0;
                else h[i][j]=h[i-1][j]+1;
            }
        }
        ans=0;
        //printf("11111\n");
        for(i=1;i<=n;i++)
        {
            //printf("%d",i);
            h[i][0]=h[i][m+1]=-1;
            for(j=m;j>=1;j--)
            {
                while(h[i][r[i][j]+1]>=h[i][r[i][j]])
                    r[i][j]=r[i][r[i][j]+1];
            }

            for(j=1;j<=m;j++)
            {
                while(h[i][l[i][j]-1]>=h[i][l[i][j]])
                    l[i][j]=l[i][l[i][j]-1];
            }
            for(j=1;j<=m;j++)
            {
                //printf("%d %d %d %d\n",(l[i][j]-r[i][j]+1)*h[i][j],r[i][j],l[i][j],h[i][j]);
                ans=max(ans,(r[i][j]-l[i][j]+1)*h[i][j]);
            }
        }
        printf("%d\n",3*ans);
    }
    return 0;
}
