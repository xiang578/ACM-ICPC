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
int x[20480],y[20480];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,a,b,c,t,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        //if(a<b) swap(a,b);
        cnt=0;
        for(i=0; a*i<=c; i++)
         {
            for(j=0; j*b<=c; j++)
                if(a*i+j*b==c)
                {
                    x[cnt]=i;
                    y[cnt]=j;
                    cnt++;
                }
                else if(a*i+j*b>c)
                    break;
         }
         int m,n,ans=-1;
         for(i=0;i<cnt;i++)
         {
             if(x[i]%2==0&&y[i]%2==0)
             {
                if(ans>x[i]+y[i]||ans==-1)
                {
                    ans=x[i]+y[i];
                    n=x[i];
                    m=y[i];
                }
             }
         }
        if(ans!=-1)
            printf("%d %d\n",n,m);
        else printf("Impossible\n");
    }
    return 0;
}
