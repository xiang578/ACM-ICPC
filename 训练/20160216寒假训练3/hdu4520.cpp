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

double x[100],y[100];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,n,ans;
    double tmp;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&x[i]);
            y[i]=x[i];
        }
        tmp=0;
        sort(y,y+n);
        for(i=1;i<n-1;i++)
            tmp+=y[i];
        tmp=tmp/(n-2);
        ans=0;
        for(i=1;i<n;i++)
        {
            double fa=fabs(x[i]-tmp);
            double fb=fabs(x[ans]-tmp);
            if(fa<fb)
            {
                ans=i;
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
