/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#pragma comment(linker, "/STACK:102400000,102400000")
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
vector<long long>v;

void get(int x,int y,long long sum)
{
    //if(x+y>18||x>9||y>9) return ;
    if(x==y&&sum!=0)  v.push_back(sum);
    if(x<9) get(x+1,y,sum*10+4);
    if(y<9) get(x,y+1,sum*10+7);
}

/*void get(int k)
{
    //printf("%d\n",k);
    int cnt=0,a[30],a1,a2;
    long long ret=0;
    a1=a2=0;
    while(k>0)
    {
        if(k%2==0)  {a[cnt++]=4;a1++;}
        else {a[cnt++]=7;a2++;}
        k/=2;
    }
    if(a1==a2)
    {
        for(int i=cnt-1;i>=0;i--)
        {
            ret=ret*10+a[i];
        }
        v.push_back(ret);
    }
}*/

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    scanf("%d",&_);
    v.clear();
    long long t;
    get(0,0,0);
    sort(v.begin(),v.end());
    //for(int i=0;i<10;i++)   printf("%lld\n",v[i]);
    while(_--)
    {
        scanf("%lld",&t);
        int k=lower_bound(v.begin(),v.end(),t)-v.begin();
        if(t>v[k])
        {
            for(int i=0;i<10;i++)
                printf("4");
            for(int i=0;i<10;i++)
                printf("7");
            printf("\n");
        }
        else
            printf("%lld\n",v[k]);
    }
    return 0;
}
