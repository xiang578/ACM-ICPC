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
const int N=20480;
const int M=1e6+10;
int a[N],n,k,ans;



int Partition(int l,int r) {
	int pivot = a[l];
	while(l<r)
	{
		while(l<r&&a[r]>pivot) r--;
		a[l] = a[r];
		while(l<r&&a[l]<pivot) l++;
		a[r] = a[l];
	}
	a[l] = pivot;
	return l;
}

void get(int l,int r) {
	if(l<r) {
		int postion = Partition(l,r);
		if(postion==k) {ans=a[k]; return ;}
		if(postion<k) 
			get(postion+1,r);
		else
			get(l,postion-1);
	}
	if(l==r)
	{
		ans = a[k];return ;
	}
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	n = 0;
    char ch;
	while(scanf("%d%c",a+n,&ch)) {
		n++;
		if(ch=='\n') 
			break;
	}
	scanf("%d",&k);
	k=n-k;
	get(0,n-1);
	printf("%d\n",ans);
    return 0;
}
