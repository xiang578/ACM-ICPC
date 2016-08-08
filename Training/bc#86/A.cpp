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
    int _,n,m,a;
    ll ans,t;
    string o;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            ans+=a;
        }
        o="";
        for(int i=0;i<m;i++)
        {
            scanf("%lld",&t);
            if(t>ans) o+='1';
            else o+='0';
        }
        cout<<o<<endl;
    }
    return 0;
}
