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
    int i,k,j,t,m,n;
    int f[1024];
    while(~scanf("%d%d",&n,&m))
    {
        memset(f,0,sizeof(f));
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            for(j=0;j<k;j++)
            {
                scanf("%d",&t);
                if(!f[t]) f[t]=1;
            }
        }
        for(i=1;i<=m;i++)
            if(f[i]==0) break;
        if(i<=m) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
