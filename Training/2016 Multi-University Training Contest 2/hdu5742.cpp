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
    int n,m,a[120],x,y,a1,a2;
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        memset(a,0xff,sizeof(a));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            x--;
            a[x]=y;
        }
        a[n]=0;
        for(int i=n-1;i>1;i--)
        {
            if(a[i]!=-1) continue;
            a[i]=a[i+1];
        }
        if(a[0]==-1) a[0]=100;
        if(a[1]==-1) a[1]=a[0];
        a1=a[0]+a[1];
        a2=0;
        for(int i=0;i<n;i++) a2+=a[i];
        int t=__gcd(a1,a2);
        printf("%d/%d\n",a1/t,a2/t);
    }
    return 0;
}
