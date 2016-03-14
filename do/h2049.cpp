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
    int i,_,n,m;
    ll f[25],a[25],ans;
    f[1]=0;f[2]=1;
    for(i=3;i<=20;i++)
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    a[0]=1;
    a[1]=1;
    for(i=2;i<=20;i++)
        a[i]=a[i-1]*i;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        ans=a[n]/a[m]/a[n-m];
        printf("%lld\n",ans*f[m]);
    }
    return 0;
}
