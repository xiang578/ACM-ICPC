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
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b,p[20],t;
    ll ans=0;
    p[0]=6;p[1]=2;p[2]=5;p[3]=5;p[4]=4;
    p[5]=5;p[6]=6;p[7]=3;p[8]=7;p[9]=6;
    while(~scanf("%d%d",&a,&b))
    {
        ans=0;
        rep(i,a,b+1)
        {
            t=i;
            while(t)
            {
                ans+=p[t%10];
                t/=10;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
