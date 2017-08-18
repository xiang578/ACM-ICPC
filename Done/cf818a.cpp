#include<stdio.h>
#include<cstring>
using namespace std;
typedef long long ll;

int main(){
    ll n,k;
    //n=n/2;
    scanf("%lld %lld",&n,&k);
    if(k+1>n/2)
        printf("0 0 %lld",n);
    else{
        ll t=n/2/(k+1);
        printf("%lld %lld %lld\n",t,t*k,n-t-t*k);
    }
    return 0;
}
