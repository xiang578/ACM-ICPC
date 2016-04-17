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
    int _,i,j,n,t,f;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        f=0;
        int f1=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            if(t==0) f=1;
            if(t==1) f1=1;
        }
        if(f&&f1) puts("YES");
        else puts("NO");
    }
    return 0;
}
