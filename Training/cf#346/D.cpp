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
const int N=1e5+10;
int x[N],y[N];
int n;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)
    {
        cin>>x[i]>>y[i];
    }
    int pre=0,now,a=0;
    for(int i=2;i<=n;i++)
    {
        if(y[i-1]==y[i]&&x[i]==x[i+1]&&x[i-1]<x[i]&&y[i]<y[i+1]) a++;
        if(x[i-1]==x[i]&&y[i]==y[i+1]&&y[i-1]>y[i]&&x[i]<x[i+1]) a++;
        if(y[i-1]==y[i]&&x[i]==x[i+1]&&x[i-1]>x[i]&&y[i]>y[i+1]) a++;
        if(x[i-1]==x[i]&&y[i]==y[i+1]&&y[i-1]<y[i]&&x[i]>x[i+1]) a++;
    }
    cout<<a;
    return 0;
}
