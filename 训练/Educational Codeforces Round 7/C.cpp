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

vector<int>v[1000005];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    for(int i=0;i<1000005;i++)
    v[i].clear();
    int n,m,t,l,r,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        v[t].push_back(i);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&l,&r,&t);
        int ans=-1;
        for(j=0;j<v[t].size();j++)
        {
            if(v[t][j]<l) continue;
            if(v[t][j]>r) break;
            while(l==v[t][j])
            {
                l++;
                j++;
            }
            if(l<=r) ans=l;
        }
        printf("%d\n",ans);
    }
    return 0;
}
