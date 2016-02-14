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

int a[N],b[2*N];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,x,y,n,ans;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            a[x+y]++;
            b[x-y+N]++;
        }
        ans=0;
        for(i=0;i<N;i++)
        {
            if(a[i]>1)
                ans+=(a[i]-1)*a[i]/2;
        }
        //printf("%d\n",ans);
        for(i=0;i<2*N;i++)
        {
            if(b[i]>1)
                ans+=(b[i]-1)*b[i]/2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
