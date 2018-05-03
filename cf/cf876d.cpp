/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Wed Nov  8 15:53:46 2017
File Name     :cf876d.cpp
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

int n,p,t,a[312345];
long long cnt,ans;
vector<int>v;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n;
    cnt=1;
    p=n;
    v.push_back(cnt);
    for(int i=0;i<n;i++)
    {
        cin>>t;
        a[t]=1;
        cnt++;
        while(a[p]) {p--;cnt--;}
        v.push_back(cnt);
    }
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    return 0;
}
