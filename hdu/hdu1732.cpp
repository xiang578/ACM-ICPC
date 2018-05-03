#include<bits/stdc++.h>
using namespace std;
struct node
{
    int t,x[3],y[3],px,py;
} t,p;
int n,m,px,py,g[10][10];
bool vis[8][8][8][8][8][8][8][8];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

char s[10][10];
vector<int>sx;
vector<int>sy;
vector<int>ex;
vector<int>ey;

int ok(int x,int y)
{
    if(x<0||y<0||x>=n||y>=m) return 0;
    else return 1;
}

int get(int a1,int b1,int a2,int b2,int a3,int b3)
{
    int i;
    for(i=0; i<3; i++)
    {
        if(a1==ex[i]&&b1==ey[i]) continue;
        else if(a2==ex[i]&&b2==ey[i]) continue;
        else if(a3==ex[i]&&b3==ey[i]) continue;
        else break;
    }
    if(i==3) return 1;
    else return 0;
}

int bfs()
{
    memset(vis,0,sizeof(vis));
    queue<node>q;
    p.px=px;
    p.py=py;
    p.t=0;
    for(int i=0; i<3; i++)
    {
        p.x[i]=sx[i];
        p.y[i]=sy[i];
    }
    q.push(p);
    while(!q.empty())
    {
        t=q.front();
        //printf("%d %d\n",t.px,t.py);
        q.pop();
        if(get(t.x[0],t.y[0],t.x[1],t.y[1],t.x[2],t.y[2])==1)
            return t.t;
        memset(g,0,sizeof(g));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='#') g[i][j]=-1;
            }
        }
        for(int i=0; i<3; i++)
            g[t.x[i]][t.y[i]]=i+1;
        for(int i=0; i<4; i++)
        {
            p=t;
            p.t++;
            p.px=dx[i]+p.px;
            p.py=dy[i]+p.py;
            if(ok(p.px,p.py)==0||g[p.px][p.py]==-1) continue;
            if(g[p.px][p.py]!=0)
            {
                int tx=p.px+dx[i];
                int ty=p.py+dy[i];
                if(ok(tx,ty)==0||g[tx][ty]!=0) continue;
                int k=g[p.px][p.py]-1;
                p.x[k]=tx;
                p.y[k]=ty;
            }
            if(vis[p.px][p.py][p.x[0]][p.y[0]][p.x[1]][p.y[1]][p.x[2]][p.y[2]]==0)
            {
                q.push(p);
                vis[p.px][p.py][p.x[0]][p.y[0]][p.x[1]][p.y[1]][p.x[2]][p.y[2]]=1;
            }
        }
    }
    return -1;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        sx.clear();
        sy.clear();
        ex.clear();
        ey.clear();
        for(int i=0; i<n; i++)
        {
            scanf("%s",s[i]);
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='X')
                {
                    px=i;
                    py=j;
                }
                if(s[i][j]=='*')
                {
                    sx.push_back(i);
                    sy.push_back(j);
                }
                if(s[i][j]=='@')
                {
                    ex.push_back(i);
                    ey.push_back(j);
                }
            }
        }

        printf("%d\n",bfs());
    }
    return 0;
}
