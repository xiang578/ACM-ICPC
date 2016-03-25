#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100000+10];

int main()
{
    int _,i,t,n;
    ll ans;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        ans=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&t);
            if(a[t]==0)
            {
                ans+=(n-i+1)*t;
                ans+=(i)*t;
                a[t]++;
                if(i==n||i==1) ans-=t;
            }
            else
            {
                ans+=(n-i+1)*t;
                ans+=(i-a[t])*t;
            }
            a[t]++;
            //printf("%d\n",ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
