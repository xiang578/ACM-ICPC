/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Wed May 23 16:22:53 2018
File Name     :cf978a.cpp
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,t;
    int a[1024];
    memset(a,0,sizeof(a));
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++) {cin>>t;v.push_back(t);}
    vector<int>ans;
    for(auto i = v.rbegin();i!=v.rend();i++)
    {
        if(a[*i]) continue;
        a[*i] = 1;
        ans.push_back(*i);
    }
    cout<<ans.size()<<endl;
    for(auto i=ans.rbegin();i!=ans.rend();i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    return 0;
}
