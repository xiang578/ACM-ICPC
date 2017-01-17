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
const int N=1e6+10;
char s[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,n,ok;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        if(n%2) ok=0;
        else
        {
            ok=1;
            int l=0,r=0,t=0;
            for(int i=0; i<n; i++)
            {
                if(s[i]=='(') l++;
                else if(s[i]==')')  r++;
                t=max(t,r-l);
            }
            if(l!=r||t>2) ok=0;
            else
            {
                if(t==0&&n==2) ok=0;
                else ok=1;
            }
        }
        if(ok) puts("Yes");
        else puts("No");
    }
    return 0;
}
