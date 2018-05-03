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


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,a,b;
    string s;
    vector<string>ans;
    cin>>n;
    while(n--)
    {
        cin>>s>>a>>b;
        if(a<15||a>20||b>70||b<50) ans.push_back(s);
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}