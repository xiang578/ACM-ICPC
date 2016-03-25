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
int dp[100*100+10],c[100*100+10];
int w[200];


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,i,j,m,k,t,sum;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&w[i]);
        memset(dp,0,sizeof(dp));
        memset(c,0,sizeof(c));
        sum=0;
        dp[0]=1;
        dp[w[0]]=1;
        for(i=0;i<n;i++)
            sum+=w[i];
        for(i=1;i<n;i++)
        {
            for(j=0;j<=sum;j++)
            {
                if(!dp[j]) continue;
                for(k=0;k<=w[i];k+=w[i])
                {
                    c[j+k]+=dp[j];
                    c[abs(j-k)]+=dp[j];
                }
            }
            for(j=0;j<=sum;j++)
            {
                dp[j]=c[j];
                c[j]=0;
            }
        }
        int cnt=0;
        vector<int>vt;
        vt.clear();
        for(i=1;i<=sum;i++)
        {
            if(!dp[i])
            {
                cnt++;
                vt.push_back(i);
            }
        }
        printf("%d\n",cnt);
        for(i=0;i<vt.size();i++)
        {
            if(i) printf(" ");
            printf("%d",vt[i]);
        }
        if(cnt) printf("\n");
    }
    return 0;
}

/*
01±³°ü
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
int dp[100*100+10];
int w[200];


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,i,j,m,k,t,sum;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&w[i]);
        memset(dp,0,sizeof(dp));
        sum=0;
        dp[0]=1;
        for(i=0;i<n;i++)
            sum+=w[i];

        for(i=0;i<n;i++)
        {
            for(j=sum;j>=w[i];j--)
            {
                if(dp[j-w[i]]) dp[j]=1;
            }
        }

        for(i=0;i<n;i++)
            for(j=0;j<=sum-w[i];j++)
        {
            if(dp[j+w[i]]) dp[j]=1;
        }
        int cnt=0;
        vector<int>vt;
        vt.clear();
        for(i=1;i<=sum;i++)
        {
            if(!dp[i])
            {
                cnt++;
                vt.push_back(i);
            }
        }
        printf("%d\n",cnt);
        for(i=0;i<vt.size();i++)
        {
            if(i) printf(" ");
            printf("%d",vt[i]);
        }
        if(cnt) printf("\n");
    }
    return 0;
}
*/
