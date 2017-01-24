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
const int M=1e6+10;
char s[50];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%s",s))
    {
        ll b=2147483648;
        b=-b;
        ll c=2147483647;
        ll d=32768;
        d=-d;
        char s1[50]="9223372036854775807";
        char s2[50]="-9223372036854775808";
        int n=strlen(s);
        if(n<19)
        {
            ll a;
            if(s[0]=='-')
            {
                a=s[1]-'0';
                for(int i=2; i<n; i++)
                {
                    a=a*10+s[i]-'0';
                }
                a=-a;
            }
            else
            {
                a=s[0]-'0';
                for(int i=1; i<n; i++)
                {
                    a=a*10+s[i]-'0';
                }
            }
            if(a>=d&&a<=32767) puts("short");
            else if(a>=b&&a<=c) puts("int");
            else puts("long long");
        }
        else if(n>20)
        {
            puts("It is too big!");
        }
         else if(n==20&&s[0]!='-')
        {
            puts("It is too big!");
        }
        else
        {
            int ok=0;
            if(s[0]=='-')
            {
                for(int i=1; i<n; i++)
                {
                    if(s[i]>s2[i])
                    {
                        ok=1;
                        break;
                    }
                    else if(s[i]<s2[i]) break;
                }
            }
            else
            {
                for(int i=0; i<n; i++)
                {
                    if(s[i]>s1[i])
                    {
                        ok=1;
                        break;
                    }
                    else if(s[i]<s1[i]) break;
                }
            }
            if(ok) puts("It is too big!");
            else puts("long long");
        }
    }
    return 0;
}
