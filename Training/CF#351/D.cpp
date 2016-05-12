#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,v[1024],n,m;
    scanf("%d%d",&n,&m);
    memset(v,0,sizeof(v));
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(m<n+1||n==4) puts("-1");
    else
    {
        v[a]=v[b]=v[c]=v[d]=1;
        printf("%d %d",a,c);
        for(int i=1;i<=n;i++)
        {
            if(v[i]==0) printf(" %d",i);
        }
        printf(" %d %d\n",d,b);
        printf("%d %d",c,a);
        for(int i=1;i<=n;i++)
        {
            if(v[i]==0) printf(" %d",i);
        }
        printf(" %d %d\n",b,d);
    }
    return 0;
}
