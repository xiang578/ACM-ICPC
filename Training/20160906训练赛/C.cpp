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
char s[M],b[20][20];
int n,a[M];
struct node
{
    int st,ed;
};
vector<node>g;

int cmp(node n1,node n2)
{
    if(n1.st==n2.st) return n1.ed<n2.ed;
    else
    return n1.st<n2.st;
}

void getfail(char *p,int *f)
{
    int m=strlen(p);
    f[0]=0;
    f[1]=0;
    for(int i=1; i<m; i++)
    {
        int j=f[i];
        while(j&&p[i]!=p[j]) j=f[j];
        f[i+1]=p[i]==p[j]?j+1:0;
    }
}

int kmp(char *t,char *p,int *f)
{
    int cnt=0,i,j,n=strlen(t),m=strlen(p);
    getfail(p,f);
    for(i=0,j=0; i<n; i++)
    {
        while(j&&p[j]!=t[i]) j=f[j];
        if(p[j]==t[i]) j++;
        if(j==m)
        {
            node tmp;
            tmp.st=i-m+1;
            tmp.ed=i;
            g.push_back(tmp);
            cnt++;
            j=f[j];
        }
    }
    return cnt;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int f[100];
    scanf("%s",s);
    int len=strlen(s);
    g.clear();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",b[i]);
        kmp(s,b[i],f);
    }
    sort(g.begin(),g.end(),cmp);
    for(int i=g.size()-2;i>=0;i--)
    {
        g[i].ed=min(g[i].ed,g[i+1].ed);
    }
    int j=0;
    int ans=0,st=0,now;
    for(int i=0;i<len;i++)
    {
        for(;j<g.size();j++)
        {
            if(g[j].st>=i) break;
        }
        if(j==g.size()) now=len-i;
        else if(i==g[j].st) now=g[j].ed-g[j].st;
        else now=g[j].ed-i;
        if(now>ans)
        {
            ans=now;
            st=i;
        }
        //printf("%d %d %d\n",g[j].st,i,now);
    }
    printf("%d %d\n",ans,st);
    return 0;
}
