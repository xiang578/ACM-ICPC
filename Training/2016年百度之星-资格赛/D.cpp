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
map<string,int>mp;
int cmp(char a,char b)
{
    return a<b;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,a[50];
    string s;
    char st[50];
    while(~scanf("%d",&n))
    {
        mp.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%s",st);
            s="";
            sort(st,st+strlen(st),cmp);
            int len=strlen(st);
            for(int k=0;k<len;k++)
                s+=st[k];
            printf("%d\n",mp[s]);
            mp[s]++;
        }
    }
    return 0;
}
