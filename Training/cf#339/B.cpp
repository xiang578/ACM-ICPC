/* ***********************************************
Author        :xryz
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
Created Time  :1-16 11:22:37
File Name     :B.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,cnt,f1,sum,i,j,k,flag,f2;
    char s[100000+5],s1[100000+5];
    while(~scanf("%d",&n))
    {
        sum=0;
        flag=0;
        f2=0;
        for(i=0; i<n; i++)
        {
            scanf("%s",s);
            //printf("%s\n",s);
            int len=strlen(s);
            if(len==1&&s[0]=='0') flag=1;
            f1=0;
            cnt=0;
            for(j=0; j<len; j++)
            {
                if(s[j]!='0'&&s[j]!='1')
                {
                    f1=-1;
                    break;
                }
                if(s[j]=='0'&&f1==1) cnt++;
                if(s[j]=='1') f1++;
                if(f1==2)
                {
                    f1=-1;
                    break;
                }
            }
            //printf("%d %d %d\n",f1,sum,cnt);
            if(f1==-1)
            {
                f2=1;
                for(j=0; j<len; j++)
                    if(s[j]!='0') break;
                for(k=0; j<len; j++,k++)
                    s1[k]=s[j];
                s1[k]=0;
                //printf("%s %s\n",s1,s);
            }
            else
                sum+=cnt;
        }
        if(flag==1) printf("0\n");
        else
        {
            if(f2==1) printf("%s",s1);
            else printf("1");
            for(i=0; i<sum; i++)
                printf("0");
            printf("\n");
        }
    }
    return 0;
}
