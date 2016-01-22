/* ***********************************************
Author        :xryz
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
Created Time  :1-16 11:22:37
File Name     :B.cpp
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
vector<int>edge[100000+5];
int n,m,i,j,k,u,v,dp[1000000+5];
typedef long long ll;
ll ans;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0; i<=n; i++)
        {
            edge[i].clear();
            dp[i]=1;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        ans=0;
        for(i=1; i<=n; i++)
        {
            j=edge[i].size();
            ans=max(ans,(ll)dp[i]*j);
            for(j=0; j<edge[i].size(); j++)
            {
                k=edge[i][j];
                if(k>i)
                    dp[k]=max(dp[k],dp[i]+1);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
