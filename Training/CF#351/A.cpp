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
    int n,a[1024];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    int ans=0;
    a[0]=0;
    a[n+1]=90;
    for(int i=1;i<=n+1;i++)
    {
        if(a[i]-a[i-1]>15) {ans=a[i-1]+15;break;}
        else ans=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
