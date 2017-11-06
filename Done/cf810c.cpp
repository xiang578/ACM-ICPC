/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Mon Nov  6 10:52:14 2017
File Name     :cf810c.cpp
************************************************ */

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
int n;
long long a[523456],f[523456];
const long long mod=1e9+7;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",a+i);
    sort(a,a+n);
    f[0]=1;
    for(int i=1;i<n;i++) f[i]=(f[i-1]*2)%mod;
    for(int i=1;i<n;i++) f[i]=(f[i]+f[i-1])%mod;
    long long A=0;
    long long B=0;
    for(int i=0;i<n-1;i++) B=(B+a[i]*f[n-i-1-1]%mod)%mod;
    for(int i=1;i<n;i++) A=(A+a[i]*f[i-1]%mod)%mod;
    printf("%lld\n",(A-B+mod)%mod);
    return 0;
}
