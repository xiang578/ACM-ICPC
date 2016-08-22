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
    int x,n,y,a,b;
    scanf("%d",&n);
    a=b=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        if(x>y) a++;
        else if(x<y) b++;
    }
    if(a>b) puts("Mishka");
    else if(b>a) puts("Chris");
    else puts("Friendship is magic!^^");
    return 0;
}
