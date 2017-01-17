#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    while(~scanf("%lld%lld",&n,&m))
    {
        n=(n/2)*(n-n/2);
        if(n<=m) printf("T\n");
        else printf("F\n");
    }
    return 0;
}

