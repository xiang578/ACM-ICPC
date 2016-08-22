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
char s[10000000+10];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,cas=0;
    while(~scanf("%s",&s))
    {
        int ok=1;
        int t=0;
        n=strlen(s);
        for(int i=0;i<n;i++)
        {
            t=t*10+s[i]-'0';
            t%=73;
        }
        if(t!=0) ok=0;
        t=0;
        for(int i=0;i<n;i++)
        {
            t=t*10+s[i]-'0';
            t%=137;
        }
        if(t!=0) ok=0;
        printf("Case #%d: ",++cas);
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}
