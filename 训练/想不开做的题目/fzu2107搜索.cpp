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
int n,cnt;
int vis[10][10];

void dfs11()
{
    for(int i=1;i<=n;i++)
       for(int j=1;j<=4;j++)
            printf("%d ",vis[i][j]);
    printf("\n");
    cnt++;
    return ;
}

//2*1;
void dfs21(int x,int y)
{
    dfs11();
    for(int i=x; i<n; i++)
    {
        for(int j=y; j<=4; j++)
        {
            if(vis[i][j]==0&&vis[i+1][j]==0)
            {
                vis[i][j]=vis[i+1][j]=3;
                dfs21(i,j);
                vis[i][j]=vis[i+1][j]=0;
            }
        }
    }
}

//1*2
void dfs12(int x,int y)
{
    int i,j;
    dfs21(1,1);
    for(i=x; i<=n; i++)
    {
        for(j=y; j<=3; j++)
        {
            if(vis[i][j]==0&&vis[i][j+1]==0)
            {
                vis[i][j]=vis[i][j+1]=2;
                dfs12(i,j);
                vis[i][j]=vis[i][j+1]=0;

            }
        }
    }
}

int main()
{
    int i,j;
    n=3;
    memset(vis,0,sizeof(vis));
    /*int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    */
    //²Ü²Ù
    cnt=0;
    for(i=1; i<=n-1; i++)
    {
        for(j=1; j<=3; j++)
        {
            vis[i][j]=vis[i+1][j]=vis[i][j+1]=vis[i+1][j+1]=1;
            dfs12(1,1);
            printf("%d\n",cnt);
            vis[i][j]=vis[i+1][j]=vis[i][j+1]=vis[i+1][j+1]=0;
        }
    }

    printf("%d\n",cnt);
    return 0;
}
