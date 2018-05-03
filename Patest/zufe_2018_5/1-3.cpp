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
int book[2000];
int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,b,h,m;
    char s[10];
    scanf("%d",&n);
    int p=0,num=0,time=0;
    memset(book,0xff,sizeof(book));
    while(~scanf("%d%s%d:%d",&b,&s,&h,&m))
    {
        int now=h*60+m;
        if(b==0)
        {
            int ans=0;
            if(num) printf("%d %.0f\n",num,1.0*time/num);
            else puts("0 0");
            memset(book,0xff,sizeof(book));
            num=0,time=0;
        }
        p=now;
        if(s[0]=='S')
        {
                book[b]=now;
        }
        else
        {
            if(book[b]==-1) continue;
            else
            {
                num++;
                time+=now-book[b];
                book[b]=-1;
            }
        }
    }
    //printf("%d %.0f\n",num,1.0*time/num);
    return 0;
}
