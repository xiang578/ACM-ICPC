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
int a[N],ans;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,d,b,t;
    scanf("%d%d%d",&n,&d,&b);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    ans=0;
    t=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>d) continue;
        t+=a[i];
        if(t>b) {t=0;ans++;}
    }
    printf("%d\n",ans);
    return 0;
}
