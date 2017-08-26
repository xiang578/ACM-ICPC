#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,sx,sy,ex,ey;
char g[1024][1024];
int use[120][120][1400];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct node
{
    int x,y,k;
};

int bfs()
{
    memset(use,0xff,sizeof(use));
    queue<node>q;
    node t;
    t.x=sx;
    t.y=sy;
    t.k=0;
    use[t.x][t.y][t.k]=0;
    q.push(t);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        //printf("%d %d %d %d\n",t.x,t.y,t.k,use[t.x][t.y][t.k]);
        if(t.x==ex&&t.y==ey) return use[t.x][t.y][t.k];
        for(int i=0;i<4;i++)
        {
            node k;
            k.x = t.x + dx[i];
            k.y = t.y + dy[i];
            k.k = t.k;
            if(k.x<0||k.x>=n||k.y<0||k.y>=m||g[k.x][k.y]=='0') continue;
            if(g[k.x][k.y]>='a'&&g[k.x][k.y]<='z')
            {
                k.k = k.k|(1<<(g[k.x][k.y]-'a'));
            }
            if(g[k.x][k.y]>='A'&&g[k.x][k.y]<='Z')
            {
                int p = k.k&(1<<(g[k.x][k.y]-'A'));
                //printf("%d %d %d\n",k.k,1<<(g[k.x][k.y]-'A'),p);
                if(p==0) continue;
            }
            if(use[k.x][k.y][k.k]==-1||use[k.x][k.y][k.k]>use[t.x][t.y][t.k]+1)
            {
                use[k.x][k.y][k.k]=use[t.x][t.y][t.k]+1;
                q.push(k);
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",g[i]);
        for(int j=0;j<m;j++)
        {
            if(g[i][j]=='2') {sx=i;sy=j;}
            if(g[i][j]=='3') {ex=i;ey=j;}
        }
    }
    printf("%d\n",bfs());
    return 0;
}
