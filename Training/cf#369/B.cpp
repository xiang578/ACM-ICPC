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
ll a[N][N],b[N],c[N];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&a[i][j]);
            if(a[i][j]==0)
            {
                x=i;
                y=j;
            }
        }
    }
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i]+=a[i][j];
            c[j]+=a[i][j];
        }
    }
    if(n==1) printf("1");
    else
    {
        int n1,n2;
        if(x==0) n1=1;
        else n1=0;

        if(y==0) n2=1;
        else n2=0;
        int ok=1;
        for(int i=0;i<n;i++)
        {
            if(i!=x&&b[i]!=b[n1]) ok=0;
            if(i!=y&&c[i]!=c[n2]) ok=0;
        }
        ll x1,x2,x3;
        x1=b[n1]-b[x];
        x2=c[n2]-c[y];
        if(x1!=x2||ok==0||x1<=0) {printf("-1\n");return 0;}
        a[x][y]=x1;
        ll sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            sum1+=a[i][i];
            sum2+=a[i][n-i-1];
        }
        if(sum1!=sum2||sum1!=b[n1]) printf("-1\n");
        else printf("%lld\n",x1);
    }
    return 0;
}
