/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Tue Nov 14 14:32:02 2017
File Name     :cf888d.cpp
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
    long long ans=0,n,k;
    cin>>n>>k;
    if(k>=1) ans+=1;
    if(k>=2) {ans+=1LL*n*(n-1)/2;}
    if(k>=3) {ans+=1LL*n*(n-1)*(n-2)/3;}
    if(k>=4) {ans+=1LL*n*(n-1)*(n-2)*(n-3)/24*9;}
    cout<<ans<<endl;
    return 0;
}
