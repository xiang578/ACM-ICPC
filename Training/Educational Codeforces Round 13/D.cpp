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
const ll p=1e9+7;
const int N=2048;
ll n,a,b,x;

struct node
{
    ll mat[2][2];
} A,B;

node operator *(const node &n1,const node &n2)
{
    node c;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            c.mat[i][j]=0;
            for(int k=0; k<2; k++)
            {
                //c.mat[i][j]=(c.mat[i][j]+n1.mat[i][k]*n2.mat[k][j]%(p-1))%(p-1);
                c.mat[i][j]=(c.mat[i][j]+n1.mat[i][k]*n2.mat[k][j]%p)%p;
            }
        }
    }
    return c;
}
node fst(node n1,ll x)
{
    node c;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
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

int main()
{
    cin>>a>>b>>n>>x;
    A.mat[0][0]=x;
    A.mat[0][1]=0;
    A.mat[1][0]=b;
    A.mat[1][1]=0;
    B.mat[0][0]=a;
    B.mat[0][1]=1;
    B.mat[1][0]=0;
    B.mat[1][1]=1;
    B=fst(B,n);
    A=B*A;
    cout<<A.mat[0][0]%p<<endl;
    return 0;
}
