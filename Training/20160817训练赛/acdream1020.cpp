#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll l,r,n,ans,t;
    ll f[35];
    f[0]=1;
    for(int i=1;i<32;i++) f[i]=f[i-1]*2;
    while(~scanf("%lld",&n))
    {
        for(int i=1;i<32;i++)
        {
            if(f[i]>n)
            {
                printf("%lld\n",2*(n-f[i-1])+1);
                break;
            }
        }
    }
    return 0;
}
