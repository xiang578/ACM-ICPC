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
    int h,m,t,n;
    while(~scanf("%d:%d",&h,&m))
    {
        scanf("%d",&t);
        m+=t%60;
        n=t/60;
        if(m>=60)
        {
            m-=60;
            n+=1;
        }
        h+=n;
        h=h%24;
        if(h<10) printf("0%d:",h);
        else printf("%d:",h);
        if(m<10) printf("0%d\n",m);
        else printf("%d\n",m);
    }
    return 0;
}
