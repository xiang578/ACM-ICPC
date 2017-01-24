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
const int N=1e5;
int a[N],t,c[N];
ll ans,s[N];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        t=10000;
        for(int i=0;i<n;i++)
        {
            int b=0;
            memset(c,0,sizeof(c));
            c[t]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(a[j]>a[i])
                    b++;
                if(a[i]>a[j])
                    b--;
                c[b+t]++;
            }
            b=0;
            ans=c[t];
            for(int j=i+1;j<n;j++)
            {
                if(a[j]>a[i])
                    b++;
                if(a[j]<a[i])
                    b--;
                ans+=c[t-b];
            }
            s[i]=ans;
        }
        for(int i=0;i<n;i++)
        {
            if(i) printf(" ");
            printf("%lld",s[i]);
        }
        printf("\n");
    }
    return 0;
}
