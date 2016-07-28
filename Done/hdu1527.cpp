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
const int N=1000;

int main()
{
    int _,n,m,b,k;
    while(~scanf("%d%d",&n,&m)){
    if(n>m) swap(n,m);
    k=m-n;
    b=k*(1+sqrt(5.0))/2;
    if(b==n) puts("0");
    else puts("1");
    }
    return 0;
}
