#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,i,t,ans,a[1024],m,p;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        m=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&t,&p);
            if(t>m) m=t;
            a[t]+=p;
        }
        ans=0;
        t=0;
        for(i=0;i<=m;i++)
        {
            if(a[i]==0) continue;
            t+=a[i]/64;
            if(a[i]%64!=0) t++;
        }
        ans=t/36;
        if(t%36!=0) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
