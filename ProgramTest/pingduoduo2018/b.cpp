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
const int M=1e6+10;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    int ans[200],d[200];
    scanf("%d%d",&n,&m);
    int now=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",ans+i,d+i);
        if(ans[i]>0) now++;
    }
    while(1)
    {
        for(int j=0;j<2;j++){
            int mx=-1;
            for(int i=0;i<n;i++)
            {
                if(ans[i]<=0) continue;
                if(mx==-1||ans[mx]<ans[i]||(ans[mx]==ans[i]&&d[mx]<d[i])) mx=i;
            }
            //printf("%d\n",mx);
            if(mx==-1) break;
            ans[mx]=-1;
        }
        now=0;
        for(int i=0;i<n;i++)
        {
            if(ans[i]<=-1) continue;
            if(ans[i]-d[i]<=0) ans[i]=0;
            else {ans[i]-=d[i];now++;}
        }
        if(now<m||now==0) break;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
