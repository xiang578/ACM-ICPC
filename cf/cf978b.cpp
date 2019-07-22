/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Wed May 23 16:36:47 2018
File Name     :978b.cpp
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
    int n;
    string s;
    int ans=0;
    cin>>n>>s;
    for(int i=0;i+2<s.size();i++)
    {
        if(s[i]=='x'&&s[i+1]=='x'&&s[i+2]=='x') ans++;
    }
    cout<<ans<<endl;
    return 0;
}
