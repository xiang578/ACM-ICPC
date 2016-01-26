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

int n,m,use[50][50],f;
char mp[50][50];
ll ans;
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}

void dfs(int x,int y,ll a,ll b)
{
    use[x][y]=1;

}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%lld",&n,&m,&ans);
        for(i=0;i<n;i++)
            scanf("%s",mp[i]);
        for(i=0;i<n;i+=2)
            for(j=0;j<m;j+=2)
                mp[i][j]=mp[i][j]-'0';
        f=0;
        for(i=0;i<n;i+=2)
            for(j=0;j<m;j+=2)
            if(0<=mp[i][j]&&mp[i][j]<=9&&!f)
            {
                memset(use,0,sizeof(use));
                dfs(i,j,mp[i][j],1);
            }
        if(f)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}
