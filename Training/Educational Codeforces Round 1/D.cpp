#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char g[1024][1024];
int dx[]= {0,0,-1,1};
int dy[]= {1,-1,0,0};
int p[1024][1024];
int n,m,k,cnt;
int ans[1024*1024+10];

int bfs(int x,int y,int t)
{
    int ans=0,i,tx,ty;
    p[x][y]=t;
    queue<int>qx;
    queue<int>qy;
    qx.push(x);
    qy.push(y);
    while(!qx.empty())
    {
        x=qx.front();
        y=qy.front();
        qx.pop();
        qy.pop();
        for(i=0;i<4;i++)
        {
            tx=x+dx[i];
            ty=y+dy[i];
            if(tx<0||tx>=n||ty<0||ty>=m) continue;
            if(g[tx][ty]=='.')
            {
                if(p[tx][ty]==0)
                {
                    p[tx][ty]=t;
                    qx.push(tx);
                    qy.push(ty);
                }
            }
            else if(g[tx][ty]=='*') ans++;
        }
    }
    return ans;
}
int main()
{
    int i,j,k,x,y,t;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(i=0; i<n; i++)
            scanf("%s",g[i]);
        memset(p,0,sizeof(p));
        memset(ans,0,sizeof(ans));
        t=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
        {
            if(g[i][j]=='*') continue;
            if(p[i][j]==0)
            {
                t++;
                ans[t]=bfs(i,j,t);
            }
        }
        while(k--)
        {
            scanf("%d%d",&x,&y);
            x--;
            y--;
            printf("%d\n",ans[p[x][y]]);
        }
    }
    return 0;
}
