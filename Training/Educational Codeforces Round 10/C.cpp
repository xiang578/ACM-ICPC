#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3*1e5+10;
int n,m,p[N],pos[N],up[N];

int main()
{
    int i,a,b,x,y;
    ll ans;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1;i<=n;i++)
            up[i]=n;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
            pos[p[i]]=i;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            x=pos[a];
            y=pos[b];
            if(x>y) swap(x,y);
            up[x]=min(up[x],y-1);
        }
        for(i=n-1;i>=1;i--)
        {
            up[i]=min(up[i],up[i+1]);
        }
        ans=0;
        for(i=1;i<=n;i++)
            ans+=(up[i]-i+1);
        cout<<ans<<endl;
    }
    return 0;
}
