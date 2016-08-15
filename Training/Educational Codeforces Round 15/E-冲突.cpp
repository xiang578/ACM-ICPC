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
const int N=1e5+10;
ll p[N][35],s[N][35],m[N][35];
int n,k;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&k);
    memset(p,0,sizeof(p));
    memset(s,0,sizeof(s));
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&p[i][0]);
        p[i][0]++;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i][0]);
        m[i][0]=s[i][0];
    }
    for(int i=1;i<35;i++)
    {

    }
    return 0;
}
