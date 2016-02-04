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

char key[50][50];
char s[20000];
char t[20000];
char ans[50000];
int use[200],r[200],c[200],k;

void get(char a,char b)
{
    int p,q;
    if(r[a]==r[b])
    {
        p=r[a];
        q=c[a]+1;
        if(q==5) q=0;
        ans[k++]=key[p][q];

        p=r[b];
        q=c[b]+1;
        if(q==5) q=0;
        ans[k++]=key[p][q];

    }
    else if(c[a]==c[b])
    {
        p=r[a]+1;
        q=c[a];
        if(p==5) p=0;
        ans[k++]=key[p][q];

        p=r[b]+1;
        q=c[b];
        if(p==5) p=0;
        ans[k++]=key[p][q];
    }
    else
    {
        p=r[a];
        q=c[b];
        ans[k++]=key[p][q];

        p=r[b];
        q=c[a];
        ans[k++]=key[p][q];
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,i,j,x,y,p,q;
    while(~scanf("%s",s))
    {
        n=strlen(s);
        x=0;
        y=0;
        memset(use,0,sizeof(use));
        for(i=0; i<n; i++)
        {
            if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
            if(s[i]=='j') s[i]='i';
            p=s[i]-'a';
            if(!use[p])
            {
                use[p]=1;
                key[x][y]=s[i];
                r[s[i]]=x;
                c[s[i]]=y;
                y++;
                if(y==5)
                {
                    x++;
                    y=0;
                }
            }
        }
        for(i=0; i<26; i++)
        {
            if(i=='j'-'a') continue;
            if(!use[i])
            {
                use[i]=1;
                key[x][y]='a'+i;
                r['a'+i]=x;
                c['a'+i]=y;
                y++;
                if(y==5)
                {
                    x++;
                    y=0;
                }
            }
        }
        //for(i=0;i<5;i++)  {for(j=0;j<5;j++)    printf("%c",key[i][j]); printf("\n");}
        k=0;
        int f=0;
        while(gets(s))
        {
            n=strlen(s);
            for(i=0; i<n; i++)
            {
                if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
                if(s[i]=='j') s[i]='i';
                if(s[i]=='*') f=1;
                if(s[i]>='a'&&s[i]<='z') t[k++]=s[i];
            }
            if(f==1) break;
        }
        t[k]=0;
        n=strlen(t);
        for(i=0,k=0; i+1<n; i++)
        {
            if(t[i]==t[i+1])
            {
                get(t[i],'x');
            }
            else
            {
                get(t[i],t[i+1]);
                i++;
            }
        }
        ans[k]=0;
        printf("%s\n",ans);
    }
    return 0;
}
