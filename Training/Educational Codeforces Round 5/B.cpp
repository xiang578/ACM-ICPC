#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<int> VI;
typedef long long ll;

int main()
{
    int n,m;
    ll fmin,ans,t;
    while(~scanf("%d%d",&n,&m))
    {
        ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%lld",&t);
                if(j==0) fmin=t;
                if(t<fmin) fmin=t;
            }
            if(ans<fmin) ans=fmin;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

