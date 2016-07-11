#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct
{
    int x,y;
    int t;
}p,t;
char s[100][100];
int use[100][100],n,m,k;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void bfs()
{
    memset(use,0xff,sizeof(use));
    p.x=0;
    p.y=k-1;
    p.t=0;
    use[p.x][p.y]=0;
    while(1)
    {
        if(s[p.x][p.y]=='N')
        {
            p.x-=1;
        }
        else if(s[p.x][p.y]=='S')
        {
            p.x+=1;
        }
        else if(s[p.x][p.y]=='W')
        {
            p.y-=1;
        }
        else if(s[p.x][p.y]=='E')
        {
            p.y+=1;
        }
        p.t++;
        //printf("%d %d\n",p.x,p.y);
        if(p.x<0||p.x>=n||p.y<0||p.y>=m)
        {
            printf("%d step(s) to exit\n",p.t);
            return ;
        }
        if(use[p.x][p.y]==-1)
        {
            use[p.x][p.y]=p.t;
        }
        else
        {
            printf("%d step(s) before a loop of %d step(s)\n",use[p.x][p.y],p.t-use[p.x][p.y]);
            return ;
        }
    }
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        if(!n&&!m&&!k) break;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        bfs();
    }
    return 0;
}
