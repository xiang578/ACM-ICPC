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
ll n,a,b,c,p;

struct node
{
    ll mat[3][3];
}A,B;

node operator *(const node &n1,const node &n2)
{
    node c;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c.mat[i][j]=0;
            for(int k=0;k<3;k++)
            {
                c.mat[i][j]=(c.mat[i][j]+n1.mat[i][k]*n2.mat[k][j]%(p-1))%(p-1);
            }
        }
    }
    return c;
}
node fst(node n1,ll x)
{
    node c;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c.mat[i][j]=(i==j);
        }
    }
    while(x)
    {
        if(x&1) c=c*n1;
        n1=n1*n1;
        x>>=1;
    }
    return c;
}

ll pow_mod(ll x,ll y)
{
    ll ans=1;
    for(y;y;y>>=1)
    {
        if(y&1) ans=ans*x%p;
        x=x*x%p;
    }
    return ans;
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        cin>>n>>a>>b>>c>>p;
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        if(a%p==0)
        {
            printf("0\n");
            continue;
        }
        A.mat[0][0]=b;A.mat[1][0]=0;A.mat[2][0]=b;
        B.mat[0][0]=c;B.mat[0][1]=1;B.mat[0][2]=1;
        B.mat[1][0]=1;B.mat[1][1]=0;B.mat[1][2]=0;
        B.mat[2][0]=0;B.mat[2][1]=0;B.mat[2][2]=1;
        B=fst(B,n-2);
        A=B*A;
        cout<<pow_mod(a,A.mat[0][0])<<endl;
    }
    return 0;
}
