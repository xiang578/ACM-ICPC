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


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,n,t,ans,a;
    while(~scanf("%d",&n))
    {
        a=sqrt(n);
        ans=0;
        if(a*a==n)
        {
            ans+=4;
        }
        for(i=1;i<=a+1;i++)
        {
            t=n-i*i;
            t=sqrt(t);
            if(t>i&&t*t+i*i==n)
                ans+=8;
            if(t==i&&t*t+i*i==n)
                ans+=4;

        }
        printf("%d\n",ans);
    }
    return 0;
}
