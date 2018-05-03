#include<bits/stdc++.h>
using namespace std;

int d[500000+5],a[500000+5];

int Binary_search(int s,int t,int i)
{
    int mid;
    while(s<t)
    {
        mid=(s+t)>>1;
        if(i>=d[mid]) s=mid+1;
        else t=mid;
    }
    return s;
}
int main()
{
    int i,n,b,p,r,k,cas=0;
    while(~scanf("%d",&n))
    {
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&p,&r);
            a[p]=r;
        }
        b=1;
        memset(d,0,sizeof(d));
        d[0]=a[1];
        for(i=2; i<=n; i++)
        {
            k=Binary_search(0,b-1,a[i]);
            if(d[k]>=a[i]) d[k]=a[i];
            else d[b++]=a[i];
        }
        printf("Case %d:\n",++cas);
        if(b==1) printf("My king, at most 1 road can be built.\n\n");
        else printf("My king, at most %d roads can be built.\n\n",b);
    }
    return 0;
}
