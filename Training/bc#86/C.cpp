/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2*1e5+10;
int a[N],b[N],n,m,k,t;
ll ans=0;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1; i<=n; i++) scanf("%d",a+i);
        b[0]=0;
        for(int i=1; i<=n; i++)
        {
            if(a[i]>=m) b[i]=b[i-1]+1;
            else b[i]=b[i-1];
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(n-i+1<k) break;
            if(a[i]>=m) t=lower_bound(b+i+k-1,b+n+1,b[i]+k-1)-b;
            else t=lower_bound(b+i+k-1,b+n+1,b[i]+k)-b;
            if(t==n+1) continue;
            else
            {
                //printf("%d ",n-t+1);
                ans+=n-t+1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
