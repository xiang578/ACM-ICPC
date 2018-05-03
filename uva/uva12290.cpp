/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Thu Apr 26 13:34:23 2018
File Name     :uva12290.cpp
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

int ok(int x)
{
    if(x%7==0) return 1;
    while(x)
    {
        if(x%10==7) return 1;
        x/=10;
    }
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a[1024],n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        if(n+m+k==0) break;
        memset(a,0,sizeof(a));
        int now = 1;
        int id=1,f=1;
        while(1)
        {
            if(now>=100000) {now=-1;break;}
            a[id]+=ok(now);
            if(a[m]==k) break;
            now++;
            id+=f;
            if(id==n+1)
            {
                id=n-1;
                f=-1;
            }
            if(id==0)
            {
                id=2;
                f=1;
            }
        }
        printf("%d\n",now);
    }
    return 0;
}
