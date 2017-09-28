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
int a[10],b[10];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,t;
    scanf("%d",&_);
    while(_--)
    {
        int num;
        scanf("%d",&num);
        memset(a,0,sizeof(a));
        int t=num;
        while(t)
        {
            a[t%10]++;
            t/=10;
        }
        int ok=0;
        for(int i=2;i<=10;i++)
        {
            t=num*i;
            memset(b,0,sizeof(b));
            while(t)
            {
                b[t%10]++;
                t/=10;
            }
            ok=1;
            for(int i=0;i<10;i++)
            {
                if(a[i]!=b[i])
                {
                    ok=0;
                    break;
                }
            }
            if(ok==1) break;
        }
        if(ok) puts("Possible");
        else puts("Impossible");
    }
    return 0;
}
