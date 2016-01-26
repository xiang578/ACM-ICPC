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
    int n,m,i,j,_,cas,ans;
    scanf("%d",&_);
    for(int k=1;k<=_;k++)
    {
        cas=0;
        while(~scanf("%d%d",&n,&m))
        {
            if(n==0&&m==0) break;
            ans=0;
            for(i=1;i<n;i++)
                for(j=i+1;j<n;j++)
            {
                int t=i*i+j*j+m;
                if(t%(i*j)==0) ans++;
            }
            printf("Case %d: %d\n",++cas,ans);
        }
        if(k!=_) printf("\n");
    }
    return 0;
}
