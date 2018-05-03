#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],b[N];

int main()
{
    int n,m,t,ans;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        memset(b,0,sizeof(b));
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&t);
            b[t]++;
        }
        ans=0;
        t=0;
        for(int i=n;i>=1;i--)
        {
            t+=b[i];
            ans+=min(t,a[i]);
            t=max(t-a[i],0);
        }
        /*for(int i=n;i>=1;i--)
        {
            j=min(j,i);
            while(j>0&&a[i]>0)
            {
                if(a[i]>=b[j])
                {
                    a[i]-=b[j];
                    ans+=b[j];
                    b[j]=0;
                    j--;
                }
                else
                {
                    b[j]-=a[i];
                    ans+=a[i];
                    a[i]=0;
                }
            }
            if(j==0) break;
        }*/
        printf("%d\n",ans);
    }
    return 0;
}
