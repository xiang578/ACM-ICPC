/* ***********************************************
Author        :xryz
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
Created Time  :1-21 14:51:18
File Name     :POJ2955.cpp
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char s[120];
    int i,j,k,t,dp[120][120],len;
    while(~scanf("%s",s))
    {
        if(strcmp(s,"end")==0) break;
        memset(dp,0,sizeof(dp));
        len=strlen(s);
        for(i=1;i<len;i++)
        {
            for(j=0,k=i;k<len;j++,k++)
            {
                if((s[j]=='('&&s[k]==')')||(s[j]=='['&&s[k]==']'))
                    dp[j][k]=dp[j+1][k-1]+2;
                for(t=j;t<k;t++)
                    dp[j][k]=max(dp[j][k],dp[j][t]+dp[t+1][k]);
            }
        }
        printf("%d\n",dp[0][len-1]);
    }
    return 0;
}
