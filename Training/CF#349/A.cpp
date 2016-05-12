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
double pi=3.1415926535897932384626433832795028841971;
double eps=1e-8;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    double h,d,v,e,r,s,p;
    scanf("%lf%lf%lf%lf",&d,&h,&v,&e);
    r=d/2;
    s=pi*r*r;
    p=v/s;
    if(p>e)
    {
       puts("YES");
       printf("%.12f\n",h/(p-e));
    }
    else puts("NO");
    return 0;
}
