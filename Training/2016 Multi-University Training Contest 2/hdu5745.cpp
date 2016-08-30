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
#include<bitset>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=1e5+10;
char s[N],p[N];
bitset<N>dp[2][3];
bitset<N>w[30];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,m,ok,cur;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",s);
        scanf("%s",p);
        for(int i=0;i<30;i++)
            w[i].reset();
        for(int i=0;i<n;i++)
            w[s[i]-'a'][i]=1;
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                dp[i][j].reset();
        cur=1;
        dp[cur][1]=w[p[0]-'a'];
        if(m>1) dp[cur][2]=w[p[1]-'a'];
        for(int j=1;j<m;j++)
        {
            cur^=1;
            dp[cur][0]=w[p[j-1]-'a']&(dp[cur^1][2]<<1);
            dp[cur][1]=w[p[j]-'a']&((dp[cur^1][0]|dp[cur^1][1])<<1);
            if(j+1<m) dp[cur][2]=w[p[j+1]-'a']&((dp[cur^1][0]|dp[cur^1][1])<<1);
        }

        for(int i=0;i<n;i++)
            if(dp[cur][0][i+m-1]||dp[cur][1][i+m-1])
                printf("1");
            else
                printf("0");
        printf("\n");
    }
    return 0;
}

/*
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
const int N=1e5+10;
char s[N],p[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,m,ok;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",s);
        scanf("%s",p);
        for(int i=0;i<=n-m;i++)
        {
            ok=1;
            for(int j=0;j<m;j++)
            {
                if(s[i+j]==p[j]) continue;
                if(j+1<m&&s[i+j]==p[j+1]&&s[i+j+1]==p[j]) {j++;continue;}
                ok=0;
                break;
            }
            printf("%d",ok);
        }
        for(int i=n-m+1;i<n;i++)
            printf("0");
        printf("\n");
    }
    return 0;
}*/
