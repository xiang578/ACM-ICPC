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

int get(int a,int b,int c)
{
    if(a<b) swap(a,b);
    if(c>=a||c<=b) return 1;
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a1,a2,a3,b1,b2,b3,i,n,ans=3;
    scanf("%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3);
    if(a1==a2&&a2==a3) ans=1;
    else if(b1==b2&&b2==b3) ans=1;
    else
    {
        if(a1==a2&&get(b1,b2,b3)) ans=2;
        if(a2==a3&&get(b2,b3,b1)) ans=2;
        if(a3==a1&&get(b3,b1,b2)) ans=2;
        if(b1==b2&&get(a1,a2,a3)) ans=2;
        if(b2==b3&&get(a2,a3,a1)) ans=2;
        if(b3==b1&&get(a3,a1,a2)) ans=2;

    }
    printf("%d\n",ans);
    return 0;
}
