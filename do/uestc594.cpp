/* ***********************************************
Author        :xryz
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
Created Time  :10-22 20:22:55
File Name     :uestc594.cpp
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
const int inf=0xfffffff;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int dp[2][105],n,c,i,j,k,x,ans,cur,now;
	int q[100+5],ph,pt;
	while(~scanf("%d%d",&n,&c))
	{
		scanf("%d",&x);
		cur=0;
		for(i=0;i<x;i++)
			dp[cur][i]=inf;
		for(i=x;i<=100;i++)
			dp[cur][i]=(i-x)*(i-x);

		for(i=1;i<n;i++)
		{
			scanf("%d",&x);
			cur=1-cur;

			//前一个比后一个矮
			ph=pt=0;
			for(j=0;j<=100;j++)
			{
				now=dp[1-cur][j]-c*j;
				while(ph<pt&&q[pt-1]>now)
					pt--;
				q[pt++]=now;
				if(j<x)
					dp[cur][j]=inf;
				else
					dp[cur][j]=q[ph]+(x-j)*(x-j)+c*j;
			}
			
			//前一个比后一个高
			ph=pt=0;
			for(j=100;j>=0;j--)
			{
				now=dp[1-cur][j]+c*j;
				while(ph<pt&&q[pt-1]>now)
					pt--;
				q[pt++]=now;
				if(j>=x)
					dp[cur][j]=min(dp[cur][j],q[ph]+(x-j)*(x-j)-c*j);
			}
		}

		ans=inf;
		for(i=0;i<=100;i++)
			ans=min(dp[cur][i],ans);

		printf("%d\n",ans);
	}
    return 0;
}
