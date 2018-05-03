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
string c[200];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n,d,h,m;
    cin>>n;
    while(n--){
    scanf("%d %d:%d",&d,&h,&m);
    if(d==0) {printf("%d %02d:%02d\n",d,h,m);}
    else 
    {
        int t = h*60+m;
        if(d%2==0) t+=24*60;
        int nd=0;
        if(d<=2) nd=1;
        else if(d<=4) nd=2;
        else nd=3;
        t=t/2;
        int nh=t/60;
        int nm=t-nh*60;
        printf("%d %02d:%02d\n",nd,nh,nm);
    }
    }
    return 0;
}