/* ***********************************************
Author        :xryz
Email         :xiang578@foxmail.com
Created Time  :10-18 9:45:55
File Name     :h1503.cpp
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
//#include <bits/stdc++.h>
using namespace std;
int dp[100+5][100+5],vis[100+5][100+5],fa[100+5];
void dfs(int i,int j)
{
	if(i==0||j==0) return;
	if(vis[i][j]==0)
	{
		fa[i]=j;
		dfs(i-1,j-1);
	}
	else if(vis[i][j]==1)
	{
		dfs(i-1,j);
	}
	else dfs(i,j-1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char a[100+5],b[100+5];
	int i,j,n,m;
	while(~scanf("%s%s",&a,&b))
	{
		n=strlen(a);
		m=strlen(b);
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(a[i]==b[j]) 
					{
						dp[i+1][j+1]=dp[i][j]+1;
						vis[i+1][j+1]=0;
					}
				else 
				{
					if(dp[i][j+1]>dp[i+1][j])
					{
						dp[i+1][j+1]=dp[i][j+1];
						vis[i+1][j+1]=1;
					}
					else
					{
						dp[i+1][j+1]=dp[i+1][j];
						vis[i+1][j+1]=-1;
					}
				}
			}
		memset(fa,0,sizeof(fa));
		dfs(n,m);
		//for(i=1;i<=n;i++)
		//	printf("%d ",fa[i]);
		for(i=0,j=0;i<n;i++)
		{
			if(fa[i+1]==0) 
			{
				printf("%c",a[i]);
			}
			else
			{
			while(j<m&&j+1<=fa[i+1])
			{
				printf("%c",b[j]);
				j++;
			}
			}
		}

		for(;j<m;j++)
			printf("%c",b[j]);
		printf("\n");
	}
    return 0;
}
