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
const int M=1e6+10;
const double eps=1e-8;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    cin>>_;
    while(_--)
    {
        double a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        if(fabs(a)<eps||fabs(c)<eps) printf("parabola\n");
        else if(a*c<0) puts("hyperbola");
        else if(fabs(a-c)<eps) puts("circle");
        else puts("ellipse");
    }
    return 0;
}
