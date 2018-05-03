/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Thu Apr 26 13:44:06 2018
File Name     :uva12291.cpp
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
int n,m,ok;
int t[30][30],g[30][30],b[30][30];
char s[100][100],a[100][100];

int check(int x,int y,int p,int q)
{
    //if(p>=x&&p<=x+m&&q>=y&&q<=y+m) return 0;
    //printf("%d %d %d %d\n",x,y,p,q);
    memset(t,0,sizeof(t));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[i][j]) {t[i+x][j+y]++;t[i+p][j+q]++;}
        }
    }
    // for(int i=0;i<10;i++)
    // {
    //     for(int j=0;j<10;j++)
    //     {
    //         printf("%d",g[i][j]);
    //         //if(g[i][j]!=t[i][j]) return 0;
    //     }
    //     printf("\n");
    // }

    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            //printf("%d",t[i][j]);
            if(g[i][j]!=t[i][j]) return 0;
        }
        //printf("\n");
    }
    return 1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        for(int j=0;j<m;j++)
            scanf("%s",a[j]);
        memset(b,0,sizeof(b));
        int x=m,y=m;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='*') x=min(x,i);
                if(a[i][j]=='*') y=min(y,j);
            }
        }
       // printf("%d %d\n",x,y);
        for(int i=x;i<m;i++)
        {
            for(int j=y;j<m;j++)
            {
                if(a[i][j]=='*') b[i-x][j-y]=1;
            }
        }
        ok=0;
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[i][j]=='*') g[i][j]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int p=0;p<n;p++)
                {
                    for(int q=0;q<n;q++)
                    {
                        ok+=check(i,j,p,q);
                        if(ok) break;
                    }
                    if(ok) break;
                }
                if(ok) break;
            }
            if(ok) break;
        }
        printf("%d\n",ok);
    }
    return 0;
}
