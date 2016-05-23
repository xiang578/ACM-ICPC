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
const int N=2048;
int a[100000+10];

int get(long long  k)
{
    long long t=sqrt(2*k);
    t--;
    while(1)
    {
        if((t+2)*(t+1)/2>k) break;
        t++;
    }
    //printf("%lld\n",t+1);
    long long ret=k-(t+1)*(t)/2;
    //printf("%lld\n",ret);
    return (int)ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    long long k;
    while(~scanf("%d%lld",&n,&k))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("%d\n",a[get(k)]);
    }
    return 0;
}
