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
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b , a%b);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int k,i,a,b,n,m,ans;
    while(~scanf("%d%d",&n,&m))
    {
        ans=0;
        for(i=1;i<=n;i++)
        {
            if(i%3==1&&(i+1)<=m) ans++;
            if(i%3==2&&(i-1)<=m&&(i-1)>0) ans++;
            if(i%3==0&&(i)<=m) ans++;
        }
        if(ans)
        {
            k=gcd(n*m,ans);
            a=ans/k;
            b=n*m/k;
        }
        else
        {
            a=0;
            b=1;
        }
        printf("%d/%d\n",a,b);
    }
    return 0;
}
