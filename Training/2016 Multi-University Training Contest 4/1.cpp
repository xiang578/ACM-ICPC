#include <stdio.h>
#include <string.h>
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
using namespace std;
const int N=1e5+10;
const long long mod=1000000007;
char t[N],p[N];
int f[N],a[N];
long long b[N];
void getfail()
{
    int m=strlen(p);
    f[0]=0;
    f[1]=0;
    for(int i=1; i<m; i++)
    {
        int j=f[i];
        while(j&&p[i]!=p[j]) j=f[j];
        f[i+1]=p[i]==p[j]?j+1:0;
    }
}

void kmp()
{
    int i,j,n=strlen(t),m=strlen(p);
    getfail();
    memset(a,0,sizeof(a));
    for(i=0,j=0; i<n; i++)
    {
        while(j&&p[j]!=t[i]) j=f[j];
        if(p[j]==t[i]) j++;
        if(j==m)
        {
            a[i]=1;
            j=f[j];
        }
    }
}

int main()
{
    int _;
    scanf("%d",&_);
    for(int k=1;k<=_;k++)
    {
        scanf("%s",t);
        scanf("%s",p);
        kmp();
        int n=strlen(t);
        int m=strlen(p);
        long long ans=1;
        b[0]=1;
        for(int i=0;i<n;i++)
        {
            b[i+1]=b[i];
            if(a[i]!=0)
            {
                b[i+1]=(b[i+1]+b[i-m+1])%mod;
            }
        }
        printf("Case #%d: %lld\n",k,b[n]);
    }
    return 0;
}
