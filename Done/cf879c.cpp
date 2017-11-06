/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Sat Nov  4 07:52:30 2017
File Name     :cf879c.cpp
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

char s[1000000+5][10];
int a[1000000+5];
int b[20];
int c[20];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    memset(b,0xff,sizeof(b));
    memset(c,0xff,sizeof(c));
    for(int i=0;i<n;i++)
    {
        scanf("%s%d",s[i],&a[i]);
        if(s[i][0]=='|')
        {
            for(int j=0;j<10;j++)
            {
                if(a[i]&(1<<j)) {c[j]=-1;b[j]=1;}
            }
        }
        else if(s[i][0]=='&')
        {
            for(int j=0;j<10;j++)
            {
                if((a[i]&(1<<j))==0) {c[j]=-1;b[j]=0;}
            }
        }
        else{
            for(int j=0;j<10;j++)
            {
                if(b[j]==-1)
                {
                    if(c[j]==-1) c[j]=(a[i]>>j)&1;
                    else c[j]^=(a[i]>>j)&1;
                }
                else if(a[i]&(1<<j))
                {
                    b[j]^=1;
                }
                else
                {
                    b[j]^=0;
                }
                //printf("%d %d\n",j,c[j]);
            }
        }
    }
    int ans1=0;
    for(int j=0;j<10;j++)
    {
        if(b[j]==1) ans1+=1<<j;
    }
    int ans2=1023;
    for(int j=0;j<10;j++)
    {
        if(b[j]==0) ans2-=1<<j;
    }
    int ans3=0;
    for(int j=0;j<10;j++)
    {
        if(c[j]==1) ans3+=1<<j;
    }
    printf("3\n| %d\n& %d\n^ %d\n",ans1,ans2,ans3);
    //if(n<=5)
    //{
        //printf("%d\n",n);
        //for(int i=0;i<n;i++)
        //printf("%s %d\n",s[i],a[i]);
        //return 0;
    //}

    return 0;
}
