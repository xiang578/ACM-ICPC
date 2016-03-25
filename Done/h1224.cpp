/* ***********************************************
Author        :xryz
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
Created Time  :10-26 21:27:04
File Name     :h1224.cpp
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

int n,m,a[100+5],dp[100+5],f[100+5];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,__,i,u,v,ans[100+5];
	scanf("%d",&_);
	for(__=1;__<=_;__++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		a[n+1]=0;
		memset(dp,0,sizeof(dp));
		memset(f,0xff,sizeof(f));
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			if(dp[v]<dp[u]+a[v])
			{
				dp[v]=dp[u]+a[v];
				f[v]=u;
			}
		}
		u=n+1;
		v=0;
		while(u!=-1)
		{
			ans[v++]=u;
			u=f[u];
		}
		printf("CASE %d#\n",__);
		printf("points : %d\ncircuit : ",dp[n+1]);
		for(i=v-1;i>0;i--)
			printf("%d->",ans[i]);
		printf("1\n");
		if(__!=_) printf("\n");
	}
    return 0;
}

