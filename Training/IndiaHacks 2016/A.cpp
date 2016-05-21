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
    int i,t,a[1024],n;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        a[t]=1;
    }
    int f=0;
    for(i=2;i<1000;i++)
    {
        if(a[i-1]&&a[i]&&a[i+1]) {f=1;break;}
    }
    if(f) puts("YES");
    else puts("NO");
    return 0;
}
