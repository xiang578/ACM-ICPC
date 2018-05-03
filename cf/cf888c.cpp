/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Tue Nov 14 14:12:03 2017
File Name     :cf888c.cpp
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
    string s;
    cin>>s;
    int ans=s.size();
    int n=s.size();
    for(int i='a';i<='z';i++)
    {
        int mx=-1;
        int p=-1;
        for(int j=0;j<n;j++)
        {
            if(s[j]==i) mx=max(j-p,mx),p=j;
        }
        mx=max(n-p,mx);
        if(mx==-1) continue;
        ans=min(ans,mx);
    }
    cout<<ans<<endl;
    return 0;
}
