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


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    ll t,a,b,c;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lld",&t);
        int f=0;
        //ll up=sqrt(t)+1;
        for(ll i=1;i*i<=t;i++)
        {
            if(t%i==0)
            {
                a=i;
                b=t/i;
                if(a==b||a==0||b==0) continue;
                c=a+b;
                if(c%2==0) {f=1;}
            }
            if(f) break;
        }
        if(f) puts("True");
        else puts("False");
    }
    return 0;
}
