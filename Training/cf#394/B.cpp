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
int n,m;
int a[1000],b[1000],u[1000];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int ok=0;
    for(int i=0;i<n;i++)
    {
        u[a[i]]=1;
    }
    for(int s=0;s<m;s++)
    {
        ok=1;
        for(int i=0;i<n;i++)
        {
            int now=(s+b[i])%m;
            if(u[now]!=1)
            {
                ok=0;break;
            }
        }
        if(ok) break;
    }
    if(ok) puts("YES");
    else puts("NO");
    return 0;
}
