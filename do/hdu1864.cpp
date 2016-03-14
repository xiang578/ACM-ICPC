#include<bits/stdc++.h>
using namespace std;
int n,a[10000+5];
int main()
{
    int i,ans,t,tl,tr,l,r;
    while(~scanf("%d",&n)&&n)
    {
        memset(a,0,sizeof(a));
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        t=tl=0;
        ans=r=l=-1;
        for(i=0; i<n; i++)
        {
            t+=a[i];
            if(t<0)
            {
                t=0;
                tl=i+1;
            }
            else
            {
                if(t>ans)
                {
                    ans=t;
                    l=tl;
                    r=i;
                }
                else if(t==ans&&l+r>i+tl)
                {
                    l=tl;
                    r=i;
                }
            }
        }
        if(l==-1) printf("0 %d %d\n",a[0],a[n-1]);
        else printf("%d %d %d\n",ans,a[l],a[r]);
    }
    return 0;
}
