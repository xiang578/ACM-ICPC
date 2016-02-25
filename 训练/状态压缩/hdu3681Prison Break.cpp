/*#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
struct node
{
    int x,y,cnt,mx;
    int e,s;
};
stack<node>st;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int g[100][100],ecnt,scnt,n,m,ans;
char mp[100][100];
int vis[15][15][1<<15+1];

void bfs(int x,int y)
{
    int i,j,up,k;
    node p,t;
    up=1<<scnt;
    while(!st.empty()) st.pop();
    p.x=x;
    p.y=y;
    p.cnt=0;
    p.mx=0;
    p.e=0;
    p.s=0;
    memset(vis,0xff,sizeof(vis));
    st.push(p);
    while(!st.empty())
    {
        p=st.top();
        st.pop();
        if(p.s==up-1)
        {
            ans=min(p.mx,ans);
            continue;
        }
        for(i=0;i<4;i++)
        {
            t.x=p.x+dx[i];
            t.y=p.y+dy[i];
            t.s=p.s;
            t.e=p.e;
            t.mx=p.mx;
            t.cnt=p.cnt+1;
            t.mx=max(t.mx,t.cnt);
            if(t.x<0||t.x>=n||t.y<0||t.y>=m) continue;
            if(mp[t.x][t.y]=='D') continue;
            if(mp[t.x][t.y]=='Y')
            {
                k=1<<g[t.x][t.y];
                t.s=t.s|k;
            }
            if(mp[t.x][t.y]=='G')
            {
                k=1<<g[t.x][t.y];
                if((t.e&k)==0)
                {
                    t.cnt=0;
                    t.e=t.e|k;
                }
            }
            if(vis[t.x][t.y][t.s]==-1||t.cnt<=vis[t.x][t.y][t.s])
            {
                vis[t.x][t.y][t.s]=t.cnt;
                st.push(t);
            }
        }
    }
}
int main()
{
    int i,j,x,y;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        for(i=0;i<n;i++)
            scanf("%s",mp[i]);
        scnt=ecnt=0;
        ans=inf;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mp[i][j]=='F')
                {
                    x=i;
                    y=j;
                }
                else if(mp[i][j]=='G')
                {
                    g[i][j]=ecnt;
                    ecnt++;
                }
                else if(mp[i][j]=='Y')
                {
                    g[i][j]=scnt;
                    scnt++;
                }
            }
        }
        //if(scnt==0) ans=0
        bfs(x,y);
        if(ans>=inf) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
*/
