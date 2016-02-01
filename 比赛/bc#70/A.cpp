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
    int f,n,i,j,a,b,c,c1,c2,p,q;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&a,&b,&c);
        f=0;
        c1=sqrt(a)+1;
        c2=sqrt(c)+1;
        for(i=1;i<=c1;i++)
        {
            if(a%i) continue;
            p=a/i;
            for(j=1;j<=c2;j++)
            {
                if(c%j) continue;
                q=c/j;
                if(i*j+p*q==b) f=1;
                if(i*q+j*p==b) f=1;
                if(f) break;
            }
            if(f) break;
        }
        if(f==1)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
