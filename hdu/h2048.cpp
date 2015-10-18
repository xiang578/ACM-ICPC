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
    int _,n,i;
    ll f[25],c[25];
    double a[25];
    f[1]=0;f[2]=1;
    for(i=3;i<=20;i++)
        f[i]=(i-1)*(f[i-2]+f[i-1]);
    for(i=2,c[1]=1;i<=20;i++)
        c[i]=i*c[i-1];
    for(i=1;i<=20;i++)
        a[i]=1.0*f[i]/c[i]*100;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        printf("%.2f%%\n",a[n]);
    }
    return 0;
}
