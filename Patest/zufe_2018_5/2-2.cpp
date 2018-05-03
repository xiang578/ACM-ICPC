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
int data[100000],nt[100000],next[100000];
vector<int>ans,ans2;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int st,n,a,b,c;
    scanf("%d%d",&st,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        data[a]=b;
        nt[a]=c;
    }
    while(st!=-1)
    {
        //printf("!!! %d\n",st);
        ans.push_back(st);
        st=nt[st];
    }
    int p1=n-1,p2=0;
    while(1)
    {
        ans2.push_back(ans[p1]);
        p1--;
        if(p1<p2) break;

        ans2.push_back(ans[p2]);
        p2++;
        if(p2>p1) break;
    }
    //for(int i=0;i<n;i++) //printf("%d\n",ans2[i]);
    for(int i=0;i<n;i++)
    {
        printf("%05d %d ",ans2[i],data[ans2[i]]);
        if(i==n-1) printf("-1\n");
        else printf("%05d\n",ans2[i+1]);
    }
    return 0;
}
