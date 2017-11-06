/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Mon Oct 16 16:14:25 2017
File Name     :hdu1006.cpp
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

int ge(int a)
{
    return min(360*120-a,a);
}
int fun(int a,int b,int c,int t)
{
    if(ge(abs(a-b))<t||ge(abs(a-c))<t||ge(abs(b-c))<t) return 0;
    return 1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    while(~scanf("%d",&t))
    {
        if(t==-1) break;
        int all=12*60*60*10;
        int cnt=0;
        int a=0,b=0,c=0;
        t=t*120;
        for(int i=0;i<all;i++)
        {
            cnt+=fun(a,b,c,t);
            a+=1;
            a%=360*120;
            b+=12;
            b%=360*120;
            c+=720;
            c%=360*120;
        }
        printf("%.3f\n",1.0*cnt/all*100);
    }
    return 0;
}
