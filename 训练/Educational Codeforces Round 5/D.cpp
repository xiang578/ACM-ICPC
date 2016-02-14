/* ***********************************************
Author        :xryz
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
Created Time  :1-16 18:55:04
File Name     :D.cpp
************************************************ */

//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <set>
//#include <map>
//#include <string>
//#include <math.h>
//#include <stdlib.h>
//#include <time.h>
#include <bits/stdc++.h>
using namespace std;

int a[500000+10];
int f[1000000+10];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,n,k,l,r,ans,tl,tr,t,p;
    while(~scanf("%d%d",&n,&k))
    {
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        memset(f,0,sizeof(f));
        ans=0;
        tl=0;
        t=1;
        p=1;
        f[a[0]]=1;
        l=r=1;
        for(i=1; i<n; i++)
        {
            if(f[a[i]]==0)
                p++;
            f[a[i]]++;
            t++;
            while(p>k)
            {
                f[a[tl]]--;
                if(f[a[tl]]==0)
                    p--;
                tl++;
                t--;
            }
            if(t>ans)
            {
                ans=t;
                l=tl+1;
                r=i+1;
            }
        }

        printf("%d %d\n",l,r);
    }
    return 0;
}
