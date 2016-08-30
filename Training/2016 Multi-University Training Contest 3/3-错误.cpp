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
int a[1024][1024],b[5][1024][1024];
int t,n,m,flag;

/*int main()
{
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&t,&n,&m);
        if(t==1)
        {
            if(n%2!=m%2) puts("B");
            else puts("G");
        }
        else if(t==2)
        {
            if(n==m) puts("G");
            else puts("B");
        }
    }
}*/
int dfs(int x,int y)
{
    int ok=0;
    if(x==n&&y==m)
    {
        flag=1;
    }
    if(x>n||x<1||y>m||y<1) return -1;
    if(a[x][y]!=-1) return a[x][y];
    if(t==1)
    {
        if(dfs(x+1,y)==0) ok++;
        if(dfs(x,y+1)==0) ok++;
    }
    else if(t==2)
    {
        for(int i=x+1; i<=n; i++)
        {
            if(dfs(i,y)==0) ok++;
        }
        for(int j=y+1; j<=m; j++)
        {
            if(dfs(x,j)==0) ok++;
        }
    }
    else if(t==3)
    {
        if(dfs(x+2,y+1)==0) ok++;
        if(dfs(x+1,y+2)==0) ok++;
    }
    else if(t==4)
    {
        for(int i=x+1; i<=n; i++)
        {
            if(dfs(i,y)==0) ok++;
        }
        for(int j=y+1; j<=m; j++)
        {
            if(dfs(x,j)==0) ok++;
        }
        for(int i=1; x+i<=n&&y+i<=m; i++)
        {
            if(dfs(x+i,y+i)==0) ok++;
        }
    }
    if(ok) a[x][y]=1;
    else a[x][y]=0;
    return a[x][y];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    scanf("%d",&_);
    memset(b,0xff,sizeof(b));
    t=1;

    //while(_--)
    for(n=1;n<=20;n++)
        for(m=1;m<=20;m++)
    {
        //scanf("%d%d%d",&t,&n,&m);
        printf("%d %d:",n,m);
        if(b[t][n][m]==-1)
        {
            memset(a,0xff,sizeof(a));
            a[n][m]=0;
            flag=0;
            dfs(1,1);
            if(flag==0) b[t][n][m]=0;
            else if(a[1][1]==0) b[t][n][m]=1;
            else b[t][n][m]=2;
        }
        if(b[t][n][m]==0) printf("D\n");
        else if(b[t][n][m]==1) printf("G\n");
        else printf("B\n");
    }
    return 0;
}

