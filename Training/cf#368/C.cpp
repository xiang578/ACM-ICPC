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
ll n,m,k,t;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%lld",&n);
    if(n<=2) puts("-1");
    else
    {
        if(n%4==0)
        {
            m=n/4*3;
            k=n/4*5;
        }
        else if(n%2==1)
        {
            t=n*n;
            m=t/2;
            k=t-m;
        }
        else
        {
            n/=2;
            t=n*n;
            m=t/2;
            k=t-m;
            m*=2;
            k*=2;
        }
        printf("%lld %lld\n",m,k);
    }
    return 0;
}
