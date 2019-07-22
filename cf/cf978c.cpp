/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Wed May 23 16:41:29 2018
File Name     :cf978c.cpp
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
typedef long long ll;
ll a[212345],s[212345];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=a[i]+s[i-1];
    }
    int k=0;
    for(int i=0;i<m;i++)
    {
        ll t;
        cin>>t;
        while(t>s[k]) k++;
        printf("%d %lld\n",k,t-s[k-1]);
    }
    return 0;
}
