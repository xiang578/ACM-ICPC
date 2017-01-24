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

long long a,b,c,t;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	cin>>a>>b>>c;
	if(c==0)
	{
		if(a==b) puts("YES");
		else puts("No");
		return 0;
	}
	t=(b-a)/c;
	if((b-a)%c==0&&t>=0) puts("YES");
	else puts("NO");
    return 0;
}
