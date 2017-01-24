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
int n;
int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int a,b,c,d,t,ti,t4,t1,t2,t3;
	long long ans;
	while(~scanf("%d%d%d%d%d",&n,&a,&b,&c,&d)) {
		ans=0;
		for(int j=1; j<=n; j++) {
			t1=n-(j+a+b);
			t2=n-(a+j+c);
			t3=n-(b+d+j);
			t4=n-(c+d+j);
			t=max(max(t1,t2),max(t3,t4));
			ti=min(t+n,t1+n);
			ti=min(ti,t2+n);
			ti=min(ti,t3+n);
			ti=min(ti,t4+n);
			if(ti<t+1) 
				continue;
			else 
				ans+=(ti-t);
		}
		cout<<ans<<endl;
	}
	return 0;
}
