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


int check(int x,long long n)
{
    long long tmp=0;
    for(int i=1;i<=x;i++)
    {
        tmp=tmp*10+1;
        tmp%=n;
    }
    return tmp;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long n;
    int ans;
    cin>>n;
    ans=1;
    vector<int>v;
    while(check(ans,n))
    {
        ans++;
    }
    long long now=0;
    for(int i=0;i<ans;i++)
    {
        now=now*10+1;
        v.push_back(now/n);
        now=now%n;
    }
    int i=0;
    for(i=0;i<v.size();i++) if(v[i]!=0) break;
    for(;i<v.size();i++) printf("%d",v[i]);
    printf(" %d\n",ans);
    return 0;
}