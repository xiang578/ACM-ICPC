/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
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
typedef long long LL;
const int N=2048;
const int maxn=1e6+9;

LL euler_phi(LL n);
LL quickpow(LL m,LL n,LL k);

char b[maxn],x[maxn];
LL c;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%s",b);
    scanf("%s",x);
    scanf("%lld",&c);
    LL mm=euler_phi(c);
    //cout<<mm<<endl;
    LL pre=0;
    int blen=strlen(b),xlen=strlen(x);
    pre=b[0]-'0';
    for(int i=1; i<blen; i++)
    {
        pre=(pre*10+b[i]-'0')%c;
    }
    //printf("%lld\n",pre);
    LL di=pre;
    pre=(pre-1+c)%c;
    LL zhi=x[0]-'0';
    int f=1;
    for(int i=1;i<xlen;i++)
    {
        zhi=(zhi*10+x[i]-'0');
        if(zhi>=mm) {f=0;break;}
    }
    if(!f)
    {
        zhi=x[0]-'0';
        for(int i=1; i<xlen; i++)
            zhi=(zhi*10+x[i]-'0')%mm;
        zhi=zhi-1+mm;
        if(zhi==0) zhi==mm;
    }
    else zhi=zhi-1;
    LL ans=quickpow(di,zhi,c);
    //printf("%lld\n",pre);
    ans=ans*pre;
    ans%=c;
    if(ans==0)
        printf("%lld\n",c);
    else
        printf("%lld\n",ans);

    return 0;
}

LL quickpow(LL m,LL n,LL k)
{
    if(n==0) return 1;
    LL b = 1;
    while (n > 0)
    {
        if (n & 1)
            b = (b*m)%k;
        n = n >> 1 ;
        m = (m*m)%k;
    }
    return b;
}

LL euler_phi(LL n)
{
    LL m=sqrt(n+0.5);
    LL ans=n;
    for(LL i=2; i<=m; i++)
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}
