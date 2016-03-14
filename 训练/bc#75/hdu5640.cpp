#include<bits/stdc++.h>
using namespace std;

int gcd(int n,int m)
{
    if(m==0) return n;
    else return gcd(m,n%m);
}

int main()
{
    int n,m,t;
    int ans,_;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        ans=0;
        while(1)
        {
            if(m>n) swap(n,m);
            t=n/m;
            n=n-t*m;
            ans+=t;
            if(n==0) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
