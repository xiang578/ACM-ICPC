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
    int _,i,n,m;
    ll ans;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        ans=1;
        for(i=n;i>m;i--)
            ans=ans*2;
        printf("%lld\n",ans);
    }
    return 0;
}
