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


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char s[1024];
    int _,m,i,j,len,p,st;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%s %d",s,&m);
        len=strlen(s);
        st=0;
        for(i=0;i<len;i++)
        {
            if(i!=0) st=1;
            if(m==0) break;
            p=-1;
            for(j=len-1;j>i;j--)
            {
                if(s[j]=='0'&&!st) continue;
                if(s[j]<s[i])
                {
                    if(p==-1) p=j;
                    if(s[p]>s[j])
                    {
                        p=j;
                    }
                }
            }
            if(p==-1) continue;
            else
            {
                swap(s[p],s[i]);
                m--;
            }
        }
        printf("%s\n",s);
    }
    return 0;
}
