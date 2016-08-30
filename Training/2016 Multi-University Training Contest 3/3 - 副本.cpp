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
const int N=1000;
int b[1024][1024];
int t,n,m,flag;

void init()
{
    int x1,x2;
    //3
    memset(b,0xff,sizeof(b));
    b[N][N]=0;
    for(int i=N;i>=1;i--)
    {
        for(int j=N;j>=1;j--)
        {
            if(i==N&&j==N) continue;
            if(i+1>N||j+2>N) x1=-1;
            else x1=b[i+1][j+2];

            if(i+2>N||j+1>N) x2=-1;
            else x2=b[i+2][j+1];

            if(x1==0||x2==0) b[i][j]=1;
            if(x1==1&&x2==1) b[i][j]=0;
        }
    }
}

int main()
{
    int _;
    init();
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&t,&n,&m);
        if(t==1)
        {
            if(n%2&&m%2) puts("G");
            else puts("B");
        }
        else if(t==2)
        {
            if(n==m) puts("G");
            else puts("B");
        }
        else if(t==3)
        {
            int tmp=b[1+N-n][1+N-m];
            if(tmp==-1) puts("D");
            else if(tmp==1) puts("B");
            else puts("G");

            /*if(n>m) swap(n,m);
            if(n%3==1&&n==m) puts("G");
            else if(n%3==2&&n==m-1) puts("B");
            else puts("D");*/
        }
        else if(t==4)
        {
            int k,p,a1,a2;
            a1=n-1;
            a2=m-1;
            if(a1>a2) swap(a1,a2);
            k=a2-a1;
            p=floor(k*(1+sqrt(5.0))/2);
            if(p==a1) puts("G");
            else puts("B");
        }
    }
    return 0;
}
