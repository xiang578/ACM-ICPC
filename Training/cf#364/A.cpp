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
    int n,a[1024],s=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        s+=a[i];
    }
    s/=n/2;
    int u[1024];
    memset(u,0,sizeof(u));
    for(int i=1;i<=n;i++)
    {
        if(u[i]) continue;
        u[i]=1;
        for(int j=1;j<=n;j++)
        {
            if(a[i]+a[j]==s&&u[j]==0)
            {
                u[j]=1;
                printf("%d %d\n",i,j);
                break;
            }
        }
    }
    return 0;
}
