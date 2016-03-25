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
    int n,i,m;
    double a,b;
    while(~scanf("%d",&n))
    {
        a=1;
        i=1;
        while(n-i>0)
        {
            a*=(n-i);
            i+=2;
        }
        b=1;
        i=2;
        while(n-i>0)
        {
            b*=(n-i);
            i+=2;
        }
        printf("%.5f\n",b/a);
    }
    return 0;
}
