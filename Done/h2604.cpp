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
    ll a[40];
    int i,n;
    a[1]=2;
    for(i=2;i<=35;i++)
        a[i]=a[i-1]*3+2;
    while(~scanf("%d",&n))
    {
        printf("%lld\n",a[n]);
    }
    return 0;
}
