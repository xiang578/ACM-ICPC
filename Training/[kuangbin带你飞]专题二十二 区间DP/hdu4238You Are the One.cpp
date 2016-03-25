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

        //��ʼ��
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                dp[i][j]=inf;

        for(len=1;len<n;len++)//��С���俪ʼ�ϲ�
        {
            for(i=1;i<=n-len;i++)//���
            {
                j=i+len;//�յ�
                for(k=i;k<=j;k++)//ö�ٵ�k����ջ
                {
                    tp=a[i]*(k-i);//��i���ɵ�һ����ʼ���¼��㣬����ڶ��еĽ�����Ĳ��ֲ���ȥ
                    tp+=dp[i+1][k]+dp[k+1][j];//����ϲ�
                    tp+=(sum[j]-sum[k])*(k-i+1);//���������Ǽ���dp[k+1][j]������ʱ�����ǰ�k+1���ɵ�һ�����㣬�ϲ�ʱҪ���ٵĲ��ֲ����ȥ
                    dp[i][j]=min(tp,dp[i][j]);
                }
            }
        }

        printf("Case #%d: %d\n",++cas,dp[1][n]);
    }
    return 0;
}
