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
int x[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,t;
    scanf("%d",&n);
    memset(x,0,sizeof(x));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        x[t]++;
    }
    int q;
    for(int i=1;i<=100000;i++)
        x[i]+=x[i-1];
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&t);
        t=min(t,100000);
        printf("%d\n",x[t]);
    }
    return 0;
}
