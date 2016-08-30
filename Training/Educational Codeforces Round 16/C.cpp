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
int ans[50][50];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    if(n==1)
    {printf("%d\n",n);return 0;}
    int a=1;
    int b=2;
    int f=1;
    int m=n/2+1;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++)
    {

        for(int j=m;j<m+f;j++)
        {
            ans[i][j]=a;
            a+=2;
        }
        for(int j=m-1;j>m-f;j--)
        {
            ans[i][j]=a;
            a+=2;
        }
        if(i<m) f++;
        else if(i>=m) f--;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        if(ans[i][j]==0) {ans[i][j]=b;b+=2;}
        printf("%d ",ans[i][j]);
        if(j==n) printf("\n");
    }
    return 0;
}
