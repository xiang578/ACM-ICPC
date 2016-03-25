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
char s1[100000+5],s2[50];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,n,m,ans,flag;
    while(~scanf("%s%s",s1,s2))
    {
        ans=0;
        n=strlen(s1);
        m=strlen(s2);
        for(i=0;i<n;i++)
        {

            for(j=0;j<m&&i+j<n;j++)
                if(s1[i+j]!=s2[j]) break;
            if(j==m)
            {
                ans++;
                s1[i+j-1]='#';
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
