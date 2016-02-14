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
typedef long long ll;
const ll mod=1000000007;
const int N=2048;

ll a[100];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,f;
    ll n;
    a[1]=1;
    for(i=2; i<=60; i++)
        a[i]=a[i-1]*2;
    while(~scanf("%lld",&n))
    {
        f=0;
        for(i=60; i>=1; i--)
        {
            if(n>=a[i])
            {
                if(f) printf(" ");
                else f++;
                printf("%d",i);
                n-=a[i];
            }
        }
        printf("\n");
    }
    return 0;
}
