#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int w;
    ll a,b;
} v[1000000+10];

int cmp(node n1,node n2)
{
    return n1.w<n2.w;
}

int n,k,use[5000];
ll c[5000],cnt,ans;

int main()
{
    int i,j,a,b;
    while(~scanf("%d%d",&n,&k))
    {
        for(i=0; i<n; i++)
            scanf("%lld",&c[i]);
        cnt=0;
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                v[cnt].a=i;
                v[cnt].b=j;
                v[cnt].w=(c[i]-c[j])*(c[i]-c[j]);
                cnt++;
            }
        }
        sort(v,v+cnt,cmp);
        memset(use,0,sizeof(use));
        ans=0;
        j=0;
        for(i=0; i<cnt; i++)
        {
            a=v[i].a;
            b=v[i].b;
            if(!use[a]&&!use[b])
            {
                use[a]=use[b]=1;
                ans+=v[i].w;
                j++;
            }
            if(j==k) break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
