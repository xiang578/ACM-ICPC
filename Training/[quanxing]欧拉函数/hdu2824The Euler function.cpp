#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phi[3000000];
void phi_table()
{
    int n=3000000-1;
    for(int i=2;i<=n;i++)   phi[i]=0;
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!phi[i])
        {
            for(int j=i;j<=n;j+=i)
            {
                if(!phi[j]) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}

int main()
{
    int a,b;
    phi_table();
    phi[1]=0;
    for(int i=3;i<3000000;i++)
        phi[i]=phi[i-1]+phi[i];
    while(~scanf("%d%d",&a,&b))
    {
        printf("%lld\n",phi[b]-phi[a-1]);
    }
    return 0;
}
