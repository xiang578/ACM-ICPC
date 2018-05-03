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

int v,e,k;
int se[10000],a[250000+10],b[250000+10],u[1000];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    scanf("%d%d%d",&v,&e,&k);
    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&a[i],b+i);
    }
    int n;
    cin>>n;
    while(n--)
    {
        set<int>st;
        for(int i=0;i<v;i++)
        {
            cin>>u[i];
            st.insert(u[i]);
        }
        if(st.size()!=k) puts("No");
        else 
        {
            int ok=0;
            for(int i=0;i<e;i++)
            {
                if(u[a[i]]==u[b[i]]) ok=1;
            }
            if(ok) puts("No");
            else puts("Yes");
        }
    }
    return 0;
}
