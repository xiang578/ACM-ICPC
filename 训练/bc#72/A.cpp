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

int a[30],b[30],c[30];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,_,ta,tb,tc,t,k;
    char ch[10];
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&ta,&tb,&tc);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(i=0;i<ta;i++)
        {
            scanf("%s%d",&ch,&t);
            a[ch[0]-'A']=t;
        }
        for(i=0;i<tb;i++)
        {
            scanf("%s%d",&ch,&t);
            b[ch[0]-'A']=t;
        }
        for(i=0;i<tc;i++)
        {
            scanf("%s%d",&ch,&t);
            c[ch[0]-'A']=t;
        }
        int f=0;
        for(i=1;i<=100;i++)
        {
            for(j=1;j<=100;j++)
            {
                for(k=0;k<26;k++)
                {
                    if(i*a[k]+j*b[k]!=c[k]) break;
                }
                if(k==26) f=1;
                if(f) break;
            }
            if(f) break;
        }
        if(f) printf("%d %d\n",i,j);
        else puts("NO");
    }
    return 0;
}
