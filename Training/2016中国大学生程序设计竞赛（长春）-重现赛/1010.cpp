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
char s[1024],t[1024];
vector<string>ans;

void sub()
{
    // printf("%s %s ",s,t);
    char x[1024];
    memset(x,0,sizeof(x));
    int m=strlen(t),n=strlen(s),j=0;
    for(int i=0; i<m; i++)
    {
        if(j==1)
        {
            if(s[i]=='0')
            {
                j=1;
                s[i]='9';
            }
            else
            {
                j=0;
                s[i]--;
            }
        }
        if(s[i]>=t[i])
        {
            x[i]=s[i]-t[i]+'0';
        }
        else
        {
            j=1;
            x[i]=s[i]+10-t[i]+'0';
        }
    }
    for(int i=m; i<n; i++)
    {
        if(j==1)
        {
            if(s[i]=='0')
            {
                j=1;
                s[i]='9';
            }
            else
            {
                j=0;
                s[i]--;
            }
        }
        x[i]=s[i];
    }
    int len=strlen(x);
    for(int i=len-1; i>=0; i--)
    {
        if(x[i]!='0') break;
        x[i]=0;
    }
    len=strlen(x);
    memset(s,0,sizeof(s));
    for(int i=0; i<len; i++)
        s[i]=x[i];
    //printf("%s\n",s);
}

void get()
{
    ans.clear();
    int n=strlen(s),k,m;
    while(n!=0)
    {
        string tmp="";
        memset(t,0,sizeof(t));
        if(n==1)
        {

        }
        else
        {
            for(int i=0; i<n-1; i++)
            {
                t[i]='9';
            }
            m=strlen(t);
            for(int i=m-1; i>=0; i--)
            {
                tmp+=t[i];
            }
        }
        sub();
        n=strlen(s);
        //n=0;
        //printf("%s %s\n",t,s);
        ans.push_back(tmp);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    scanf("%d",&_);
    for(int k=1; k<=_; k++)
    {
        scanf("%s",t);
        int n=strlen(t);
        memset(s,0,sizeof(s));
        for(int i=0; i<n; i++)
        {
            s[n-i-1]=t[i];
        }
        get();
        printf("Case #%d:\n",k);
        printf("%d\n",ans.size());

        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}
