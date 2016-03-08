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

int a[20],b[20];

int get(int u,int v)
{
    int w=abs(u-v);

}

int main()
{
    int _,n,m,cnt,u,v;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<3;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        cnt=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            printf("%d\n",get(u,v));
        }
    }
    return 0;
}
