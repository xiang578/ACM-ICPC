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
const int N=2*1e5+10;
int use[N],d[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,_,t,q;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        memset(use,0,sizeof(use));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            use[t]=i;
        }
        int t=0;
        for(int i=1;i<N;i++)
        {
            if(use[i]==0) d[t++]=i;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&q);
            int k=lower_bound(d,d+t,q)-d;
            printf("%d\n",d[k]);
        }
    }
    return 0;
}
