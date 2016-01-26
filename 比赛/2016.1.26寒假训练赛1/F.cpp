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

char s[2000000];
int a[10000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,n,j,ans,t,cnt,len;
    while(~scanf("%s",s))
    {
        if(strcmp(s,"END")==0) break;
        len=strlen(s);
        for(i=0;i<len;i++)
            if(s[i]!='0') break;
        if(i==len)
        {
            n=1;
            a[0]==0;
            a[1]=1;
        }
        else
        {
            n=len-i;
            a[1]=n;
            if(n==1)
                a[0]=s[i]-'0';
            else
                a[0]=1;
        }
        if(a[1]==a[0])
        {printf("1\n");continue;}
        for(i=2;;i++)
        {
            cnt=0;
            while(n)
            {
                cnt++;
                n/=10;
            }
            a[i]=cnt;
            if(a[i]==a[i-1]) break;
            n=cnt;
        }
        printf("%d\n",i);
    }
    return 0;
}
