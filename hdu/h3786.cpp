#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mp[50][50],a1,a2;

void dfs1(int st,int ed,int cnt)
{
    if(a1) return;
    if(st==ed) {a1=cnt;return ;}
    for(int i=0;i<26;i++)
    {
        if(mp[st][i]==1)
        {
            dfs1(i,ed,cnt+1);
        }
    }
}

void dfs2(int st,int ed,int cnt)
{
    if(a2) return;
    if(st==ed) {a2=cnt;return ;}
    for(int i=0;i<26;i++)
    {
        if(mp[st][i]==1)
        {
            dfs2(i,ed,cnt+1);
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,n,m,a,b,c;
    char s[10];
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        memset(mp,0,sizeof(mp));
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            if(s[0]=='-') continue;
            else
            {
                a=s[0]-'A';
                if(s[1]!='-')
                {
                    b=s[1]-'A';
                    mp[a][b]=1;
                }
                if(s[2]!='-')
                {
                    c=s[2]-'A';
                    mp[a][c]=1;
                }
            }
        }
        for(i=0;i<m;i++)
        {
            scanf("%s",s);
            a1=a2=0;
            dfs1(s[0]-'A',s[1]-'A',0);
            dfs2(s[1]-'A',s[0]-'A',0);
            if(a1==0&&a2==0) printf("-\n");
            if(a1==1) printf("child\n");
            if(a2==1) printf("parent\n");
            if(a1==2) printf("grandchild\n");
            if(a2==2) printf("grandparent\n");
            if(a1>=3)
            {
                for(int j=3;j<=a1;j++)
                    printf("great-");
                printf("grandchild\n");
            }
            if(a2>=3)
            {
                for(int j=3;j<=a2;j++)
                    printf("great-");
                printf("grandparent\n");
            }
        }
    }
    return 0;
}
