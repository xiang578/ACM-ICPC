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
    double t,f,a,b;
    a=asin(sqrt(14)/8);
    b=asin(sqrt(14)/4);
    f=b/4-a+sqrt(7)/8;
    f*=2;
    //printf("%lf\n",f);
    scanf("%d",&_);
    while(_--)
    {
        scanf("%lf",&t);
        printf("%.2f\n",t*t*f);
    }
    return 0;
}
