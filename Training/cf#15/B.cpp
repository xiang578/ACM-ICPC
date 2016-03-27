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
   	ll n,m,x1,x2,y1,y2,l1,l2,r1,r2,d1,d2,u1,u2,l,r,d,u,ans,a1,a2,b1,b2;
	int _;
	scanf("%d",&_);
	while(_--)
	{
		cin>>n>>m>>x1>>y1>>x2>>y2;
		if(x1>x2) {swap(x1,x2);swap(y1,y2);}
		l1=x1-1;r1=n-x1;u1=y1-1;d1=m-y1;
		l2=x2-1;r2=n-x2;u2=y2-1;d2=m-y2;
		l=min(l1,l2);
		r=min(r1,r2);
		u=min(u1,u2);
		d=min(d1,d2);
		//cout<<l<<r<<u<<d;
		ans=(l+r+1)*(1+u+d)*2;
		//printf(" %lld\n",ans);
        if(x1<x2)
        {
            a1=x1+r;
            a2=x2-l;
            if(y1<y2)
            {
                b1=y1+d;
                b2=y2-u;
                if(a1>=a2&&b1>=b2)
                {
                    //printf("%lld\n",(a1-a2+1)*(b1-b2+1));
                    ans-=(a1-a2+1)*(b1-b2+1);
                }

            }
            else if(y1==y2)
            {
                //printf("%lld %lld\n",a1,a2);
                if(a1>=a2) ans-=(a1-a2+1)*m;
            }
            else
            {
                b1=y1-u;
                b2=y2+d;
                if(a1>=a2&&b1<=b2)
                {
                    ans-=(a1-a2+1)*(b2-b1+1);
                }
            }
        }
        else if(x1==x2)
        {
            if(y1>y2)
            {
                b1=y1-u;
                b2=y2+d;
                if(b1<=b2)
                    ans-=(b2-b1+1)*n;
            }
            else
            {
                b1=y1+d;
                b2=y2-u;
                if(b1>=b2)
                {
                    ans-=(b1-b2+1)*n;
                }
            }

        }
        //cout<<a1<<b1<<a2<<b2<<endl;
		//printf("%lld\n",ans);
		cout<<n*m-ans<<endl;
	}
    return 0;
}
