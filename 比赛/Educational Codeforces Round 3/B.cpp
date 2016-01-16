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
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;

int a[20];
int sum[20];
ll ans;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int k,n,m;
    scanf("%d%d",&n,&m);
    rep(i,0,n)
    {
        scanf("%d",&k);
        a[k]++;
    }
    ans=0;
    sum[0]=0;
    rep(i,1,m+1)
    {
        sum[i]=a[i]+sum[i-1];
    }

    per(i,1,1+m)
    {
        ans+=a[i]*(sum[i-1]);
        //printf("%d\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}


