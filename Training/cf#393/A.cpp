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
const int M=1e5+10;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int ans,t,m,d;
    cin>>m>>d;
    if(m==2) t=28;
    else if(m<=7&&m%2==1) t=31;
    else if(m>7&&m%2==0) t=31;
    else t=30;
    ans=0;
    while(t>0)
    {
        ans++;
        t-=7-d+1;
        d=1;
        //cout<<ans<<" "<<t<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
