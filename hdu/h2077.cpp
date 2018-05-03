#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a[25],b[25];
    int i,n,_;
    b[1]=1;
    for(i=2;i<=20;i++)
        b[i]=b[i-1]*3+1;
    a[1]=2;
    for(i=2;i<=20;i++)
        a[i]=b[i-1]*2+2;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
