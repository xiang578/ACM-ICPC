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
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={0,1,-1,-1,1,1,-1,0};
int ok(int x,int y)
{
    if(x<=0||x>8||y<=0||y>8) return 0;
    return 1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char s[10];
    int a,b;
    scanf("%s",s);
    a=s[0]-'a'+1;
    b=s[1]-'0';
    int ans=0;
    for(int i=0;i<8;i++)
    {
        ans+=ok(a+dx[i],b+dy[i]);
    }
    printf("%d\n",ans);
    return 0;
}
