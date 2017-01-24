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


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    double rb,rf,yue1,yue2,li1,li2,huan1,huan2,huan;
    int y,ym,ph,mf,need,shangye;
    while(~scanf("%d%d%lf%lf%d",&ph,&mf,&rb,&rf,&y))
    {
        ym=y*12;
        rb/=12;
        rf/=12;
        need=ph*7/10-mf;
        shangye=ph-need-mf;
        li1=1;
        li2=1;
        for(int i=1;i<=ym;i++)
        {
            li1*=(1+0.01*rb);
            li2*=(1+0.01*rf);
        }
        huan1=need*1.0*10000*(0.01*rb*li1)/(li1-1);
        huan2=mf*1.0*10000*(0.01*rf*li2)/(li2-1);
        //printf("%lf %lf\n",huan1,huan2);
        huan=huan1+huan2;
        printf("%d %.0f\n",shangye,huan);
    }
    return 0;
}
