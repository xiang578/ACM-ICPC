/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Mon Nov  6 16:11:14 2017
File Name     :cf887c.cpp
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
int a[30];

int ok(int x,int y,int z,int t)
{
    if(a[x]==a[y]&&a[y]==a[z]&&a[z]==a[t])
        return 1;
    else
        return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    for(int i=1;i<=24;i++) scanf("%d",a+i);
    if(ok(1,21,3,23)&&ok(5,2,7,4)&&ok(9,6,11,8)&&ok(17,18,19,20)) puts("YES");
    else if(ok(1,6,3,8)&&ok(5,10,7,12)&&ok(9,21,11,23)&&ok(17,18,19,20)) puts("YES");
    else if(ok(1,2,14,16)&&ok(5,6,7,8)&&ok(17,19,11,12)&&ok(3,4,18,20)) puts("YES");
    else if(ok(1,2,17,19)&&ok(5,6,7,8)&&ok(14,16,11,12)&&ok(9,10,18,20)) puts("YES");
    else if(ok(1,2,3,4)&&ok(17,18,7,8)&&ok(9,10,11,12)&&ok(21,22,19,20)) puts("YES");
    else if(ok(1,2,3,4)&&ok(13,14,7,8)&&ok(9,10,11,12)&&ok(5,6,19,20)) puts("YES");
    else puts("NO");
    return 0;
}
