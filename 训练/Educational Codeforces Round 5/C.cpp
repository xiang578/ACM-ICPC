/* ***********************************************
Author        :xryz
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
Created Time  :1-16 11:27:09
File Name     :C.cpp
************************************************ */

//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <set>
//#include <map>
//#include <string>
//#include <math.h>
//#include <stdlib.h>
//#include <time.h>
#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
char mp[1024][1024];
int use[1024][1024];
char ans[1024][1024];
int p[1024*1024];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

int dfs(int x,int y,int cnt)
{
    //printf("%d %d %d\n",x,y,cnt);
    sum++;
    use[x][y]=cnt;
    int i,tx,ty;
    for(i=0; i<4; i++)
    {
        tx=x+dx[i];
        ty=y+dy[i];
        if(tx<0||tx>=n||ty<0||ty>=m) continue;
        if(mp[tx][ty]=='*'||use[tx][ty]!=-1) continue;
        dfs(tx,ty,cnt);
    }
}

int get(int x,int y)
{
    int ret=1;
    int f1=-1,f2=-2,f3=-3,f4=-4;
    if(x>0&&mp[x-1][y]=='.')
    {
        f1=use[x-1][y];
        ret+=p[f1];
    }
    if(x+1<n&&mp[x+1][y]=='.')
    {
        f2=use[x+1][y];
        if(f1!=f2)
            ret+=p[f2];
    }
    if(y>0&&mp[x][y-1]=='.')
    {
        f3=use[x][y-1];
        if(f1!=f3&&f2!=f3)
            ret+=p[f3];
    }
    if(y<m-1&&mp[x][y+1]=='.')
    {
        f4=use[x][y+1];
        if(f1!=f4&&f2!=f4&&f3!=f4)
            ret+=p[f4];
    }
    return ret;
}


int main()
{
    int i,j,cnt;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0; i<n; i++)
            scanf("%s",mp[i]);
        memset(use,0xff,sizeof(use));
        cnt=1;
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                if(use[i][j]==-1&&mp[i][j]=='.')
                {
                    sum=0;
                    dfs(i,j,cnt);
                    p[cnt]=sum;
                   // printf("%d %d\n",cnt,sum);
                    cnt++;
                }
            }

        /*for(i=0; i<n; i++)
        {

            for(j=0; j<m; j++)
            {
                if(use[i][j]==-1)
                    printf(".");
                else printf("%d",use[i][j]);
            }
            printf("\n");
        }*/

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(mp[i][j]=='.') ans[i][j]='.';
                else
                {
                    ans[i][j]=get(i,j)%10+'0';
                }
            }
            ans[i][j]=0;
        }

        for(i=0; i<n; i++)
            printf("%s\n",ans[i]);
    }
    return 0;
}
