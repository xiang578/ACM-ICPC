/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Tue Feb 20 12:37:28 2018
File Name     :cf#935b.cpp
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
    int n,ans;
    string s;
    cin>>n;
    cin>>s;
    int x=0,y=0;
    int m=s.size();
    ans = 0;
    for(int i=0;i<m;i++)
    {
        if(x&&x==y&&s[i-1]==s[i])  ans++;
        if(s[i]=='U') y++;
        if(s[i]=='R') x++;
    }
    cout<<ans<<endl;
    return 0;
}
