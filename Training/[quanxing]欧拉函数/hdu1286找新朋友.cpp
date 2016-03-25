#include<bits/stdc++.h>
using namespace std;
int euler_phi(int n)
{
    int m=(int)sqrt(n+0.5);
    int ans=n;
    for(int i=2; i<=m; i++)
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}

int main()
{
    int n,t;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        printf("%d\n",euler_phi(t));
    }
    return 0;
}
