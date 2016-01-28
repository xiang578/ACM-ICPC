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
const int inf=1<<24;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,j,k,n,tp,len,dp[200][200],a[200],sum[200];
    int cas=0;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        sum[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=a[i]+sum[i-1];
        }

        //初始化
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                dp[i][j]=inf;

        for(len=1;len<n;len++)//从小区间开始合并
        {
            for(i=1;i<=n-len;i++)//起点
            {
                j=i+len;//终点
                for(k=i;k<=j;k++)//枚举第k个出栈
                {
                    tp=a[i]*(k-i);//把i当成第一个开始重新计算，下面第二行的将少算的部分补回去
                    tp+=dp[i+1][k]+dp[k+1][j];//区间合并
                    tp+=(sum[j]-sum[k])*(k-i+1);//这里的理解是计算dp[k+1][j]的区间时，我们把k+1当成第一个计算，合并时要把少的部分补充回去
                    dp[i][j]=min(tp,dp[i][j]);
                }
            }
        }

        printf("Case #%d: %d\n",++cas,dp[1][n]);
    }
    return 0;
}
