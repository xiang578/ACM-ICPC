/* ***********************************************
Author        :xryz
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
Created Time  :1-16 11:22:08
File Name     :A.cpp
************************************************ */

//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <set>
//#include <map>
//#include <string>
//#include <math.h>
//#include <stdlib.h>
//#include <time.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow1(ll m,ll n)
{
    ll ret=1;
    while(n)
    {
        if(n&1)
            ret=ret*m;
        n=n>>1;
        m=(m*m);
    }
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll a,b,l,r,k;
    while(~scanf("%lld%lld%lld",&l,&r,&k))
    {
        int f=0;
        a=log(l)/log(k)+0.1;
        b=log(r)/log(k)+0.1;
        if(pow1(k,a)<l) a++;
        if(pow1(k,b)>r) b--;
        if(a>b) {printf("-1\n");continue;}
        for(ll i=a;i<=b;i++)
        {
            if(f==0) f=1;
            else printf(" ");
            printf("%lld",pow1(k,i));
        }
        if(f==0) puts("-1");
        else printf("\n");
    }
    return 0;
}
