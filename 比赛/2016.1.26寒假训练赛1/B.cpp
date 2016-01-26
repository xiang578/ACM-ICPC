/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
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
int m,n,a,b,c,d,T;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int v[10][10];char map[10][10];
int dfs(int x,int y,int t)
{
    int i;
    if(t==T)
    {
        if(map[x][y]=='D') return 1;
        else return 0;
    }
    if((T-t+c-x+d-y)%2) return 0;
    int xx,yy;
    for(i=0;i<4;i++)
    {
        xx=x+dx[i];
        yy=y+dy[i];
        if(xx<0||xx>=n||yy<0||yy>=m||v[xx][yy]||map[xx][yy]=='X')
            continue;
        v[xx][yy]=1;
        if(dfs(xx,yy,t+1)) return 1;
        v[xx][yy]=0;
    }
    return 0;
}
int main()
{
    int i,j;
    while(~scanf("%d%d%d",&n,&m,&T))
    {
        if(n==0)break;
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(j=0;j<m;j++)
            {
                if(map[i][j]=='S')
                {a=i;b=j;}
                else if(map[i][j]=='D')
                {c=i;d=j;}
            }
        }
         memset(v,0,sizeof(v));
        v[a][b]=1;
        if(dfs(a,b,0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
