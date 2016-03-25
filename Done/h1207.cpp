#include<bits/stdc++.h>
#include <time.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a[70],t;
    int i,j,n;
    a[1]=1;
    a[2]=3;
    a[3]=5;
    for(i=4;i<=64;i++)
    {
        t=0xfffffff;
        for(j=1;j<=i/2;j++)
        {
           if(t>2*a[i-j]+pow(2.0,j)-1) t=2*a[i-j]+pow(2.0,j)-1;
        }
        a[i]=t;
    }
    while(~scanf("%d",&n))
    {
        printf("%lld\n",a[n]);
    }
    return 0;
}
