/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Fri Mar 30 15:59:43 2018
File Name     :l1-1.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
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
using namespace std;

int bin[10000+10],u[10000+10];

int Find(int x)
{
    if(x==bin[x]) return x;
    else return bin[x]=Find(bin[x]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    memset(u,0,sizeof(u));
    for(int i=0;i<=10000;i++) bin[i]=i;
    int n,m,k,t,v;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            scanf("%d",&t);
            u[t]=1;
            if(i==0) v=t;
            else
            {
                int fu=Find(v);
                int ft=Find(t);
                bin[fu]=ft;
            }
        }
    }
    int ans=0,cnt=0;
    for(int i=0;i<=10000;i++)
    {
        if(u[i]==0) continue;
        cnt++;
        if(Find(i)==i) ans++;
    }
    printf("%d %d\n",cnt,ans);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&k,&t);
        if(Find(k)!=Find(t)) puts("N");
        else puts("Y");
    }
    return 0;
}
