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
const int N=1e+5;
int n,m;
int g[4*N],x[N],y[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,f;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof(g));
        for(int i=0; i<n; i++)
            scanf("%d%d",&x[i],&y[i]);
        f=0;
        for(int i=0; i<n; i++)
        {

            for(int j=i+1; j<n; j++)
            {
                int t=abs(x[i]-x[j])+abs(y[i]-y[j]);
                g[t]++;
                if(g[t]==2)
                {
                    f=1;
                    break;
                }
            }
            if(f) break;
        }

        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
