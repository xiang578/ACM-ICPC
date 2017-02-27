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
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;
const int M=1e6+10;
int p[M],u[M],b[M];

void dfs(int x)
{
    if(u[x]==1) return ;
    u[x]=1;
    dfs(p[x]);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,cnt=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) {cin>>b[i];if(b[i]) cnt++;}
    memset(u,0,sizeof(u));

    for(int i=1;i<=n;i++)
    {
        if(u[i]==0)
        {
            dfs(i);
            ans++;
        }
    }
    if(ans==1) ans=0;
    if(cnt%2==0) ans++;
    cout<<ans<<endl;
    return 0;
}
