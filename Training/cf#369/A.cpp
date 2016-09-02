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
char s[N][N];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    int ok=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        if(ok) continue;
        int m=strlen(s[i]);
        for(int j=1;j<m;j++)
        {
            if(s[i][j]=='O'&&s[i][j-1]=='O')
            {
                s[i][j]='+';
                s[i][j-1]='+';
                ok=1;
            }
            if(ok) break;
        }
    }
    if(!ok) puts("NO");
    else
    {
        puts("YES");
        for(int i=0;i<n;i++)
        {
            printf("%s\n",s[i]);
        }
    }
    return 0;
}
