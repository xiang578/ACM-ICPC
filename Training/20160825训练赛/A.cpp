/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
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
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;

int get(int x)
{
    if(x==0) return 3;
    else if(x==1) return 4;
    else if(x==2) return 5;
    else if(x==3) return 0;
    else if(x==4) return 1;
    else if(x==5) return 2;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int d[3],_,n,m,face,head,right;
    char s[1024];
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        d[0]=d[1]=d[2]=0;
        face=0;
        head=2;
        right=1;
        for(int i=0; i<n; i++)
        {
            scanf("%s%d",s,&m);
            if(s[0]=='f')
            {

            }
            else if(s[0]=='b')
            {
                face=get(face);
                right=get(right);
                //printf("%d %d\n",face,get(face));
            }
            else if(s[0]=='l')
            {
                int t=face;
                face=get(right);
                right=t;
            }
            else if(s[0]=='r')
            {
                int t=face;
                face=right;
                right=get(t);
            }
            else if(s[0]=='u')
            {
                int t=face;
                face=head;
                head=get(t);
            }
            else if(s[0]=='d')
            {
                int t=face;
                face=get(head);
                head=t;
            }
            if(face<3)
                d[face]+=m;
            else
                d[face%3]-=m;

        }
        printf("%d %d %d %d\n",d[0],d[1],d[2],face);
    }
    return 0;
}
