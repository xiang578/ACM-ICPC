/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Tue Feb 20 12:51:04 2018
File Name     :cf935c.cpp
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
    double r,x1,x2,y1,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    double dis = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(dis>r) {printf("%.8f %.8f %.8f\n",x1,y1,r);return 0;}
    double R = (dis+r)/2;
    double X = fabs(x1-x2)*R*2/dis;
    double Y = fabs(y1-y2)*R*2/dis;
    if(dis < 1e-6) X = fabs(x1-x2),Y = r;
    double a,b;
    if(y1>=y2) b = y2 +Y/2;
    else b = y2 - Y/2;
    if (x2<=x1) a = x2 + X/2;
    else a = x2 - X/2;
    printf("%.8f %.8f %.8f\n", a, b, R);
    return 0;
}
