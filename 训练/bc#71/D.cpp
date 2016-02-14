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
int a[50000+5],f[50000+5];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int mx,i,j,_,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        mx=a[0];
        f[i]=0;
        for(i=0; i<n; i++)
        {
            mx=max(mx,a[i]-f[i]);
            f[i+1]=mx;
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
