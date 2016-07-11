/* ***********************************************
Author        :xryz
Email         :523689985@qq.com
Created Time  :2015/4/9 19:45:38
File Name     :C:\Users\Administrator\Desktop\a.cpp
************************************************ */

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

struct node
{
    int x,y,z,t;
} m,m0;

int a,b,c,vis[55][55][55];
int dx[6]= {0,0,0,0,1,-1};
int dy[6]= {0,0,1,-1,0,0};
int dz[6]= {1,-1,0,0,0,0};
char g[50][50][50];
int sx,sy,sz;

int bfs()
{
    queue<node>q;
    m.x=sx,m.y=sy,m.z=sz,m.t=0;
    q.push(m);
    memset(vis,0,sizeof(vis));
    while(!q.empty())
    {
        m0=q.front();
        q.pop();
        //printf("%d %d %d\n",m0.x,m0.y,m0.z);
        if(g[m0.x][m0.y][m0.z]=='E')
        {
            printf("Escaped in %d minute(s).\n",m0.t);
            return 0;
        }
        m.t=m0.t+1;
        for(int i=0; i<6; i++)
        {
            m.x=m0.x+dx[i];
            m.y=m0.y+dy[i];
            m.z=m0.z+dz[i];
            if(m.x<1||m.x>a||m.y<1||m.y>b||m.z<1||m.z>c||vis[m.x][m.y][m.z]||g[m.x][m.y][m.z]=='#') continue;
            q.push(m);
            vis[m.x][m.y][m.z]=1;
        }
    }
    printf("Trapped!\n");
}

int main()
{
    int i,j,k;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        if(!a&&!b&&!c) break;
        for(int i=1; i<=a; i++)
        {
            for(int j=1; j<=b; j++)
            {
                scanf("%s",g[i][j]+1);
                for(int k=1; k<=c; k++)
                {
                    if(g[i][j][k]=='S')
                    {
                        sx=i;
                        sy=j;
                        sz=k;
                    }
                }
            }
        }
        bfs();
    }
    return 0;
}
