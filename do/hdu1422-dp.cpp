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

int a[400000+10];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,i,ans,w,l,st,cnt;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&w,&l);
			a[i+n]=a[i]=w-l;
		}
		//for(i=0;i<n;i++) printf("%d\n",a[i]);
		ans=0;
		w=0;
		st=-1;
		cnt=0;
		for(i=0;i<2*n;i++)
		{
			if(i>=n&&st==-1) break;
			if(i-n==st&&st!=-1) break;
			if(st==-1)
			{
				if(a[i]<0) continue;
				cnt=1;
				w=a[i];
				st=i;
			}
			else
			{
				if(w+a[i]>=0)
				{
				    //printf("%d %d\n",w,a[i]);
					w=w+a[i];
					cnt++;
				}
				else
				{
					st=-1;
					cnt=0;
					w=0;
					//printf("%d %d\n",i,a[i]);
				}
			}
			ans=max(cnt,ans);
			//printf("%d %d %d %d\n",ans,cnt,i,w);
		}
		printf("%d\n",ans);
	}
    return 0;
}
