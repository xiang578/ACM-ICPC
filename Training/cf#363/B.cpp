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
const int N=1048;
const int M=1e6+10;
char s[N][N];
struct node
{
    int x,y;
} p[N*N];
int a[N],b[N];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) scanf("%s",s[i]);
    int x=-1,y=-1,o=1;
    int t=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='.') continue;
            p[t].x=i;
            p[t++].y=j;
        }
    }
    if(t>n+m) puts("NO");
    else
    {
        x=p[0].x;
        for(y=0;y<m;y++)
        {
            o=1;
            for(int i=0;i<t;i++)
            {
                if(x==p[i].x||p[i].y==y) continue;
                o=0;
                break;
            }
            if(o) break;
        }
        if(o) {printf("YES\n%d %d\n",x+1,y+1);return 0;}
        y=p[0].y;
        for(x=0;x<n;x++)
        {
            o=1;
            for(int i=0;i<t;i++)
            {
                if(x==p[i].x||p[i].y==y) continue;
                o=0;
                break;
            }
            if(o) break;
        }
        if(o) {printf("YES\n%d %d\n",x+1,y+1);return 0;}
        printf("NO\n");
    }
    return 0;
}
