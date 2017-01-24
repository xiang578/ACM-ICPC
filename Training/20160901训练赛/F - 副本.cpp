/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
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
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
const int M=1e6+10;
struct node
{
    int x,y,t;
}p[120][120];
int f[120][120],a,b,c,ok,vis[120][120];
vector<node>ans;
void dfs(int x,int y,int fx,int fy,int t)
{
    printf("%d %d %d %d\n",x,y,fx,fy);
    if(x>a||y>b) return ;
    if(ok||vis[x][y]==1) return ;
    vis[x][y]=1;
    p[x][y].x=fx;
    p[x][y].y=fy;
    p[x][y].t=t;
    if(x==c||y==c)
    {
        printf("%d %d\n",x,y);
        ok=1;
        int px,py;
        px=x;
        py=y;
        ans.clear();
        while(px!=0||py!=0)
        {
            node tp;
            int k=p[px][py].t;
            if(k==1) {tp.t=1;tp.x=1;}
            else if(k==2) {tp.t=2;tp.x=2;}
            else if(k==3) {tp.t=3;tp.x=1;}
            else if(k==4) {tp.t=4;tp.x=2;}
            else if(k==5) {tp.t=5;tp.x=1;tp.y=2;}
            else if(k==6) {tp.t=6;tp.x=2;tp.y=1;}
            int nx=p[px][py].x;
            int ny=p[px][py].y;
            px=nx;
            py=ny;
            printf("%d %d %d\n",k,px,py);
            ans.push_back(tp);

        }
        printf("%d\n",ans.size());
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i].t==1||ans[i].t==2) printf("FILL(%d)\n",ans[i].x);
            else if(ans[i].t==3||ans[i].t==4) printf("DROP(%d)\n",ans[i].x);
            else printf("POUR(%d,%d)\n",ans[i].x,ans[i].y);
        }
        return ;
    }
    //1
    if(x<a)
    {
        dfs(a,y,x,y,1);
    }

    //2
    if(y<b)
    {
        dfs(x,b,x,y,2);
    }

    //3
    if(x>0)
    {
        dfs(0,y,x,y,3);
    }

    //4
    if(y>0)
    {
        dfs(x,0,x,y,4);
    }

    //5 x->y
    if(x)
    dfs(x-min(x,b-y),y+min(x,b-y),x,y,5);

    //6 y->x
    if(y)
    dfs(x+min(a-x,y),y-min(a-x,y),x,y,6);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        memset(vis,0,sizeof(vis));
        ok=0;
        dfs(0,0,-1,-1,-1);
        if(!ok) printf("impossible\n");
    }
    return 0;
}
