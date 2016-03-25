#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int _,n,i;
    ll a[40];
    a[0]=1;
    for(i=1;i<30;i++)
    {
        a[i]=3*a[i-1];
    }
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
