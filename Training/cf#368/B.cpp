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
const int N=1e5+10;
int u[N],v[N],w[N],use[N];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    memset(u,0,sizeof(u));
    int ans=-1;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
    }
    for(int i=0;i<k;i++)
    {
        int t;
        cin>>t;
        use[t]=1;
    }
    for(int i=0;i<m;i++)
    {
        if(use[u[i]]!=use[v[i]])
        {
            //printf("%d\n",i);
            if(ans==-1) ans=w[i];
            else ans=min(ans,w[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
