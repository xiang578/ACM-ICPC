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
int a[M];

int Find(int x)
{
    if(a[x]==x) return x;
    else return a[x]=Find(a[x]);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            a[i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            int fx=Find(x);
            int fy=Find(i);
            if(fx!=fy)
            {
                a[fx]=fy;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(Find(i)==i) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
