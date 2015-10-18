#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef long long ll;

int main()
{
    int n,i,j,m;
    ll f[30],ans,tp;
    f[1]=0;f[2]=1;
    for(i=3;i<=25;i++)
        f[i]=(i-1)*(f[i-1]+f[i-2]);

    while(~scanf("%d",&n))
    {
        if(n==0) break;
        ans=1;
        if(n%2==0) m=n/2;
        else m=(n+1)/2;
        for(i=m;i<n;i++)
        {
            tp=1;
            for(j=i+1;j<=n;j++)
                tp*=j;
            for(j=1;j<=n-i;j++)
                tp/=j;
            ans+=tp*f[n-i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
