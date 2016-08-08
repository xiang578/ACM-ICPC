#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
#define cl(a) memset(a,0,sizeof(a))
typedef vector<int> VI;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const ll mod=1000000007;
const int N=1e6+10;
const int inf=0x7fffffff;
const db pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
const db eps=1e-8;
const int u=1e6;
int a[N],b[N],c[N],d[N][20],n,m,v[2*N+10];

void rmq_init()
{
    for(int i=0; i<n; i++) d[i][0]=a[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=0; i+(1<<j)-1<n; i++)
            d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}

int rmq(int l,int r)
{
    if(r<l) return 0;
    int k=0;
    while((1<<(k+1))<r-l+1) k++;
    return max(d[l][k],d[r-(1<<k)+1][k]);
}

int main()
{
    int l,r,k,ans;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",c+i);
            c[i]+=u;
        }
        memset(v,0xff,sizeof(v));
        k=0;
        l=0;
        while(l<n)
        {
            while(v[c[l]]==-1)
            {
                v[c[l]]=l;
                l++;
            }
            while(k<=v[c[l]])
            {
                b[k]=l-1;
                k++;
            }
            v[c[l]]=l;
            l++;
        }
        while(k<n)
        {
            b[k]=n-1;
            k++;
        }
        for(int i=0;i<n;i++)
            a[i]=b[i]-i+1;
        rmq_init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&l,&r);
            k=lower_bound(b+l,b+r+1,r)-b;
            while(b[k]==r) {k++;if(k==n) break;};
            ans=0;
            if(k<=r)  ans=r-k+1;
            ans=max(ans,rmq(l,k-1));
            //printf("%d %d %d\n",rmq(l,k-1),l,k-1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*const int u=1e6;
int n,m,l,r,p[N],a[N],b[2*N+10],ans;

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(b,0xff,sizeof(b));
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            p[i]=b[a[i]+u];
            b[a[i]+u]=i;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&l,&r);
            ans=0;
            for(int j=l;j<=r;j++)
            {
                if(p[j]<l) ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}*/
