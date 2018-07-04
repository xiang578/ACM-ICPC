/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Wed May 23 17:01:36 2018
File Name     :cf978d.cpp
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
int n;
int b[123456];
int inf = 0x7fffffff;

int get(int x,int y,int k)
{
    if(n<=2) return 0;
    int t = y-x;
    int p=y;
    for(int i=2;i<n;i++)
    {
        if(p+t!=b[i])
        {
            if(p+t+1==b[i]||p+t-1==b[i])
            {
                k++;
            }
            else return inf;
        }
        p+=t;
    }
    return k;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>b[i];
    int ans=inf;
    if(n==1) {cout<<"0"<<endl;return 0;}
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            ans=min(ans,get(b[0]+i,b[1]+j,abs(i)+abs(j)));
        }
    }
    if(ans==inf) ans=-1;
    cout<<ans<<endl;
    return 0;
}
