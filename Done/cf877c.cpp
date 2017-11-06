/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Mon Nov  6 13:31:59 2017
File Name     :cf877c.cpp
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
vector<int>ans;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i+=2) ans.push_back(i);
    for(int i=1;i<=n;i+=2) ans.push_back(i);
    for(int i=2;i<=n;i+=2) ans.push_back(i);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}
